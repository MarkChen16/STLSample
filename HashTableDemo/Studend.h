#pragma once

#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	Student(const char *name, int age, bool sex, int sorce)
	{
		strcpy_s(szName, name);
		intAge = age;
		bSex = sex;
		intSorce = sorce;
		szInfo[0] = 0x00;
	}

	Student(const char *name)
	{
		strcpy_s(szName, name);
		intAge = 0;
		bSex = true;
		intSorce = 0;
		szInfo[0] = 0x00;
	}

	Student() = default;

	~Student()
	{
	}

	operator const char *()
	{
		sprintf_s(szInfo, "%s: %i", szName, intSorce);
		return szInfo;
	}

	operator int()
	{
		int intRev = 0;

		//折叠法转换为整型关键字
		for (int i = 0; i < 10; i++)
		{
			int tmp = (szName[i * 4 + 3] << 22) + (szName[i * 4 + 2] << 16) + (szName[i * 4 + 1] << 8) + szName[i * 4];
			if (0 == tmp) break;

			intRev += tmp;
		}

		return intRev;
	}

	bool operator ==(const Student &s)
	{
		if (0 == strcmp(this->szName, s.szName)) return true;
		else return false;
	}

	bool operator != (const Student &s)
	{
		return !operator==(s);
	}

	const char* getName()
	{
		return szName;
	}

	int getAge()
	{
		return intAge;
	}

	bool getSex()
	{
		return bSex;
	}

	int getSorce()
	{
		return intSorce;
	}

	void setSorce(int value)
	{
		intSorce = value;
	}

private:
	char szName[40];
	int intAge;
	bool bSex;
	int intSorce;

	char szInfo[100];
};


