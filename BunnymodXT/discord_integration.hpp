#pragma once
#include <discord-rpc/include/discord_rpc.h>
#include "stdafx.hpp"
#include <unordered_set>
#include "modules/ClientDLL.hpp"
#include <string>
#include "cvars.hpp"

using namespace std::literals;

namespace discord_integration
{
		/**
		* Initializes the Discord integration. Call this once on BXT or game start.
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
		const std::unordered_set<std::string> hl1_chapter1{ // Anomalous Materials
			"c1a0"s,
			"c1a0a"s,
			"c1a0b"s,
			"c1a0d"s,
			"c1a0e"s
		};

		const std::unordered_set<std::string> hl1_chapter2{ // Unforeseen Consequences
			"c1a0c"s,
			"c1a1"s,
			"c1a1a"s,
			"c1a1b"s,
			"c1a1c"s,
			"c1a1d"s,
			"c1a1f"s
		};

		const std::unordered_set<std::string> hl1_chapter3{ // Office Complex
			"c1a2"s,
			"c1a2a"s,
			"c1a2b"s,
			"c1a2c"s,
			"c1a2d"s
		};

		const std::unordered_set<std::string> hl1_chapter4{ // We've Got Hostiles
			"c1a3"s,
			"c1a3a"s,
			"c1a3b"s,
			"c1a3c"s,
			"c1a3d"s
		};

		const std::unordered_set<std::string> hl1_chapter5{ // Blast Pit
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

		const std::unordered_set<std::string> hl1_chapter6{ // Power Up
			"c2a1"s,
			"c2a1a"s,
			"c2a1b"s
		};

		const std::unordered_set<std::string> hl1_chapter7{ // On A Rail
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

		const std::unordered_set<std::string> hl1_chapter8{ // Apprehension
			"c2a3"s,
			"c2a3a"s,
			"c2a3b"s,
			"c2a3c"s,
			"c2a3d"s,
			"c2a3e"s
		};

		const std::unordered_set<std::string> hl1_chapter9{ // Residue Processing
			"c2a4"s,
			"c2a4a"s,
			"c2a4b"s,
			"c2a4c"s
		};

		const std::unordered_set<std::string> hl1_chapter10{ // Questionable Ethics
			"c2a4d"s,
			"c2a4e"s,
			"c2a4f"s,
			"c2a4g"s
		};

		const std::unordered_set<std::string> hl1_chapter11{ // Surface Tension
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

		const std::unordered_set<std::string> hl1_chapter12{ // Forget About Freeman
			"c3a1"s,
			"c3a1a"s,
			"c3a1b"s
		};

		const std::unordered_set<std::string> hl1_chapter13{ // Lambda Core
			"c3a2"s,
			"c3a2a"s,
			"c3a2b"s,
			"c3a2c"s,
			"c3a2d"s,
			"c3a2e"s,
			"c3a2f"s
		};

		const std::unordered_set<std::string> hl1_chapter14{ // Xen
			"c4a1"s
		};

		const std::unordered_set<std::string> hl1_chapter15{ // Gonarch's Lair
			"c4a2"s,
			"c4a2a"s,
			"c4a2b"s
		};

		const std::unordered_set<std::string> hl1_chapter16{ // Interloper
			"c4a1a"s,
			"c4a1b"s,
			"c4a1c"s,
			"c4a1d"s,
			"c4a1e"s,
			"c4a1f"s
		};

		const std::unordered_set<std::string> hl1_chapter17{ // Nihilanth
			"c4a3"s
		};

		const std::unordered_set<std::string> hl1_chapter18{ // Endgame
			"c5a1"s
		};

		const std::unordered_set<std::string> hl1_chapter19{ // Hazard Course
			"t0a0"s,
			"t0a0a"s,
			"t0a0b"s,
			"t0a0b1"s,
			"t0a0b2"s,
			"t0a0c"s,
			"t0a0d"s
		};

		const std::unordered_set<std::string> op4_chapter1{ // Welcome To Black Mesa
			"of1a1"s,
			"of1a2"s,
			"of1a3"s,
			"of1a4"s,
			"of1a4b"s
		};

		const std::unordered_set<std::string> op4_chapter2{ // We Are Pulling Out
			"of1a5"s,
			"of1a5b"s,
			"of1a6"s
		};

		const std::unordered_set<std::string> op4_chapter3{ // Missing In Action
			"of2a1"s,
			"of2a1b"s,
			"of2a2"s,
			"of2a3"s
		};

		const std::unordered_set<std::string> op4_chapter4{ // Friendly Fire
			"of2a4"s,
			"of2a5"s,
			"of2a6"s
		};

		const std::unordered_set<std::string> op4_chapter5{ // We Are Not Alone
			"of3a1"s,
			"of3a1b"s,
			"of3a2"s
		};

		const std::unordered_set<std::string> op4_chapter6{ // Crush Depth
			"of3a4"s,
			"of3a5"s,
			"of3a6"s
		};

		const std::unordered_set<std::string> op4_chapter7{ // Vicarious Reality
			"of4a1"s,
			"of4a2"s,
			"of4a3"s
		};

		const std::unordered_set<std::string> op4_chapter8{ // Pit Worm's Nest
			"of4a4"s,
			"of4a5"s
		};

		const std::unordered_set<std::string> op4_chapter9{ // Foxtrot Uniform
			"of5a1"s,
			"of5a2"s,
			"of5a3"s,
			"of5a4"s
		};

		const std::unordered_set<std::string> op4_chapter10{ // The Package
			"of6a1"s,
			"of6a2"s,
			"of6a3"s,
			"of6a4"s
		};

		const std::unordered_set<std::string> op4_chapter11{ // Worlds Collide
			"of6a4b"s,
			"of6a5"s
		};

		const std::unordered_set<std::string> op4_chapter12{ // Conclusion
			"of7a0"s
		};

		const std::unordered_set<std::string> op4_chapter13{ // Boot Camp
			"ofboot0"s,
			"ofboot1"s,
			"ofboot2"s,
			"ofboot3"s,
			"ofboot4"s
		};

		const std::unordered_set<std::string> bs_chapter1{ // Insecurity
			"ba_security1"s,
			"ba_security2"s,
			"ba_maint"s,
			"ba_elevator"s
		};

		const std::unordered_set<std::string> bs_chapter2{ // Duty Calls
			"ba_canal1"s,
			"ba_canal1b"s,
			"ba_canal2"s,
			"ba_canal3"s
		};

		const std::unordered_set<std::string> bs_chapter3{ // Captive Freight
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

		const std::unordered_set<std::string> bs_chapter4{ // Focal Point
			"ba_xen1"s,
			"ba_xen2"s,
			"ba_xen3"s,
			"ba_xen4"s,
			"ba_xen5"s,
			"ba_xen6"s
		};

		const std::unordered_set<std::string> bs_chapter5{ // Power Struggle
			"ba_power1"s,
			"ba_power2"s
		};

		const std::unordered_set<std::string> bs_chapter6{ // Captive Freight & A Leap of Faith
			"ba_teleport2"s
		};

		const std::unordered_set<std::string> bs_chapter7{ // Outro
			"ba_outro"s
		};

		const std::unordered_set<std::string> bs_chapter8{ // Hazard Course
			"ba_hazard1"s,
			"ba_hazard2"s,
			"ba_hazard3"s,
			"ba_hazard4"s,
			"ba_hazard5"s,
			"ba_hazard6"s
		};

		const std::unordered_set<std::string> gmc_chapter1{ // City
			"city2a"s,
			"city2b"s,
			"city3a"s,
			"city3b"s
		};

		const std::unordered_set<std::string> gmc_chapter2{ // Mayan
			"mayan0a"s,
			"mayan0b"s,
			"mayan1"s,
			"mayan3a"s,
			"mayan4"s,
			"mayan6"s,
			"mayan8"s
		};

		const std::unordered_set<std::string> gmc_chapter3{ // Cinematic
			"cinematic1"s,
			"cinematic2"s
		};

		const std::unordered_set<std::string> gmc_chapter4{ // Rust
			"rust1"s,
			"rust2a"s,
			"rust2b"s,
			"rust3a"s,
			"rust4a"s,
			"rust4b"s,
			"rust4c"s,
			"rust5a"s,
			"rust6a"s,
			"rust6b"s,
			"rust6c"s,
			"rust6d"s,
			"rust7a"s,
			"rust7b"s,
			"rust7c"s,
			"rust7d"s,
			"rust7e"s,
			"rust8a"s,
			"rust9a"s
		};

		const std::unordered_set<std::string> gmc_chapter5{ // Cinematic
			"cinematic3"s,
			"cinematic4"s
		};

		const std::unordered_set<std::string> gmc_chapter6{ // West
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

		const std::unordered_set<std::string> gmc_chapter7{ // Rebar
			"rebar0a"s,
			"rebar0b"s,
			"rebar2a"s,
			"rebar2b"s,
			"rebar2c"s,
			"rebar2d"s,
			"rebar2e"s,
			"rebar2f"s,
			"rebar2g"s,
			"rebar2h"s,
			"rebar2i"s,
			"rebar2j"s,
			"rebar2k"s,
			"rebar2l"s,
			"rebar3b"s,
			"rebar3d"s,
			"rebar3e"s
		};

		const std::unordered_set<std::string> gmc_chapter8{ // End
			"end1"s,
			"end2"s
		};

		const std::unordered_set<std::string> czds_chapter1{ // Recoil
			"cz_recoil"s,
			"cz_recoil2"s
		};

		const std::unordered_set<std::string> czds_chapter2{ // Lost Cause
			"cz_lostcause"s,
			"cz_lostcause2"s
		};

		const std::unordered_set<std::string> czds_chapter3{ // Secret War
			"cz_silo01"s,
			"cz_silo02"s,
			"cz_silo03"s,
			"cz_silo04"s,
			"cz_silo05"s
		};

		const std::unordered_set<std::string> czds_chapter4{ // Building Recon
			"cz_brecon01"s,
			"cz_brecon02"s,
			"cz_brecon03"s,
			"cz_brecon04"s,
			"cz_brecon05"s,
			"cz_brecon06"s
		};

		const std::unordered_set<std::string> czds_chapter5{ // DrugLab
			"cz_druglab1"s,
			"cz_druglab2"s,
			"cz_druglab3"s,
			"cz_druglab4"s
		};

		const std::unordered_set<std::string> czds_chapter6{ // Motorcade Assault
			"cz_motor1"s,
			"cz_motor2"s,
			"cz_motor3"s
		};

		const std::unordered_set<std::string> czds_chapter7{ // Thin Ice
			"cz_thinice01"s,
			"cz_thinice02"s,
			"cz_thinice03"s
		};

		const std::unordered_set<std::string> czds_chapter8{ // Downed Pilot
			"cz_downed1"s,
			"cz_downed2"s,
			"cz_downed3"s,
			"cz_downed4"s
		};

		const std::unordered_set<std::string> czds_chapter9{ // Hankagai
			"cz_hankagai1"s,
			"cz_hankagai2"s,
			"cz_hankagai3"s,
			"cz_hankagai4"s,
			"cz_hankagai5"s
		};

		const std::unordered_set<std::string> czds_chapter10{ // Turn of the Crank
			"cz_turncrank"s,
			"cz_turncrank2"s,
			"cz_turncrank3"s
		};

		const std::unordered_set<std::string> czds_chapter11{ // Alamo
			"cz_alamo"s,
			"cz_alamo2"s
		};

		const std::unordered_set<std::string> czds_chapter12{ // Rise Hard
			"cz_hr01"s,
			"cz_hr02"s,
			"cz_hr02b"s,
			"cz_hr03"s,
			"cz_hr04"s,
			"cz_hr05"s,
			"cz_hr06"s,
			"cz_hr07"s
		};

		const std::unordered_set<std::string> czds_chapter13{ // Fastline
			"cz_fastline1"s,
			"cz_fastline2"s,
			"cz_fastline3"s,
			"cz_fastline4"s
		};

		const std::unordered_set<std::string> czds_chapter14{ // Miami Heat
			"cz_miami1"s,
			"cz_miami2"s
		};

		const std::unordered_set<std::string> czds_chapter15{ // Pipe Dream
			"cz_pipedream1"s,
			"cz_pipedream2"s,
			"cz_pipedream3"s
		};

		const std::unordered_set<std::string> czds_chapter16{ // Run
			"cz_run1"s,
			"cz_run2"s,
			"cz_run3"s
		};

		const std::unordered_set<std::string> czds_chapter17{ // Sandstorm
			"cz_sandstorm"s,
			"cz_sandstorm2"s,
			"cz_sandstorm3"s,
			"cz_sandstorm4"s
		};

		const std::unordered_set<std::string> czds_chapter18{ // Truth in Chaos
			"cz_truth1"s,
			"cz_truth2"s,
			"cz_truth3"s,
			"cz_truth4"s
		};

		const std::unordered_set<std::string> czds_chapter19{ // CT Training
			"cz_train01"s,
			"cz_train02"s,
			"cz_train03"s
		};

		const std::unordered_set<std::string> th_chapter1{ // They Hunger Episode 1
			"they2"s,
			"they3"s,
			"they4"s,
			"they5"s,
			"they6"s,
			"they7"s,
			"they8"s,
			"they9"s,
			"they10"s,
			"they11"s,
			"they12"s,
			"they13"s,
			"they14"s,
			"they15"s
		};

		const std::unordered_set<std::string> th_chapter2{ // They Hunger Episode 2
			"they16"s,
			"they17"s,
			"they18"s,
			"they19"s,
			"they20"s,
			"they21"s,
			"they22"s,
			"they23"s,
			"they24"s,
			"they25"s,
			"they26"s,
			"they27"s,
			"they28"s,
			"they29"s
		};

		const std::unordered_set<std::string> th_chapter3{ // They Hunger Episode 3
			"they30"s,
			"they30a"s,
			"they31"s,
			"they32"s,
			"they33"s,
			"they34"s,
			"they35"s,
			"they36"s,
			"they37"s,
			"they38"s,
			"they39"s,
			"they40"s,
			"they41"s,
			"they42"s,
			"they43"s,
			"they44"s,
			"they45"s,
			"they46"s,
			"they47"s,
			"they48"s,
			"they49"s,
			"they50"s,
			"they51"s,
			"they52"s,
			"they53"s,
			"they54"s,
			"they55"s,
			"they56"s
		};

		const std::unordered_set<std::string> wanted_chapter1{ // Redrock Creek
			"want1"s
		};

		const std::unordered_set<std::string> wanted_chapter2{ // The Journey
			"want2"s,
			"want3"s,
			"want4"s,
			"want5"s,
			"want6"s,
			"want7"s
		};

		const std::unordered_set<std::string> wanted_chapter3{ // Breypass
			"want8"s,
			"want9"s,
			"want10"s
		};

		const std::unordered_set<std::string> wanted_chapter4{ // Lokita Falls
			"want11"s,
			"want12"s,
			"want13"s,
			"want14"s,
			"want15"s
		};

		const std::unordered_set<std::string> wanted_chapter5{ // Serino
			"want16"s,
			"want17"s,
			"want18"s
		};

		const std::unordered_set<std::string> wanted_chapter6{ // The Border Hills
			"want19"s,
			"want20"s,
			"want21"s,
			"want22"s,
			"want23"s,
			"want24"s,
			"want24a"s,
			"want25"s,
			"want25a"s,
			"want25b"s,
			"want25c"s
		};

		const std::unordered_set<std::string> wanted_chapter7{ // Return to Redrock
			"want26"s,
			"want27"s,
			"want28"s,
			"want29"s,
			"want30"s,
			"want31"s,
			"want32"s,
			"want33"s,
			"want34"s
		};

		const std::unordered_set<std::string> wanted_chapter8{ // Showdown
			"want35"s,
			"want36"s,
			"want37"s
		};

		const std::unordered_set<std::string> echoes_chapter1{ // Foundation
			"echoes01"s,
			"echoes01a"s,
			"echoes02"s,
			"echoes03"s
		};

		const std::unordered_set<std::string> echoes_chapter2{ // Collapse
			"echoes04"s,
			"echoes05"s
		};

		const std::unordered_set<std::string> echoes_chapter3{ // Ruin
			"echoes06"s
			"echoes07"s,
			"echoes08"s,
			"echoes09"s
		};

		const std::unordered_set<std::string> echoes_chapter4{ // Surge
			"echoes09a"s,
			"echoes09b"s,
			"echoes10"s,
			"echoes11"s,
			"echoes12"s
		};

		const std::unordered_set<std::string> echoes_chapter5{ // Liberation
			"echoes13"s,
			"echoes14"s,
			"echoes14b"s,
			"echoes15"s,
			"echoes16"s
		};

		const std::unordered_set<std::string> echoes_chapter6{ // Tabula Rasa
			"echoes17"s,
			"echoes18"s,
			"echoes19"s
		};

		const std::unordered_set<std::string> echoes_chapter7{ // Ashes
			"echoes20"s,
			"echoes21"s,
			"echoes22"s
		};

		const std::unordered_set<std::string> echoes_chapter8{ // Dust
			"echoes23"s
		};

		const std::unordered_set<std::string> echoes_chapter9{ // Echoes
			"echoes24"s
		};

		const std::unordered_set<std::string> caged_chapter1{ // Scheduled Termination
			"caged_1"s
		};

		const std::unordered_set<std::string> caged_chapter2{ // Turret Unwellness
			"caged_1b"s,
			"caged_1c"s
		};

		const std::unordered_set<std::string> caged_chapter3{ // The Yard
			"caged_2"s
		};

		const std::unordered_set<std::string> caged_chapter4{ // Jet-Boat Escape
			"caged_3"s
		};

		const std::unordered_set<std::string> poke646_chapter1{ // Audion Industries
			"po_aud01"s,
			"po_aud02"s,
			"po_aud03"s,
			"po_aud04"s
		};

		const std::unordered_set<std::string> poke646_chapter2{ // The Sewers
			"po_sew01"s,
			"po_sew02"s,
			"po_sew03"s,
			"po_sew04"s,
			"po_sew05"s
		};

		const std::unordered_set<std::string> poke646_chapter3{ // Nation City Library
			"po_lib01"s,
			"po_lib02"s,
			"po_lib03"s,
			"po_lib04"s,
			"po_lib05"s,
			"po_lib06"s,
			"po_lib07"s
		};

		const std::unordered_set<std::string> poke646_chapter4{ // Eastend
			"po_eas01"s,
			"po_eas02"s,
			"po_eas03"s,
			"po_eas04"s,
			"po_eas05"s,
			"po_eas06"s
		};

		const std::unordered_set<std::string> poke646_chapter5{ // Xen
			"po_xen01"s
		};
}
