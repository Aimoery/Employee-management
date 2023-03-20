#pragma once
#include<iostream>
#include<string>
#include"worker.h"


using namespace std;

class Employee :public abstructworker
{

public:
	Employee(int num, string name, int wherename);

	//员工信息
	virtual void workerinfo();

	//员工职责描述
	virtual void workerdescribe();



};
