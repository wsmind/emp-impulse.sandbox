#ifndef __WORLD_HPP__
#define __WORLD_HPP__

#include <string>
#include <map>
#include <lua.hpp>

namespace scene { class Scene; }

namespace game {

class GameObject;

class World
{
	public:
		World();
		~World();
		
		void run();
		
		void loadMap(); // fake
		
		scene::Scene *getScene();
		
		// gameplay api (w/ script bindings too)
		void executeAction(std::string target, std::string action);
		void sendEvent(std::string sender, std::string event);
	
	private:
		scene::Scene *gameScene;
		bool running;
		
		// one map: objects and one script
		typedef std::map<std::string, GameObject *> GameObjectMap;
		GameObjectMap objects;
		lua_State *luaState;
};

} // game namespace

#endif // __WORLD_HPP__
