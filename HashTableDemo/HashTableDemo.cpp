// HashTableDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
��ϣ��(ɢ�б�)��
��Ҫ֪����¼�����ķ�Χ�����ݴ������Ǿ�̬�ģ��������ܴﵽ����Ч�ʣ�
ͨ��ɢ�к�������ؼ��ֻ�õ�ַ��ֱ�Ӳ�����ַָ��Ͱ�����ݣ�

���ҡ������ɾ�����㷨���Ӷȶ���O(1)

ɢ�к�����ƣ�
ȡ��������f(key) = key mod p
�۵������ѹؼ��ַ�Ϊ�������֣����������ȡ��λ��Ϊ��ַ
ƽ��ȡ�з���ȡ�ؼ��ֵ�ƽ���м䲿�ֵ�ֵ��Ϊ��ַ

��ͻ�������
1������ַ������������ͬ�ĵ�ַ�ļ�¼������һ��������
2����ɢ�к�������ʹ�ö��ɢ�к���
3������̽�ⷨ������ϣ����һ�����α��ӵ�ַ���²��ң�ֱ���ҵ���ͬ�Ĺؼ��֡����߿ռ�¼Ϊֹ��

*/


#include "stdafx.h"
#include "Studend.h"
#include "HashTable.h"

int main()
{
	int intSize = 100000;
	HashTable<Student> ht(intSize, Student());
	char szName[100];

	//����
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

	//����
	Student &guiquan1 = ht["GuiQuan1"];
	Student &guiquan2 = ht["GuiQuan2"];

	guiquan1.setSorce(99);
	guiquan2.setSorce(100);

	Student &g1 = ht["GuiQuan1"];

	//ɾ��
	ht.removeData("GuiQuan1");

	//���
	ht.clearData();

	getchar();
    return 0;
}

