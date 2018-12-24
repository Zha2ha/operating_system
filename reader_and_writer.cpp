#include <iostream>
#include <Thread>
#include <Windows.h>
using namespace std;

HANDLE Rmutex = NULL;
HANDLE Wmutex = NULL;
int Rcount = 0;
DWORD WINAPI ReadThread(LPVOID lpParamter)
{
	while (Rcount >= 0)
	{
		WaitForSingleObject(Rmutex, INFINITE);
		Rcount++;                             
		if (Rcount == 1)
			WaitForSingleObject(Wmutex, INFINITE);
		ReleaseMutex(Rmutex);                     

		cout << Rcount << " men are reading!\n";

		WaitForSingleObject(Rmutex, INFINITE);
		Rcount--;
		if (Rcount == 0)
			ReleaseMutex(Wmutex);
		ReleaseMutex(Rmutex);
	}	
	return 0L;
}

DWORD WINAPI WriteThread(LPVOID lpParamter)
{
	while (1)
	{
		WaitForSingleObject(Wmutex, INFINITE);
		cout << "writing!\n";
		Sleep(100);                           
		ReleaseMutex(Wmutex);
	}		
	return 0;
}

int main()
{
	Rmutex = CreateMutex(NULL, false, "Read");
	Wmutex = CreateMutex(NULL, false, "write");

	HANDLE Wthread1 = CreateThread(NULL, 0, WriteThread, NULL, 0, NULL);
	HANDLE Rthread1 = CreateThread(NULL, 0, ReadThread, NULL, 0, NULL);
	HANDLE Rthread2 = CreateThread(NULL, 0, ReadThread, NULL, 0, NULL);
	HANDLE Rthread3 = CreateThread(NULL, 0, ReadThread, NULL, 0, NULL);
	//HANDLE Rthread4 = CreateThread(NULL, 0, ReadThread, NULL, 0, NULL);
	//HANDLE Rthread5 = CreateThread(NULL, 0, ReadThread, NULL, 0, NULL);
	//WaitForSingleObject(Rthread, INFINITE);
	//WaitForSingleObject(Wthread, INFINITE);
	CloseHandle(Rthread1);
	CloseHandle(Rthread2);
	CloseHandle(Rthread3);
	CloseHandle(Wthread1);
	system("pause");
	return 0;
}

