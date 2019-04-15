// HashTableDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
��ϣ��(ɢ�б���������)��
��Ҫ֪����¼�Ĵ�����������ݴ������Ǿ�̬�ģ��������ܴﵽ��õĲ���Ч�ʣ�
ͨ��ɢ�к�������ؼ��ֻ�õ�ַ��ֱ�Ӳ�����ַָ��Ͱ�����ݣ�

���ҡ������ɾ�����㷨���Ӷȶ���O(1)���޷�������

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

ostream& operator << (ostream &out, Student stud)
{
	out << stud.getName().c_str() << ": " << stud.getSorce();

	return out;
}

int main()
{
	int intSize = 100000;

	//��ʼ��======================================
	HashTable<string, Student> ht(intSize);	//��ʼ���㹻��Ĺ�ϣ���Ƚ�ռ���ڴ�

	//����========================================
	for (int i = 0; i < intSize; i++)
	{
		char szName[100];
		sprintf(szName, "N%i", intSize + i);

		string strName = szName;

		//ht[strName] = Student(strName.c_str(), 15 + rand() % 8, true, 50 + rand() % 50);

		ht.insertData(strName, Student(strName.c_str(), 15 + rand() % 8, true, 50 + rand() % 50));
	}

	//����========================================
	Student &stud1 = ht["N100001"];
	cout << stud1 << endl;

	Student &stud2 = ht["N100002"];
	cout << stud2 << endl;

	//ɾ��========================================
	ht.removeData("N100001");

	getchar();
    return 0;
}

