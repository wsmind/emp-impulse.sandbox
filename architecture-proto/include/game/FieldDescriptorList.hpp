#ifndef __FIELDDESCRIPTORLIST_HPP__
#define __FIELDDESCRIPTORLIST_HPP__

#include <string>
#include <map>
#include <game/FieldDescriptor.hpp>

namespace game {

class FieldDescriptorList
{
	public:
		// empty the list
		void empty();
		
		// read descriptors
		typedef std::map<std::string, FieldDescriptor> FieldDescriptorMap;
		const FieldDescriptorMap *getDescriptors();
		
		// field declaration
		void declareBoolean(std::string name, bool *location, bool defaultValue);
		void declareNumber(std::string name, float *location, float defaultValue);
		void declareString(std::string name, std::string *location, std::string defaultValue);
	
	private:
		FieldDescriptorMap descriptors;
};

} // game namespace

#endif // __FIELDDESCRIPTORLIST_HPP__

