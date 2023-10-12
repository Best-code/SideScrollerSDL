#include "Mario.hpp"
#include "GameObject.hpp"

int main()
{
	Engine* mario = new Mario("Colins Epic Side Scroller");
	if(!mario->run())
	{
		std::cout << "Womp Womp";
		return 0;
	}
	
	return 1;
}
