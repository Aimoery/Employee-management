#pragma once
#include<iostream>
#include "worker.h"
using namespace std;

class WorkManger
{
public:
	WorkManger();	
	//显示菜单列表
	void showManger();
	void ExitMange();
	//添加职工
	void AddInfo();
	

	//统计文件中的人数
	int personname();
	//删除员工
	void delete_Emp();
	//修改员工
	void Modefy_Emp();
	//查找员工
	void find_Emp();

	//根据员工号进行排序
	void sort_Emp();

	int IsExist_Emp(int id);
	//初始化员工
	void init_Emp();

	//显示职工功能
	void show_Emp();

	//保存文件
	void savefile();

	//清空操作
	void clear_Emp();
	~WorkManger();


	//判断文件是否存在
	bool m_fileexict;
	//记录员工总数
	int sum;
	//新建员工数组的指针
	abstructworker** WorkerArray; //两层指针 即在worker类下还要进行一次新空间创造

};
