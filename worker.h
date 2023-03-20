#pragma once
#include<iostream>
#include<string>
using namespace std;

class  abstructworker
{
public:
	//员工信息
	virtual void workerinfo() = 0;
	//员工职责描述
	virtual void workerdescribe() = 0;

	int m_num;
	int m_wherenum;
	string m_Name;

//private:


};


