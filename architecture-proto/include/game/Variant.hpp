#ifndef __VARIANT_HPP__
#define __VARIANT_HPP__

#include <string>

namespace game {

/**
 * \class Variant
 * 
 * A type wrapper, allowing a single variable to store different data types.
 */
class Variant
{
	public:
		/**
		 * \enum Type
		 * 
		 * Possible types for a variant object
		 */
		enum Type
		{
			NIL,
			BOOLEAN,
			NUMBER,
			STRING
		};
		
		/**
		 * \brief Default constructor
		 * 
		 * Stored value is NIL.
		 */
		Variant();
		
		/**
		 * \brief Copy constructor
		 * 
		 * Type and value are duplicated
		 */
		Variant(const Variant &variant);
		
		/**
		 * \brief Destructor
		 */
		~Variant();
		
		/**
		 * \brief Build a boolean variant
		 * \param value the variant value
		 */
		static Variant fromBoolean(bool value);
		
		/**
		 * \brief Build a number variant
		 * \param value the variant value
		 */
		static Variant fromNumber(double value);
		
		/**
		 * \brief Build a string variant
		 * \param value the variant value
		 */
		static Variant fromString(std::string value);
		
		/**
		 * \brief Read current value type
		 */
		Type getType();
		
		/**
		 * \brief Set the type to NIL (discards any previously stored value)
		 */
		void setNil();
		
		/**
		 * \brief Set the type to BOOLEAN and store boolean value
		 * \param booleanValue the value to store
		 */
		void setBoolean(bool booleanValue);
		
		bool toBoolean() const;
		
		void setNumber(double numberValue);
		
		double toNumber() const;
		
		void setString(std::string stringValue);
		
		std::string toString() const;
		
		Variant& operator =(const Variant &variant);
		
	private:
		/// value type
		Type type;
		
		/// actual value (used when the type is not NIL)
		union
		{
			bool booleanValue;
			double numberValue;
			std::string *stringValue;
		};
};

} // game namespace

#endif // __VARIANT_HPP__
