#include"manger.h"


Manger::Manger(int num, string name, int wherenum)
{
	this->m_Name = name;
	this->m_num = num;
	this->m_wherenum = wherenum;
}

//������Ϣ
void Manger::workerinfo()
{
	cout << "����" << endl;
}

//����ְ������
void Manger::workerdescribe()
{
	cout << "��������Ϊ��" << m_Name
		<< "\t��������:" << m_wherenum
		<< "\t������Ϊ��" << m_num
		<< "\t��λְ��Ϊ����Ա����������" << endl;
}