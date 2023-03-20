#include"WorkManger.h"
#include"manger.h"
#include"worker.h"
#include"Boss.h"
#include"employee.h"
#include<fstream>
#define FILENAME "empfile.txt"  //定义一个文件名称便于后期进行修改

WorkManger::WorkManger()
{
	ifstream ifs;//建立一个读文件数据流
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())//如果文件不存在
	{
		cout << "文件不存在" << endl;
		//人数初始化为0
		sum = 0;
		//指针初始化为空
		WorkerArray = NULL;
		//初始化文件为空
		m_fileexict=false;
		ifs.close();
		return ;
	}
	else
	{
		char ch;
		ifs >> ch;//读取一个字节用于判定是否文件为空  等同于ifs.get（ch）
		if (ifs.eof())
		{
			cout << "文件存在但为空" << endl;
			//人数初始化为0
			sum = 0;
			//指针初始化为空
			WorkerArray = NULL;
			//初始化文件为空
			m_fileexict = false;
			ifs.close();
			return;
		}
		else
		{
			//m_fileexict = true;
			cout << "文件存在且不为空" << endl;
			int number = this->personname();
			cout << "职工人数为" << number << "个人" << endl;
			this->sum = number;
			//开辟空间
			this->WorkerArray = new abstructworker * [this->sum];
			//将文件中的数据，存到数组中
			this->init_Emp();
			for (int i = 0; i < this->sum; i++)
			{
				cout << "编号为" << this->WorkerArray[i]->m_num
					<< "\t姓名为" << this->WorkerArray[i]->m_Name
					<< "\t职务为" << this->WorkerArray[i]->m_wherenum << endl;
			}
		}
		ifs.close();
	}
}

WorkManger::~WorkManger()
{
	//释放堆区空间
	if (WorkerArray != NULL)//如果不为空，清空每一个数组内的内容
	{
		for (int i = 0; i < this->sum; i++)
		{
			delete this->WorkerArray[i];
		}
		delete[] this->WorkerArray;
		WorkerArray = NULL;
	}
		
	
}

void WorkManger::showManger()
{
	cout << "**************************" << endl;
	cout << "***欢迎使用职工管理系统***" << endl;
	cout << "******0.退出管理程序******" << endl;
	cout << "******1.增加职工信息******" << endl;
	cout << "******2.显示职工信息******" << endl;
	cout << "******3.删除离职职工******" << endl;
	cout << "******4.修改职工信息******" << endl;
	cout << "******5.查找职工信息******" << endl;
	cout << "******6.按照编号排序******" << endl;
	cout << "******7.清空所有文档******" << endl;
	cout << "**************************" << endl;
	cout << endl;
}

//0、退出
void WorkManger::ExitMange()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//调用即退出
}

//1、增加员工信息
void  WorkManger::AddInfo()
{
	int Newsum;
	cout << "请输入增加员工数量" << endl;
	cin >> Newsum;

	if (Newsum > 0)
	{   //创建新的空间 大小及指向的指针[与WorkerManger里面的num和WorkerArray]
		//计算新空间大小
		int newSize = this->sum + Newsum;
		//开辟新空间大小的指针
		abstructworker** Newspace = new  abstructworker*[newSize];  //开辟的是指针所以必须要 **  两边都是抽象类 进行new
		if (this->sum != NULL)
		{
			for (int i = 0; i < this->sum; i++)
			{
				Newspace[i] = this->WorkerArray[i];//Newspace是空间
			}
		}
		//输入新数据  
		for (int i = 0; i < Newsum; i++)
		{
			int id; 
			string name;
			int profession;

			cout << "请输入第" << i+1 << "个人的id" << endl;
			cin >> id;


			cout << "请输入第" << i+1 << "个人的姓名" << endl;
			cin >> name;

			cout << "请选择第" << i+1 << "个人的职务" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、总裁" << endl;
			cin >> profession;

			abstructworker* work=NULL;  //新建指针置为空  其实等同于abstructworker* worker=new 类（id，name，1）
			switch (profession)
			{
			case 1:
				work = new Employee(id, name, 1);
				break;
			case 2:
				work = new Manger(id, name, 2);
				break;
			case 3:
				work = new Boss(id, name, 3);  //work是父类  boss employee和manger是子类
				break;
			default:
				cout << "没有这种职务！" << endl;
				break;
			}
			//创建职工指针，保存到数组中
			//this->WorkerArray = new abstructworker * [this->sum];
			Newspace[this->sum + i] = work;//找到这个人对应的位置
		}
		//释放已有空间
		delete[] this->WorkerArray;
		//将空间赋值
		this->WorkerArray = Newspace;
		//记录现在人员个数
		this->sum = newSize;
		m_fileexict = true;
		//调用保存
		this->savefile();
		cout << "成功新增" << Newsum << "个职工信息" << endl;
	}
	else
	{
		cout << "输入有误" << endl;
		
	}
	//system("pause");
	//system("cls");
}

