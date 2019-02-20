// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _N_STORABLE_CONTAINER_H_
#define _N_STORABLE_CONTAINER_H_

#include "systemdefines.h"
#include "IStorable.h"

#include <set>
#include <map>
#include <string>

namespace NSL
{
	UTILITY_CLASS class NAPI StorableContainer final
	{
	public:
		UTILITY void Register(IStorable* IN storableObject);
		UTILITY void Unregister(IStorable* IN storableObject);

		UTILITY void SaveAll(std::map<IStorable*, std::string>& OUT emptyOutMap);
		UTILITY void LoadAll(const std::map<IStorable*, std::string>& OUT emptyOutMap);

		UTILITY void ToFile(const std::string& path, const std::map<IStorable*, std::string>& IN map);
		UTILITY void FromFile(const std::string& path, std::map<IStorable*, std::string>& OUT map);

	private:
		static std::set<IStorable*> globalRegistry;
	};
}

#endif // !_N_STORABLE_CONTAINER_H_