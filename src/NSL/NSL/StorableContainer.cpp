// © 2019 NIREX ALL RIGHTS RESERVED

#include "StorableContainer.h"
#include "FileUtils.h"
#include "StrUtils.h"

namespace NSL
{
	std::set<IStorable*> StorableContainer::globalRegistry = {};

	void StorableContainer::Register(IStorable* IN storableObject)
	{
		globalRegistry.emplace(storableObject);
	}

	void StorableContainer::Unregister(IStorable* IN storableObject)
	{
		globalRegistry.erase(storableObject);
	}

	void StorableContainer::SaveAll(std::map<IStorable*, std::string>& OUT emptyOutMap)
	{
		for (const auto& p : globalRegistry)
		{
			p->Store(emptyOutMap[p]);
		}
	}

	void StorableContainer::LoadAll(const std::map<IStorable*, std::string>& OUT emptyOutMap)
	{
		for (const auto& p : globalRegistry)
		{
			p->Retrieve(emptyOutMap.at(p));
		}
	}

	void StorableContainer::ToFile(const std::string& path, const std::map<IStorable*, std::string>&IN map)
	{
		std::vector<std::string> tempVec;
		for (const auto& p : map)
		{
			tempVec.push_back(p.first->UniqueID() + ":" + p.second);
		}
		FileUtils::WriteAllLines(path, tempVec);

	}

	void StorableContainer::FromFile(const std::string& path, std::map<IStorable*, std::string>& OUT map)
	{
		std::vector<std::string> tempVec = FileUtils::ReadAllLines(path);
		for (const auto& str : tempVec)
		{
			std::vector<std::string> outVec = StrUtils::Split(str, ":");

			std::string id = outVec[0];
			std::string data = outVec[1];

			for (const auto& p : globalRegistry)
			{
				if (p->UniqueID() == id)
				{
					map.emplace(p, data);
				}
			}
		}
	}
}
