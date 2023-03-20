#include"boss.h"


Boss::Boss(int num, string name, int wherenum)
{
	this->m_Name = name;
	this->m_num = num;
	this->m_wherenum = wherenum;
}

//经理信息
void Boss::workerinfo()
{
	cout << "总裁" << endl;
}

//经理职责所在
void Boss::workerdescribe()
{
	cout << "总裁姓名为：" << m_Name
		<< "\t总裁所属:" << m_wherenum
		<< "\t总裁工号为：" << m_num
		<< "\t岗位职责为：给经理布置任务" << endl;
}