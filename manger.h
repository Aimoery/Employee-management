#pragma once
#include<iostream>
#include<string>
#include"worker.h"

class Manger :public abstructworker
{
public:
	Manger(int num, string name, int wherenum);

	//������Ϣ
	void workerinfo();

	//����ְ������
	void workerdescribe();
};
