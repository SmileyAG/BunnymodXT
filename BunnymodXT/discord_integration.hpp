#pragma once
#include "stdafx.hpp"
#include <unordered_set>
#include "modules/ClientDLL.hpp"
#include <discord-rpc/include/discord_rpc.h>
#include "cvars.hpp"

using namespace std::literals;

namespace discord_integration
{
		/**
		* Initializes the Discord integration. Call this once on game start.
		*/
		void initialize();

		/**
		* Shuts down the Discord integration. Call this once on game end.
		*/
		void shutdown();

		/**
		* Call this in HUD_UpdateClientData.
		*/
		void on_update_client_data();

		/**
		* Call this in HUD_Frame.
		*/
		void on_frame();

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
}
