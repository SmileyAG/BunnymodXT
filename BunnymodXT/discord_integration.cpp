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

		// Chapters
		const std::unordered_set<std::string> hl1_chapter1{
			"c1a0"s,
			"c1a0a"s,
			"c1a0b"s,
			"c1a0d"s,
			"c1a0e"s
		};

		const std::unordered_set<std::string> hl1_chapter2{
			"c1a0c"s,
			"c1a1"s,
			"c1a1a"s,
			"c1a1b"s,
			"c1a1c"s,
			"c1a1d"s,
			"c1a1f"s
		};

		const std::unordered_set<std::string> hl1_chapter3{
			"c1a2"s,
			"c1a2a"s,
			"c1a2b"s,
			"c1a2c"s,
			"c1a2d"s
		};

		const std::unordered_set<std::string> hl1_chapter4{
			"c1a3"s,
			"c1a3a"s,
			"c1a3b"s,
			"c1a3c"s,
			"c1a3d"s
		};

		const std::unordered_set<std::string> hl1_chapter5{
			"c1a4"s,
			"c1a4b"s,
			"c1a4d"s,
			"c1a4e"s,
			"c1a4f"s,
			"c1a4g"s,
			"c1a4i"s,
			"c1a4j"s,
			"c1a4k"s
		};

		const std::unordered_set<std::string> hl1_chapter6{
			"c2a1"s,
			"c2a1a"s,
			"c2a1b"s
		};

		const std::unordered_set<std::string> hl1_chapter7{
			"c2a2"s,
			"c2a2a"s,
			"c2a2b1"s,
			"c2a2b2"s,
			"c2a2c"s,
			"c2a2d"s,
			"c2a2e"s,
			"c2a2f"s,
			"c2a2g"s,
			"c2a2h"s
		};

		const std::unordered_set<std::string> hl1_chapter8{
			"c2a3"s,
			"c2a3a"s,
			"c2a3b"s,
			"c2a3c"s,
			"c2a3d"s,
			"c2a3e"s
		};

		const std::unordered_set<std::string> hl1_chapter9{
			"c2a4"s,
			"c2a4a"s,
			"c2a4b"s,
			"c2a4c"s
		};

		const std::unordered_set<std::string> hl1_chapter10{
			"c2a4d"s,
			"c2a4e"s,
			"c2a4f"s,
			"c2a4g"s
		};

		const std::unordered_set<std::string> hl1_chapter11{
			"c2a5"s,
			"c2a5a"s,
			"c2a5b"s,
			"c2a5c"s,
			"c2a5d"s,
			"c2a5e"s,
			"c2a5f"s,
			"c2a5g"s,
			"c2a5w"s,
			"c2a5x"s
		};

		const std::unordered_set<std::string> hl1_chapter12{
			"c3a1"s,
			"c3a1a"s,
			"c3a1b"s
		};

		const std::unordered_set<std::string> hl1_chapter13{
			"c3a2"s,
			"c3a2a"s,
			"c3a2b"s,
			"c3a2c"s,
			"c3a2d"s,
			"c3a2e"s,
			"c3a2f"s
		};

		const std::unordered_set<std::string> hl1_chapter14{
			"c3a2"s,
			"c3a2a"s,
			"c3a2b"s,
			"c3a2c"s,
			"c3a2d"s,
			"c3a2e"s,
			"c3a2f"s
		};

		const std::unordered_set<std::string> hl1_chapter15{
			"c4a1"s
		};

		const std::unordered_set<std::string> hl1_chapter16{
			"c4a2"s,
			"c4a2a"s,
			"c4a2b"s
		};

		const std::unordered_set<std::string> hl1_chapter17{
			"c4a1a"s,
			"c4a1b"s,
			"c4a1c"s,
			"c4a1d"s,
			"c4a1e"s,
			"c4a1f"s
		};

		const std::unordered_set<std::string> hl1_chapter18{
			"c4a3"s
		};

		const std::unordered_set<std::string> hl1_chapter19{
			"c5a1"s
		};

		const std::unordered_set<std::string> hl1_chapter20{
			"t0a0"s,
			"t0a0a"s,
			"t0a0b"s,
			"t0a0b1"s,
			"t0a0b2"s,
			"t0a0c"s,
			"t0a0d"s
		};

		const std::unordered_set<std::string> op4_chapter1{
			"of1a1"s,
			"of1a2"s,
			"of1a3"s,
			"of1a4"s,
			"of1a4b"s
		};

		const std::unordered_set<std::string> op4_chapter2{
			"of1a5"s,
			"of1a5b"s,
			"of1a6"s
		};

		const std::unordered_set<std::string> op4_chapter3{
			"of2a1"s,
			"of2a1b"s,
			"of2a2"s,
			"of2a3"s
		};

		const std::unordered_set<std::string> op4_chapter4{
			"of2a4"s,
			"of2a5"s,
			"of2a6"s
		};

		const std::unordered_set<std::string> op4_chapter5{
			"of3a1"s,
			"of3a1b"s,
			"of3a2"s
		};

		const std::unordered_set<std::string> op4_chapter6{
			"of3a4"s,
			"of3a5"s,
			"of3a6"s
		};

		const std::unordered_set<std::string> op4_chapter7{
			"of4a1"s,
			"of4a2"s,
			"of4a3"s
		};

		const std::unordered_set<std::string> op4_chapter8{
			"of4a4"s,
			"of4a5"s
		};

		const std::unordered_set<std::string> op4_chapter9{
			"of5a1"s,
			"of5a2"s,
			"of5a3"s,
			"of5a4"s
		};

		const std::unordered_set<std::string> op4_chapter10{
			"of6a1"s,
			"of6a2"s,
			"of6a3"s,
			"of6a4"s
		};

		const std::unordered_set<std::string> op4_chapter11{
			"of6a4b"s,
			"of6a5"s
		};

		const std::unordered_set<std::string> op4_chapter12{
			"of7a0"s
		};

		const std::unordered_set<std::string> op4_chapter13{
			"ofboot0"s,
			"ofboot1"s,
			"ofboot2"s,
			"ofboot3"s,
			"ofboot4"s
		};

		const std::unordered_set<std::string> bs_chapter1{
			"ba_security1"s,
			"ba_security2"s,
			"ba_maint"s,
			"ba_elevator"s
		};

		const std::unordered_set<std::string> bs_chapter2{
			"ba_canal1"s,
			"ba_canal1b"s,
			"ba_canal2"s,
			"ba_canal3"s
		};

		const std::unordered_set<std::string> bs_chapter3{
			"ba_yard1"s,
			"ba_yard2"s,
			"ba_yard3"s,
			"ba_yard3a"s,
			"ba_yard3b"s,
			"ba_yard4"s,
			"ba_yard4a"s,
			"ba_yard5"s,
			"ba_yard5a"s,
			"ba_teleport1"s
		};

		const std::unordered_set<std::string> bs_chapter4{
			"ba_xen1"s,
			"ba_xen2"s,
			"ba_xen3"s,
			"ba_xen4"s,
			"ba_xen5"s,
			"ba_xen6"s
		};

		const std::unordered_set<std::string> bs_chapter5{
			"ba_power1"s,
			"ba_power2"s
		};

		const std::unordered_set<std::string> bs_chapter6{
			"ba_teleport2"s
		};

		const std::unordered_set<std::string> bs_chapter7{
			"ba_outro"s
		};

		const std::unordered_set<std::string> bs_chapter8{
			"ba_hazard1"s,
			"ba_hazard2"s,
			"ba_hazard3"s,
			"ba_hazard4"s,
			"ba_hazard5"s,
			"ba_hazard6"s
		};

		const std::unordered_set<std::string> gmc_chapter1{
			"CITY2A"s,
			"city2b"s,
			"city3a"s,
			"city3b"s
		};

		const std::unordered_set<std::string> gmc_chapter2{
			"MAYAN0A"s,
			"MAYAN0B"s,
			"mayan1"s,
			"mayan3a"s,
			"mayan4"s,
			"mayan6"s,
			"MAYAN8"s
		};

		const std::unordered_set<std::string> gmc_chapter3{
			"cinematic1"s,
			"cinematic2"s
		};

		const std::unordered_set<std::string> gmc_chapter4{
			"rust1"s,
			"rust2a"s,
			"rust2b"s,
			"rust3a"s,
			"RUST4A"s,
			"RUST4B"s,
			"RUST4C"s,
			"RUST5A"s,
			"rust6a"s,
			"rust6b"s,
			"rust6c"s,
			"rust6d"s,
			"rust7a"s,
			"RUST7B"s,
			"RUST7C"s,
			"rust7d"s,
			"rust7e"s,
			"rust8a"s,
			"rust9a"s
		};

		const std::unordered_set<std::string> gmc_chapter5{
			"cinematic3"s,
			"cinematic4"s
		};

		const std::unordered_set<std::string> gmc_chapter6{
			"west1"s,
			"west2"s,
			"west3a"s,
			"west3b"s,
			"west4a"s,
			"west4b"s,
			"west5b"s,
			"west6a"s,
			"west6b"s,
			"west6c"s,
			"west6d"s,
			"west6e"s
		};

		const std::unordered_set<std::string> gmc_chapter7{
			"REBAR0A"s,
			"REBAR0B"s,
			"REBAR2A"s,
			"REBAR2B"s,
			"REBAR2C"s,
			"REBAR2D"s,
			"REBAR2E"s,
			"REBAR2F"s,
			"REBAR2G"s,
			"REBAR2H"s,
			"REBAR2I"s,
			"REBAR2J"s,
			"REBAR2K"s,
			"rebar2l"s,
			"REBAR3B"s,
			"REBAR3D"s,
			"REBAR3E"s
		};

		const std::unordered_set<std::string> gmc_chapter8{
			"end1"s,
			"end2"s
		};

		const std::unordered_set<std::string> czds_chapter1{
			"cz_recoil"s,
			"cz_recoil2"s
		};

		const std::unordered_set<std::string> czds_chapter2{
			"cz_lostcause"s,
			"cz_lostcause2"s
		};

		const std::unordered_set<std::string> czds_chapter3{
			"cz_silo01"s,
			"cz_silo02"s,
			"cz_silo03"s,
			"cz_silo04"s,
			"cz_silo05"s
		};

		const std::unordered_set<std::string> czds_chapter4{
			"cz_brecon01"s,
			"cz_brecon02"s,
			"cz_brecon03"s,
			"cz_brecon04"s,
			"cz_brecon05"s,
			"cz_brecon06"s
		};

		const std::unordered_set<std::string> czds_chapter5{
			"cz_druglab1"s,
			"cz_druglab2"s,
			"cz_druglab3"s,
			"cz_druglab4"s
		};

		const std::unordered_set<std::string> czds_chapter6{
			"cz_motor1"s,
			"cz_motor2"s,
			"cz_motor3"s
		};

		const std::unordered_set<std::string> czds_chapter7{
			"cz_thinice01"s,
			"cz_thinice02"s,
			"cz_thinice03"s
		};

		const std::unordered_set<std::string> czds_chapter8{
			"cz_downed1"s,
			"cz_downed2"s,
			"cz_downed3"s,
			"cz_downed4"s
		};

		const std::unordered_set<std::string> czds_chapter9{
			"cz_hankagai1"s,
			"cz_hankagai2"s,
			"cz_hankagai3"s,
			"cz_hankagai4"s,
			"cz_hankagai5"s
		};

		const std::unordered_set<std::string> czds_chapter10{
			"cz_turncrank"s,
			"cz_turncrank2"s,
			"cz_turncrank3"s
		};

		const std::unordered_set<std::string> czds_chapter11{
			"cz_alamo"s,
			"cz_alamo2"s
		};

		const std::unordered_set<std::string> czds_chapter12{
			"cz_hr01"s,
			"cz_hr02"s,
			"cz_hr02b"s,
			"cz_hr03"s,
			"cz_hr04"s,
			"cz_hr05"s,
			"cz_hr06"s,
			"cz_hr07"s
		};

		const std::unordered_set<std::string> czds_chapter13{
			"cz_fastline1"s,
			"cz_fastline2"s,
			"cz_fastline3"s,
			"cz_fastline4"s
		};

		const std::unordered_set<std::string> czds_chapter14{
			"cz_miami1"s,
			"cz_miami2"s
		};

		const std::unordered_set<std::string> czds_chapter15{
			"cz_pipedream1"s,
			"cz_pipedream2"s,
			"cz_pipedream3"s
		};

		const std::unordered_set<std::string> czds_chapter16{
			"cz_run1"s,
			"cz_run2"s,
			"cz_run3"s
		};

		const std::unordered_set<std::string> czds_chapter17{
			"cz_sandstorm"s,
			"cz_sandstorm2"s,
			"cz_sandstorm3"s,
			"cz_sandstorm4"s
		};

		const std::unordered_set<std::string> czds_chapter18{
			"cz_truth1"s,
			"cz_truth2"s,
			"cz_truth3"s,
			"cz_truth4"s
		};

		const std::unordered_set<std::string> czds_chapter19{
			"cz_train01"s,
			"cz_train02"s,
			"cz_train03"s
		};

		// For tracking if we're in-game.
		bool updated_client_data = false;

		// Text names of game states
		const std::string STATE_NAMES[] = {
			"Not Playing"s,
			"Playing"s
		};

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
						if (presence.largeImageKey == "default")
						{
							// Game directory
							const char* gameDir = ClientDLL::GetInstance().pEngfuncs->pfnGetGameDirectory();

							if (strstr(gameDir, "valve") != NULL)
							{
								if (hl1_chapter1.find(map_name) != hl1_chapter1.cend())
									presence.largeImageKey = "hl1_chapter1";

								if (hl1_chapter2.find(map_name) != hl1_chapter2.cend())
									presence.largeImageKey = "hl1_chapter2";

								if (hl1_chapter3.find(map_name) != hl1_chapter3.cend())
									presence.largeImageKey = "hl1_chapter3";

								if (hl1_chapter4.find(map_name) != hl1_chapter4.cend())
									presence.largeImageKey = "hl1_chapter4";

								if (hl1_chapter5.find(map_name) != hl1_chapter5.cend())
									presence.largeImageKey = "hl1_chapter5";

								if (hl1_chapter6.find(map_name) != hl1_chapter6.cend())
									presence.largeImageKey = "hl1_chapter6";

								if (hl1_chapter7.find(map_name) != hl1_chapter7.cend())
									presence.largeImageKey = "hl1_chapter7";

								if (hl1_chapter8.find(map_name) != hl1_chapter8.cend())
									presence.largeImageKey = "hl1_chapter8";

								if (hl1_chapter9.find(map_name) != hl1_chapter9.cend())
									presence.largeImageKey = "hl1_chapter9";

								if (hl1_chapter10.find(map_name) != hl1_chapter10.cend())
									presence.largeImageKey = "hl1_chapter10";

								if (hl1_chapter11.find(map_name) != hl1_chapter11.cend())
									presence.largeImageKey = "hl1_chapter11";

								if (hl1_chapter12.find(map_name) != hl1_chapter12.cend())
									presence.largeImageKey = "hl1_chapter12";

								if (hl1_chapter13.find(map_name) != hl1_chapter13.cend())
									presence.largeImageKey = "hl1_chapter13";

								if (hl1_chapter14.find(map_name) != hl1_chapter14.cend())
									presence.largeImageKey = "hl1_chapter14";

								if (hl1_chapter15.find(map_name) != hl1_chapter15.cend())
									presence.largeImageKey = "hl1_chapter15";

								if (hl1_chapter16.find(map_name) != hl1_chapter16.cend())
									presence.largeImageKey = "hl1_chapter16";

								if (hl1_chapter17.find(map_name) != hl1_chapter17.cend())
									presence.largeImageKey = "hl1_chapter17";

								if (hl1_chapter18.find(map_name) != hl1_chapter18.cend())
									presence.largeImageKey = "hl1_chapter18";

								if (hl1_chapter19.find(map_name) != hl1_chapter19.cend())
									presence.largeImageKey = "hl1_chapter19";

								if (hl1_chapter20.find(map_name) != hl1_chapter20.cend())
									presence.largeImageKey = "hl1_chapter20";
							}

							if (strstr(gameDir, "gearbox") != NULL)
							{
								if (op4_chapter1.find(map_name) != op4_chapter1.cend())
									presence.largeImageKey = "op4_chapter1";

								if (op4_chapter2.find(map_name) != op4_chapter2.cend())
									presence.largeImageKey = "op4_chapter2";

								if (op4_chapter3.find(map_name) != op4_chapter3.cend())
									presence.largeImageKey = "op4_chapter3";

								if (op4_chapter4.find(map_name) != op4_chapter4.cend())
									presence.largeImageKey = "op4_chapter4";

								if (op4_chapter5.find(map_name) != op4_chapter5.cend())
									presence.largeImageKey = "op4_chapter5";

								if (op4_chapter6.find(map_name) != op4_chapter6.cend())
									presence.largeImageKey = "op4_chapter6";

								if (op4_chapter7.find(map_name) != op4_chapter7.cend())
									presence.largeImageKey = "op4_chapter7";

								if (op4_chapter8.find(map_name) != op4_chapter8.cend())
									presence.largeImageKey = "op4_chapter8";

								if (op4_chapter9.find(map_name) != op4_chapter9.cend())
									presence.largeImageKey = "op4_chapter9";

								if (op4_chapter10.find(map_name) != op4_chapter10.cend())
									presence.largeImageKey = "op4_chapter10";

								if (op4_chapter11.find(map_name) != op4_chapter11.cend())
									presence.largeImageKey = "op4_chapter11";

								if (op4_chapter12.find(map_name) != op4_chapter12.cend())
									presence.largeImageKey = "op4_chapter12";

								if (op4_chapter13.find(map_name) != op4_chapter13.cend())
									presence.largeImageKey = "op4_chapter13";
							}

							if (strstr(gameDir, "bshift") != NULL)
							{
								if (bs_chapter1.find(map_name) != bs_chapter1.cend())
									presence.largeImageKey = "bs_chapter1";

								if (bs_chapter2.find(map_name) != bs_chapter2.cend())
									presence.largeImageKey = "bs_chapter2";

								if (bs_chapter3.find(map_name) != bs_chapter3.cend())
									presence.largeImageKey = "bs_chapter3";

								if (bs_chapter4.find(map_name) != bs_chapter4.cend())
									presence.largeImageKey = "bs_chapter4";

								if (bs_chapter5.find(map_name) != bs_chapter5.cend())
									presence.largeImageKey = "bs_chapter5";

								if (bs_chapter6.find(map_name) != bs_chapter6.cend())
									presence.largeImageKey = "bs_chapter6";

								if (bs_chapter7.find(map_name) != bs_chapter7.cend())
									presence.largeImageKey = "bs_chapter7";

								if (bs_chapter8.find(map_name) != bs_chapter8.cend())
									presence.largeImageKey = "bs_chapter8";
							}

							if (strstr(gameDir, "rewolf") != NULL)
							{
								if (gmc_chapter1.find(map_name) != gmc_chapter1.cend())
									presence.largeImageKey = "gmc_chapter1";

								if (gmc_chapter2.find(map_name) != gmc_chapter2.cend())
									presence.largeImageKey = "gmc_chapter2";

								if (gmc_chapter3.find(map_name) != gmc_chapter3.cend())
									presence.largeImageKey = "gmc_chapter3";

								if (gmc_chapter4.find(map_name) != gmc_chapter4.cend())
									presence.largeImageKey = "gmc_chapter4";

								if (gmc_chapter5.find(map_name) != gmc_chapter5.cend())
									presence.largeImageKey = "gmc_chapter5";

								if (gmc_chapter6.find(map_name) != gmc_chapter6.cend())
									presence.largeImageKey = "gmc_chapter6";

								if (gmc_chapter7.find(map_name) != gmc_chapter7.cend())
									presence.largeImageKey = "gmc_chapter7";

								if (gmc_chapter8.find(map_name) != gmc_chapter8.cend())
									presence.largeImageKey = "gmc_chapter8";
							}

							if (strstr(gameDir, "czeror") != NULL)
							{
								if (czds_chapter1.find(map_name) != czds_chapter1.cend())
									presence.largeImageKey = "czds_chapter1";

								if (czds_chapter2.find(map_name) != czds_chapter2.cend())
									presence.largeImageKey = "czds_chapter2";

								if (czds_chapter3.find(map_name) != czds_chapter3.cend())
									presence.largeImageKey = "czds_chapter3";

								if (czds_chapter4.find(map_name) != czds_chapter4.cend())
									presence.largeImageKey = "czds_chapter4";

								if (czds_chapter5.find(map_name) != czds_chapter5.cend())
									presence.largeImageKey = "czds_chapter5";

								if (czds_chapter6.find(map_name) != czds_chapter6.cend())
									presence.largeImageKey = "czds_chapter6";

								if (czds_chapter7.find(map_name) != czds_chapter7.cend())
									presence.largeImageKey = "czds_chapter7";

								if (czds_chapter8.find(map_name) != czds_chapter8.cend())
									presence.largeImageKey = "czds_chapter8";

								if (czds_chapter9.find(map_name) != czds_chapter9.cend())
									presence.largeImageKey = "czds_chapter9";

								if (czds_chapter10.find(map_name) != czds_chapter10.cend())
									presence.largeImageKey = "czds_chapter10";

								if (czds_chapter11.find(map_name) != czds_chapter11.cend())
									presence.largeImageKey = "czds_chapter11";

								if (czds_chapter12.find(map_name) != czds_chapter12.cend())
									presence.largeImageKey = "czds_chapter12";

								if (czds_chapter13.find(map_name) != czds_chapter13.cend())
									presence.largeImageKey = "czds_chapter13";

								if (czds_chapter14.find(map_name) != czds_chapter14.cend())
									presence.largeImageKey = "czds_chapter14";

								if (czds_chapter15.find(map_name) != czds_chapter15.cend())
									presence.largeImageKey = "czds_chapter15";

								if (czds_chapter16.find(map_name) != czds_chapter16.cend())
									presence.largeImageKey = "czds_chapter16";

								if (czds_chapter17.find(map_name) != czds_chapter17.cend())
									presence.largeImageKey = "czds_chapter17";

								if (czds_chapter18.find(map_name) != czds_chapter18.cend())
									presence.largeImageKey = "czds_chapter18";

								if (czds_chapter19.find(map_name) != czds_chapter19.cend())
									presence.largeImageKey = "czds_chapter19";
							}
						}

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
