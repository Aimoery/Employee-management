#pragma once
#include<iostream>
#include "worker.h"
using namespace std;

class WorkManger
{
public:
	WorkManger();	
	//��ʾ�˵��б�
	void showManger();
	void ExitMange();
	//���ְ��
	void AddInfo();
	

	//ͳ���ļ��е�����
	int personname();
	//ɾ��Ա��
	void delete_Emp();
	//�޸�Ա��
	void Modefy_Emp();
	//����Ա��
	void find_Emp();

	//����Ա���Ž�������
	void sort_Emp();

	int IsExist_Emp(int id);
	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ������
	void show_Emp();

	//�����ļ�
	void savefile();

	//��ղ���
	void clear_Emp();
	~WorkManger();


	//�ж��ļ��Ƿ����
	bool m_fileexict;
	//��¼Ա������
	int sum;
	//�½�Ա�������ָ��
	abstructworker** WorkerArray; //����ָ�� ����worker���»�Ҫ����һ���¿ռ䴴��

};
