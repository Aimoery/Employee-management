#include<iostream>
using namespace std;
#include"WorkManger.h"
#include"manger.h"
#include"worker.h"
#include"Boss.h"
#include"employee.h"

int main()
{
	int num;
	WorkManger wm;
	//wm.showManger();	
	
	//abstructworker* worker = new Employee(1,"zhangsan",1);  //父类调用 但是在子类创建
	//worker->workerdescribe();
	//delete worker;

	//abstructworker* worker2 = new Boss(2, "lisi", 2);
	//worker2->workerdescribe();
	//delete worker2;


	//abstructworker* worker3 = new Manger(2, "lisi", 3);
	//worker3->workerdescribe();
	//delete worker3;

	while (1)
	{
		wm.showManger();
		cout << "请输入你的选择（标号前数字）：" << endl;
		cin >> num;

		switch (num)
		{
		case 0://退出管理程序
			wm.ExitMange();
			break;
		case 1://增加职工信息
			wm.AddInfo();  //增加信息 统一各类数组
			break;
		case 2://显示职工信息
			wm.show_Emp();  //利用多态输出
			break;
		case 3://删除离职职工
		//{
			/*int ret = wm.IsExist_Emp(1);
			cout << ret << endl;*/
			wm.delete_Emp();  //用后一个的地址覆盖前一个
			break;
		//}
		case 4:	//4.修改职工信息
			wm.Modefy_Emp();  //遍历找到需求，然后进行重新输入
			break;
		case 5:	//5.查找职工信息
			wm.find_Emp();  //遍历
			break;
		case 6:	//6.按照编号排序
			wm.sort_Emp();  //选择排序  先赋值第一个，然后不断地更改确认值
			break;
		case 7:	//7.清空所有文档
			wm.clear_Emp();
			break;
		default:
			system("cls");
		}
		system("pause");
		system("cls");
	}
	return 0;
}