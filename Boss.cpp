#include"boss.h"


Boss::Boss(int num, string name, int wherenum)
{
	this->m_Name = name;
	this->m_num = num;
	this->m_wherenum = wherenum;
}

//������Ϣ
void Boss::workerinfo()
{
	cout << "�ܲ�" << endl;
}

//����ְ������
void Boss::workerdescribe()
{
	cout << "�ܲ�����Ϊ��" << m_Name
		<< "\t�ܲ�����:" << m_wherenum
		<< "\t�ܲù���Ϊ��" << m_num
		<< "\t��λְ��Ϊ��������������" << endl;
}