// memory_management.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include"Memory2.h"
#include <iostream>
using namespace std;

#define STOP 0
//void mainview(int stop, int &count, Frame F[]);

int main()
{
	int stop = 1;//停止标志
	Frame F[10];
	init_frame(F);
	int count = 9;
	while (stop != STOP)        
	{
		cout << "******** 内存管理 ********" << endl;
		cout << "1、加入进程\n" << "2、撤回进程\n" << "3、查看内存情况\n" << "4、退出\n" << "请输入操作序号：";
		string name;
		int size;
		int opNum;
		cin >> opNum;
		if (opNum < 1 || opNum > 4)
		{
			cerr << "不存在此操作！";
		}

		switch (opNum)
		{
		case 1:
			AddProcess(F, count);
			break;
		case 2:
			DelProcess(F);
			break;
		case 3:
			PrintMem(F);
			break;
		case 4:
			stop = STOP;
			cout << "退出系统" << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}
