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
		std::cout<<setfill('*')<<setw(28)<<'*'<<" ��ѡ�����¹��� "<<setfill('*')<<setw(29)<<'*'<<std::endl;
	    std::cout<<setfill('*')<<setw(28)<<'*'<<" 1 ¼��ѧ����Ϣ "<<setfill('*')<<setw(29)<<'*'<<std::endl;
	    std::cout<<setfill('*')<<setw(28)<<'*'<<" 2 ��ѯѧ����Ϣ "<<setfill('*')<<setw(29)<<'*'<<std::endl;
	    std::cout<<setfill('*')<<setw(28)<<'*'<<" 3 ��ѯ�γ���Ϣ "<<setfill('*')<<setw(29)<<'*'<<std::endl;
	    std::cout<<setfill('*')<<setw(28)<<'*'<<" 4 �޸�ѧ����Ϣ "<<setfill('*')<<setw(29)<<'*'<<std::endl;
	    std::cout<<setfill('*')<<setw(28)<<'*'<<" ����  �˳�ϵͳ "<<setfill('*')<<setw(29)<<'*'<<std::endl;
	    std::cin>>order;
	    switch(order)
	    {
	    case 1://¼�빦��
		{
			std::cout<<"��ѡ����¼��ѧ�����꼶��1 һ�꼶 2 ���꼶 3 ���꼶 4 ��ҵ��"<<std::endl;
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
							std::cout<<"ѧ����Ϣ�Ѵ��ڣ������ԣ�"<<std::endl;
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
						cout<<"¼��ɹ�!"<<endl;
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
							std::cout<<"ѧ����Ϣ�Ѵ��ڣ������ԣ�"<<std::endl;
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
						cout<<"¼��ɹ���"<<endl;
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
							std::cout<<"ѧ����Ϣ�Ѵ��ڣ������ԣ�"<<std::endl;
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
						cout<<"¼��ɹ���"<<endl;
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
							std::cout<<"ѧ����Ϣ�Ѵ��ڣ������ԣ�"<<std::endl;
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
						cout<<"¼��ɹ���"<<endl;
					}
				    break;
			    }
		    default:
				{
					std::cout<<"�����꼶���������ԣ�"<<std::endl;
		        	break;
				}
			}
			break;
		}
		case 2://��ѯѧ����Ϣ�Ĺ���
		{
			int way;char buffer[100];
			for(int m=0;m<100;m++)
				buffer[m]=' ';
			std::cout<<"��ѡ���ѯ��ʽ��1 ���� 2 ѧ��"<<std::endl;
			std::cin>>way;
			if((way!=1)&&(way!=2))
			{
				std::cout<<"����ָ����������ԣ�"<<std::endl;
				order=0;
			}
			else if(way==1)
			{
				std::cout<<"������������"<<std::endl;
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
				    cout<<"��ѧ�������ڣ������ԣ�"<<endl;
			}
			else if(way==2)
            {
				std::cout<<"������ѧ�ţ�"<<std::endl;
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
					std::cout<<"��ѧ�������ڣ������ԣ�"<<endl;
			}
			break;
		}
		case 3://��ѯ�γ���Ϣ�Ĺ���
		{
			std::cout<<"��������Ҫ��ѯ�Ŀγ�����"<<std::endl;
			std::string temp;
			std::cin>>temp;
			std::string tempname;char tempsex;long long tempnumber;char buffer[100];
			for(int m=0;m<100;m++)
				buffer[m]=' ';
			if((temp=="΢����")||(temp=="���Դ���")||(temp=="��ɢ��ѧ")||(temp=="�����������ƻ���"))
			{
				ifstream infile("freshman.txt",ios_base::in);double tempscore[4];
				if(!infile)
					throw openerror;
				if(temp=="΢����")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"����"<<setw(5)<<"�Ա�"<<setw(12)<<"ѧ��"<<setw(5)<<"�ɼ�";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
						infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[0];
					}
					cout<<endl;
				}
				else if(temp=="���Դ���")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"����"<<setw(5)<<"�Ա�"<<setw(12)<<"ѧ��"<<setw(5)<<"�ɼ�";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[1];
					}
					cout<<endl;
				}
				else if(temp=="��ɢ��ѧ")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"����"<<setw(5)<<"�Ա�"<<setw(12)<<"ѧ��"<<setw(5)<<"�ɼ�";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[2];
					}
					cout<<endl;
				}
				else if(temp=="�����������ƻ���")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"����"<<setw(5)<<"�Ա�"<<setw(12)<<"ѧ��"<<setw(5)<<"�ɼ�";
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
			else if((temp=="��ѧ����")||(temp=="�綯��ѧ")||(temp=="�������㷨")||(temp=="���ӵ�·��ϵͳ����")
				||(temp=="�ź���ϵͳ")||(temp=="�������߼�"))
			{
				ifstream infile("sophomore.txt",ios_base::in);double tempscore[6];
				if(!infile)
					throw openerror;
				if(temp=="��ѧ����")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"����"<<setw(5)<<"�Ա�"<<setw(12)<<"ѧ��"<<setw(5)<<"�ɼ�";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4]>>tempscore[5];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[0];
					}
					cout<<endl;
				}
				else if(temp=="�綯��ѧ")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"����"<<setw(5)<<"�Ա�"<<setw(12)<<"ѧ��"<<setw(5)<<"�ɼ�";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4]>>tempscore[5];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[1];
					}
					cout<<endl;
				}
				else if(temp=="�������㷨")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"����"<<setw(5)<<"�Ա�"<<setw(12)<<"ѧ��"<<setw(5)<<"�ɼ�";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4]>>tempscore[5];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[2];
					}
					cout<<endl;
				}
				else if(temp=="���ӵ�·��ϵͳ����")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"����"<<setw(5)<<"�Ա�"<<setw(12)<<"ѧ��"<<setw(5)<<"�ɼ�";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4]>>tempscore[5];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[3];
					}
					cout<<endl;
				}
				else if(temp=="�ź���ϵͳ")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"����"<<setw(5)<<"�Ա�"<<setw(12)<<"ѧ��"<<setw(5)<<"�ɼ�";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4]>>tempscore[5];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[4];
					}
					cout<<endl;
				}
				else if(temp=="�������߼�")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"����"<<setw(5)<<"�Ա�"<<setw(12)<<"ѧ��"<<setw(5)<<"�ɼ�";
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
			else if((temp=="������ͳ��")||(temp=="��������")||(temp=="ͨ��������")||(temp=="ý������֪")
				||(temp=="���������������"))
			{
				ifstream infile("junior.txt",ios_base::in);double tempscore[5];
				if(!infile)
					throw openerror;
				if(temp=="������ͳ��")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"����"<<setw(5)<<"�Ա�"<<setw(12)<<"ѧ��"<<setw(5)<<"�ɼ�";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[0];
					}
					cout<<endl;
				}
				else if(temp=="��������")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"����"<<setw(5)<<"�Ա�"<<setw(12)<<"ѧ��"<<setw(5)<<"�ɼ�";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[1];
					}
					cout<<endl;
				}
				else if(temp=="ͨ��������")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"����"<<setw(5)<<"�Ա�"<<setw(12)<<"ѧ��"<<setw(5)<<"�ɼ�";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[2];
					}
					cout<<endl;
				}
				else if(temp=="ý������֪")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"����"<<setw(5)<<"�Ա�"<<setw(12)<<"ѧ��"<<setw(5)<<"�ɼ�";
					infile.seekg(ios_base::beg);
					for(i=0;infile.peek()!=EOF;i++)
					{
					    infile>>tempname>>tempsex>>tempnumber>>tempscore[0]>>tempscore[1]>>tempscore[2]>>tempscore[3]>>tempscore[4];
						infile.getline(buffer,100);
					    std::cout<<endl<<setfill(' ')<<setw(10)<<tempname<<setw(5)<<tempsex<<setw(12)<<tempnumber<<setw(5)<<tempscore[3];
					}
					cout<<endl;
				}
				else if(temp=="���������������")
				{
					std::cout<<setiosflags(ios_base::left)<<setfill(' ')<<setw(10)<<"����"<<setw(5)<<"�Ա�"<<setw(12)<<"ѧ��"<<setw(5)<<"�ɼ�";
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
				cout<<"�γ̲����ڣ������ԣ�"<<endl;
			break;
		}
		case 4://�޸�ѧ����Ϣ�Ĺ���
		{
			std::cout<<"����������Ҫ�޸�ѧ�����꼶��1 һ�꼶 2 ���꼶 3 ���꼶 4 ��ҵ��"<<std::endl;
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
				std::cout<<"����������Ҫ�޸�ѧ����������";
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
					cout<<"��ѧ�������ڣ������ԣ�"<<endl;
				else
				{
					cout<<"��ѡ������Ҫ�޸ĵ���Ϣ��1 ���� 2 �Ա� 3 ѧ��"<<endl<<"4 ΢���ֳɼ� 5 ���Դ����ɼ� 6 ��ɢ��ѧ�ɼ� 7 �����������ƻ����ɼ�"<<endl;
					int reorder=0;std::cin>>reorder;
					cout<<"�������޸ĺ����Ϣ��";
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
						cout<<"����ָ����������ԣ�"<<endl;
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
					cout<<"�޸ĳɹ���"<<endl;
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
				std::cout<<"����������Ҫ�޸�ѧ����������";
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
					cout<<"��ѧ�������ڣ������ԣ�"<<endl;
				else
				{
					cout<<"��ѡ������Ҫ�޸ĵ���Ϣ��1 ���� 2 �Ա� 3 ѧ��"<<endl<<"4 ��ѧ����ɼ� 5 �綯��ѧ�ɼ� 6 �������㷨�ɼ� 7 ���ӵ�·��ϵͳ�����ɼ� 8 �ź���ϵͳ�ɼ� 9 �������߼��ɼ�"<<endl;
					int reorder=0;std::cin>>reorder;
					cout<<"�������޸ĺ����Ϣ��";
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
						cout<<"����ָ����������ԣ�"<<endl;
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
					cout<<"�޸ĳɹ���"<<endl;
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
				std::cout<<"����������Ҫ�޸�ѧ����������";
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
					cout<<"��ѧ�������ڣ������ԣ�"<<endl;
				else
				{
					cout<<"��ѡ������Ҫ�޸ĵ���Ϣ��1 ���� 2 �Ա� 3 ѧ��"<<endl<<"4 ������ͳ�Ƴɼ� 5 ��������ɼ� 6 ͨ��������ɼ� 7 ý������֪�ɼ� 8 ��������������̳ɼ�"<<endl;
					int reorder=0;std::cin>>reorder;
					cout<<"�������޸ĺ����Ϣ��";
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
						cout<<"����ָ����������ԣ�"<<endl;
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
					cout<<"�޸ĳɹ���"<<endl;
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
				std::cout<<"����������Ҫ�޸�ѧ����������";
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
					cout<<"��ѧ�������ڣ������ԣ�"<<endl;
				else
				{
					cout<<"��ѡ������Ҫ�޸ĵ���Ϣ��1 ���� 2 �Ա� 3 ѧ��"<<endl;
					int reorder=0;std::cin>>reorder;
					cout<<"�������޸ĺ����Ϣ��";
					if(reorder==1)
						std::cin>>tempname;
					else if(reorder==2)
						std::cin>>tempsex;
					else if(reorder==3)
						std::cin>>tempnumber;
					else 
					{
						cout<<"����ָ����������ԣ�"<<endl;
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
					cout<<"�޸ĳɹ���"<<endl;
			    }
				delete []student;
			}
			else 
				cout<<"����ָ����������ԣ�"<<endl;
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




					

