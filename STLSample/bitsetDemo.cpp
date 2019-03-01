
#include "stdafx.h"
#include "bitsetDemo.h"

void bitsetDemo()
{
	//λ���ϵ��÷�=======================================================
	bitset<16> b1;
	bitset<16> b2("1100111100001111");	//ʹ���ַ�����ʼ��λ����
	bitset<16> b3(b2);
	
	b1 = b2;

	int i1 = b1.count();			//����ֵΪ1�ĸ���

	if (b1.any()) cout<<"any 1 in b1."<<endl;		//�Ƿ����1

	if (b1.none()) cout<<"all is 0 in b1."<<endl;	//�Ƿ�ȫΪ0

	if (b1.test(6)) cout<<"b1 pos 5 is 1."<<endl;	//��5λ�Ƿ�Ϊ1

	b1.set(5, false);			//��5λ��Ϊ0������ȫ����Ϊ1

	b1.reset(6);				//��6λ����Ϊ0������ȫ����Ϊ0

	b1.flip(7);					//��7λȡ��������ȫ��ȡ��

	unsigned long ul = b1.to_ulong();	//ת��Ϊulong

	string str = b1.to_string();		//ת��Ϊstring

	if (b2==b3) cout<<"b2 equal to b3."<<endl;		//�Ƚ�����λ�����Ƿ����

	if (b2!=b3) cout<<"b2 equal to b3."<<endl;

	bool bMy = b1[5];

	b1 = b1 << 1;		//�����ƶ�N��λ��

	b1 = b1 >> 2;		//�����ƶ�N��λ��

	b3 = b1 & b2;		//����λ���ϰ�λ�����
	b3 = b1 | b2;		//����λ���ϰ�λ�����
	b3 = b1 ^ b2;		//����λ���ϰ�λ������
	b3 = b1.operator~();	//ȡ��

	cin.get();
}
