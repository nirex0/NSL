// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _N_FILE_UTILS_H_
#define _N_FILE_UTILS_H_

#include "systemdefines.h"
#include <string>
#include <vector>
#include <fstream>

namespace NSL
{
	//-->DOC_CLASS
	// File IO Utility class
	class FileUtils final
	{
	public:
		UTILITY std::string ReadAllText(const std::string& file);
		UTILITY int WriteAllText(const std::string& file, const std::string& str);

		UTILITY std::vector<std::string> ReadAllLines(const std::string& file);
		UTILITY int WriteAllLines(const std::string& file, std::vector<std::string> vecstr);

		UTILITY std::vector<char> ReadAllBytes(const std::string& fileName);
		UTILITY int WriteAllBytes(const std::string& fileName, std::vector<char> vecBytes);

		UTILITY std::int32_t FindFirst(const std::string& file, const std::string& val);
		UTILITY std::vector<int32_t> FindAll(const std::string& file, const std::string& val);
	};
}

#endif // !_N_FILE_UTILS_H_