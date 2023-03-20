#pragma once
#include<iostream>
#include<string>
#include"worker.h"

class Manger :public abstructworker
{
public:
	Manger(int num, string name, int wherenum);

	//经理信息
	void workerinfo();

	//经理职责所在
	void workerdescribe();
};
