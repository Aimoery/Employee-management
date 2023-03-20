#include"employee.h"



Employee::Employee(int num, string name, int wherename)
{
	this->m_Name = name;
	this->m_num = num;
	this->m_wherenum = wherename;
}
//员工信息
void Employee::workerinfo()
{
	cout << "员工" << endl;
}
//员工职责描述
void Employee::workerdescribe()
{
	cout << "员工姓名为：" << m_Name
		<< "\t员工所属:" << m_wherenum
		<< "\t员工工号为：" << m_num 
		<< "\t岗位职责为：听从经理调遣，完成经理安排的任务"<<endl;
}

