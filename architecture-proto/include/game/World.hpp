#ifndef __WORLD_HPP__
#define __WORLD_HPP__

#include <string>
#include <map>

namespace scene { class Scene; }

namespace game {

class GameObject;
class Event;

class World
{
	public:
		World();
		~World();
		
		void run();
		
		void loadMap(); // fake
		
		scene::Scene *getScene();
		
		// world queries
		/*typedef std::set<std::string> GameObjectSet;
		GameObjectSet queryObjectsNear(float x, float y, float radius);*/
		
		void sendEvent(std::string sender, std::string target, Event *event);
	
	private:
		scene::Scene *gameScene;
		bool running;
		
		// game objects
		typedef std::map<std::string, GameObject *> GameObjectMap;
		GameObjectMap objects;
};

} // game namespace

#endif // __WORLD_HPP__

