#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include <string>
#include <map>
#include <game/Variant.hpp>

namespace game {

struct Event
{
	public:
		Event(std::string name);
		
		// event type/name
		std::string name;
		
		// payload
		typedef std::map<std::string, Variant> VariantMap;
		VariantMap data;
};

} // game namespace

#endif // __EVENT_HPP__

