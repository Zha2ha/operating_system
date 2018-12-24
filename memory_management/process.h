#pragma once
#include<string>


using namespace std;

class process
{
public:
	//process() {}
	process(string str, int sz) {
		name = str; size = sz;
		if (size % PAGESIZE == 0)
			pageNum = size / PAGESIZE;
		else
			pageNum = (size / PAGESIZE) + 1;
	}
	~process() {}

	string name;
	int size;//进程大小
	//int start;//开始地址
	//int end;//结束地址
	int pageNum;//请求页面数
	//int *frameNum = new int[pageNum];//进程的页表
	
};

