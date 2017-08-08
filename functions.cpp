#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "scores.h"
using namespace std;
extern int i;
int j=0;
void functions(void)
{
	int order=0,openerror=0;double inputerror=0;
	for(int count=0;;count++)
	{
		std::cout<<setfill('*')<<setw(28)<<'*'<<" 请选择以下功能 "<<setfill('*')<<setw(29)<<'*'<<std::endl;
	    std::cout<<setfill('*')<<setw(28)<<'*'<<" 1 录入学生信息 "<<setfill('*')<<setw(29)<<'*'<<std::endl;
	    std::cout<<setfill('*')<<setw(28)<<'*'<<" 2 查询学生信息 "<<setfill('*')<<setw(29)<<'*'<<std::endl;
	    std::cout<<setfill('*')<<setw(28)<<'*'<<" 3 查询课程信息 "<<setfill('*')<<setw(29)<<'*'<<std::endl;
	    std::cout<<setfill('*')<<setw(28)<<'*'<<" 4 修改学生信息 "<<setfill('*')<<setw(29)<<'*'<<std::endl;
	    std::cout<<setfill('*')<<setw(28)<<'*'<<" 其他  退出系统 "<<setfill('*')<<setw(29)<<'*'<<std::endl;
	    std::cin>>order;
	    switch(order)
	    {
	    case 1://录入功能
		{
			std::cout<<"请选择所录入学生的年级：1 一年级 2 二年级 3 三年级 4 毕业生"<<std::endl;
		    int year=0;
			std::cin>>year;
		    switch (year)
		    {
		    case 1:
			    {
				    Freshman temp;
					std::string tempname;char tempsex;long long tempnumber;double tempscore[4]={0,0,0,0};
					bool flag=0;
			        std::cin>>temp;
					ifstream infile("freshman.txt",ios_base::in);
					if(!infile)
						throw openerror;
					for(i=0;infile.peek()!=EOF;i++)
					{
						infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3];
						Freshman temptemp=Freshman(tempname,tempsex,tempnumber,tempscore);
						if(temptemp==temp)
						{
							std::cout<<"学生信息已存在，请重试！"<<std::endl;
							flag=1;
							break;
						}
					}
					infile.close();
                    if(flag==0)
					{
						ofstream outfile("freshman.txt",ios_base::app);
						if(!outfile)
						    throw openerror;
						outfile<<temp.studentname<<" "<<temp.sex<<" "<<temp.studentnumber<<" ";
						for(i=0;i<temp.number_of_course;i++)
							outfile<<temp.studentcourse[i].coursescore<<" ";
						outfile<<'\n';
						outfile.close();
						cout<<"录入成功!"<<endl;
					}
				    break;
			    }
		    case 2:
			    {
				    Sophomore temp;
					std::string tempname;char tempsex;long long tempnumber;double tempscore[6]={0,0,0,0};
					bool flag=0;
			        std::cin>>temp;
					ifstream infile("sophomore.txt",ios_base::in);
					if(!infile)
						throw openerror;
					for(i=0;infile.peek()!=EOF;i++)
					{
						infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4]>>tempscore[5];
						Sophomore temptemp=Sophomore(tempname,tempsex,tempnumber,tempscore);
						if(temptemp==temp)
						{
							std::cout<<"学生信息已存在，请重试！"<<std::endl;
							flag=1;
							break;
						}
					}
					infile.close();
                    if(flag==0)
					{
						ofstream outfile("sophomore.txt",ios_base::app);
						if(!outfile)
						    throw openerror;
						outfile<<temp.studentname<<" "<<temp.sex<<" "<<temp.studentnumber<<" ";
						for(i=0;i<temp.number_of_course;i++)
							outfile<<temp.studentcourse[i].coursescore<<" ";
						outfile<<'\n';
						outfile.close();
						cout<<"录入成功！"<<endl;
					}
				    break;
			    }
	    	case 3:
		    	{
					Junior temp;
					std::string tempname;char tempsex;long long tempnumber;double tempscore[5];
					bool flag=0;
			        std::cin>>temp;
					ifstream infile("junior.txt",ios_base::in);
					if(!infile)
						throw openerror;
					for(i=0;infile.peek()!=EOF;i++)
					{
						infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4];
						Junior temptemp=Junior(tempname,tempsex,tempnumber,tempscore);
						if(temptemp==temp)
						{
							std::cout<<"学生信息已存在，请重试！"<<std::endl;
							flag=1;
							break;
						}
					}
					infile.close();
                    if(flag==0)
					{
						ofstream outfile("junior.txt",ios_base::app);
						if(!outfile)
						    throw openerror;
						outfile<<temp.studentname<<" "<<temp.sex<<" "<<temp.studentnumber<<" ";
						for(i=0;i<temp.number_of_course;i++)
							outfile<<temp.studentcourse[i].coursescore<<" ";
						outfile<<'\n';
						outfile.close();
						cout<<"录入成功！"<<endl;
					}
				    break;
			    }
		    case 4:
		    	{
			    	Graduate temp;
					std::string tempname;char tempsex;long long tempnumber;double tempscore[15];
					bool flag=0;
			        std::cin>>temp;
					ifstream infile("graduate.txt",ios_base::in);
					if(!infile)
						throw openerror;
					for(i=0;infile.peek()!=EOF;i++)
					{
						infile>>tempname>>tempsex>>tempnumber;
						for(i=0;i<14;i++)
							infile>>tempscore[i];
						Graduate temptemp=Graduate(tempname,tempsex,tempnumber,tempscore);
						if(temptemp==temp)
						{
							std::cout<<"学生信息已存在，请重试！"<<std::endl;
							flag=1;
							break;
						}
					}
					infile.close();
                    if(flag==0)
					{
						ofstream outfile("graduate.txt",ios_base::app);
						if(!outfile)
						    throw openerror;
						outfile<<temp.studentname<<" "<<temp.sex<<" "<<temp.studentnumber<<" ";
						for(i=0;i<temp.number_of_course;i++)
							outfile<<temp.studentcourse[i].coursescore<<" ";
						outfile<<'\n';
						outfile.close();
						cout<<"录入成功！"<<endl;
					}
				    break;
			    }
		    default:
				{
					std::cout<<"输入年级错误，请重试！"<<std::endl;
		        	break;
				}
			}
			break;
		}
		case 2://查询学生信息的功能
		{
			int way;char buffer[100];
			for(int m=0;m<100;m++)
				buffer[m]=' ';
			std::cout<<"请选择查询方式：1 姓名 2 学号"<<std::endl;
			std::cin>>way;
			if((way!=1)&&(way!=2))
			{
				std::cout<<"输入指令错误，请重试！"<<std::endl;
				order=0;
			}
			else if(way==1)
			{
				std::cout<<"请输入姓名："<<std::endl;
				std::string temp,compare;int flag=0;char temp_sex;long long temp_number;
				std::cin>>temp;
				ifstream freshman_infile("freshman.txt",ios_base::in);
				if(!freshman_infile)
					throw openerror;
				for(i=0,flag=0;!freshman_infile.eof();i++)
				{
                    double temp_score[4];
					freshman_infile>>compare>>temp_sex>>temp_number>>temp_score[0]>>temp_score[1]>>temp_score[2]>>temp_score[3];
					freshman_infile.getline(buffer,100);
					if(compare==temp)
					{
						Freshman tempfreshman(temp,temp_sex,temp_number,temp_score);
						std::cout<<tempfreshman;
						flag=1;
						break;
					}
				}
				freshman_infile.close();
				if(flag==0)
				{
					ifstream sophomore_infile("sophomore.txt",ios_base::in);
					if(!sophomore_infile)
						throw openerror;
					for(i=0,flag=0;!sophomore_infile.eof();i++)
				{
					double temp_score[6];
					sophomore_infile>>compare>>temp_sex>>temp_number>>temp_score[0]>>temp_score[1]>>temp_score[2]>>temp_score[3]>>temp_score[4]>>temp_score[5];
					sophomore_infile.getline(buffer,100);
					if(compare==temp)
					{
						Sophomore tempsophomore(temp,temp_sex,temp_number,temp_score);
						std::cout<<tempsophomore;
						flag=1;
						break;
					}
				}
                    sophomore_infile.close();
				}
				if(flag==0)
				{
                    ifstream junior_infile("junior.txt",ios_base::in);
					if(!junior_infile)
						throw openerror;
					for(i=0,flag=0;!junior_infile.eof();i++)
				{
					double temp_score[5];
					junior_infile>>compare>>temp_sex>>temp_number>>temp_score[0]>>temp_score[1]>>temp_score[2]>>temp_score[3]>>temp_score[4];
					junior_infile.getline(buffer,100);
					if(compare==temp)
					{
						Junior tempjunior(temp,temp_sex,temp_number,temp_score);
						std::cout<<tempjunior;
						flag=1;
						break;
					}
				}
				    junior_infile.close();
				}
				if(flag==0)
				{
					ifstream graduate_infile("graduate.txt",ios_base::in);
					if(!graduate_infile)
						throw openerror;
					for(i=0,flag=0;!graduate_infile.eof();i++)
				{
					double temp_score[15];
					graduate_infile>>compare>>temp_sex>>temp_number;
					for(i=0;i<15;i++)
						graduate_infile>>temp_score[i];
					graduate_infile.getline(buffer,100);
					if(compare==temp)
					{
						Graduate tempgraduate(temp,temp_sex,temp_number,temp_score);
						std::cout<<tempgraduate;
						flag=1;
						break;
					}
				}
				graduate_infile.close();
				}
				if(flag==0)
				    cout<<"此学生不存在，请重试！"<<endl;
			}
			else if(way==2)
            {
				std::cout<<"请输入学号："<<std::endl;
				std::string tempname;
				char tempsex;long long temp,compare;
				int flag=0;
				std::cin>>temp;
				ifstream freshman_infile("freshman.txt",ios_base::in);
				if(!freshman_infile)
					throw openerror;
				for(i=0,flag=0;!freshman_infile.eof();i++)
				{
					double temp_score[4];
					freshman_infile>>tempname>>tempsex>>compare>>temp_score[0]>>temp_score[1]>>temp_score[2]>>temp_score[3];
					freshman_infile.getline(buffer,100);
					if(compare==temp)
					{
						Freshman tempfreshman(tempname,tempsex,compare,temp_score);
						std::cout<<tempfreshman;
						flag=1;
						break;
					}
				}
				freshman_infile.close();
				if(flag==0)
				{
					ifstream sophomore_infile("sophomore.txt",ios_base::in);
					if(!sophomore_infile)
						throw openerror;
					for(i=0,flag=0;!sophomore_infile.eof();i++)
				{
					double temp_score[6];
					sophomore_infile>>tempname>>tempsex>>compare>>temp_score[0]>>temp_score[1]>>temp_score[2]>>temp_score[3]>>temp_score[4]>>temp_score[5];
					sophomore_infile.getline(buffer,100);
					if(compare==temp)
					{
						Sophomore tempsophomore(tempname,tempsex,compare,temp_score);
						std::cout<<tempsophomore;
						flag=1;
						break;
					}
				}
                    sophomore_infile.close();
				}
				if(flag==0)
				{
                    ifstream junior_infile("junior.txt",ios_base::in);
					if(!junior_infile)
						throw openerror;
					for(i=0,flag=0;!junior_infile.eof();i++)
				{
					double temp_score[5];
					junior_infile>>tempname>>tempsex>>compare>>temp_score[0]>>temp_score[1]>>temp_score[2]>>temp_score[3]>>temp_score[4];
					junior_infile.getline(buffer,100);
					if(compare==temp)
					{
						Junior tempjunior(tempname,tempsex,compare,temp_score);
						std::cout<<tempjunior;
						flag=1;
						break;
					}
				}
				    junior_infile.close();
				}
				if(flag==0)
				{
					ifstream graduate_infile("graduate.txt",ios_base::in);
					if(!graduate_infile)
						throw openerror;
					for(i=0,flag=0;!graduate_infile.eof();i++)
				{
					double temp_score[15];
					graduate_infile>>tempname>>tempsex>>compare;
					for(i=0;i<15;i++)
						graduate_infile>>temp_score[i];
					graduate_infile.getline(buffer,100);
					if(compare==temp)
					{
						Graduate tempgraduate(tempname,tempsex,compare,temp_score);
						std::cout<<tempgraduate;
						flag=1;
						break;
					}
				}
				graduate_infile.close();
				}
				if(flag==0)
					std::cout<<"此学生不存在，请重试！"<<endl;
			}
			break;
		}
		case 3://查询课程信息的功能
		{
			std::cout<<"请输入想要查询的课程名："<<std::endl;
			std::string temp;
			std::cin>>temp;
			std::string tempname;char tempsex;long long tempnumber;char buffer[100];
			for(int m=0;m<100;m++)
				buffer[m]=' ';
			if((temp=="微积分")||(temp=="线性代数")||(temp=="离散数学")||(temp=="计算机程序设计基础"))
			{
				ifstream infile("freshman.txt",ios_base::in);double tempscore[4];
				if(!infile)
					throw openerror;
				if(temp=="微积分")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"姓名"<<setw(5)<<"性别"<<setw(12)<<"学号"<<setw(5)<<"成绩";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
						infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[0];
					}
					cout<<endl;
				}
				else if(temp=="线性代数")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"姓名"<<setw(5)<<"性别"<<setw(12)<<"学号"<<setw(5)<<"成绩";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[1];
					}
					cout<<endl;
				}
				else if(temp=="离散数学")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"姓名"<<setw(5)<<"性别"<<setw(12)<<"学号"<<setw(5)<<"成绩";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[2];
					}
					cout<<endl;
				}
				else if(temp=="计算机程序设计基础")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"姓名"<<setw(5)<<"性别"<<setw(12)<<"学号"<<setw(5)<<"成绩";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[3];
					}
					cout<<endl;
				}
				infile.close();
			}
			else if((temp=="大学物理")||(temp=="电动力学")||(temp=="数据与算法")||(temp=="电子电路与系统基础")
				||(temp=="信号与系统")||(temp=="数字与逻辑"))
			{
				ifstream infile("sophomore.txt",ios_base::in);double tempscore[6];
				if(!infile)
					throw openerror;
				if(temp=="大学物理")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"姓名"<<setw(5)<<"性别"<<setw(12)<<"学号"<<setw(5)<<"成绩";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4]>>tempscore[5];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[0];
					}
					cout<<endl;
				}
				else if(temp=="电动力学")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"姓名"<<setw(5)<<"性别"<<setw(12)<<"学号"<<setw(5)<<"成绩";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4]>>tempscore[5];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[1];
					}
					cout<<endl;
				}
				else if(temp=="数据与算法")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"姓名"<<setw(5)<<"性别"<<setw(12)<<"学号"<<setw(5)<<"成绩";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4]>>tempscore[5];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[2];
					}
					cout<<endl;
				}
				else if(temp=="电子电路与系统基础")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"姓名"<<setw(5)<<"性别"<<setw(12)<<"学号"<<setw(5)<<"成绩";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4]>>tempscore[5];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[3];
					}
					cout<<endl;
				}
				else if(temp=="信号与系统")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"姓名"<<setw(5)<<"性别"<<setw(12)<<"学号"<<setw(5)<<"成绩";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4]>>tempscore[5];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[4];
					}
					cout<<endl;
				}
				else if(temp=="数字与逻辑")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"姓名"<<setw(5)<<"性别"<<setw(12)<<"学号"<<setw(5)<<"成绩";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{ 
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4]>>tempscore[5];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[5];
					}
					cout<<endl;
				}
				infile.close();
			}
			else if((temp=="量子与统计")||(temp=="固体物理")||(temp=="通信与网络")||(temp=="媒体与认知")
				||(temp=="概率论与随机过程"))
			{
				ifstream infile("junior.txt",ios_base::in);double tempscore[5];
				if(!infile)
					throw openerror;
				if(temp=="量子与统计")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"姓名"<<setw(5)<<"性别"<<setw(12)<<"学号"<<setw(5)<<"成绩";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[0];
					}
					cout<<endl;
				}
				else if(temp=="固体物理")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"姓名"<<setw(5)<<"性别"<<setw(12)<<"学号"<<setw(5)<<"成绩";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[1];
					}
					cout<<endl;
				}
				else if(temp=="通信与网络")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"姓名"<<setw(5)<<"性别"<<setw(12)<<"学号"<<setw(5)<<"成绩";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[2];
					}
					cout<<endl;
				}
				else if(temp=="媒体与认知")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"姓名"<<setw(5)<<"性别"<<setw(12)<<"学号"<<setw(5)<<"成绩";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[3];
					}
					cout<<endl;
				}
				else if(temp=="概率论与随机过程")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"姓名"<<setw(5)<<"性别"<<setw(12)<<"学号"<<setw(5)<<"成绩";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[4];
					}
					cout<<endl;
				}
				infile.close();
			}
			else 
				cout<<"课程不存在，请重试！"<<endl;
			break;
		}
		case 4://修改学生信息的功能
		{
			std::cout<<"请输入你想要修改学生的年级：1 一年级 2 二年级 3 三年级 4 毕业生"<<std::endl;
			int year=0;char buffer[100];bool flag=0;int line=0;
			for(int m=0;m<100;m++)
				buffer[m]=' ';
	        std::cin>>year;
			if(year==1)
			{
				ifstream infile("freshman.txt",ios_base::in);
				if(!infile)
					throw openerror;
				while(1)
				{
					infile.getline(buffer,100);
					line++;
					if(infile.peek()==EOF)
						break;
				}
				Freshman *freshman=new Freshman[line];
				std::string tempname;char tempsex;long long tempnumber;double tempscore[4];
				infile.seekg(ios_base::beg);
				for(j=0;j<line;j++)
				{
					infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3];
					infile.getline(buffer,100);
					freshman[j]=Freshman(tempname,tempsex,tempnumber,tempscore);
				}
				infile.close();
				infile.clear();
				std::cout<<"请输入你想要修改学生的姓名：";
				std::string name;std::cin>>name;
				for(j=0,flag=0;j<line;j++)
				{
					if(freshman[j].studentname==name)
					{
						flag=1;
						tempname=freshman[j].studentname;
						tempsex=freshman[j].sex;
						tempnumber=freshman[j].studentnumber;
						tempscore[0]=freshman[j].studentcourse[0].coursescore;
						tempscore[1]=freshman[j].studentcourse[1].coursescore;
						tempscore[2]=freshman[j].studentcourse[2].coursescore;
						tempscore[3]=freshman[j].studentcourse[3].coursescore;
						break;
					}
				}
				if(flag==0)
					cout<<"此学生不存在，请重试！"<<endl;
				else
				{
					cout<<"请选择你想要修改的信息：1 姓名 2 性别 3 学号"<<endl<<"4 微积分成绩 5 线性代数成绩 6 离散数学成绩 7 计算机程序设计基础成绩"<<endl;
					int reorder=0;std::cin>>reorder;
					cout<<"请输入修改后的信息：";
					if(reorder==1)
						std::cin>>tempname;
					else if(reorder==2)
						std::cin>>tempsex;
					else if(reorder==3)
						std::cin>>tempnumber;
					else if((reorder>=4)&&(reorder<=7))
						std::cin>>tempscore[reorder-4];
					else 
					{
						cout<<"输入指令错误，请重试！"<<endl;
						break;
					}
					freshman[j]=Freshman(tempname,tempsex,tempnumber,tempscore);
					ofstream outfile("freshman.txt",ios::out);
					if(!outfile)
					    throw openerror;
					for(j=0;j<line;j++)
					{
						outfile<<freshman[j].studentname<<" "<<freshman[j].sex<<" "<<freshman[j].studentnumber<<" ";
						outfile<<freshman[j].studentcourse[0].coursescore<<" ";
						outfile<<freshman[j].studentcourse[1].coursescore<<" ";
						outfile<<freshman[j].studentcourse[2].coursescore<<" ";
						outfile<<freshman[j].studentcourse[3].coursescore<<" ";
						outfile<<'\n';
					}
					outfile.close();
					outfile.clear();
					cout<<"修改成功！"<<endl;
				}
				delete []freshman;
			}
			else if(year==2)
			{
				ifstream infile("sophomore.txt",ios::in);
				if(!infile)
					throw openerror;
				while(1)
				{
					infile.getline(buffer,100);
					line++;
					if(infile.peek()==EOF)
						break;
				}
				Sophomore *student=new Sophomore[line];
				std::string tempname;char tempsex;long long tempnumber;double tempscore[6];
				infile.seekg(ios_base::beg);
				for(j=0;j<line;j++)
				{
					infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4]>>tempscore[5];
					infile.getline(buffer,100);
					student[j]=Sophomore(tempname,tempsex,tempnumber,tempscore);
				}
				infile.close();
				infile.clear();
				std::cout<<"请输入你想要修改学生的姓名：";
				std::string name;std::cin>>name;
				for(j=0,flag=0;j<line;j++)
				{
					if(student[j].studentname==name)
					{
						flag=1;
						tempname=student[j].studentname;
						tempsex=student[j].sex;
						tempnumber=student[j].studentnumber;
						tempscore[0]=student[j].studentcourse[0].coursescore;
						tempscore[1]=student[j].studentcourse[1].coursescore;
						tempscore[2]=student[j].studentcourse[2].coursescore;
						tempscore[3]=student[j].studentcourse[3].coursescore;
						tempscore[3]=student[j].studentcourse[4].coursescore;
						tempscore[3]=student[j].studentcourse[5].coursescore;
						break;
					}
				}
				if(flag==0)
					cout<<"此学生不存在，请重试！"<<endl;
				else
				{
					cout<<"请选择你想要修改的信息：1 姓名 2 性别 3 学号"<<endl<<"4 大学物理成绩 5 电动力学成绩 6 数据与算法成绩 7 电子电路与系统基础成绩 8 信号与系统成绩 9 数字与逻辑成绩"<<endl;
					int reorder=0;std::cin>>reorder;
					cout<<"请输入修改后的信息：";
					if(reorder==1)
						std::cin>>tempname;
					else if(reorder==2)
						std::cin>>tempsex;
					else if(reorder==3)
						std::cin>>tempnumber;
					else if((reorder>=4)&&(reorder<=9))
						std::cin>>tempscore[reorder-4];
					else 
					{
						cout<<"输入指令错误，请重试！"<<endl;
						break;
					}
					student[j]=Sophomore(tempname,tempsex,tempnumber,tempscore);
					ofstream outfile("sophomore.txt",ios::out);
					if(!outfile)
					    throw openerror;
					outfile.seekp(ios_base::beg);
					for(j=0;j<line;j++)
					{
						outfile<<student[j].studentname<<" "<<student[j].sex<<" "<<student[j].studentnumber<<" ";
						outfile<<student[j].studentcourse[0].coursescore<<" ";
						outfile<<student[j].studentcourse[1].coursescore<<" ";
						outfile<<student[j].studentcourse[2].coursescore<<" ";
						outfile<<student[j].studentcourse[3].coursescore<<" ";
						outfile<<student[j].studentcourse[4].coursescore<<" ";
						outfile<<student[j].studentcourse[5].coursescore<<" ";
						outfile<<'\n';
					}
					outfile.close();
					outfile.clear();
					cout<<"修改成功！"<<endl;
			    }
				delete []student;
			}
			else if(year==3)
			{
				ifstream infile("junior.txt",ios::in);
				if(!infile)
					throw openerror;
				while(1)
				{
					infile.getline(buffer,100);
					line++;
					if(infile.peek()==EOF)
						break;
				}
				Junior *student=new Junior[line];
				std::string tempname;char tempsex;long long tempnumber;double tempscore[5];
				infile.seekg(ios_base::beg);
				for(j=0;j<line;j++)
				{
					infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4];
					infile.getline(buffer,100);
					student[j]=Junior(tempname,tempsex,tempnumber,tempscore);
				}
				infile.close();
				infile.clear();
				std::cout<<"请输入你想要修改学生的姓名：";
				std::string name;std::cin>>name;
				for(j=0,flag=0;j<line;j++)
				{
					if(student[j].studentname==name)
					{
						flag=1;
						tempname=student[j].studentname;
						tempsex=student[j].sex;
						tempnumber=student[j].studentnumber;
						tempscore[0]=student[j].studentcourse[0].coursescore;
						tempscore[1]=student[j].studentcourse[1].coursescore;
						tempscore[2]=student[j].studentcourse[2].coursescore;
						tempscore[3]=student[j].studentcourse[3].coursescore;
						tempscore[3]=student[j].studentcourse[4].coursescore;
						break;
					}
				}
				if(flag==0)
					cout<<"此学生不存在，请重试！"<<endl;
				else
				{
					cout<<"请选择你想要修改的信息：1 姓名 2 性别 3 学号"<<endl<<"4 量子与统计成绩 5 固体物理成绩 6 通信与网络成绩 7 媒体与认知成绩 8 概率论与随机过程成绩"<<endl;
					int reorder=0;std::cin>>reorder;
					cout<<"请输入修改后的信息：";
					if(reorder==1)
						std::cin>>tempname;
					else if(reorder==2)
						std::cin>>tempsex;
					else if(reorder==3)
						std::cin>>tempnumber;
					else if((reorder>=4)&&(reorder<=8))
						std::cin>>tempscore[reorder-4];
					else 
					{
						cout<<"输入指令错误，请重试！"<<endl;
						break;
					}
					student[j]=Junior(tempname,tempsex,tempnumber,tempscore);
					ofstream outfile("junior.txt",ios::out);
					if(!outfile)
					    throw openerror;
					outfile.seekp(ios_base::beg);
					for(j=0;j<line;j++)
					{
						outfile<<student[j].studentname<<" "<<student[j].sex<<" "<<student[j].studentnumber<<" ";
						outfile<<student[j].studentcourse[0].coursescore<<" ";
						outfile<<student[j].studentcourse[1].coursescore<<" ";
						outfile<<student[j].studentcourse[2].coursescore<<" ";
						outfile<<student[j].studentcourse[3].coursescore<<" ";
						outfile<<student[j].studentcourse[4].coursescore<<" ";
						outfile<<'\n';
					}
					outfile.close();
					outfile.clear();
					cout<<"修改成功！"<<endl;
			    }
				delete []student;
			}
			else if(year==4)
			{
				ifstream infile("graduate.txt",ios::in);
				if(!infile)
					throw openerror;
				while(1)
				{
					infile.getline(buffer,100);
					line++;
					if(infile.peek()==EOF)
						break;
				}
				Graduate *student=new Graduate[line];
				std::string tempname;char tempsex;long long tempnumber;double tempscore[15];
				infile.seekg(ios_base::beg);
				for(j=0;j<line;j++)
				{
					infile>>tempname>>tempsex>>tempnumber;
					for(int k=0;k<15;k++)
						infile>>tempscore[k];
					infile.getline(buffer,100);
					student[j]=Graduate(tempname,tempsex,tempnumber,tempscore);
				}
				infile.close();
				infile.clear();
				std::cout<<"请输入你想要修改学生的姓名：";
				std::string name;std::cin>>name;
				for(j=0,flag=0;j<line;j++)
				{
					if(student[j].studentname==name)
					{
						flag=1;
						tempname=student[j].studentname;
						tempsex=student[j].sex;
						tempnumber=student[j].studentnumber;
						for(int k=0;k<15;k++)
							tempscore[k]=student[j].studentcourse[k].coursescore;
						break;
					}
				}
				if(flag==0)
					cout<<"此学生不存在，请重试！"<<endl;
				else
				{
					cout<<"请选择你想要修改的信息：1 姓名 2 性别 3 学号"<<endl;
					int reorder=0;std::cin>>reorder;
					cout<<"请输入修改后的信息：";
					if(reorder==1)
						std::cin>>tempname;
					else if(reorder==2)
						std::cin>>tempsex;
					else if(reorder==3)
						std::cin>>tempnumber;
					else 
					{
						cout<<"输入指令错误，请重试！"<<endl;
						break;
					}
					student[j]=Graduate(tempname,tempsex,tempnumber,tempscore);
					ofstream outfile("graduate.txt",ios::out);
                    if(!outfile)
						throw openerror;
					outfile.seekp(ios_base::beg);
					for(j=0;j<line;j++)
					{
						outfile<<student[j].studentname<<" "<<student[j].sex<<" "<<student[j].studentnumber<<" ";
						for(int k=0;k<15;k++)
							outfile<<student[j].studentcourse[k].coursescore<<" ";
						outfile<<'\n';
					}
					outfile.close();
					outfile.clear();
					cout<<"修改成功！"<<endl;
			    }
				delete []student;
			}
			else 
				cout<<"输入指令错误，请重试！"<<endl;
			break;
		}
		default:
		{
			throw(inputerror);
			break;
		}
		}
	}
}




					

