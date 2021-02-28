#pragma once

//Internal includes
#include "GameWindow.hpp"

//System includes
#include <dxgi.h>
#include <d3d11.h>

namespace yam
{
	struct GameRenderer
	{
		~GameRenderer();
		GameRenderer(const GameRenderer& other) = delete;
		GameRenderer& operator=(const GameRenderer& other) = delete;

		IDXGISwapChain* swapChain;
		ID3D11Device* device;
		ID3D11DeviceContext* deviceContext;
	};

	struct GameRendererInitParams
	{
		GameWindow& window;
	};

	void initGameRenderer();
}