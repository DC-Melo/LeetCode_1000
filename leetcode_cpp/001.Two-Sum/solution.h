#pragma once
#include <deque>      // STL 双端队列容器
#include <exception>  // 异常处理类
#include <fstream>    // 文件输入／输出
#include <functional> // STL 定义运算函数（代替运算符）
#include <limits>     // 定义各种数据类型最值常量
#include <list>       // STL 线性列表容器
#include <map>        // STL 映射容器
#include <unordered_map>
#include <iomanip>    // 参数化输入／输出
#include <ios>        // 基本输入／输出支持
#include <sstream>    // 基于字符串的流
#include <stack>      // STL 堆栈容器
#include <algorithm>  // STL 通用算法
#include <bitset>     // STL 位集容器
#include <cctype>     // 字符处理
#include <stdexcept>  // 标准异常类
#include <streambuf>  // 底层输入／输出支持
#include <string>     // 字符串类
#include <utility>    // STL 通用模板类
#include <vector>     // STL 动态数组容器
#include <iosfwd>     // 输入／输出系统使用的前置声明
#include <cerrno>     // 定义错误码
#include <clocale>    // 定义本地化函数
#include <cmath>      // 定义数学函数
#include <complex>    // 复数类
#include <cstdio>     // 定义输入／输出函数
#include <cstdlib>    // 定义杂项函数及内存分配函数
#include <cstring>    // 字符串处理
#include <ctime>      // 定义关于时间的函数
#include <iostream>   // 数据流输入／输出
#include <istream>    // 基本输入流
#include <ostream>    // 基本输出流
#include <queue>      // STL 队列容器
#include <set>        // STL 集合容器
#include <cwchar>     // 宽字符处理及输入／输出
#include <cwctype>    // 宽字符分类
#include <complex.h>  // 复数处理
#include <fenv.h>     // 浮点环境
#include <inttypes.h> // 整数格式转换
#include <stdbool.h>  // 布尔环境
#include <stdint.h>   // 整型环境
#include <tgmath.h>   // 通用类型数学宏

using namespace std;
class Solution
{
public:
    Solution() {}
    ~Solution() {}
    vector<int> twoSum(vector<int> &numbers, int target);
private:

};

