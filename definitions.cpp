#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "scores.h"
using namespace std;
int i=0,sumcredit=0;
double sumscore=0.0;
Course Freshman_course[4]={
	{"微积分","math",10421055,5,0.0},
	{"线性代数","math",10421094,4,0.0},
	{"离散数学","math",40420393,3,0.0},
	{"计算机程序设计基础","programming",30230672,2,0.0}};
Course Sophomore_course[6]={
	{"大学物理","physics",10430934,4,0.0},
	{"电动力学","physics",30230024,4,0.0},
	{"数据与算法","programming",20230253,3,0.0},
	{"电子电路与系统基础","circuit",30230822,2,0.0},
	{"信号与系统","circuit",30230104,4,0.0},
	{"数字与逻辑","circuit",30230793,3,0.0}};
Course Junior_course[5]={
	{"量子与统计","physics",20430094,4,0.0},
	{"固体物理","physics",80230814,4,0.0},
	{"通信与网络","circuit",30230964,4,0.0},
	{"媒体与认知","circuit",30230832,2,0.0},
	{"概率论与随机过程","math",30230783,3,0.0}};
Course All_course[15]={
	{"微积分","math",10421055,5,0.0},
	{"线性代数","math",10421094,4,0.0},
	{"离散数学","math",40420393,3,0.0},
	{"计算机程序设计基础","programming",30230672,2,0.0},
	{"大学物理","physics",10430934,4,0.0},
	{"电动力学","physics",30230024,4,0.0},
	{"数据与算法","programming",20230253,3,0.0},
	{"电子电路与系统基础","circuit",30230822,2,0.0},
	{"信号与系统","circuit",30230104,4,0.0},
	{"数字与逻辑","circuit",30230793,3,0.0},
	{"量子与统计","physics",20430094,4,0.0},
	{"固体物理","physics",80230814,4,0.0},
	{"通信与网络","circuit",30230964,4,0.0},
	{"媒体与认知","circuit",30230832,2,0.0},
	{"概率论与随机过程","math",30230783,3,0.0}};
