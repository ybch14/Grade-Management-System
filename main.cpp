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
		cout<<"文件未成功打开！"<<endl;
		return 0;
	}
	catch(double)
	{
		cout<<"谢谢使用，再见！"<<endl;
		return 0;
	}
	system("pause");
	return 0;
}
