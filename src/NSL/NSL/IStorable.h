// � 2019 NIREX ALL RIGHTS RESERVED

#ifndef _I_STORABLE_H_
#define _I_STORABLE_H_

#include "systemdefines.h"
#include <string>

typedef long HRESULT;

//-->DOC_CLASS
// Main Interface for all the classes that need to have saving and loading functionality.
class NAPI IStorable
{
public:
	//-->DOC_FUNC
	// Store the data within the class in a string
	// OUT str: put the calculated string inside the str argument
	// returns: whether or not the operation was successful
	virtual HRESULT Store(const std::string& OUT str) PURE;

	//-->DOC_FUNC
	// Retrieves the data from the given string and loads it into the class
	// IN str: put the string inside the object's members
	// returns: whether or not the operation was successful
	virtual HRESULT Retrieve(const std::string& IN str) PURE;
};

#endif // !_I_STORABLE_H_
