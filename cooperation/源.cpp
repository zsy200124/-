
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include<mysql.h>
void lianjie()
{
	MYSQL mysql, *sock;
	mysql_init(&mysql);   //��ʼ��MYSQL����
	sock = mysql_real_connect(&mysql, "localhost", "root", "020866", "ͼ������", 3306, NULL, 0);
	if (sock == NULL)//�������ݿ�
	{
		printf("\n�������ݿ�ʱ��������!\n");
		cout << mysql_error(&mysql) << endl;
		exit(0);
	}
	else
		printf("\n�������ݿ�ɹ�!\n");
}
void showreader()
{
	MYSQL mysql;
	mysql_init(&mysql);   //��ʼ��MYSQL����
	MYSQL_RES* result;
	MYSQL_ROW row;
	int num;        //������Ž��������
	int i;
	mysql_real_connect(&mysql, "localhost", "root", "020866", "ku", 3306, NULL, 0);
	mysql_query(&mysql, "set names gbk");
	mysql_query(&mysql, "select * from ������Ϣ��");
	result = mysql_store_result(&mysql);    //����ѯ���Ľ�������浽result��
	num = mysql_num_fields(result);        //�������������ŵ�num��
	cout << "ѧ��	     ����֤��    ����	 �༶   �ȼ�" << endl;
	while ((row = mysql_fetch_row(result)))  //�������һ�У�����ֹѭ��
	{
		for (i = 0; i < num; i++)         //����forѭ����������е�ÿһ��
		{
			cout << row[i] << "\t";    //row��MYSQL_ROW���������Ե�������ʹ�ã�iΪ����
		}
		cout << endl;
	}
	mysql_free_result(result);     //�ͷŽ������ռ�õ��ڴ�
	mysql_close(&mysql); //�ͷ����ݿ�
	getchar();
}
void showbook()
{
	MYSQL mysql;
	mysql_init(&mysql);   //��ʼ��MYSQL����
	MYSQL_RES* result;
	MYSQL_ROW row;
	int num;        //������Ž��������
	int i;
	mysql_real_connect(&mysql, "localhost", "root", "020866", "ku", 3306, NULL, 0);
	mysql_query(&mysql, "set names gbk");
	mysql_query(&mysql, "select * from ͼ����Ϣ��");
	result = mysql_store_result(&mysql);    //����ѯ���Ľ�������浽result��
	num = mysql_num_fields(result);        //�������������ŵ�num��
	cout << "��� ����     ����    ������      ����������     ���    ���   ���������   ��ǰ�����   �ѽ������" << endl;
	while ((row = mysql_fetch_row(result)))  //�������һ�У�����ֹѭ��
	{
		for (i = 0; i < num; i++)         //����forѭ����������е�ÿһ��
		{
			cout << row[i] << "\t";    //row��MYSQL_ROW���������Ե�������ʹ�ã�iΪ����
		}
		cout << endl;
	}
	mysql_free_result(result);     //�ͷŽ������ռ�õ��ڴ�
	mysql_close(&mysql); //�ͷ����ݿ�
	getchar();
}
void showjieyue()
{
	MYSQL mysql;
	mysql_init(&mysql);   //��ʼ��MYSQL����
	MYSQL_RES* result;
	MYSQL_ROW row;
	int num;        //������Ž��������
	int i;
	mysql_real_connect(&mysql, "localhost", "root", "020866", "ku", 3306, NULL, 0);
	mysql_query(&mysql, "set names gbk");
	mysql_query(&mysql, "select * from ����ͼ���");
	result = mysql_store_result(&mysql);    //����ѯ���Ľ�������浽result��
	num = mysql_num_fields(result);        //�������������ŵ�num��
	cout << "���    ����    ���   ����֤��  ��������      ��������     ������" << endl;
	while ((row = mysql_fetch_row(result)))  //�������һ�У�����ֹѭ��
	{
		for (i = 0; i < num; i++)         //����forѭ����������е�ÿһ��
		{
			cout << row[i] << "\t";    //row��MYSQL_ROW���������Ե�������ʹ�ã�iΪ����
		}
		cout << endl;
	}
	mysql_free_result(result);     //�ͷŽ������ռ�õ��ڴ�
	mysql_close(&mysql); //�ͷ����ݿ�
	getchar();
}
void insertreader()
{
	MYSQL mysql;
	char c_array[200]{ 0 };
	mysql_init(&mysql);   //��ʼ��MYSQL����
	string banji, xing, jie, deng;
	int  xue;
	mysql_real_connect(&mysql, "localhost", "root", "020866", "������Ϣ��", 3306, NULL, 0);//�������ݿ�
	mysql_query(&mysql, "SET NAMES GBK");//��������
	cout << "ѧ��	     ����֤��    ����	 �༶   �ȼ�" << endl;
	cin >> xue >> jie >> xing >> banji >> deng;
	sprintf_s(c_array, sizeof(c_array), "insert into ������Ϣ�� values(%d, %s, %s, %s, %s);", xue, jie.c_str(), xing.c_str(), banji.c_str(), deng.c_str());
	mysql_query(&mysql, c_array);
	mysql_close(&mysql); //�ͷ����ݿ�
	getchar();
}
void insertbook()
{
	MYSQL mysql;
	char c_array[200]{ 0 };
	mysql_init(&mysql);   //��ʼ��MYSQL����
	string book_name;
	int  bianhao, all_num, now_num;
	mysql_real_connect(&mysql, "localhost", "root", "020866", "ͼ����Ϣ��", 3306, NULL, 0);//�������ݿ�
	mysql_query(&mysql, "SET NAMES GBK");//��������
	cout << "���   ����   ���������	��ǰ�����" << endl;
	cin >> bianhao >> book_name >> all_num >> now_num;
	sprintf_s(c_array, sizeof(c_array), "insert into ͼ����Ϣ�� values(%d, %s, %d, %d);", bianhao, book_name.c_str(), all_num, now_num);
	mysql_query(&mysql, c_array);
	mysql_close(&mysql); //�ͷ����ݿ�
	getchar();
}
void insertjieyue()
{
	MYSQL mysql;
	char c_array[200]{ 0 };
	mysql_init(&mysql);   //��ʼ��MYSQL����
	string book_name, time_jie, time_huan, reader_jie;
	int  bianhao;
	mysql_real_connect(&mysql, "localhost", "root", "020866", "����ͼ���", 3306, NULL, 0);//�������ݿ�
	mysql_query(&mysql, "SET NAMES GBK");//��������
	cout << "���    ����       ����֤��  ��������      ��������    " << endl;
	cin >> bianhao >> book_name >> time_jie >> time_huan >> reader_jie;
	sprintf_s(c_array, sizeof(c_array), "insert into ����ͼ��� values(%d, %s, %s, %s,%s);", bianhao, book_name.c_str(), time_jie.c_str(), time_huan.c_str(), reader_jie.c_str());
	mysql_query(&mysql, c_array);
	mysql_close(&mysql); //�ͷ����ݿ�
	getchar();
}
int main()
{
	int j = 0;
	while (1)
	{
		{
			cout << "\n\n--------��ӭʹ��ͼ�����ϵͳ----------" << endl << endl;
			cout << "===========================================" << endl;
			cout << "||========================================||" << endl;
			cout << "||    1.��ѯ�Ƿ�ɹ�        2.��ѯ������Ϣ||" << endl;
			cout << "||    3.��ѯͼ����Ϣ        4.��ѯ������Ϣ||" << endl;
			cout << "||    5.���������Ϣ        6.����ͼ����Ϣ||" << endl;
			cout << "||    7.���������Ϣ                      ||" << endl;
			cout << "||						                   ||" << endl;
			cout << "||========================================||" << endl;
			cout << "============================================" << endl;
			cout << "��������Ĺ���ѡ��" << endl;
		}
		cin >> j;
		switch (j)
		{
		case 1:
		{
			lianjie();
			j = 0;
		}
		break;
		case 2:
		{
			showreader();
			j = 0;
		}
		break;
		case 3:
		{
			showbook();
			j = 0;
		}
		break;
		case 4:
		{
			showjieyue();
			j = 0;
		}
		break;
		case 5:
		{
			insertreader();
			j = 0;
		}
		break;
		case 6:
		{
			insertbook();
			j = 0;
		}
		break;
		case 7:
		{
			insertjieyue();
			j = 0;
		}
		break;
		default:
			j = 0;
			break;
		}
		system("pause");
	}
}