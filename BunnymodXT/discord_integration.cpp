#include "stdafx.hpp"
#include <unordered_set>
#include "modules/ClientDLL.hpp"
#include <discord-rpc/include/discord_rpc.h>

using namespace std::literals;

namespace discord_integration
{
	namespace
	{
		// From Discord developer dashboard.
		constexpr const char CLIENT_ID[] = "962015108714885150";

		// Maps for which we have thumbnails.
		const std::unordered_set<std::string> maps_with_thumbnails {
			// Half-Life compaign
			"c0a0"s,
			"c0a0a"s,
			"c0a0b"s,
			"c0a0c"s,
			"c0a0d"s,
			"c0a0e"s,
			"c1a0"s,
			"c1a0a"s,
			"c1a0b"s,
			"c1a0c"s,
			"c1a0d"s,
			"c1a0e"s,
			"c1a1"s,
			"c1a1a"s,
			"c1a1b"s,
			"c1a1c"s,
			"c1a1d"s,
			"c1a1f"s,
			"c1a2"s,
			"c1a2a"s,
			"c1a2b"s,
			"c1a2c"s,
			"c1a2d"s,
			"c1a3"s,
			"c1a3a"s,
			"c1a3b"s,
			"c1a3c"s,
			"c1a3d"s,
			"c1a4"s,
			"c1a4b"s,
			"c1a4d"s,
			"c1a4e"s,
			"c1a4f"s,
			"c1a4g"s,
			"c1a4i"s,
			"c1a4j"s,
			"c1a4k"s,
			"c2a1"s,
			"c2a1a"s,
			"c2a1b"s,
			"c2a2"s,
			"c2a2a"s,
			"c2a2b1"s,
			"c2a2b2"s,
			"c2a2c"s,
			"c2a2d"s,
			"c2a2e"s,
			"c2a2f"s,
			"c2a2g"s,
			"c2a2h"s,
			"c2a3"s,
			"c2a3a"s,
			"c2a3b"s,
			"c2a3c"s,
			"c2a3d"s,
			"c2a3e"s,
			"c2a4"s,
			"c2a4a"s,
			"c2a4b"s,
			"c2a4c"s,
			"c2a4d"s,
			"c2a4e"s,
			"c2a4f"s,
			"c2a4g"s,
			"c2a5"s,
			"c2a5a"s,
			"c2a5b"s,
			"c2a5c"s,
			"c2a5d"s,
			"c2a5e"s,
			"c2a5f"s,
			"c2a5g"s,
			"c2a5w"s,
			"c2a5x"s,
			"c3a1"s,
			"c3a1a"s,
			"c3a1b"s,
			"c3a2"s,
			"c3a2a"s,
			"c3a2b"s,
			"c3a2c"s,
			"c3a2d"s,
			"c3a2e"s,
			"c3a2f"s,
			"c4a1"s,
			"c4a1a"s,
			"c4a1b"s,
			"c4a1c"s,
			"c4a1d"s,
			"c4a1e"s,
			"c4a1f"s,
			"c4a2"s,
			"c4a2a"s,
			"c4a2b"s,
			"c4a3"s,
			"c5a1"s,
			"t0a0"s,
			"t0a0a"s,
			"t0a0b"s,
			"t0a0b1"s,
			"t0a0b2"s,
			"t0a0c"s,
			"t0a0d"s
		};

		// Text names of game states
		const std::string STATE_NAMES[] = {
			"Not Playing"s,
			"Playing"s
		};

		// For tracking if we're in-game.
		bool updated_client_data = false;

		// Possible game states.
		enum class game_state
		{
			NOT_PLAYING = 0,
			PLAYING
		};

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
					// Get the map name and icon.
					get_map_name(map_name, ARRAYSIZE_HL(map_name));
					if (map_name[0])
					{
						if (maps_with_thumbnails.find(map_name) != maps_with_thumbnails.cend())
							presence.largeImageKey = map_name;

						presence.largeImageText = map_name;
					}
				}

				presence.state = state.c_str();

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
			ClientDLL::GetInstance().pEngfuncs->Con_Printf(const_cast<char*>("Connected to Discord.\n"));
		}

		void handle_errored(int error_code, const char* message)
		{
			ClientDLL::GetInstance().pEngfuncs->Con_Printf(const_cast<char*>("Discord error (%d): %s\n"), error_code, message);
		}

		void handle_disconnected(int error_code, const char* message)
		{
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