//保存数据到文件中
void WorkManger::savefile()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//可以直接输入定义的名字
	for (int i = 0; i < this->sum; i++)
	{
		ofs <<this->WorkerArray[i]->m_num 
			<< "\t" << this->WorkerArray[i]->m_Name
			 <<"\t" << this->WorkerArray[i]->m_wherenum << endl;
	}
	ofs.close();
}

int WorkManger::personname()//统计成员人数
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	string name;
	int id;
	int did;
	int num=0;
	while(ifs >> id && ifs >> name && ifs >> did)
	{	
		num++;
	}
		
	ifs.close();
	return num;
}

//初始化员工
void WorkManger::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	string name;
	int id;
	int did;
	//int num = 0;
	//abstructworker* worker=NULL;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		abstructworker* worker = NULL;
		switch (did)
		{
		case 1:
			worker = new Employee(id, name, 1);
			break;
		case 2:
			worker = new Manger(id, name, 2);
			break;
		case 3:
			worker = new Boss(id, name, 3);
			break;
		default:
			cout << "没有这种职务！" << endl;
			system("pause");
			system("cls");
			break;
		}
		this->WorkerArray[index] = worker;
		index++;
	}
	ifs.close();
}

//显示职工功能
void WorkManger::show_Emp()
{/*
	if  (sum != 0)
	{
		ifstream ifs;
		ifs.open(FILENAME, ios::in);

		string name;
		int id;
		int did;

		for (int i = 0; i < sum; i++)
		{
			ifs >> id;
			ifs >> name;
			ifs >> did;
			cout << "职工姓名为" << name << "  "
				<< "职工编号为" << id << "  "
				<< "职工所属部门为" << did << endl;
		}
	}
	else
	{
		cout << "存储列表为空，请先添加信息" << endl;
	}*/
	if (!this->m_fileexict) //默认存在文件
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->sum;i++)
		{
			this->WorkerArray[i]->workerdescribe();//利用多态输出
		}
	}
}
//删除职工
void WorkManger::delete_Emp()
{
	cout << "请输入需要删除的员工编号：" << endl;
	int id;
	cin >> id;
	int number=IsExist_Emp(id);
	if (number == -1)
	{
		cout << "查无此人，请检查是否输入错误" << endl;
	}
	else
	{
		for (int i = number; i < this->sum; i++)
		{
			this->WorkerArray[i] = this->WorkerArray[i + 1];  //后移向前
		}
		//重新管理人员信息  人员数-1，重新保存文件
		cout << "删除成功" << endl;
		this->sum--;
		this->savefile();
	}
	/*system("pause");
	system("cls");*/
}
//判定职工是否存在
int WorkManger::IsExist_Emp(int id)
{
	int index;
	if (!this->m_fileexict) //默认存在文件
	{
		//cout << "文件不存在或者为空" << endl;
		index = -1;
	}
	else
	{ 
	
		for (int i = 0; i < this->sum; i++)
		{
			if (this->WorkerArray[i]->m_num == id)
			{
				index = i;
				break;
				//不考虑重名现象 
			}
		}
	}
	return index;
}

