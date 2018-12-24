#include <iostream>

using namespace std;
struct JCB
{
	char Pname[4];
	float atime;
	float rtime;
};

void FCFS(JCB *js, int n);
void SortInatime(JCB *js, int n);
void SortInatime(JCB *js, int n)
{
	JCB temp;
	int bound, exchange = n - 1;
	while (exchange != 0)
	{
		bound = exchange; exchange = 0;
		for (int j = 0; j < bound; j++)
		{
			if ((js + j)->atime > (js + j + 1)->atime)
			{
				temp = *(js + j);
				*(js + j) = *(js + j + 1);
				*(js + j + 1) = temp;
				exchange = j;
			}
		}
	}

}
void FCFS(JCB *js, int n)
{
	SortInatime(js, n);
	cout << "����˳��Ϊ��\n";
	float stime = 0;
	float ftime = 0;
	float zztime;
	float dqzzt;
	float avrzz = 0;
	float avrdqzz = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			stime = js[0].atime;
		}
		else
		{
			stime += js[i-1].rtime;
		}
		ftime = stime + js[i].rtime;
		cout << js[i].Pname << "  " << "��ʼʱ�䣺";
		if (stime < js[i].atime)
		{
			cout << js[i].atime;
		}
		else
		{
			cout << stime;
		}
		zztime = ftime - js[i].atime;
		avrzz += zztime;
		dqzzt = zztime / js[i].rtime;
		avrdqzz += dqzzt;
		cout << "���ʱ�䣺" << ftime << "��תʱ�䣺" << zztime << "��Ȩ��תʱ�䣺" << dqzzt;
		cout << endl;
	}
	avrzz = avrzz / n;
	avrdqzz = avrdqzz / n;
	cout << "ƽ����תʱ��Ϊ��" << avrzz << endl;
	cout << "ƽ����Ȩ��תʱ��Ϊ��" << avrdqzz << endl;
}

int main()
{
	int num;
	cout << "��������̸�����";
	cin >> num;
	
	JCB *js;
	js = (JCB*)malloc(num * sizeof(JCB));
	for (int i = 0; i < num; i++)
	{
		cout << "������JCB" << i << "�������Ϣ��\n";
		cout << "Pname :";
		cin >> (js + i)->Pname;
		cout << "arrive time :";
		cin >> (js + i)->atime;
		cout << "run time :";
		cin >> (js + i)->rtime;
	}
	FCFS(js, num);
	system("pause");
	return 0;
}