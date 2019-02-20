// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _N_TEST_H_
#define _N_TEST_H_

#include <NSL\nwin.h>
#include <NSL\IStorable.h>

class test : public NSL::IStorable
{
public:
	test(const std::string& uid);
	~test(void);

	std::string GetHiddenData(void) const;
	void SetHiddenData(const std::string& val);

protected:
	virtual HRESULT Store(std::string& OUT str) override;
	virtual HRESULT Retrieve(const std::string& IN str) override;
	virtual std::string UniqueID(void) override;

private:
	std::string hiddenData;
	std::string unique_id;
};

#endif // !_N_TEST_H_
