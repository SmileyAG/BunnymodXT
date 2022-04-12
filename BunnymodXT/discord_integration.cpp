#include "discord_integration.hpp"

namespace discord_integration
{
	namespace
	{
		// From Discord developer dashboard.
		constexpr const char CLIENT_ID[] = "962015108714885150";

		// Text names of game states
		const std::string STATE_NAMES[] = {
			"In menu"s,
			"Playing"s
		};

		// Possible game states.
		enum class game_state
		{
			NOT_PLAYING = 0,
			PLAYING
		};

		// For tracking if we're in-game.
		bool updated_client_data = false;

		// Class that handles tracking state changes.
		class DiscordState {
		public:
			DiscordState()
				: cur_state(game_state::NOT_PLAYING)
				, dirty(true)
			{
				update_presence();
			};

			inline void set_game_state(game_state new_game_state)
			{
				if (cur_state != new_game_state)
				{
					cur_state = new_game_state;

					dirty = true;
				}
			}

			inline static size_t get_map_name(char* dest, size_t count)
			{
				auto map_path = ClientDLL::GetInstance().pEngfuncs->pfnGetLevelName();

				const char* slash = strrchr(map_path, '/');
				if (!slash)
					slash = map_path - 1;

				const char* dot = strrchr(map_path, '.');
				if (!dot)
					dot = map_path + strlen(map_path);

				size_t bytes_to_copy = std::min(count - 1, static_cast<size_t>(dot - slash - 1));

				strncpy(dest, slash + 1, bytes_to_copy);
				dest[bytes_to_copy] = '\0';

				return bytes_to_copy;
			}

			inline game_state get_game_state() const
			{
				return cur_state;
			}

			inline void update_presence_if_dirty()
			{
				if (dirty)
					update_presence();
			}

		protected:
			void update_presence()
			{
				dirty = false;

				DiscordRichPresence presence{};

				std::string state = STATE_NAMES[static_cast<size_t>(cur_state)];

				// Default icon.
				presence.largeImageKey = "default";

				// Declare these outside of the following block, so they are in scope for Discord_UpdatePresence().
				char map_name[64];

				if (cur_state != game_state::NOT_PLAYING)
				{
					if (ClientDLL::GetInstance().pEngfuncs)
					{
						// Get the map name and icon.
						get_map_name(map_name, ARRAYSIZE_HL(map_name));
						if (map_name[0])
						{
							// Game directory
							const char* gameDir = ClientDLL::GetInstance().pEngfuncs->pfnGetGameDirectory();

							if (strncmp(gameDir, "valve", 5) == NULL)
							{
								if (hl1_chapter1.find(map_name) != hl1_chapter1.cend())
									presence.largeImageKey = "hl1_chapter1";
							}

							if (strncmp(gameDir, "gearbox", 7) == NULL)
							{
							}

							if (strncmp(gameDir, "bshift", 6) == NULL)
							{
							}

							if (strncmp(gameDir, "rewolf", 6) == NULL)
							{
							}

							if (strncmp(gameDir, "czeror", 6) == NULL)
							{
							}

							char buffer_details[128];
							sprintf(buffer_details, "Map: %s | Game: %s", map_name, gameDir);

							presence.details = buffer_details;
							presence.largeImageText = map_name; // TODO: should be chapter name instead map_name
						}
					}
				}

				std::ostringstream oss;
				oss << CVars::fps_max.GetFloat() << std::fixed << std::setprecision(1);

				char buffer_state[128];
				sprintf(buffer_state, "%s | FPS Max: %s | Skill: %u", state.c_str(), oss.str().c_str(), CVars::skill.GetInt());

				presence.state = buffer_state;
				presence.buttonLabel[0] = "Download";
				presence.buttonLabel[1] = "Join SourceRuns Discord";
				presence.buttonUrl[0] = "https://github.com/YaLTeR/BunnymodXT";
				presence.buttonUrl[1] = "https://discord.gg/sourceruns";

				Discord_UpdatePresence(&presence);
			}

			game_state cur_state;

			// Flag indicating there are some changes not sent to Discord yet.
			bool dirty;
		};

		// Pointer so the constructor doesn't run too early.
		std::unique_ptr<DiscordState> discord_state;

		void handle_ready(const DiscordUser*)
		{
			if (ClientDLL::GetInstance().pEngfuncs)
				ClientDLL::GetInstance().pEngfuncs->Con_Printf(const_cast<char*>("Connected to Discord.\n"));
		}

		void handle_errored(int error_code, const char* message)
		{
			if (ClientDLL::GetInstance().pEngfuncs)
				ClientDLL::GetInstance().pEngfuncs->Con_Printf(const_cast<char*>("Discord error (%d): %s\n"), error_code, message);
		}

		void handle_disconnected(int error_code, const char* message)
		{
			if (ClientDLL::GetInstance().pEngfuncs)
				ClientDLL::GetInstance().pEngfuncs->Con_Printf(const_cast<char*>("Disconnected from Discord (%d): %s\n"), error_code, message);
		}
	}

	void initialize()
	{
		DiscordEventHandlers handlers{};
		handlers.ready = handle_ready;
		handlers.errored = handle_errored;
		handlers.disconnected = handle_disconnected;
		Discord_Initialize(CLIENT_ID, &handlers, 1, NULL);

		discord_state = std::make_unique<DiscordState>();

		Discord_RunCallbacks();
	}

	void shutdown()
	{
		discord_state.reset();
		Discord_Shutdown();
	}

	void on_update_client_data()
	{
		updated_client_data = true;
	}

	void on_frame()
	{
		// Check if we're still in-game.
		if (!updated_client_data)
			discord_state->set_game_state(game_state::NOT_PLAYING);
		else if (discord_state->get_game_state() == game_state::NOT_PLAYING)
			// Only set this if we weren't playing, otherwise we might overwrite some other state.
			discord_state->set_game_state(game_state::PLAYING);

		updated_client_data = false;

		discord_state->update_presence_if_dirty();

		Discord_RunCallbacks();
	}
}
