#pragma once
#include<iostream>
#include<string>
#include"worker.h"


using namespace std;

class Employee :public abstructworker
{

public:
	Employee(int num, string name, int wherename);

	//Ա����Ϣ
	virtual void workerinfo();

	//Ա��ְ������
	virtual void workerdescribe();



};
