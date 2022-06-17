#define MAX 1000
#include<iostream>
using namespace std;

//�����ϵ�˽ṹ��
struct Person {
	string m_name;
	string sex;
	int age;
	string m_phone;
	string m_addr;
};

//���ͨѶ¼�ṹ��
struct Addressbooks {
	struct Person personArray[MAX]; //ͨѶ¼�������е���ϵ��
	int m_size;
};
//�˵�ҳ��
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

//�����ϵ��
void addPerson(Addressbooks* abs) {
	//�ж�ͨѶ¼�Ƿ������������򷵻�ͨѶ¼����
	if (abs->m_size == MAX) {
		cout << "ͨѶ¼����,�޷���ӣ�" << endl;
		return;
	}
	else
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;

		//�Ա�
		string sex;
		cout << "�������Ա�" << endl;
		
		while (true) {
			cin >> sex;
			if (sex == "��" || sex == "Ů") {
				abs->personArray[abs->m_size].sex = sex;
				break;
			}
			else {
				cout << "����ֻ���ǣ���/Ů�������������롣";
			}
		}

		//����
		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[abs->m_size].age = age;

		//�绰
		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_phone = phone;

		//��ַ
		string addr;
		cout << "�������ַ��" << endl;
		cin >> addr;
		abs->personArray[abs->m_size].m_addr = addr;
	}
	//����ͨѶ¼����
	abs->m_size++;
	cout << endl;
	cout << "��ӳɹ�" << endl;

	system("pause"); //�밴���������
	system("cls"); //��������
}

//��ʾ��ϵ��
void showPerson(Addressbooks abs) {
	//�ж�ͨѶ¼�е������Ƿ�Ϊ0��Ϊ0��ʾͨѶ¼Ϊ��
	if (abs.m_size==0) {
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs.m_size; i++) {
			cout << "������" << abs.personArray[i].m_name << "\t";
			cout << "�Ա�" << abs.personArray[i].sex << "\t";
			cout << "���䣺" << abs.personArray[i].age << "\t";
			cout << "�绰��" << abs.personArray[i].m_phone << "\t";
			cout << "��ַ��" << abs.personArray[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ����
int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->personArray[i].m_name == name) {
			return i;
		}
	}
	return -1;
}

//ɾ����ϵ��
void delPerson(Addressbooks* abs) {
	if (abs->m_size == 0) {
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else {
		string name;
		cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
		while (true) {
			cin >> name;
			int res = isExist(abs, name);
			if (res == -1) {
				cout << "���������ϵ�˲����ڣ����������롣";
			}
			else
			{
				for (int i = res; i < abs->m_size; i++) {
					abs->personArray[i] = abs->personArray[i + 1];
				}
				abs->m_size--;
				cout << "ɾ���ɹ���" << endl;
				cout << endl;
				break;
			}
		}
	}
	system("pause");
	system("cls");
}

//������ϵ��
void findPerson(Addressbooks* abs) {
	if (abs->m_size == 0) {
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else {
		string name;
		cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
		cin >> name;
		int res = isExist(abs, name);
		if (res==-1){
			cout << "���޴���" << endl;
		}
		else {
			cout << "������" << abs->personArray[res].m_name << "\t";
			cout << "�Ա�" << abs->personArray[res].sex << "\t";
			cout << "���䣺" << abs->personArray[res].age << "\t";
			cout << "�绰��" << abs->personArray[res].m_phone << "\t";
			cout << "��ַ��" << abs->personArray[res].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//�޸���ϵ��
void editPerson(Addressbooks* abs) {
	if (abs->m_size == 0) {
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else {
		string name;
		cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
		cin >> name;
		int res = isExist(abs, name);
		if (res == -1) {
			cout << "���޴���" << endl;
		}else{
			cout << "��������Ҫ�޸ĵ�ѡ�1 = ������2 = �Ա�3 = ���䡢4 = �绰��5 = סַ" << endl;
			int flag = 0;
			cin >> flag;
			switch (flag) 
			{
			case 1: {
				//����
				string re_name;
				cout << "������������" << endl;
				cin >> re_name;
				abs->personArray[res].m_name = re_name;
				cout << "�޸ĳɹ�" << endl;
				break;
			}
				
			case 2: {
				//�Ա�
				string sex;
				cout << "�������Ա�" << endl;

				while (true) {
					cin >> sex;
					if (sex == "��" || sex == "Ů") {
						abs->personArray[res].sex = sex;
						break;
					}
					else {
						cout << "����ֻ���ǣ���/Ů�������������롣";
					}
				}
				cout << "�޸ĳɹ�" << endl;
				break;
			}
				
			case 3: {
				//����
				int age = 0;
				cout << "���������䣺" << endl;
				cin >> age;
				abs->personArray[res].age = age;
				cout << "�޸ĳɹ�" << endl;
				break;
			}
				
			case 4: {
				//�绰
				string phone;
				cout << "������绰��" << endl;
				cin >> phone;
				abs->personArray[res].m_phone = phone;
				cout << "�޸ĳɹ�" << endl;
				break;
			}
				
			case 5: {
				//��ַ
				string addr;
				cout << "�������ַ��" << endl;
				cin >> addr;
				abs->personArray[res].m_addr = addr;
				cout << "�޸ĳɹ�" << endl;
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

//�����ϵ��,�����е���ϵ�˶�ɾ��
void clearPerson(Addressbooks* abs) {
	cout << "��ȷ�����������ϵ����" << endl;
	cout << "����1ȷ�ϣ�����0���ء�" << endl;
	int flag = 0;
	cin >> flag;
	if (flag == 1) {
		abs->m_size = 0;
		cout << "ͨѶ¼�����" << endl;
	}
	else {
		showMenu();
	}
	system("pause");
	system("cls");
}

int main() {
	Addressbooks abs; //����ͨѶ¼
	abs.m_size = 0; //ͨѶ¼��ʼ��ϵ�˸���

	int select = 0;
	while (true) {
		//���ò˵�
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1: //�����ϵ��
			addPerson(&abs); //���õ�ַ���ݣ������޸�ʵ��
			break;
		case 2: //��ʾ��ϵ��
			showPerson(abs);
			break;
		case 3: //ɾ����ϵ��
			delPerson(&abs);
			break;
		case 4: //������ϵ��
			findPerson(&abs);
			break;
		case 5: //�޸���ϵ��
			editPerson(&abs);
			break;
		case 6: //�����ϵ��
			clearPerson(&abs);
			break;
		case 0: //�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}