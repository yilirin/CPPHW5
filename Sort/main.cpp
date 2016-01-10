// Sort.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"

#include <assert.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

// mysort.h是需要提交的代码，其中包含mysort函数的实现，mysort函数原型请自行根据测试代码设计
// 初步要求：mysort以选择排序为排序算法，实现后应能通过测试程序
// 深入要求：mysort会自动根据当前输入迭代器所对应容器类型，选择排序算法，若vector之类具有随机访问能力的容器，则通过冒泡排序实现；否则仍通过选择排序。
#include "mysort.h"

// 通过vector定义用于管理整形元素的数组类型
typedef std::vector<int> IVector;
// 通过list定义用于管理整形元素的链表类型
typedef std::list<int> IList;

int main()
{
    // 定义所需排序的数组
    IVector iv, iv_sorted;
    IList il, il_sorted;
    
    // 为rand准备随机种子
    srand((unsigned)time(NULL));
    
    // 随机生成元素，通过push_back追加到两个测试容器中
    for (int i = 0; i < 20; ++i)
    {
        iv.push_back(rand());
        il.push_back(rand());
    }
    
    ////////////////////////////////////////////////////////////
    // 复制插入的数据，并通过STL自身的排序算法排序，排序后的容器将用于测试所实现的mysort函数
    iv_sorted = iv;
    il_sorted = il;
    
    sort(iv_sorted.begin(), iv_sorted.end());
    il_sorted.sort();
    
    
    ////////////////////////////////////////////////////////////
    // 通过实现的mysort函数对容器排序
    mysort(iv.begin(), iv.end());
    mysort(il.begin(), il.end());
    
    
    
    
    ////////////////////////////////////////////////////////////
    // 排序后结果应与STL排序后的结果相同
    assert(iv_sorted == iv); 
    assert(il_sorted == il); 
    
    system("pause"); 
    
    return 0;
}

