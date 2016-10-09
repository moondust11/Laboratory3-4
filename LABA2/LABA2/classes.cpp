#include "stdafx.h"
#include "classes.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int product::count = 0;
int bouquet::count = 0;

// Блок методов класса good
void good::get() const //Вывести всё
{
	cout << "                           class good:" << endl;
	obj.ifget();
	cout << "1)Тип: " << type << endl;
	cout << "2)Стоимость: " << price << endl;
}
void good::set() //Задать всё
{
	cout << "Впишите тип: "; cin >> type;
	cout << "Впишите стоимость: "; cin >> price;
}
void good::set(string word1) //Задать только тип
{	
	type = word1;
}
void good::set(float number) //Задать только стоимость
{
	price = number;
}
void good::set(string word1, float number) //Задать всё параметрически
{
	type = word1;
	price = number;
}
void good::setbool(bool eve)
{
	obj.set(eve);
}

// Блок методов класса product
void product::get() const //Вывести всё
{
	good::get();
	cout << "                           class product:" << endl;
	cout << "3)Вид:  " << kind << endl;
}
void product::set() //Задать всё
{
	good::set();
	cout << "Впишите вид: "; cin >> kind;
}
void product::set(string word1, string word2) //Задать только тип и вид
{
	good::set(word1);
	kind = word2;
}
void product::set(float number) //Задать только стоимость
{
	good::set(number);
}
void product::set(string word1, string word2, float number) //Задать всё параметрически
{
	good::set(word1, number);
	kind = word2;
}

// Блок методов класса cake
void cake::get() const //Вывести всё
{
	
	product::get();
	cout << "                           class cake:" << endl;
	cout << "4)Название: " << name << endl;
}
void cake::set() //Задать всё
{
	
	
	product::set();
	cout << "Впишите название: "; cin >> name;
}
void cake::set(string word1, string word2, string word3) //Задать только тип, вид и название
{
	product::set(word1, word2);
	name = word3;
}
void cake::set(float number) //Задать только цену
{
	product::set(number);
}
void cake::set(string word1, string word2, string word3, float number) //Задать всё параметрически
{
	product::set(word1, word2, number);
	name = word3;
}
void cake::toConsole()
{
	product::get();
	cout << "                           class cake:" << endl;
	cout << typeid(this).name() << endl;
	cout << "4)Название: " << name << endl; 
}

// Блок методов класса candys
void candys::get() const //Вывести всё
{
	product::get();
	cout << "                           class candys:" << endl;
	cout << "4)Название: " << name << endl;
}
void candys::set() //Задать всё
{
	product::set();
	cout << "Впишите название: "; cin >> name;
}
void candys::set(string word1, string word2, string word3) //Задать только тип, вид и название
{
	product::set(word1, word2);
	name = word3;
}
void candys::set(float number) //Задать только цену
{
	product::set(number);
}
void candys::set(string word1, string word2, string word3, float number) //Задать всё параметрически
{
	product::set(word1, word2, number);
	name = word3;
}
void candys::toConsole()
{
	product::get();
	cout << "                           class candys:" << endl;
	cout << typeid(this).name() << endl;
	cout << "4)Название: " << name << endl;
}

// Блок методов класса watch
void watch::get() const //Вывести всё
{
	good::get();
	cout << "                           class watch:" << endl;
	cout << "3)Модель:  " << model << endl;
}
void watch::set() //Задать всё
{
	good::set();
	cout << "Впишите модель: "; cin >> model;
}
void watch::set(string word1, string word2) //Задать только тип и модель
{
	good::set(word1);
	model = word2;
}
void watch::set(float number) //Задать только стоимость
{
	good::set(number);
}
void watch::set(string word1, string word2, float number)
//Задать всё параметрически
{
	good::set(word1, number);
	model = word2;
}
void watch::toConsole()
{
	good::get();
	cout << "                           class watch:" << endl;
	cout << typeid(this).name() << endl;
	cout << "3)Модель:  " << model << endl;
}

// Блок методов класса flowers
void flowers::get() const //Вывести всё
{
	good::get();
	cout << "                           class flowers:" << endl;
	cout << "3)Вид:  " << kind << endl;
}
void flowers::set() //Задать всё
{
	good::set();
	cout << "Впишите вид: "; cin >> kind;
}
void flowers::set(string word1, string word2) //Задать только тип и вид
{
	good::set(word1);
	kind = word2;
}
void flowers::set(float number) //Задать только стоимость
{
	good::set(number);
}
void flowers::set(string word1, string word2, float number)
//Задать всё параметрически
{
	good::set(word1, number);
	kind = word2;
}
void flowers::toConsole()
{
	good::get();
	cout << "                           class flowers:" << endl;
	cout << typeid(this).name() << endl;
	cout << "3)Вид:  " << kind << endl;
}

// Блок методов класса bouquet
void bouquet::get() const //Вывести всё
{
	cout << "                           class bouquet:" << endl;
	cout << "Букет состоит из:\n";
	for (int i = 0; i < count;i++)
	{
		cout << "Цветок №" << i + 1 << ":\n";
		flows[i].get();
	}
}
void bouquet::set() //Задать всё
{
	for (int i = 0; i < count; i++)
	{
		cout << "Впишите хар-ки цветка №" << i + 1 << ":\n";
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
	cout << "Букет состоит из:\n";
	for (int i = 0; i < count; i++)
	{
		cout << "Цветок №" << i + 1 << ":\n";
		flows[i].get();
	}
}