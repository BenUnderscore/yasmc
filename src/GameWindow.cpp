//Implementation include
#include "GameWindow.hpp"

//Include Windows
#include "IncludeWindows.hpp"

//Standard includes
#include <string>
#include <stdexcept>

namespace yam
{

	static LRESULT wndProc(
		HWND window,
		UINT message,
		WPARAM wParam,
		LPARAM lParam
	)
	{
		GameWindow* instance = nullptr;

		if(message == WM_NCCREATE)
		{
			CREATESTRUCTW* cs = reinterpret_cast<CREATESTRUCTW*>(lParam);
			instance = reinterpret_cast<GameWindow*>(cs->lpCreateParams);
			SetWindowLongW(window, GWLP_USERDATA, reinterpret_cast<LONG>(cs->lpCreateParams));
		}
		else
		{
			instance = reinterpret_cast<GameWindow*>(GetWindowLongW(window, GWLP_USERDATA));
		}

		if(instance != nullptr)
		{
			return instance->handleMessage(window, message, wParam, lParam);
		}

		return DefWindowProc(window, message, wParam, lParam);
	}

	GameWindow::GameWindow(const GameWindowCreationParams& params)
		: hwnd(NULL), closed(false)
	{
		HINSTANCE hInstance = GetModuleHandle(NULL);

		std::wstring windowClassName = L"YAMC Window";

		WNDCLASS windowClass = {};
		windowClass.lpfnWndProc = &wndProc;
		windowClass.lpszClassName = windowClassName.c_str();
		windowClass.hInstance = hInstance;

		RegisterClassW(&windowClass);

		HWND hwnd = CreateWindowExW(
			0,
			windowClassName.c_str(),
			L"Yet Another Minecraft Clone",
			WS_OVERLAPPED | WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
			CW_USEDEFAULT, CW_USEDEFAULT,
			params.width,
			params.height,
			NULL,
			NULL,
			hInstance,
			this);

		if(hwnd == NULL)
		{
			throw std::runtime_error("Failed to create window!");
		}

		ShowWindow(hwnd, SW_SHOW);

		this->hwnd = hwnd;
	}

	void GameWindow::update()
	{
		MSG msg;
		BOOL success;
		while(success = PeekMessageW(&msg, this->hwnd, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}
	}

	bool GameWindow::isClosed()
	{
		return this->closed;
	}

	LRESULT GameWindow::handleMessage(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
	{
		if(message == WM_CLOSE)
		{
			DestroyWindow(window);
			this->closed = true;
			return true;
		}
		else
		{
			return DefWindowProcW(window, message, wParam, lParam);
		}
	}
}