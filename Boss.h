#pragma once
#include"worker.h"

class Boss :public abstructworker
{
public:
	Boss(int num, string name, int wherenum);

	//�쵼��Ϣ
	void workerinfo();

	//�쵼ְ������
	void workerdescribe();
};
