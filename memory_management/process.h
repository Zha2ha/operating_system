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
	int size;//���̴�С
	//int start;//��ʼ��ַ
	//int end;//������ַ
	int pageNum;//����ҳ����
	//int *frameNum = new int[pageNum];//���̵�ҳ��
	
};

