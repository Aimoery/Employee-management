#include"WorkManger.h"
#include"manger.h"
#include"worker.h"
#include"Boss.h"
#include"employee.h"
#include<fstream>
#define FILENAME "empfile.txt"  //����һ���ļ����Ʊ��ں��ڽ����޸�

WorkManger::WorkManger()
{
	ifstream ifs;//����һ�����ļ�������
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())//����ļ�������
	{
		cout << "�ļ�������" << endl;
		//������ʼ��Ϊ0
		sum = 0;
		//ָ���ʼ��Ϊ��
		WorkerArray = NULL;
		//��ʼ���ļ�Ϊ��
		m_fileexict=false;
		ifs.close();
		return ;
	}
	else
	{
		char ch;
		ifs >> ch;//��ȡһ���ֽ������ж��Ƿ��ļ�Ϊ��  ��ͬ��ifs.get��ch��
		if (ifs.eof())
		{
			cout << "�ļ����ڵ�Ϊ��" << endl;
			//������ʼ��Ϊ0
			sum = 0;
			//ָ���ʼ��Ϊ��
			WorkerArray = NULL;
			//��ʼ���ļ�Ϊ��
			m_fileexict = false;
			ifs.close();
			return;
		}
		else
		{
			//m_fileexict = true;
			cout << "�ļ������Ҳ�Ϊ��" << endl;
			int number = this->personname();
			cout << "ְ������Ϊ" << number << "����" << endl;
			this->sum = number;
			//���ٿռ�
			this->WorkerArray = new abstructworker * [this->sum];
			//���ļ��е����ݣ��浽������
			this->init_Emp();
			for (int i = 0; i < this->sum; i++)
			{
				cout << "���Ϊ" << this->WorkerArray[i]->m_num
					<< "\t����Ϊ" << this->WorkerArray[i]->m_Name
					<< "\tְ��Ϊ" << this->WorkerArray[i]->m_wherenum << endl;
			}
		}
		ifs.close();
	}
}

WorkManger::~WorkManger()
{
	//�ͷŶ����ռ�
	if (WorkerArray != NULL)//�����Ϊ�գ����ÿһ�������ڵ�����
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
	cout << "***��ӭʹ��ְ������ϵͳ***" << endl;
	cout << "******0.�˳��������******" << endl;
	cout << "******1.����ְ����Ϣ******" << endl;
	cout << "******2.��ʾְ����Ϣ******" << endl;
	cout << "******3.ɾ����ְְ��******" << endl;
	cout << "******4.�޸�ְ����Ϣ******" << endl;
	cout << "******5.����ְ����Ϣ******" << endl;
	cout << "******6.���ձ������******" << endl;
	cout << "******7.��������ĵ�******" << endl;
	cout << "**************************" << endl;
	cout << endl;
}

//0���˳�
void WorkManger::ExitMange()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//���ü��˳�
}

//1������Ա����Ϣ
void  WorkManger::AddInfo()
{
	int Newsum;
	cout << "����������Ա������" << endl;
	cin >> Newsum;

	if (Newsum > 0)
	{   //�����µĿռ� ��С��ָ���ָ��[��WorkerManger�����num��WorkerArray]
		//�����¿ռ��С
		int newSize = this->sum + Newsum;
		//�����¿ռ��С��ָ��
		abstructworker** Newspace = new  abstructworker*[newSize];  //���ٵ���ָ�����Ա���Ҫ **  ���߶��ǳ����� ����new
		if (this->sum != NULL)
		{
			for (int i = 0; i < this->sum; i++)
			{
				Newspace[i] = this->WorkerArray[i];//Newspace�ǿռ�
			}
		}
		//����������  
		for (int i = 0; i < Newsum; i++)
		{
			int id; 
			string name;
			int profession;

			cout << "�������" << i+1 << "���˵�id" << endl;
			cin >> id;


			cout << "�������" << i+1 << "���˵�����" << endl;
			cin >> name;

			cout << "��ѡ���" << i+1 << "���˵�ְ��" << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ܲ�" << endl;
			cin >> profession;

			abstructworker* work=NULL;  //�½�ָ����Ϊ��  ��ʵ��ͬ��abstructworker* worker=new �ࣨid��name��1��
			switch (profession)
			{
			case 1:
				work = new Employee(id, name, 1);
				break;
			case 2:
				work = new Manger(id, name, 2);
				break;
			case 3:
				work = new Boss(id, name, 3);  //work�Ǹ���  boss employee��manger������
				break;
			default:
				cout << "û������ְ��" << endl;
				break;
			}
			//����ְ��ָ�룬���浽������
			//this->WorkerArray = new abstructworker * [this->sum];
			Newspace[this->sum + i] = work;//�ҵ�����˶�Ӧ��λ��
		}
		//�ͷ����пռ�
		delete[] this->WorkerArray;
		//���ռ丳ֵ
		this->WorkerArray = Newspace;
		//��¼������Ա����
		this->sum = newSize;
		m_fileexict = true;
		//���ñ���
		this->savefile();
		cout << "�ɹ�����" << Newsum << "��ְ����Ϣ" << endl;
	}
	else
	{
		cout << "��������" << endl;
		
	}
	//system("pause");
	//system("cls");
}

