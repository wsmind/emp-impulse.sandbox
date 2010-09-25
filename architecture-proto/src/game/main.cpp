// entry point

#include <game/World.hpp>

using namespace game;

int main()
{
	World world;
	world.loadMap();
	world.run();
	
	return 0;
}
