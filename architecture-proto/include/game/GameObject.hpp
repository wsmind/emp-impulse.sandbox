#ifndef __GAMEOBJECT_HPP__
#define __GAMEOBJECT_HPP__

#include <string>

namespace game {

class World;

/// interface
class GameObject
{
	public:
		virtual ~GameObject() {}
		
		virtual void update(float elapsedTime) {}
		virtual void executeAction(std::string action) {}
};

} // game namespace

#endif // __GAMEOBjECT_HPP__
