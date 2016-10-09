#include "stdafx.h"
#include "classes.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int product::count = 0;
int bouquet::count = 0;

// ���� ������� ������ good
void good::get() const //������� ��
{
	cout << "                           class good:" << endl;
	obj.ifget();
	cout << "1)���: " << type << endl;
	cout << "2)���������: " << price << endl;
}
void good::set() //������ ��
{
	cout << "������� ���: "; cin >> type;
	cout << "������� ���������: "; cin >> price;
}
void good::set(string word1) //������ ������ ���
{	
	type = word1;
}
void good::set(float number) //������ ������ ���������
{
	price = number;
}
void good::set(string word1, float number) //������ �� ��������������
{
	type = word1;
	price = number;
}
void good::setbool(bool eve)
{
	obj.set(eve);
}

// ���� ������� ������ product
void product::get() const //������� ��
{
	good::get();
	cout << "                           class product:" << endl;
	cout << "3)���:  " << kind << endl;
}
void product::set() //������ ��
{
	good::set();
	cout << "������� ���: "; cin >> kind;
}
void product::set(string word1, string word2) //������ ������ ��� � ���
{
	good::set(word1);
	kind = word2;
}
void product::set(float number) //������ ������ ���������
{
	good::set(number);
}
void product::set(string word1, string word2, float number) //������ �� ��������������
{
	good::set(word1, number);
	kind = word2;
}

// ���� ������� ������ cake
void cake::get() const //������� ��
{
	
	product::get();
	cout << "                           class cake:" << endl;
	cout << "4)��������: " << name << endl;
}
void cake::set() //������ ��
{
	
	
	product::set();
	cout << "������� ��������: "; cin >> name;
}
void cake::set(string word1, string word2, string word3) //������ ������ ���, ��� � ��������
{
	product::set(word1, word2);
	name = word3;
}
void cake::set(float number) //������ ������ ����
{
	product::set(number);
}
void cake::set(string word1, string word2, string word3, float number) //������ �� ��������������
{
	product::set(word1, word2, number);
	name = word3;
}
void cake::toConsole()
{
	product::get();
	cout << "                           class cake:" << endl;
	cout << typeid(this).name() << endl;
	cout << "4)��������: " << name << endl; 
}

// ���� ������� ������ candys
void candys::get() const //������� ��
{
	product::get();
	cout << "                           class candys:" << endl;
	cout << "4)��������: " << name << endl;
}
void candys::set() //������ ��
{
	product::set();
	cout << "������� ��������: "; cin >> name;
}
void candys::set(string word1, string word2, string word3) //������ ������ ���, ��� � ��������
{
	product::set(word1, word2);
	name = word3;
}
void candys::set(float number) //������ ������ ����
{
	product::set(number);
}
void candys::set(string word1, string word2, string word3, float number) //������ �� ��������������
{
	product::set(word1, word2, number);
	name = word3;
}
void candys::toConsole()
{
	product::get();
	cout << "                           class candys:" << endl;
	cout << typeid(this).name() << endl;
	cout << "4)��������: " << name << endl;
}

// ���� ������� ������ watch
void watch::get() const //������� ��
{
	good::get();
	cout << "                           class watch:" << endl;
	cout << "3)������:  " << model << endl;
}
void watch::set() //������ ��
{
	good::set();
	cout << "������� ������: "; cin >> model;
}
void watch::set(string word1, string word2) //������ ������ ��� � ������
{
	good::set(word1);
	model = word2;
}
void watch::set(float number) //������ ������ ���������
{
	good::set(number);
}
void watch::set(string word1, string word2, float number)
//������ �� ��������������
{
	good::set(word1, number);
	model = word2;
}
void watch::toConsole()
{
	good::get();
	cout << "                           class watch:" << endl;
	cout << typeid(this).name() << endl;
	cout << "3)������:  " << model << endl;
}

// ���� ������� ������ flowers
void flowers::get() const //������� ��
{
	good::get();
	cout << "                           class flowers:" << endl;
	cout << "3)���:  " << kind << endl;
}
void flowers::set() //������ ��
{
	good::set();
	cout << "������� ���: "; cin >> kind;
}
void flowers::set(string word1, string word2) //������ ������ ��� � ���
{
	good::set(word1);
	kind = word2;
}
void flowers::set(float number) //������ ������ ���������
{
	good::set(number);
}
void flowers::set(string word1, string word2, float number)
//������ �� ��������������
{
	good::set(word1, number);
	kind = word2;
}
void flowers::toConsole()
{
	good::get();
	cout << "                           class flowers:" << endl;
	cout << typeid(this).name() << endl;
	cout << "3)���:  " << kind << endl;
}

// ���� ������� ������ bouquet
void bouquet::get() const //������� ��
{
	cout << "                           class bouquet:" << endl;
	cout << "����� ������� ��:\n";
	for (int i = 0; i < count;i++)
	{
		cout << "������ �" << i + 1 << ":\n";
		flows[i].get();
	}
}
void bouquet::set() //������ ��
{
	for (int i = 0; i < count; i++)
	{
		cout << "������� ���-�� ������ �" << i + 1 << ":\n";
		flows[i].set();
	}
}
void bouquet::set(flowers fws[])
{
	for (int i = 0; i < MAX; i++)
	{
		flows[i] = fws[i];
	}
}
void bouquet::toConsole()
{
	cout << "                           class bouquet:" << endl;
	cout << typeid(this).name() << endl;
	cout << "����� ������� ��:\n";
	for (int i = 0; i < count; i++)
	{
		cout << "������ �" << i + 1 << ":\n";
		flows[i].get();
	}
}