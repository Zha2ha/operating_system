#ifndef PCH_H
#define PCH_H

// TODO: 添加要在此处预编译的标头
#include<iostream>
#include<iomanip>

using namespace std;
#define PAGESIZE 1024  //块大小
#define DEFAULTSIZE 10240//内存默认大小
int PageIsEmpty[10] = { 0 };//块的使用情况，0未被占用，1被占用


#endif //PCH_H
