#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "classes.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Инициализация объектов
	cake Cake1("", "", "Private", (float)3.5);
	candys Candy1("", "", "", 40);
	watch Watch1("", "", 30);
	flowers Flower1("", "", 40);
	Inspector Ins;
	Ins.IKnowAllAboutYou(Cake1);
	Cake1.get();
	Curator Cur;
	Cur.ICanModify(Cake1);
	Cake1.get();
	//-----
	cout << endl;
	//-----
	Cake1.getcount();
	//-----
	cout << endl;
	//Инициализация объектов с проверкой работы nested-класса
	//Проверка на брак
	watch Watch2("", "", 50, true);
	watch Watch3("", "", 55, false);
	flowers Flower2("", "", 80, true);
	cout << "Проверка на брак:\n     1.Watch2(true)\n";
	Watch2.get();
	cout << "     2.Watch3(false)\n";
	Watch3.get();
	cout << "     3.Flower2(true)\n";
	Flower2.get();
	//-----
	cout << endl;
	//-----
	//.....
	cout << "Проверка работы virtual функции:" << endl;
	flowers F("Цветок", "Ромашка", 30), *pf = &F;
	bouquet B, *pb = &B;
	flowers *p = &B;
	pf->get();
	cout << "---------------" << endl;
	pb->get();
	cout << "---------------" << endl;
	p->get();
	//////
	cout << "---------------\nПроверка класса Printer:\n";
	cake *c1 = new cake();
	flowers *f1 = new flowers();
	Printer Pr;
	Pr.IamPrinting(c1);
	Pr.IamPrinting(f1);
	cout << endl;
	const char *str = "Hello";
	char *str1 = const_cast<char*>(str);
	cout << str1 << endl;
	flowers *Flw1 = new flowers();
	flowers *Flw2 = new flowers();
	bouquet *Bq = new bouquet();
	Flw1 = static_cast<flowers*>(Bq);
	Flw1->get();
    return 0;
}

