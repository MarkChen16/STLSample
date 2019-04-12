// HashTableDemo.cpp : 定义控制台应用程序的入口点。
//

/*
哈希表(散列表)：
需要知道记录数量的范围，数据大体上是静态的，这样才能达到最大的效率；
通过散列函数计算关键字获得地址，直接操作地址指向桶的数据；

查找、插入和删除的算法复杂度都是O(1)

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

int main()
{
	int intSize = 100000;
	HashTable<Student> ht(intSize, Student());
	char szName[100];

	//插入
	ht["GuiQuan1"] = Student("GuiQuan1", 34, true, 80);
	ht["GuiQuan2"] = Student("GuiQuan2", 34, true, 80);
	ht["GuiQuan3"] = Student("GuiQuan3", 34, true, 80);
	ht["GuiQuan4"] = Student("GuiQuan4", 34, true, 80);

	for (int i = 0; i < intSize; i++)
	{
		sprintf_s(szName, "N%i", 1234 + rand() % intSize);

		ht[szName] = Student(szName, 15 + rand() % 8, true, 50 + rand() % 50);
	}
	
	//ht.show();

	//查找
	Student &guiquan1 = ht["GuiQuan1"];
	Student &guiquan2 = ht["GuiQuan2"];

	guiquan1.setSorce(99);
	guiquan2.setSorce(100);

	Student &g1 = ht["GuiQuan1"];

	//删除
	ht.removeData("GuiQuan1");

	//清除
	ht.clearData();

	getchar();
    return 0;
}

