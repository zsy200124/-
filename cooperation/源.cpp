
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include<mysql.h>
void lianjie()
{
	MYSQL mysql, *sock;
	mysql_init(&mysql);   //初始化MYSQL变量
	sock = mysql_real_connect(&mysql, "localhost", "root", "020866", "图书管理库", 3306, NULL, 0);
	if (sock == NULL)//连接数据库
	{
		printf("\n连接数据库时发生错误!\n");
		cout << mysql_error(&mysql) << endl;
		exit(0);
	}
	else
		printf("\n连接数据库成功!\n");
}
void showreader()
{
	MYSQL mysql;
	mysql_init(&mysql);   //初始化MYSQL变量
	MYSQL_RES* result;
	MYSQL_ROW row;
	int num;        //用来存放结果集列数
	int i;
	mysql_real_connect(&mysql, "localhost", "root", "020866", "ku", 3306, NULL, 0);
	mysql_query(&mysql, "set names gbk");
	mysql_query(&mysql, "select * from 读者信息表");
	result = mysql_store_result(&mysql);    //将查询到的结果集储存到result中
	num = mysql_num_fields(result);        //将结果集列数存放到num中
	cout << "学号	     借书证号    姓名	 班级   等级" << endl;
	while ((row = mysql_fetch_row(result)))  //遇到最后一行，则中止循环
	{
		for (i = 0; i < num; i++)         //利用for循环，输出该行的每一列
		{
			cout << row[i] << "\t";    //row是MYSQL_ROW变量，可以当做数组使用，i为列数
		}
		cout << endl;
	}
	mysql_free_result(result);     //释放结果集所占用的内存
	mysql_close(&mysql); //释放数据库
	getchar();
}
void showbook()
{
	MYSQL mysql;
	mysql_init(&mysql);   //初始化MYSQL变量
	MYSQL_RES* result;
	MYSQL_ROW row;
	int num;        //用来存放结果集列数
	int i;
	mysql_real_connect(&mysql, "localhost", "root", "020866", "ku", 3306, NULL, 0);
	mysql_query(&mysql, "set names gbk");
	mysql_query(&mysql, "select * from 图书信息表");
	result = mysql_store_result(&mysql);    //将查询到的结果集储存到result中
	num = mysql_num_fields(result);        //将结果集列数存放到num中
	cout << "编号 书名     作者    出版社      出版日日期     金额    类别   总入库数量   当前库存量   已借出本数" << endl;
	while ((row = mysql_fetch_row(result)))  //遇到最后一行，则中止循环
	{
		for (i = 0; i < num; i++)         //利用for循环，输出该行的每一列
		{
			cout << row[i] << "\t";    //row是MYSQL_ROW变量，可以当做数组使用，i为列数
		}
		cout << endl;
	}
	mysql_free_result(result);     //释放结果集所占用的内存
	mysql_close(&mysql); //释放数据库
	getchar();
}
void showjieyue()
{
	MYSQL mysql;
	mysql_init(&mysql);   //初始化MYSQL变量
	MYSQL_RES* result;
	MYSQL_ROW row;
	int num;        //用来存放结果集列数
	int i;
	mysql_real_connect(&mysql, "localhost", "root", "020866", "ku", 3306, NULL, 0);
	mysql_query(&mysql, "set names gbk");
	mysql_query(&mysql, "select * from 借阅图书表");
	result = mysql_store_result(&mysql);    //将查询到的结果集储存到result中
	num = mysql_num_fields(result);        //将结果集列数存放到num中
	cout << "编号    书名    金额   借书证号  借书日期      到期日期     罚款金额" << endl;
	while ((row = mysql_fetch_row(result)))  //遇到最后一行，则中止循环
	{
		for (i = 0; i < num; i++)         //利用for循环，输出该行的每一列
		{
			cout << row[i] << "\t";    //row是MYSQL_ROW变量，可以当做数组使用，i为列数
		}
		cout << endl;
	}
	mysql_free_result(result);     //释放结果集所占用的内存
	mysql_close(&mysql); //释放数据库
	getchar();
}
void insertreader()
{
	MYSQL mysql;
	char c_array[200]{ 0 };
	mysql_init(&mysql);   //初始化MYSQL变量
	string banji, xing, jie, deng;
	int  xue;
	mysql_real_connect(&mysql, "localhost", "root", "020866", "读者信息表", 3306, NULL, 0);//连接数据库
	mysql_query(&mysql, "SET NAMES GBK");//可以中文
	cout << "学号	     借书证号    姓名	 班级   等级" << endl;
	cin >> xue >> jie >> xing >> banji >> deng;
	sprintf_s(c_array, sizeof(c_array), "insert into 读者信息表 values(%d, %s, %s, %s, %s);", xue, jie.c_str(), xing.c_str(), banji.c_str(), deng.c_str());
	mysql_query(&mysql, c_array);
	mysql_close(&mysql); //释放数据库
	getchar();
}
void insertbook()
{
	MYSQL mysql;
	char c_array[200]{ 0 };
	mysql_init(&mysql);   //初始化MYSQL变量
	string book_name;
	int  bianhao, all_num, now_num;
	mysql_real_connect(&mysql, "localhost", "root", "020866", "图书信息表", 3306, NULL, 0);//连接数据库
	mysql_query(&mysql, "SET NAMES GBK");//可以中文
	cout << "编号   书名   总入库数量	当前库存量" << endl;
	cin >> bianhao >> book_name >> all_num >> now_num;
	sprintf_s(c_array, sizeof(c_array), "insert into 图书信息表 values(%d, %s, %d, %d);", bianhao, book_name.c_str(), all_num, now_num);
	mysql_query(&mysql, c_array);
	mysql_close(&mysql); //释放数据库
	getchar();
}
void insertjieyue()
{
	MYSQL mysql;
	char c_array[200]{ 0 };
	mysql_init(&mysql);   //初始化MYSQL变量
	string book_name, time_jie, time_huan, reader_jie;
	int  bianhao;
	mysql_real_connect(&mysql, "localhost", "root", "020866", "借阅图书表", 3306, NULL, 0);//连接数据库
	mysql_query(&mysql, "SET NAMES GBK");//可以中文
	cout << "编号    书名       借书证号  借书日期      到期日期    " << endl;
	cin >> bianhao >> book_name >> time_jie >> time_huan >> reader_jie;
	sprintf_s(c_array, sizeof(c_array), "insert into 借阅图书表 values(%d, %s, %s, %s,%s);", bianhao, book_name.c_str(), time_jie.c_str(), time_huan.c_str(), reader_jie.c_str());
	mysql_query(&mysql, c_array);
	mysql_close(&mysql); //释放数据库
	getchar();
}
int main()
{
	int j = 0;
	while (1)
	{
		{
			cout << "\n\n--------欢迎使用图书管理系统----------" << endl << endl;
			cout << "===========================================" << endl;
			cout << "||========================================||" << endl;
			cout << "||    1.查询是否成功        2.查询读者信息||" << endl;
			cout << "||    3.查询图书信息        4.查询借阅信息||" << endl;
			cout << "||    5.插入读者信息        6.插入图书信息||" << endl;
			cout << "||    7.插入借阅信息                      ||" << endl;
			cout << "||						                   ||" << endl;
			cout << "||========================================||" << endl;
			cout << "============================================" << endl;
			cout << "请输入你的功能选择" << endl;
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