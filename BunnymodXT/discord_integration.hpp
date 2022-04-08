#pragma once

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
}
