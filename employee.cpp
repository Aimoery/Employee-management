#include"employee.h"



Employee::Employee(int num, string name, int wherename)
{
	this->m_Name = name;
	this->m_num = num;
	this->m_wherenum = wherename;
}
//Ա����Ϣ
void Employee::workerinfo()
{
	cout << "Ա��" << endl;
}
//Ա��ְ������
void Employee::workerdescribe()
{
	cout << "Ա������Ϊ��" << m_Name
		<< "\tԱ������:" << m_wherenum
		<< "\tԱ������Ϊ��" << m_num 
		<< "\t��λְ��Ϊ�����Ӿ����ǲ����ɾ����ŵ�����"<<endl;
}

