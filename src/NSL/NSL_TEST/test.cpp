// © 2019 NIREX ALL RIGHTS RESERVED

#include "test.h"

#include <NSL\StorableContainer.h>

test::test(void)
{
	NSL::StorableContainer::Register(this);
}

test::~test(void)
{
	NSL::StorableContainer::Unregister(this);
}

HRESULT test::Store(std::string& OUT str)
{
	str = hiddenData;
	return S_OK;
}

HRESULT test::Retrieve(const std::string& IN str)
{
	hiddenData = str;
	return S_OK;
}

std::string test::UniqueID(void)
{
	return "A";
}
