
#include "stdafx.h"
#include "bitsetDemo.h"

void bitsetDemo()
{
	//位集合的用法=======================================================
	bitset<16> b1;
	bitset<16> b2("1100111100001111");	//使用字符串初始化位集合
	bitset<16> b3(b2);
	
	b1 = b2;

	int i1 = b1.count();			//返回值为1的个数

	if (b1.any()) cout<<"any 1 in b1."<<endl;		//是否存在1

	if (b1.none()) cout<<"all is 0 in b1."<<endl;	//是否全为0

	if (b1.test(6)) cout<<"b1 pos 5 is 1."<<endl;	//第5位是否为1

	b1.set(5, false);			//第5位设为0，或者全部设为1

	b1.reset(6);				//第6位重置为0，或者全部设为0

	b1.flip(7);					//第7位取反，或者全部取反

	unsigned long ul = b1.to_ulong();	//转化为ulong

	string str = b1.to_string();		//转化为string

	if (b2==b3) cout<<"b2 equal to b3."<<endl;		//比较两个位集合是否相等

	if (b2!=b3) cout<<"b2 equal to b3."<<endl;

	bool bMy = b1[5];

	b1 = b1 << 1;		//向左移动N个位置

	b1 = b1 >> 2;		//向右移动N个位置

	b3 = b1 & b2;		//两个位集合按位与操作
	b3 = b1 | b2;		//两个位集合按位或操作
	b3 = b1 ^ b2;		//两个位集合按位异或操作
	b3 = b1.operator~();	//取反

	cin.get();
}
