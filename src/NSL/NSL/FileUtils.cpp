// � 2019 NIREX ALL RIGHTS RESERVED

#include "FileUtils.h"
#include "nwin.h"

namespace NSL
{
	std::string FileUtils::ReadAllText(const std::string& file)
	{
		std::ifstream f(file.c_str());

		std::string str = "";
		std::string outstr = "";
		int iter = 0;
		while (std::getline(f, str))
		{
			iter++;
			outstr += str;
			outstr += 10;
		}
		f.close();
		return outstr;
	}

	int FileUtils::WriteAllText(const std::string& file, const std::string& str)
	{
		std::ofstream f;
		f.open(file);
		f << str;
		f.close();
		return 0;
	}

	std::vector<std::string> FileUtils::ReadAllLines(const std::string& file)
	{
		std::ifstream f(file.c_str());
		std::vector<std::string> retv;

		std::string str = "";
		while (std::getline(f, str))
		{
			retv.push_back(str);
		}

		f.close();
		return retv;
	}

	int FileUtils::WriteAllLines(const std::string& file, std::vector<std::string> vecstr)
	{
		std::ofstream f;
		f.open(file);

		for (size_t i = 0; i < vecstr.size(); i++)
		{
			f << vecstr[i];
			f << std::endl;
		}

		f.close();
		return 0;
	}

	std::vector<char> FileUtils::ReadAllBytes(const std::string& fileName)
	{
		std::ifstream ifs(fileName, std::ios::binary | std::ios::ate);
		std::ifstream::pos_type pos = ifs.tellg();

		std::vector<char> result((const unsigned int)pos);

		ifs.seekg(0, std::ios::beg);
		ifs.read(&result[0], pos);

		return result;
	}

	int FileUtils::WriteAllBytes(const std::string& fileName, std::vector<char> vecBytes)
	{
		std::ofstream ofs(fileName, std::ios::binary | std::ios::out);

		ofs.write(vecBytes.data(), vecBytes.size());

		if (ofs.bad()) //bad() function will check for badbit
		{
			return 1;
		}

		ofs.close();
		return 0;
	}

	std::int32_t FileUtils::FindFirst(const std::string& file, const std::string& val)
	{
		std::ifstream f(file.c_str());

		std::string str = "";
		int iter = 0;
		while (std::getline(f, str))
		{
			if (val == str)
			{
				return iter;
			}
			iter++;
		}
		f.close();
		return -1;
	}

	std::vector<int32_t> FileUtils::FindAll(const std::string& file, const std::string& val)
	{
		std::ifstream f(file.c_str());
		std::vector<int32_t> retv;

		std::string str = "";
		int iter = 0;

		while (std::getline(f, str))
		{
			if (val == str)
			{
				retv.push_back(iter);
			}
			iter++;
		}

		f.close();
		return retv;
	}
}