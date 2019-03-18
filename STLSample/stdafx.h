// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>


// TODO: 在此处引用程序需要的其他头文件
//输入输出设备
#include <iostream>

//序列式容器
#include <vector>
#include <list>
#include <deque>

//关联式容器
#include <set>
#include <map>

//特殊容器
#include <bitset>
#include <stack>
#include <queue>

//STL算法
#include <algorithm>

//STL仿函数
#include <functional>

using namespace std;

template<class T>
void display(const T &v)
{
	cout<<v<<" ";
}
