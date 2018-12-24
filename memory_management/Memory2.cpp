#include "pch.h"
#include "Memory2.h"

void init_frame(Frame F[])
{
	//Frame F[10];
	for (int i = 0; i< 10; i++)
	{
		if (i == 0)
		{
			F[i].Isempty = false;
			F[i].Time = 0;
			F[i].start = 0;
			F[i].end = 1024;
			F[i].Pname = "OS";
		}
		else
		{
			F[i].Isempty = true;
			F[i].Time = 0;
			F[i].start = i * PAGESIZE;
			F[i].end = F[i].start;
			F[i].Pname = "empty";
		}
		
	}
	
}

void AddProcess(Frame F[], int &count)//count为空页面数
{
	string name;
	int size;
	int sTime = 0;//占用时间
	int en;//进程最后一页的大小
	int LTime=0;//最长时间
	int change;//置换的页面号
	cout << "请输入进程名：";
	cin >> name;
	cout << "请输入进程占用内存大小(B):";
	cin >> size;
	process pro(name, size);
	en = size % PAGESIZE;
	for (int j = 1; j < 10; j++)
	{
		if (F[j].Isempty == false)
		{
			F[j].Time++;
		}
	}
	for (int i = 0; i < pro.pageNum; i++)
	{
		if (count > 0)//还有空的物理块
		{
			for (int j = 1; j < 10; j++)
			{
				if (F[j].Isempty == true)
				{
					F[j].Isempty = false;
					for (int j = 1; j < 10; j++)
					{
						if (F[j].Isempty == false)
						{
							F[j].Time++;
						}
					}
					F[j].Time = 1;
					F[j].Pname = pro.name;
					//pro.frameNum[i] = j;
					if (i == (pro.pageNum - 1))
						F[j].end = F[j].start + en;
					else
						F[j].end = F[j].start + PAGESIZE;
					count--;
					break;
				}
				
			}
		}
		else//没有空的物理块
		{
			for (int i = 1; i < 10; i++)//找出时间最大的页面
			{

				if (F[i].Time > LTime)
				{
					LTime = F[i].Time;
					change = i;
				}

			}
			for (int j = 1; j < 10; j++)
			{
				if (F[j].Isempty == false)
				{
					F[j].Time++;
				}
			}
			F[change].Time = 1;
			F[change].Pname = pro.name;
			//pro.frameNum[i] = change;
			if (i == pro.pageNum - 1)
				F[change].end = F[change].start + en;
			else
				F[change].end = F[change].start + PAGESIZE;
		}
	}
	PrintMem(F);
}
	
void DelProcess(Frame F[])
{
	string str;
	cout << "请输入要撤回的进程名：";
	cin >> str;
	for (int i = 0; i < 10; i++)
	{
		if (F[i].Pname == str)
		{
			F[i].Isempty = true;
			F[i].Pname = "empty";
			F[i].end = F[i].start;
			F[i].Time = 0;
		}
	}
	PrintMem(F);
}

void PrintMem(Frame F[])
{
	for (int i = 0; i < 10; i++)
	{
		cout << i << ":";
		if (F[i].Isempty == true)
		{
			cout << "此页面无进程" << endl;
		}
		else
		{
			cout << "name:" << setw(6) << F[i].Pname << "  start address:" << setw(6) << F[i].start
				<< "  end address:" << setw(6) << F[i].end;
			cout << endl;
		}
	}
}