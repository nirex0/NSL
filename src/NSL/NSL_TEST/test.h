// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _N_TEST_H_
#define _N_TEST_H_

#include <NSL\nwin.h>
#include <NSL\IStorable.h>

class test : public NSL::IStorable
{
public:
	test(void);
	~test(void);

	virtual HRESULT Store(std::string& OUT str) override;
	virtual HRESULT Retrieve(const std::string& IN str) override;
	virtual std::string UniqueID(void) override;

public:
	std::string hiddenData;
};

#endif // !_N_TEST_H_
