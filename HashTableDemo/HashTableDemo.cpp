// HashTableDemo.cpp : 定义控制台应用程序的入口点。
//

/*
哈希表(散列表，数组链表)：
需要知道记录的大概数量，数据大体上是静态的，这样才能达到最好的查找效率；
通过散列函数计算关键字获得地址，直接操作地址指向桶的数据；

查找、插入和删除的算法复杂度都是O(1)，无法做排序；

散列函数设计：
取余数法：f(key) = key mod p
折叠法：把关键字分为几个部分，叠加求各后取后几位作为地址
平方取中法：取关键字的平方中间部分的值作为地址

冲突溢出处理：
1、链地址法：把所有相同的地址的记录保存在一个链表中
2、再散列函数法：使用多个散列函数
3、线性探测法：将哈希表看成一个环形表，从地址向下查找，直到找到相同的关键字、或者空记录为止；

*/


#include "stdafx.h"
#include "Studend.h"
#include "HashTable.h"

ostream& operator << (ostream &out, Student stud)
{
	out << stud.getName().c_str() << ": " << stud.getSorce();

	return out;
}

int main()
{
	int intSize = 100000;

	//初始化======================================
	HashTable<string, Student> ht(intSize);	//初始化足够大的哈希表，比较占用内存

	//插入========================================
	for (int i = 0; i < intSize; i++)
	{
		char szName[100];
		sprintf(szName, "N%i", intSize + i);

		string strName = szName;

		//ht[strName] = Student(strName.c_str(), 15 + rand() % 8, true, 50 + rand() % 50);

		ht.insertData(strName, Student(strName.c_str(), 15 + rand() % 8, true, 50 + rand() % 50));
	}

	//查找========================================
	Student &stud1 = ht["N100001"];
	cout << stud1 << endl;

	Student &stud2 = ht["N100002"];
	cout << stud2 << endl;

	//删除========================================
	ht.removeData("N100001");

	getchar();
    return 0;
}