void  WorkManger::Modefy_Emp()
{
	cout << "请输入需要修改的员工编号：" << endl;
	int id;
	cin >> id;
	int number = IsExist_Emp(id);
	if (number == -1)
	{
		cout << "查无此人，请检查是否输入错误" << endl;
	}
	else
	{
		string name;
		int did;
		cout << "请输入修改后人员的姓名：" << endl;
		cin >> name;
		this->WorkerArray[number]->m_Name = name;

		cout << "请输入修改后人员的所属职务：" << endl;
		cin >> did;
		if (did == 1 || did == 2 || did == 3)
		{
			this->WorkerArray[number]->m_wherenum = did;
			this->savefile();
			cout << "修改成功" << endl;
		}
		else
			cout << "修改失败" << endl;
		
	}
	//system("pause");
	//system("cls");
}

//查找
void WorkManger::find_Emp()
{
	cout << "请输入查找方式：1、按照姓名查找  2、按照编号查找" << endl;
	int num;
	cin >> num;
	bool find = false;
	//int ret = 0;
	if (num == 1)
	{
		cout << "请输入需要查找的姓名：" << endl;
		string name;
		cin >> name;
		for (int i = 0; i < this->sum; i++)
		{
			if (this->WorkerArray[i]->m_Name == name)
			{
				find = true;
				//ret = i;
				cout << "此人信息如下" << endl;
				this->WorkerArray[i]->workerdescribe();
			}
		}
	}
	else if (num == 2)
	{
		cout << "请输入需要查找的编号：" << endl;
		int id;
		cin >> id;
		for (int i = 0; i < this->sum; i++)
		{
			if (this->WorkerArray[i]->m_num == id)
			{
				find = true;
				//ret = i;
				cout << "此人信息如下" << endl;
				this->WorkerArray[i]->workerdescribe();
			}
		}
	}
	else
	{
		cout << "输入错误，请重新输入" << endl;
	}
	if (find == false)
	{
		cout << "不存在此人" << endl;
	}
}

//排序
void WorkManger::sort_Emp()
{
	if (!this->m_fileexict) //默认存在文件
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		int cho;
		cout << "请选择排序方式" << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;
		cin >> cho;

		if (cho == 1 || cho == 2)
		{
			for (int i = 0; i < this->sum; i++)
			{
				int minnum = i;
				for (int j = i + 1; j < this->sum; j++)
				{

					if (cho == 1)
					{
						if (this->WorkerArray[minnum]->m_num > this->WorkerArray[j]->m_num)
							minnum = j;
					}
					else
					{
						if (this->WorkerArray[minnum]->m_num < this->WorkerArray[j]->m_num)
							minnum = j;
					}
				}
				if (i != minnum)
				{
					abstructworker* temp = this->WorkerArray[i];
					this->WorkerArray[i] = this->WorkerArray[minnum];
					this->WorkerArray[minnum] = temp;
				}
				cout << "排序成功" << endl;
				this->savefile();
				this->show_Emp();
				break;
			}
		}
		else
			cout << "输入错误，请检查" << endl;
	}
}

void  WorkManger::clear_Emp()
{
	cout << "确认清空？"<<endl;
	cout << "1、是" << endl;
	cout << "2、否" << endl;
	int select;
	cin >> select;

	if (select == 1)
	{
		ofstream  ofs(FILENAME, ios::trunc);//trunc可以直接对文件进行清空重建操作
		ofs.close();  //关闭文件


		if (this->WorkerArray != NULL)
		{
			for (int i = 0; i < this->sum; i++)
			{
				delete this->WorkerArray[i];
				this->WorkerArray[i]= NULL;
			}
			delete[] this->WorkerArray;
			WorkerArray = NULL;
			sum = 0;
			m_fileexict = false;
		}
		cout << "清空完成" << endl;
	}
}