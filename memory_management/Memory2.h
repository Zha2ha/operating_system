#pragma once
#include"process.h"
struct Frame
{
	bool Isempty;//�Ƿ�ռ�ñ�־
	int Time;//ռ��ʱ��
	int start;//��ʼ��ַ
	int end;//������ַ
	string Pname;//������
};
void init_frame(Frame F[]);
void AddProcess(Frame F[], int &count);
void DelProcess(Frame F[]);
void PrintMem(Frame F[]);