//�������ݵ��ļ���
void WorkManger::savefile()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//����ֱ�����붨�������
	for (int i = 0; i < this->sum; i++)
	{
		ofs <<this->WorkerArray[i]->m_num 
			<< "\t" << this->WorkerArray[i]->m_Name
			 <<"\t" << this->WorkerArray[i]->m_wherenum << endl;
	}
	ofs.close();
}

int WorkManger::personname()//ͳ�Ƴ�Ա����
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

//��ʼ��Ա��
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
			cout << "û������ְ��" << endl;
			system("pause");
			system("cls");
			break;
		}
		this->WorkerArray[index] = worker;
		index++;
	}
	ifs.close();
}

//��ʾְ������
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
			cout << "ְ������Ϊ" << name << "  "
				<< "ְ�����Ϊ" << id << "  "
				<< "ְ����������Ϊ" << did << endl;
		}
	}
	else
	{
		cout << "�洢�б�Ϊ�գ����������Ϣ" << endl;
	}*/
	if (!this->m_fileexict) //Ĭ�ϴ����ļ�
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->sum;i++)
		{
			this->WorkerArray[i]->workerdescribe();//���ö�̬���
		}
	}
}
//ɾ��ְ��
void WorkManger::delete_Emp()
{
	cout << "��������Ҫɾ����Ա����ţ�" << endl;
	int id;
	cin >> id;
	int number=IsExist_Emp(id);
	if (number == -1)
	{
		cout << "���޴��ˣ������Ƿ��������" << endl;
	}
	else
	{
		for (int i = number; i < this->sum; i++)
		{
			this->WorkerArray[i] = this->WorkerArray[i + 1];  //������ǰ
		}
		//���¹�����Ա��Ϣ  ��Ա��-1�����±����ļ�
		cout << "ɾ���ɹ�" << endl;
		this->sum--;
		this->savefile();
	}
	/*system("pause");
	system("cls");*/
}
//�ж�ְ���Ƿ����
int WorkManger::IsExist_Emp(int id)
{
	int index;
	if (!this->m_fileexict) //Ĭ�ϴ����ļ�
	{
		//cout << "�ļ������ڻ���Ϊ��" << endl;
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
				//�������������� 
			}
		}
	}
	return index;
}

void  WorkManger::Modefy_Emp()
{
	cout << "��������Ҫ�޸ĵ�Ա����ţ�" << endl;
	int id;
	cin >> id;
	int number = IsExist_Emp(id);
	if (number == -1)
	{
		cout << "���޴��ˣ������Ƿ��������" << endl;
	}
	else
	{
		string name;
		int did;
		cout << "�������޸ĺ���Ա��������" << endl;
		cin >> name;
		this->WorkerArray[number]->m_Name = name;

		cout << "�������޸ĺ���Ա������ְ��" << endl;
		cin >> did;
		if (did == 1 || did == 2 || did == 3)
		{
			this->WorkerArray[number]->m_wherenum = did;
			this->savefile();
			cout << "�޸ĳɹ�" << endl;
		}
		else
			cout << "�޸�ʧ��" << endl;
		
	}
	//system("pause");
	//system("cls");
}

//����
void WorkManger::find_Emp()
{
	cout << "��������ҷ�ʽ��1��������������  2�����ձ�Ų���" << endl;
	int num;
	cin >> num;
	bool find = false;
	//int ret = 0;
	if (num == 1)
	{
		cout << "��������Ҫ���ҵ�������" << endl;
		string name;
		cin >> name;
		for (int i = 0; i < this->sum; i++)
		{
			if (this->WorkerArray[i]->m_Name == name)
			{
				find = true;
				//ret = i;
				cout << "������Ϣ����" << endl;
				this->WorkerArray[i]->workerdescribe();
			}
		}
	}
	else if (num == 2)
	{
		cout << "��������Ҫ���ҵı�ţ�" << endl;
		int id;
		cin >> id;
		for (int i = 0; i < this->sum; i++)
		{
			if (this->WorkerArray[i]->m_num == id)
			{
				find = true;
				//ret = i;
				cout << "������Ϣ����" << endl;
				this->WorkerArray[i]->workerdescribe();
			}
		}
	}
	else
	{
		cout << "�����������������" << endl;
	}
	if (find == false)
	{
		cout << "�����ڴ���" << endl;
	}
}

//����
void WorkManger::sort_Emp()
{
	if (!this->m_fileexict) //Ĭ�ϴ����ļ�
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		int cho;
		cout << "��ѡ������ʽ" << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;
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
				cout << "����ɹ�" << endl;
				this->savefile();
				this->show_Emp();
				break;
			}
		}
		else
			cout << "�����������" << endl;
	}
}

void  WorkManger::clear_Emp()
{
	cout << "ȷ����գ�"<<endl;
	cout << "1����" << endl;
	cout << "2����" << endl;
	int select;
	cin >> select;

	if (select == 1)
	{
		ofstream  ofs(FILENAME, ios::trunc);//trunc����ֱ�Ӷ��ļ���������ؽ�����
		ofs.close();  //�ر��ļ�


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
		cout << "������" << endl;
	}
}