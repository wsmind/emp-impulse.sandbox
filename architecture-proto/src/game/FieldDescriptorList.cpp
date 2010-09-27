#include <game/FieldDescriptorList.hpp>
#include <game/Variant.hpp>

namespace game {

void FieldDescriptorList::empty()
{
	this->descriptors.empty();
}

const FieldDescriptorList::FieldDescriptorMap *FieldDescriptorList::getDescriptors()
{
	return &this->descriptors;
}

void FieldDescriptorList::declareBoolean(std::string name, bool *location, bool defaultValue)
{
	FieldDescriptor desc;
	desc.location = location;
	desc.type = Variant::BOOLEAN;
	desc.defaultValue = Variant::fromBoolean(defaultValue);
	
	this->descriptors[name] = desc;
}

void FieldDescriptorList::declareNumber(std::string name, float *location, float defaultValue)
{
	FieldDescriptor desc;
	desc.location = location;
	desc.type = Variant::NUMBER;
	desc.defaultValue = Variant::fromNumber(defaultValue);
	
	this->descriptors[name] = desc;
}

void FieldDescriptorList::declareString(std::string name, std::string *location, std::string defaultValue)
{
	FieldDescriptor desc;
	desc.location = location;
	desc.type = Variant::STRING;
	desc.defaultValue = Variant::fromString(defaultValue);
	
	this->descriptors[name] = desc;
}

} // game namespace

