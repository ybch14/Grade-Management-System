#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "scores.h"
void preface(void);
void functions(void);
int main(void)
{
	preface();
	try
	{
		functions();
	}
	catch(int)
	{
		cout<<"�ļ�δ�ɹ��򿪣�"<<endl;
		return 0;
	}
	catch(double)
	{
		cout<<"ллʹ�ã��ټ���"<<endl;
		return 0;
	}
	system("pause");
	return 0;
}