Student::Student()
{
	studentname="none";
	studentnumber=0;
	sex='m';
	number_of_course=0;
	for(i=0;i<number_of_course;i++)
		studentcourse[i]=Freshman_course[i];
}
Student::Student(std::string s_name,long long int s_studentnumber,char s_sex,Course *s_studentcourse,int s_coursenumber)
{
	studentname=s_name;
	studentnumber=s_studentnumber;
	sex=s_sex;
	number_of_course=s_coursenumber;
	for(i=0;i<number_of_course;i++)
		studentcourse[i]=s_studentcourse[i];
}
Student::Student(const Student &ref)
{
	studentname=ref.studentname;
	studentnumber=ref.studentnumber;
	sex=ref.sex;
	number_of_course=ref.number_of_course;
	for(i=0;i<number_of_course;i++)
		studentcourse[i]=ref.studentcourse[i];
}
Student::~Student(){}
////////////////////////////////
Freshman::Freshman():Student("none",0,'m',Freshman_course,4)
{
	freshman_gpa=calculategpa();
	freshman_math_average=calculate_freshman_math_average();
	freshman_programming_average=calculate_freshman_programming_average();
}
Freshman::Freshman(std::string f_name,char f_sex,long long int f_studentnumber,double f_score[])
	:Student(f_name,f_studentnumber,f_sex,Freshman_course,4)
{
	for(i=0;i<4;i++)
		studentcourse[i].coursescore=f_score[i];
	freshman_gpa=calculategpa();
	freshman_math_average=calculate_freshman_math_average();
	freshman_programming_average=calculate_freshman_programming_average();
}
Freshman::Freshman(const Freshman &ref)
{
	studentname=ref.studentname;
	studentnumber=ref.studentnumber;
	sex=ref.sex;
	number_of_course=ref.number_of_course;
	for(i=0;i<number_of_course;i++)
		studentcourse[i]=ref.studentcourse[i];
	freshman_gpa=ref.freshman_gpa;
	freshman_math_average=ref.freshman_math_average;
	freshman_programming_average=ref.freshman_programming_average;
}
Freshman::~Freshman(){}
double Freshman::calculategpa()
{
	for(i=0,sumscore=0.0,sumcredit=0;i<number_of_course;i++)
	{
		sumscore+=studentcourse[i].coursescore*(double)studentcourse[i].coursecredit;
		sumcredit+=studentcourse[i].coursecredit;
	}
	return sumscore/(double)sumcredit;
}
double Freshman::calculate_freshman_math_average()
{
	for(i=0,sumscore=0.0,sumcredit=0;i<3;i++)
	{
		sumscore+=studentcourse[i].coursescore*(double)studentcourse[i].coursecredit;
		sumcredit+=studentcourse[i].coursecredit;
	}
	return sumscore/(double)sumcredit;
}
double Freshman::calculate_freshman_programming_average()
{
	return studentcourse[3].coursescore;
}
////////////////////////////////
Sophomore::Sophomore():Student("none",0,'m',Sophomore_course,6)
{
	sophomore_gpa=calculategpa();
	sophomore_physics_average=calculate_sophomore_physics_average();
	sophomore_programming_average=calculate_sophomore_programming_avreage();
	sophomore_circuit_average=calculate_sophomore_circuit_average();
}
Sophomore::Sophomore(std::string s_name,char s_sex,long long int s_studentnumber,double s_score[])
	:Student(s_name,s_studentnumber,s_sex,Sophomore_course,6)
{
	for(i=0;i<6;i++)
		studentcourse[i].coursescore=s_score[i];
	sophomore_gpa=calculategpa();
	sophomore_physics_average=calculate_sophomore_physics_average();
	sophomore_programming_average=calculate_sophomore_programming_avreage();
	sophomore_circuit_average=calculate_sophomore_circuit_average();
}
Sophomore::Sophomore(const Sophomore &ref)
{
	studentname=ref.studentname;
	studentnumber=ref.studentnumber;
	sex=ref.sex;
	number_of_course=ref.number_of_course;
	for(i=0;i<number_of_course;i++)
		studentcourse[i]=ref.studentcourse[i];
	sophomore_gpa=ref.sophomore_gpa;
	sophomore_physics_average=ref.sophomore_physics_average;
	sophomore_programming_average=ref.sophomore_programming_average;
	sophomore_circuit_average=ref.sophomore_circuit_average;
}
Sophomore::~Sophomore(){}
double Sophomore::calculategpa()
{
	for(i=0,sumscore=0.0,sumcredit=0;i<number_of_course;i++)
	{
		sumscore+=studentcourse[i].coursescore*(double)studentcourse[i].coursecredit;
		sumcredit+=studentcourse[i].coursecredit;
	}
	return sumscore/(double)sumcredit;
}
double Sophomore::calculate_sophomore_physics_average()
{
	for(i=0,sumscore=0.0,sumcredit=0;i<2;i++)
	{
		sumscore+=studentcourse[i].coursescore*(double)studentcourse[i].coursecredit;
		sumcredit+=studentcourse[i].coursecredit;
	}
	return sumscore/(double)sumcredit;
}
double Sophomore::calculate_sophomore_programming_avreage()
{
	return studentcourse[2].coursescore;
}
double Sophomore::calculate_sophomore_circuit_average()
{
	for(i=3,sumscore=0.0,sumcredit=0;i<6;i++)
	{
		sumscore+=studentcourse[i].coursescore*(double)studentcourse[i].coursecredit;
		sumcredit+=studentcourse[i].coursecredit;
	}
	return sumscore/(double)sumcredit;
}
////////////////////////////////
Junior::Junior():Student("none",0,'m',Junior_course,5)
{
	junior_gpa=calculategpa();
	junior_physics_average=calculate_junior_physics_average();
	junior_circuit_average=calculate_junior_circuit_average();
	junior_math_average=calculate_junior_math_average();
}
Junior::Junior(std::string j_name,char j_sex,long long int j_studentnumber,double j_score[])
	:Student(j_name,j_studentnumber,j_sex,Junior_course,5)
{
	for(i=0;i<5;i++)
		studentcourse[i].coursescore=j_score[i];
	junior_gpa=calculategpa();
	junior_physics_average=calculate_junior_physics_average();
	junior_circuit_average=calculate_junior_circuit_average();
	junior_math_average=calculate_junior_math_average();
}
Junior::Junior(const Junior &ref)
{
	studentname=ref.studentname;
	studentnumber=ref.studentnumber;
	sex=ref.sex;
	number_of_course=ref.number_of_course;
	for(i=0;i<number_of_course;i++)
		studentcourse[i]=ref.studentcourse[i];
	junior_gpa=ref.junior_gpa;
	junior_physics_average=ref.junior_physics_average;
	junior_circuit_average=ref.junior_circuit_average;
	junior_math_average=ref.junior_math_average;
}
Junior::~Junior(){}
double Junior::calculategpa()
{
	for(i=0,sumscore=0.0,sumcredit=0;i<number_of_course;i++)
	{
		sumscore+=studentcourse[i].coursescore*(double)studentcourse[i].coursecredit;
		sumcredit+=studentcourse[i].coursecredit;
	}
	return sumscore/(double)sumcredit;
}
double Junior::calculate_junior_physics_average()
{
	for(i=0,sumscore=0.0,sumcredit=0;i<2;i++)
	{
		sumscore+=studentcourse[i].coursescore*(double)studentcourse[i].coursecredit;
		sumcredit+=studentcourse[i].coursecredit;
	}
	return sumscore/(double)sumcredit;
}
double Junior::calculate_junior_circuit_average()
{
	for(i=2,sumscore=0.0,sumcredit=0;i<4;i++)
	{
		sumscore+=studentcourse[i].coursescore*(double)studentcourse[i].coursecredit;
		sumcredit+=studentcourse[i].coursecredit;
	}
	return sumscore/(double)sumcredit;
}
double Junior::calculate_junior_math_average()
{
	return studentcourse[4].coursescore;
}
////////////////////////////////
Graduate::Graduate():Freshman(),Sophomore(),Junior()
{
	number_of_course=15;
	for(i=0;i<number_of_course;i++)
		studentcourse[i]=All_course[i];
	gpa=calculategpa();
	math_average=calculate_math_average();
	physics_average=calculate_physics_average();
	programming_average=calculate_programming_average();
	circuit_average=calculate_circuit_average();
}
Graduate::Graduate(std::string g_name,char g_sex,long long int g_studentnumber,double g_score[])
	:Student(g_name,g_studentnumber,g_sex,All_course,15)
{
	for(i=0;i<15;i++)
		studentcourse[i].coursescore=g_score[i];
	gpa=calculategpa();
	math_average=calculate_math_average();
	physics_average=calculate_physics_average();
	programming_average=calculate_programming_average();
	circuit_average=calculate_circuit_average();
}
Graduate::Graduate(const Graduate &ref)
{
	studentname=ref.studentname;
	studentnumber=ref.studentnumber;
	sex=ref.sex;
	number_of_course=ref.number_of_course;
	for(i=0;i<number_of_course;i++)
		studentcourse[i]=ref.studentcourse[i];
	freshman_gpa=ref.freshman_gpa;
	freshman_math_average=ref.freshman_math_average;
	freshman_programming_average=ref.freshman_programming_average;
	sophomore_gpa=ref.sophomore_gpa;
	sophomore_physics_average=ref.sophomore_physics_average;
	sophomore_programming_average=ref.sophomore_programming_average;
	sophomore_circuit_average=ref.sophomore_circuit_average;
	junior_gpa=ref.junior_gpa;
	junior_physics_average=ref.junior_physics_average;
	junior_circuit_average=ref.junior_circuit_average;
	junior_math_average=ref.junior_math_average;
	gpa=ref.gpa;
	math_average=ref.math_average;
	physics_average=ref.physics_average;
	programming_average=ref.programming_average;
	circuit_average=ref.circuit_average;
}
Graduate::~Graduate(){}
double Graduate::calculategpa()
{
	double g_gpa=0.0;int g_credit=0;
	for(i=0,g_gpa=0.0,g_credit=0;i<number_of_course;i++)
	{
		g_gpa+=studentcourse[i].coursescore*studentcourse[i].coursecredit;
		g_credit+=studentcourse[i].coursecredit;
	}
	return g_gpa/(double)g_credit;
}
double Graduate::calculate_math_average()
{
	double g_math_sum=0.0;int g_math_credit=0;
	for(i=0,g_math_sum=0.0,g_math_credit=0;i<3;i++)
	{
		g_math_sum+=studentcourse[i].coursescore*studentcourse[i].coursecredit;
		g_math_credit+=studentcourse[i].coursecredit;
	}
	g_math_sum+=studentcourse[14].coursescore*studentcourse[14].coursecredit;
	g_math_credit+=studentcourse[14].coursecredit;
	return g_math_sum/(double)g_math_credit;
}
double Graduate::calculate_physics_average()
{
	double g_physics_sum=0.0;int g_physics_credit=0;
	for(i=4,g_physics_sum=0.0,g_physics_credit=0;i<6;i++)
	{
		g_physics_sum+=studentcourse[i].coursescore*studentcourse[i].coursecredit;
		g_physics_credit+=studentcourse[i].coursecredit;
	}
	for(i=10;i<12;i++)
	{
		g_physics_sum+=studentcourse[i].coursescore*studentcourse[i].coursecredit;
		g_physics_credit+=studentcourse[i].coursecredit;
	}
	return g_physics_sum/(double)g_physics_credit;
}
double Graduate::calculate_programming_average()
{
	double g_programming_sum=0.0;int g_programming_credit=0;
	g_programming_sum=studentcourse[3].coursescore*studentcourse[3].coursecredit+studentcourse[6].coursescore*studentcourse[6].coursecredit;
	g_programming_credit=studentcourse[3].coursecredit+studentcourse[6].coursecredit;
	return g_programming_sum/(double)g_programming_credit;
}
double Graduate::calculate_circuit_average()
{
	double g_circuit_sum=0.0;int g_circuit_credit=0;
	for(i=7,g_circuit_sum=0.0,g_circuit_credit=0;i<10;i++)
	{
		g_circuit_sum+=studentcourse[i].coursescore*studentcourse[i].coursecredit;
		g_circuit_credit+=studentcourse[i].coursecredit;
	}
	for(i=12;i<14;i++)
	{
		g_circuit_sum+=studentcourse[i].coursescore*studentcourse[i].coursecredit;
		g_circuit_credit+=studentcourse[i].coursecredit;
	}
	return g_circuit_sum/(double)g_circuit_credit;
}
//operators
ostream & operator<<(ostream &os,const Freshman &ref)
{
	os<<setfill(' ')<<setiosflags(ios_base::left)<<setw(10)<<ref.studentname<<setw(3)<<ref.sex<<setw(12)<<ref.studentnumber<<"一年级"<<endl;
	os<<"本学年课程："<<endl;
	os<<setw(20)<<"课程名"<<setw(12)<<"课程号"<<setw(5)<<"学分"<<setw(8)<<"成绩"<<endl;
	for(i=0;i<ref.number_of_course;i++)
		os<<setw(20)<<ref.studentcourse[i].coursename<<setw(12)<<ref.studentcourse[i].coursenumber
			<<setw(5)<<ref.studentcourse[i].coursecredit<<setw(8)<<ref.studentcourse[i].coursescore<<endl;
	os<<" 学分绩："<<ref.freshman_gpa<<endl<<" 数学课程平均分："<<ref.freshman_math_average<<endl
		<<" 程序设计平均分："<<ref.freshman_programming_average<<endl;
	return os;
}
istream & operator>>(istream &is,Freshman &ref)
{
    cout<<"请按以下顺序输入学生信息：姓名 性别 学号"<<endl;
	is>>ref.studentname>>ref.sex>>ref.studentnumber;
	cout<<"请按以下顺序输入学生成绩：微积分 线性代数 离散数学 计算机程序设计基础"<<endl;
	double input_score[4]={0,0,0,0};
	for(i=0;i<4;i++)
		is>>input_score[i];
	ref=Freshman(ref.studentname,ref.sex,ref.studentnumber,input_score);
	return is;
}
ostream & operator<<(ostream &os,const Sophomore &ref)
{
	os<<setfill(' ')<<setiosflags(ios_base::left)<<setw(10)<<ref.studentname<<setw(2)<<ref.sex<<setw(12)<<ref.studentnumber<<"二年级"<<endl;
	os<<"本学年课程："<<endl;
	os<<setw(20)<<"课程名"<<setw(12)<<"课程号"<<setw(5)<<"学分"<<setw(8)<<"成绩"<<endl;
	for(i=0;i<ref.number_of_course;i++)
		os<<setw(20)<<ref.studentcourse[i].coursename<<setw(12)<<ref.studentcourse[i].coursenumber
			<<setw(5)<<ref.studentcourse[i].coursecredit<<setw(8)<<ref.studentcourse[i].coursescore<<endl;
	os<<" 学分绩："<<ref.sophomore_gpa<<endl<<" 物理课程平均分："<<ref.sophomore_physics_average<<endl
		<<" 程序设计平均分："<<ref.sophomore_programming_average<<endl<<" 电路课程平均分："<<ref.sophomore_circuit_average<<endl;
	return os;
}
istream & operator>>(istream &is,Sophomore &ref)
{
	cout<<"请按以下顺序输入学生信息：姓名 性别 学号"<<endl;
	is>>ref.studentname>>ref.sex>>ref.studentnumber;
	cout<<"请按以下顺序输入学生成绩：大学物理 电动力学 数据与算法 电子电路与系统基础 信号与系统 数字与逻辑"<<endl;
	double input_score[6]={0,0,0,0,0,0};
	for(i=0;i<6;i++)
		is>>input_score[i];
	ref=Sophomore(ref.studentname,ref.sex,ref.studentnumber,input_score);
	return is;
}
ostream & operator<<(ostream &os,const Junior &ref)
{
	os<<setfill(' ')<<setiosflags(ios_base::left)<<setw(10)<<ref.studentname<<setw(2)<<ref.sex<<setw(12)<<ref.studentnumber<<"三年级"<<endl;
	os<<"本学年课程："<<endl;
	os<<setw(20)<<"课程名"<<setw(12)<<"课程号"<<setw(5)<<"学分"<<setw(8)<<"成绩"<<endl;
	for(i=0;i<ref.number_of_course;i++)
	    os<<setw(20)<<ref.studentcourse[i].coursename<<setw(8)<<ref.studentcourse[i].coursenumber
			<<setw(5)<<ref.studentcourse[i].coursecredit<<setw(8)<<ref.studentcourse[i].coursescore<<endl;
	os<<" 学分绩："<<ref.junior_gpa<<endl<<" 物理课程平均分："<<ref.junior_physics_average<<endl
		<<" 电路课程平均分："<<ref.junior_circuit_average<<endl<<" 数学课程平均分："<<ref.junior_math_average<<endl;
	return os;
}
istream & operator>>(istream &is,Junior &ref)
{
	cout<<"请按以下顺序输入学生信息：姓名 性别 学号"<<endl;
	is>>ref.studentname>>ref.sex>>ref.studentnumber;
	cout<<"请按以下顺序输入学生成绩：量子与统计 固体物理 通信与网络 媒体与认知 概率论与随机过程"<<endl;
	double input_score[5]={0,0,0,0,0};
	for(i=0;i<4;i++)
		is>>input_score[i];
	ref=Junior(ref.studentname,ref.sex,ref.studentnumber,input_score);
	return is;
}
ostream & operator<<(ostream &os,const Graduate &ref)
{
	os<<setfill(' ')<<setiosflags(ios_base::left)<<setw(10)<<ref.studentname<<setw(2)<<ref.sex<<setw(12)<<ref.studentnumber<<"毕业生"<<endl;
	os<<"一年级课程："<<endl;
	os<<setw(20)<<"课程名"<<setw(12)<<"课程号"<<setw(5)<<"学分"<<setw(8)<<"成绩"<<endl;
	for(i=0;i<4;i++)
		os<<setw(20)<<ref.studentcourse[i].coursename<<setw(12)<<ref.studentcourse[i].coursenumber
			<<setw(5)<<ref.studentcourse[i].coursecredit<<setw(8)<<ref.studentcourse[i].coursescore<<endl;
	os<<"二年级课程："<<endl;
	os<<setw(20)<<"课程名"<<setw(12)<<"课程号"<<setw(5)<<"学分"<<setw(8)<<"成绩"<<endl;
	for(i=4;i<10;i++)
		os<<setw(20)<<ref.studentcourse[i].coursename<<setw(12)<<ref.studentcourse[i].coursenumber
		    <<setw(5)<<ref.studentcourse[i].coursecredit<<setw(8)<<ref.studentcourse[i].coursescore<<endl;
	os<<"三年级课程："<<endl;
	os<<setw(20)<<"课程名"<<setw(12)<<"课程号"<<setw(5)<<"学分"<<setw(8)<<"成绩"<<endl;
	for(i=10;i<15;i++)
		os<<setw(20)<<ref.studentcourse[i].coursename<<setw(12)<<ref.studentcourse[i].coursenumber
		    <<setw(5)<<ref.studentcourse[i].coursecredit<<setw(8)<<ref.studentcourse[i].coursescore<<endl;
    os<<" 总学分绩："<<ref.gpa<<endl<<" 物理课程总平均分："<<ref.physics_average<<endl
		<<" 电路课程总平均分："<<ref.circuit_average<<endl<<" 数学课程总平均分："<<ref.math_average<<endl
		<<" 程序设计总平均分："<<ref.programming_average<<endl;
	return os;
}
istream & operator>>(istream &is,Graduate &ref)
{
	cout<<"请按以下顺序输入学生信息：姓名 性别 学号"<<endl;
	is>>ref.studentname>>ref.sex>>ref.studentnumber;
	double input_score[15];
	cout<<"请按以下顺序输入学生大三成绩：量子与统计 固体物理 通信与网络 媒体与认知 概率论与随机过程"<<endl;
	for(i=10;i<15;i++)
		is>>input_score[i];
	cout<<"请按以下顺序输入学生大一成绩：微积分 线性代数 离散数学 计算机程序设计基础"<<endl;
	for(i=0;i<4;i++)
		is>>input_score[i];
	cout<<"请按以下顺序输入学生大二成绩：大学物理 电动力学 数据与算法 电子电路与系统基础 信号与系统 数字与逻辑"<<endl;
	for(i=4;i<10;i++)
		is>>input_score[i];
	ref=Graduate(ref.studentname,ref.sex,ref.studentnumber,input_score);
	return is;
}
bool Freshman::operator==(const Freshman &ref)
{
	if(studentname!=ref.studentname)
		return false;
	else
	{
		if(studentnumber!=ref.studentnumber)
			return false;
		else
		{
			if(sex!=ref.sex)
				return false;
			else
			    return true;
		}
	}
}
bool Sophomore::operator==(const Sophomore &ref)
{
	if(studentname!=ref.studentname)
		return false;
	else
	{
		if(studentnumber!=ref.studentnumber)
			return false;
		else
		{
			if(sex!=ref.sex)
				return false;
			else
			    return true;
		}
	}
}
bool Junior::operator==(const Junior &ref)
{
	if(studentname!=ref.studentname)
		return false;
	else
	{
		if(studentnumber!=ref.studentnumber)
			return false;
		else
		{
			if(sex!=ref.sex)
				return false;
			else
			    return true;
		}
	}
}
bool Graduate::operator==(const Graduate &ref)
{
	if(studentname!=ref.studentname)
		return false;
	else
	{
		if(studentnumber!=ref.studentnumber)
			return false;
		else
		{
			if(sex!=ref.sex)
				return false;
			else
			    return true;
		}
	}
}
////////////////////////////////
void preface(void)
{
	cout<<setfill(' ')<<setw(33)<<" "<<setfill('*')<<setw(5)<<"*"<<endl;
	cout<<setfill(' ')<<setw(31)<<" "<<setfill('*')<<setw(9)<<"*"<<endl;
	cout<<setfill(' ')<<setw(31)<<" "<<setfill('*')<<setw(11)<<"*"<<endl;
	cout<<setfill(' ')<<setw(27)<<" "<<setfill('*')<<setw(3)<<"*";
	cout<<setfill(' ')<<setw(3)<<" "<<setfill('*')<<setw(11)<<"*"<<endl;
	cout<<setfill(' ')<<setw(25)<<" "<<setfill('*')<<setw(7)<<"*";
	cout<<setfill(' ')<<setw(3)<<" "<<setfill('*')<<setw(11)<<"*"<<endl;
	cout<<setfill(' ')<<setw(23)<<" "<<setfill('*')<<setw(11)<<"*";
	cout<<setfill(' ')<<setw(3)<<" "<<setfill('*')<<setw(11)<<"*"<<endl;
	cout<<setfill(' ')<<setw(21)<<" "<<setfill('*')<<setw(15)<<"*";
	cout<<setfill(' ')<<setw(3)<<" "<<setfill('*')<<setw(11)<<"*"<<endl;
	cout<<setfill(' ')<<setw(19)<<" "<<setfill('*')<<setw(8)<<"*";
	cout<<setfill(' ')<<setw(3)<<" "<<setfill('*')<<setw(8)<<"*";
	cout<<setfill(' ')<<setw(3)<<" "<<setfill('*')<<setw(11)<<"*"<<endl;
	cout<<setfill(' ')<<setw(17)<<" "<<setfill('*')<<setw(8)<<"*";
	cout<<"   *   "<<setfill('*')<<setw(8)<<"*"<<"   ";
	cout<<setfill('*')<<setw(11)<<'*'<<endl;
	cout<<setfill(' ')<<setw(15)<<' '<<setfill('*')<<setw(8)<<"*";
	cout<<"   *****   "<<setfill('*')<<setw(8)<<"*"<<"   ";
	cout<<setfill('*')<<setw(11)<<"*"<<endl;
	cout<<setfill(' ')<<setw(13)<<' '<<setfill('*')<<setw(8)<<"*";
	cout<<"   "<<setfill('*')<<setw(9)<<"*"<<"   "<<setfill('*')<<setw(8)<<"*"<<"   ";
	cout<<setfill('*')<<setw(11)<<"*"<<endl;
	cout<<setfill(' ')<<setw(11)<<' '<<setfill('*')<<setw(12)<<"*";
	cout<<"   "<<setfill('*')<<setw(9)<<"*"<<"   "<<setfill('*')<<setw(8)<<"*"<<"   ";
	cout<<setfill('*')<<setw(11)<<"*"<<endl;
	cout<<setfill(' ')<<setw(9)<<' '<<setfill('*')<<setw(16)<<"*";
	cout<<"   "<<setfill('*')<<setw(9)<<"*"<<"   "<<setfill('*')<<setw(8)<<"*"<<"   ";
	cout<<setfill('*')<<setw(11)<<"*"<<endl;
	cout<<setfill(' ')<<setw(7)<<' '<<setfill('*')<<setw(8)<<"*"<<"   "<<setfill('*')<<setw(9)<<"*";
	cout<<"   "<<setfill('*')<<setw(9)<<"*"<<"   "<<setfill('*')<<setw(8)<<"*"<<"   ";
	cout<<setfill('*')<<setw(11)<<"*"<<endl;
	cout<<setfill(' ')<<setw(5)<<' '<<setfill('*')<<setw(8)<<"*"<<"   *   "<<setfill('*')<<setw(9)<<"*";
	cout<<"   "<<setfill('*')<<setw(9)<<"*"<<"   "<<setfill('*')<<setw(8)<<"*"<<"   ";
	cout<<setfill('*')<<setw(11)<<"*"<<endl;
	cout<<setfill(' ')<<setw(3)<<' '<<setfill('*')<<setw(8)<<"*"<<"   *****   "<<setfill('*')<<setw(9)<<"*";
	cout<<"   "<<setfill('*')<<setw(9)<<"*"<<"   "<<setfill('*')<<setw(8)<<"*"<<"   ";
	cout<<setfill('*')<<setw(11)<<"*"<<endl;
	cout<<setfill(' ')<<setw(1)<<' '<<setfill('*')<<setw(8)<<"*"<<"   *********   "<<setfill('*')<<setw(9)<<"*";
	cout<<"   "<<setfill('*')<<setw(9)<<"*"<<"   "<<setfill('*')<<setw(8)<<"*"<<"   ";
	cout<<setfill('*')<<setw(11)<<"*"<<endl;
	cout<<setfill('*')<<setw(11)<<"*"<<"   "<<setfill('*')<<setw(9)<<"*"<<"   "<<setfill('*')<<setw(9)<<"*";
	cout<<"   "<<setfill('*')<<setw(9)<<"*"<<"   "<<setfill('*')<<setw(8)<<"*"<<"   ";
	cout<<setfill('*')<<setw(10)<<"*"<<endl;
	cout<<setfill(' ')<<setw(1)<<' '<<setfill('*')<<setw(12)<<"*"<<"   "<<setfill('*')<<setw(9)<<"*"<<"   "<<setfill('*')<<setw(9)<<"*";
	cout<<"   "<<setfill('*')<<setw(9)<<"*"<<"   "<<setfill('*')<<setw(5)<<"*"<<"   ";
	cout<<setfill('*')<<setw(10)<<"*"<<endl;
	cout<<setfill(' ')<<setw(3)<<' '<<setfill('*')<<setw(12)<<"*"<<"   "<<setfill('*')<<setw(9)<<"*"<<"   "<<setfill('*')<<setw(9)<<"*";
	cout<<"   "<<setfill('*')<<setw(9)<<"*"<<"   "<<setfill('*')<<setw(1)<<"*"<<"   ";
	cout<<setfill('*')<<setw(10)<<"*"<<endl;
	cout<<setfill(' ')<<setw(5)<<' '<<setfill('*')<<setw(12)<<"*"<<"   "<<setfill('*')<<setw(9)<<"*"<<"   "<<setfill('*')<<setw(9)<<"*";
	cout<<"   "<<setfill('*')<<setw(9)<<"*"<<"   "<<setfill('*')<<setw(10)<<"*"<<endl;
	cout<<setfill(' ')<<setw(7)<<' '<<setfill('*')<<setw(12)<<"*"<<"   "<<setfill('*')<<setw(9)<<"*"<<"   "<<setfill('*')<<setw(9)<<"*";
	cout<<"   "<<setfill('*')<<setw(18)<<"*"<<endl;
    cout<<setfill(' ')<<setw(9)<<' '<<setfill('*')<<setw(12)<<"*"<<"   "<<setfill('*')<<setw(9)<<"*"<<"   "<<setfill('*')<<setw(9)<<"*";
	cout<<"   "<<setfill('*')<<setw(14)<<"*"<<endl;
	cout<<setfill(' ')<<setw(11)<<' '<<setfill('*')<<setw(12)<<"*"<<"   "<<setfill('*')<<setw(9)<<"*"<<"   "<<setfill('*')<<setw(9)<<"*";
	cout<<"   "<<setfill('*')<<setw(10)<<"*"<<endl;
	cout<<setfill(' ')<<setw(13)<<' '<<setfill('*')<<setw(12)<<"*"<<"   "<<setfill('*')<<setw(9)<<"*"<<"   "<<setfill('*')<<setw(5)<<"*";
	cout<<"   "<<setfill('*')<<setw(10)<<"*"<<endl;
	cout<<setfill(' ')<<setw(15)<<' '<<setfill('*')<<setw(12)<<"*"<<"   "<<setfill('*')<<setw(9)<<"*"<<"   "<<setfill('*')<<setw(1)<<"*";
	cout<<"   "<<setfill('*')<<setw(10)<<"*"<<endl;
	cout<<setfill(' ')<<setw(17)<<' '<<setfill('*')<<setw(12)<<"*"<<"   "<<setfill('*')<<setw(9)<<"*";
	cout<<"   "<<setfill('*')<<setw(10)<<"*"<<endl;
	cout<<setfill(' ')<<setw(19)<<' '<<setfill('*')<<setw(12)<<"*"<<"   "<<setfill('*')<<setw(18)<<"*"<<endl;
	cout<<setfill(' ')<<setw(21)<<' '<<setfill('*')<<setw(12)<<"*"<<"   "<<setfill('*')<<setw(14)<<"*"<<endl;
	cout<<setfill(' ')<<setw(23)<<' '<<setfill('*')<<setw(12)<<"*"<<"   "<<setfill('*')<<setw(10)<<"*"<<endl;
	cout<<setfill(' ')<<setw(25)<<' '<<setfill('*')<<setw(12)<<"*"<<"   "<<setfill('*')<<setw(6)<<"*"<<endl;
	cout<<setfill(' ')<<setw(27)<<' '<<setfill('*')<<setw(12)<<"*"<<"   "<<setfill('*')<<setw(2)<<"*"<<endl;
	cout<<setfill(' ')<<setw(29)<<' '<<setfill('*')<<setw(12)<<"*"<<endl;
	cout<<setfill(' ')<<setw(31)<<' '<<setfill('*')<<setw(9)<<"*"<<endl;
	cout<<setfill(' ')<<setw(33)<<' '<<setfill('*')<<setw(5)<<"*"<<endl;
	cout<<endl;
	cout<<setfill('*')<<setw(31)<<'*'<<" 欢迎使用 "<<setfill('*')<<setw(32)<<'*'<<endl
		    <<setfill('*')<<setw(24)<<'*'<<" 电子工程系成绩管理系统 "<<setfill('*')<<setw(25)<<'*'<<endl;
}	 
