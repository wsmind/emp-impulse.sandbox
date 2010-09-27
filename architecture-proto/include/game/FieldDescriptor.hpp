#ifndef __FIELDDESCRIPTOR_HPP__
#define __FIELDDESCRIPTOR_HPP__

#include <string>
#include <game/Variant.hpp>

namespace game {

class FieldDescriptor
{
	public:
		void *location;
		Variant::Type type;
		Variant defaultValue;
};

} // game namespace

#endif // __FIELDDESCRIPTOR_HPP__

