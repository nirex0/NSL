// © 2019 NIREX ALL RIGHTS RESERVED

#include "test.h"
#include <iostream>

#include <NSL\nwin.h>
#include <NSL\IStorable.h>
#include <NSL\StorableContainer.h>

int main()
{
	test x;
	x.hiddenData = "ABC";
	
	std::map<NSL::IStorable*, std::string> myMap;
	NSL::StorableContainer::SaveAll(myMap);
	NSL::StorableContainer::ToFile("p.txt", myMap);

	std::map<NSL::IStorable*, std::string> myMap;
	NSL::StorableContainer::FromFile("p.txt", myMap);
	NSL::StorableContainer::LoadAll(myMap);
	
	std::cout << x.hiddenData;
	std::getchar();
	return 0;
}