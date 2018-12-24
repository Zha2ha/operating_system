#pragma once
#include"process.h"
struct Frame
{
	bool Isempty;//是否被占用标志
	int Time;//占用时长
	int start;
	int end;
	string Pname;
};
void init_frame(Frame F[]);
void AddProcess(Frame F[], int &count);
void DelProcess(Frame F[]);
void PrintMem(Frame F[]);