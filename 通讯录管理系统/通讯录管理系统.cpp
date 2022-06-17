#define MAX 1000
#include<iostream>
using namespace std;

//设计联系人结构体
struct Person {
	string m_name;
	string sex;
	int age;
	string m_phone;
	string m_addr;
};

//设计通讯录结构体
struct Addressbooks {
	struct Person personArray[MAX]; //通讯录中现在有的联系人
	int m_size;
};
//菜单页面
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

//添加联系人
void addPerson(Addressbooks* abs) {
	//判断通讯录是否已满，满了则返回通讯录已满
	if (abs->m_size == MAX) {
		cout << "通讯录已满,无法添加！" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;

		//性别
		string sex;
		cout << "请输入性别：" << endl;
		
		while (true) {
			cin >> sex;
			if (sex == "男" || sex == "女") {
				abs->personArray[abs->m_size].sex = sex;
				break;
			}
			else {
				cout << "输入只能是（男/女），请重新输入。";
			}
		}

		//年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->m_size].age = age;

		//电话
		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;

		//地址
		string addr;
		cout << "请输入地址：" << endl;
		cin >> addr;
		abs->personArray[abs->m_size].m_addr = addr;
	}
	//更新通讯录人数
	abs->m_size++;
	cout << endl;
	cout << "添加成功" << endl;

	system("pause"); //请按任意键继续
	system("cls"); //清屏操作
}

//显示联系人
void showPerson(Addressbooks abs) {
	//判断通讯录中的人数是否为0，为0显示通讯录为空
	if (abs.m_size==0) {
		cout << "通讯录为空" << endl;
	}
	else {
		for (int i = 0; i < abs.m_size; i++) {
			cout << "姓名：" << abs.personArray[i].m_name << "\t";
			cout << "性别：" << abs.personArray[i].sex << "\t";
			cout << "年龄：" << abs.personArray[i].age << "\t";
			cout << "电话：" << abs.personArray[i].m_phone << "\t";
			cout << "地址：" << abs.personArray[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//检查联系人是否存在
int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->personArray[i].m_name == name) {
			return i;
		}
	}
	return -1;
}

//删除联系人
void delPerson(Addressbooks* abs) {
	if (abs->m_size == 0) {
		cout << "通讯录为空" << endl;
	}
	else {
		string name;
		cout << "请输入您要删除的联系人：" << endl;
		while (true) {
			cin >> name;
			int res = isExist(abs, name);
			if (res == -1) {
				cout << "您输入的联系人不存在，请重新输入。";
			}
			else
			{
				for (int i = res; i < abs->m_size; i++) {
					abs->personArray[i] = abs->personArray[i + 1];
				}
				abs->m_size--;
				cout << "删除成功！" << endl;
				cout << endl;
				break;
			}
		}
	}
	system("pause");
	system("cls");
}

//查找联系人
void findPerson(Addressbooks* abs) {
	if (abs->m_size == 0) {
		cout << "通讯录为空" << endl;
	}
	else {
		string name;
		cout << "请输入您要查找的联系人：" << endl;
		cin >> name;
		int res = isExist(abs, name);
		if (res==-1){
			cout << "查无此人" << endl;
		}
		else {
			cout << "姓名：" << abs->personArray[res].m_name << "\t";
			cout << "性别：" << abs->personArray[res].sex << "\t";
			cout << "年龄：" << abs->personArray[res].age << "\t";
			cout << "电话：" << abs->personArray[res].m_phone << "\t";
			cout << "地址：" << abs->personArray[res].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//修改联系人
void editPerson(Addressbooks* abs) {
	if (abs->m_size == 0) {
		cout << "通讯录为空" << endl;
	}
	else {
		string name;
		cout << "请输入您要修改的联系人：" << endl;
		cin >> name;
		int res = isExist(abs, name);
		if (res == -1) {
			cout << "查无此人" << endl;
		}else{
			cout << "请输入您要修改的选项：1 = 姓名、2 = 性别、3 = 年龄、4 = 电话、5 = 住址" << endl;
			int flag = 0;
			cin >> flag;
			switch (flag) 
			{
			case 1: {
				//姓名
				string re_name;
				cout << "请输入姓名：" << endl;
				cin >> re_name;
				abs->personArray[res].m_name = re_name;
				cout << "修改成功" << endl;
				break;
			}
				
			case 2: {
				//性别
				string sex;
				cout << "请输入性别：" << endl;

				while (true) {
					cin >> sex;
					if (sex == "男" || sex == "女") {
						abs->personArray[res].sex = sex;
						break;
					}
					else {
						cout << "输入只能是（男/女），请重新输入。";
					}
				}
				cout << "修改成功" << endl;
				break;
			}
				
			case 3: {
				//年龄
				int age = 0;
				cout << "请输入年龄：" << endl;
				cin >> age;
				abs->personArray[res].age = age;
				cout << "修改成功" << endl;
				break;
			}
				
			case 4: {
				//电话
				string phone;
				cout << "请输入电话：" << endl;
				cin >> phone;
				abs->personArray[res].m_phone = phone;
				cout << "修改成功" << endl;
				break;
			}
				
			case 5: {
				//地址
				string addr;
				cout << "请输入地址：" << endl;
				cin >> addr;
				abs->personArray[res].m_addr = addr;
				cout << "修改成功" << endl;
				break;
			}
				
			default:
				break;
			}
		}
	}
	system("pause");
	system("cls");
}

//清空联系人,把所有的联系人都删除
void clearPerson(Addressbooks* abs) {
	cout << "您确定清空所有联系人吗？" << endl;
	cout << "输入1确认，输入0返回。" << endl;
	int flag = 0;
	cin >> flag;
	if (flag == 1) {
		abs->m_size = 0;
		cout << "通讯录已清空" << endl;
	}
	else {
		showMenu();
	}
	system("pause");
	system("cls");
}

int main() {
	Addressbooks abs; //创建通讯录
	abs.m_size = 0; //通讯录初始联系人个数

	int select = 0;
	while (true) {
		//调用菜单
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1: //添加联系人
			addPerson(&abs); //利用地址传递，可以修改实参
			break;
		case 2: //显示联系人
			showPerson(abs);
			break;
		case 3: //删除联系人
			delPerson(&abs);
			break;
		case 4: //查找联系人
			findPerson(&abs);
			break;
		case 5: //修改联系人
			editPerson(&abs);
			break;
		case 6: //清空联系人
			clearPerson(&abs);
			break;
		case 0: //退出通讯录
			cout << "欢迎下次使用" << endl;
			return 0;
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}