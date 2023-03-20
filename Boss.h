#pragma once
#include"worker.h"

class Boss :public abstructworker
{
public:
	Boss(int num, string name, int wherenum);

	//领导信息
	void workerinfo();

	//领导职责所在
	void workerdescribe();
};
