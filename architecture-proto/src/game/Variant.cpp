#include <game/Variant.hpp>

#include <cstdlib>
#include <sstream>

namespace game {

Variant::Variant()
{
	this->type = NIL;
}

Variant::Variant(const Variant &variant) 
{
	this->type = NIL;
	switch (variant.type)
	{
		case NIL:
			break;
			
		case BOOLEAN:
			this->setBoolean(variant.booleanValue);
			break;
			
		case NUMBER:
			this->setNumber(variant.numberValue);
			break;
			
		case STRING:
			this->setString(*variant.stringValue);
			break;
	}
}

Variant::~Variant()
{
	if (this->type == STRING)
		delete this->stringValue;
}

Variant Variant::fromBoolean(bool value)
{
	Variant variant;
	variant.setBoolean(value);
	return variant;
}

Variant Variant::fromNumber(float value)
{
	Variant variant;
	variant.setNumber(value);
	return variant;
}

Variant Variant::fromString(std::string value)
{
	Variant variant;
	variant.setString(value);
	return variant;
}

Variant::Type Variant::getType()
{
	return this->type;
}

void Variant::setNil()
{
	if (this->type == STRING) {
		delete this->stringValue;
	}
	this->type = NIL;
}

void Variant::setBoolean(bool booleanValue) {
	if (this->type == STRING) {
		delete this->stringValue;
	}
	this->type = BOOLEAN;
	this->booleanValue = booleanValue;
}

bool Variant::toBoolean() const
{
	switch (this->type)
	{
		case Variant::NIL: return false;
		case Variant::BOOLEAN: return this->booleanValue;
		case Variant::NUMBER: return (this->numberValue != 0.0);
		case Variant::STRING: return !(this->stringValue->empty() || (*this->stringValue == "false") || (*this->stringValue == "0"));
	}
	
	return false;
}

void Variant::setNumber(float numberValue) {
	if (this->type == STRING) {
		delete this->stringValue;
	}
	this->type = NUMBER;
	this->numberValue = numberValue;
}

float Variant::toNumber() const
{
	switch (this->type)
	{
		case Variant::NIL: return 0.0;
		case Variant::BOOLEAN: return (float)this->booleanValue;
		case Variant::NUMBER: return this->numberValue;
		case Variant::STRING: return (float)atof(this->stringValue->c_str());
	}
	
	return 0.0;
}

void Variant::setString(std::string stringValue) {
	if (this->type == STRING) {
		delete this->stringValue;
	}
	this->type = STRING;
	this->stringValue = new std::string(stringValue);
}

std::string Variant::toString() const
{
	std::stringstream ss;
	
	switch (this->type)
	{
		case Variant::NIL: ss << "nil"; break;
		case Variant::BOOLEAN: ss << (this->booleanValue ? "true" : "false"); break;
		case Variant::NUMBER: ss << this->numberValue; break;
		case Variant::STRING: ss << *this->stringValue; break;
	}
	
	return ss.str();
}

Variant & Variant::operator =(const Variant & variant) {
	this->type = NIL;
	switch (variant.type) {
		case NIL:
			break;
	
		case BOOLEAN:
			this->setBoolean(variant.booleanValue);
			break;
	
		case NUMBER:
			this->setNumber(variant.numberValue);
			break;
	
		case STRING:
			this->setString(*variant.stringValue);
			break;
	}
	return *this;
}

} // game namespace

