// © 2019 NIREX ALL RIGHTS RESERVED

#include "test.h"
#include <iostream>

#include <NSL\nwin.h>
#include <NSL\IStorable.h>
#include <NSL\StorableContainer.h>

void Save(void);
void Load(void);

auto main(int argc, char** argv) -> int
{
	Load();
	std::getchar();
	return false;
}

void Save(void)
{
	test x0("1");
	x0.SetHiddenData("10");
	
	test x1("2");
	x1.SetHiddenData("15");
	
	test x2("3");
	x2.SetHiddenData("20");
	
	test x3("4");
	x3.SetHiddenData("25");

	NSL::StorableContainer::SaveToFile("1.txt");
}

void Load(void)
{
	test x0("1");

	test x1("2");

	test x2("3");

	test x3("4");

	NSL::StorableContainer::LoadFromFile("1.txt");

	std::cout << x0.GetHiddenData() << std::endl;
	std::getchar();

	std::cout << x1.GetHiddenData() << std::endl;
	std::getchar();

	std::cout << x2.GetHiddenData() << std::endl;
	std::getchar();

	std::cout << x3.GetHiddenData() << std::endl;
	std::getchar();

}