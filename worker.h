#pragma once
#include<iostream>
#include<string>
using namespace std;

class  abstructworker
{
public:
	//Ա����Ϣ
	virtual void workerinfo() = 0;
	//Ա��ְ������
	virtual void workerdescribe() = 0;

	int m_num;
	int m_wherenum;
	string m_Name;

//private:


};


