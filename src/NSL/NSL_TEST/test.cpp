// © 2019 NIREX ALL RIGHTS RESERVED

#include "test.h"

#include <NSL\StorableContainer.h>

test::test(const std::string& uid)
	: unique_id(uid)
{
	NSL::StorableContainer::Register(this);
}

test::~test(void)
{
	NSL::StorableContainer::Unregister(this);
}

std::string test::GetHiddenData(void) const
{
	return hiddenData;
}

void test::SetHiddenData(const std::string& val)
{
	hiddenData = val;
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
	return unique_id;
}
