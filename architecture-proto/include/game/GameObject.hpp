#ifndef __GAMEOBJECT_HPP__
#define __GAMEOBJECT_HPP__

#include <string>

namespace game {

class World;
class Event;

/// interface
class GameObject
{
	public:
		virtual ~GameObject() {}
		
		virtual void declareProperties() {}
		virtual void update(float elapsedTime) {}
		virtual void handleEvent(std::string sender, Event *event) {}
};

} // game namespace

#endif // __GAMEOBjECT_HPP__

