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
	
	//abstructworker* worker = new Employee(1,"zhangsan",1);  //������� ���������ഴ��
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
		cout << "���������ѡ�񣨱��ǰ���֣���" << endl;
		cin >> num;

		switch (num)
		{
		case 0://�˳��������
			wm.ExitMange();
			break;
		case 1://����ְ����Ϣ
			wm.AddInfo();  //������Ϣ ͳһ��������
			break;
		case 2://��ʾְ����Ϣ
			wm.show_Emp();  //���ö�̬���
			break;
		case 3://ɾ����ְְ��
		//{
			/*int ret = wm.IsExist_Emp(1);
			cout << ret << endl;*/
			wm.delete_Emp();  //�ú�һ���ĵ�ַ����ǰһ��
			break;
		//}
		case 4:	//4.�޸�ְ����Ϣ
			wm.Modefy_Emp();  //�����ҵ�����Ȼ�������������
			break;
		case 5:	//5.����ְ����Ϣ
			wm.find_Emp();  //����
			break;
		case 6:	//6.���ձ������
			wm.sort_Emp();  //ѡ������  �ȸ�ֵ��һ����Ȼ�󲻶ϵظ���ȷ��ֵ
			break;
		case 7:	//7.��������ĵ�
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