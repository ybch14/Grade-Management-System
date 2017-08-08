#ifndef MY_H_FILE
#define MY_H_FILE
#include <iostream>
#include <string>
#define Freshman_credit 14
#define Sophomore_credit 20
#define Junior_credit 17
using namespace std;
struct Course
{
	std::string coursename;
	std::string coursetype;
	long long int coursenumber;
	int coursecredit;
	double coursescore;
};
class Student
{
public:
	Student();
	Student(std::string s_name,long long int s_studentnumber,char s_sex,struct Course *s_studentcourse,
		int s_coursenumber);
	Student(const Student &ref);
	virtual ~Student();
	virtual double calculategpa()=0;
	friend void functions();
protected:
	std::string studentname;
	long long int studentnumber;
	char sex;
	Course studentcourse[15];
	int number_of_course;
};
class Freshman:virtual public Student
{
public:
	Freshman();
	Freshman(std::string f_name,char f_sex,long long int f_studentnumber,double f_score[]);
	Freshman(const Freshman &ref);
	virtual ~Freshman();
	virtual double calculategpa();
	double calculate_freshman_math_average();
	double calculate_freshman_programming_average();
	bool operator==(const Freshman &ref);
	friend ostream & operator<<(ostream &os,const Freshman &ref);
	friend istream & operator>>(istream &is,Freshman &ref);
	friend void functions();
protected:
	double freshman_gpa;
	double freshman_math_average;
	double freshman_programming_average;
};
class Sophomore:virtual public Student
{
public:
	Sophomore();
	Sophomore(std::string s_name,char s_sex,long long int s_studentnumber,double s_score[]);
	Sophomore(const Sophomore &ref);
	virtual ~Sophomore();
	virtual double calculategpa();
	double calculate_sophomore_physics_average();
	double calculate_sophomore_circuit_average();
	double calculate_sophomore_programming_avreage();
	bool operator==(const Sophomore &ref);
	friend ostream & operator<<(ostream &os,const Sophomore &ref);
	friend istream & operator>>(istream &is,Sophomore &ref);
	friend void functions();
protected:
	double sophomore_gpa;
	double sophomore_physics_average;
	double sophomore_programming_average;
	double sophomore_circuit_average;
};
class Junior:virtual public Student
{
public:
	Junior();
	Junior(std::string j_name,char j_sex,long long int j_studentnumber,double j_score[]);
	Junior(const Junior &ref);
	virtual ~Junior();
	virtual double calculategpa();
	double calculate_junior_physics_average();
	double calculate_junior_circuit_average();
	double calculate_junior_math_average();
	bool operator==(const Junior &ref);
	friend ostream & operator<<(ostream &os,const Junior &ref);
	friend istream & operator>>(istream &is, Junior &ref);
	friend void functions();
protected:
	double junior_gpa;
	double junior_physics_average;
	double junior_circuit_average;
	double junior_math_average;
};
class Graduate:public Freshman,public Sophomore,public Junior
{
public:
	Graduate();
	Graduate(std::string g_name,char g_sex,long long int g_studentnumber,double g_score[]);
	Graduate(const Graduate &ref);
	~Graduate();
	double calculategpa();
	double calculate_math_average();
	double calculate_physics_average();
	double calculate_circuit_average();
	double calculate_programming_average();
	bool operator==(const Graduate &ref);
	friend ostream & operator<<(ostream &os,const Graduate &ref);
	friend istream & operator>>(istream &is,Graduate &ref);
	friend void functions();
private:
	double gpa;
	double math_average;
	double physics_average;
	double programming_average;
	double circuit_average;
};
#endif