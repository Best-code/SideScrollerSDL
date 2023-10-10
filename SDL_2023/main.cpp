#include "Engine.hpp"

int main()
{
	Engine mario("Colins Epic Side Scroller");
	if(!mario.run())
	{
		std::cout << "Womp Womp";
	}
}
