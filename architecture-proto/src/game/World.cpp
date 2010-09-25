#include <game/World.hpp>
#include <game/GameObject.hpp>
#include <game/Element.hpp>
#include <scene/Scene.hpp>
#include <SFML/System.hpp> // shouldn't be there

using namespace scene;

namespace game {

World::World()
{
	this->gameScene = new Scene;
	this->running = true;
	
	this->luaState = lua_open();
	luaL_openlibs(this->luaState);
}

World::~World()
{
	lua_close(this->luaState);
	delete this->gameScene;
}

void World::run()
{
	sf::Clock clock;
	
	while (this->running)
	{
		float elapsedTime = clock.GetElapsedTime();
		clock.Reset();
		
		GameObjectMap::iterator i;
		for (i = this->objects.begin(); i != this->objects.end(); i++)
		{
			std::string name = i->first;
			GameObject *object = i->second;
			object->update(elapsedTime);
		}
		
		this->gameScene->redraw();
		//this->running = false;
	}
}

void World::loadMap()
{
	// load map file
	luaL_dofile(this->luaState, "level.lua");
	
	// create element game object
	Element *element = new Element(this, "water");
	this->objects["water"] = element;
}

scene::Scene *World::getScene()
{
	return this->gameScene;
}

void World::executeAction(std::string target, std::string action)
{
	GameObjectMap::iterator i = this->objects.find(target);
	if (i != this->objects.end())
	{
		GameObject *targetObject = i->second;
		targetObject->executeAction(action);
	}
}

void World::sendEvent(std::string sender, std::string event)
{
	std::string luaFunctionName = sender + "_" + event;
	lua_getglobal(this->luaState, luaFunctionName.c_str());
	lua_call(this->luaState, 0, 0);
}

} // game namespace
