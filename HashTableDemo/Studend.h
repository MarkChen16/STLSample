#pragma once

#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	Student(string name, int age, bool sex, int sorce)
	{
		szName = name;
		intAge = age;
		bSex = sex;
		intSorce = sorce;
	}

	Student()
	{
		szName = "";
		intAge = 0;
		bSex = true;
		intSorce = 0;
	}

	string getName()
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
	string szName;
	int intAge;
	bool bSex;
	int intSorce;

};

