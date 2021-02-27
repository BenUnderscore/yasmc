
//Internal includes
#include "GameWindow.hpp"

//Standard includes
#include <iostream>

namespace yam
{
	int main()
	{
		GameWindowCreationParams windowCreationParams;
		windowCreationParams.width = 200;
		windowCreationParams.height = 200;
		GameWindow window(windowCreationParams);

		while(!window.isClosed())
		{
			window.update();
		}

		return 0;
	}
}

int main()
{
	return yam::main();
}