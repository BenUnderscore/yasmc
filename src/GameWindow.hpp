#pragma once

//Internal includes
#include "Types.hpp"

//Include Windows
#include "IncludeWindows.hpp"

namespace yam
{
	struct GameWindowCreationParams
	{
		uint32 width;
		uint32 height;
	};

	//Warning: This class may not be used from more than one thread
	//Manages everything about the main window
	class GameWindow
	{
	public:

		GameWindow(const GameWindowCreationParams& params);

		void update();

		bool isClosed();

		//Accepts messages from WndProc
		LRESULT handleMessage(HWND window, UINT message, WPARAM wParam, LPARAM lParam);

	private:

		HWND hwnd;
		bool closed;
	};

}