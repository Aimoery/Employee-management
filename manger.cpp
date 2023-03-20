#include"manger.h"


Manger::Manger(int num, string name, int wherenum)
{
	this->m_Name = name;
	this->m_num = num;
	this->m_wherenum = wherenum;
}

//经理信息
void Manger::workerinfo()
{
	cout << "经理" << endl;
}

//经理职责所在
void Manger::workerdescribe()
{
	cout << "经理姓名为：" << m_Name
		<< "\t经理所属:" << m_wherenum
		<< "\t经理工号为：" << m_num
		<< "\t岗位职责为：给员工布置任务" << endl;
}