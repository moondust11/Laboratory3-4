#pragma once

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

//count--

//Базисный
//Абстрактный класс good
class good
{
private:
	string type;
	float price;
	class Reject
	{
	private:
		bool isreject;
	public:
		Reject()
		{}
		~Reject()
		{
			isreject = false;
		}
		void set()
		{
			cin >> isreject;
		}
		void set(bool eve)
		{
			isreject = eve;
		}
		void ifget() const
		{
			if (isreject == true)
				cout << "Данный товар является браком" << endl;
		}
	};
	Reject obj;
protected:
	~good()
	{
		type = "Не определён";
		price = 0;
		obj.~Reject();
	}
	good() : type("Не определён"), price(0)
	{}
	good(string word1) : type(word1), price(0)
	{}
	good(float number) : type("Не определён"), price(number)
	{}
	good(string word1, float number) : type(word1), price(number)
	{}
	good(string word1, int number) : type(word1), price(number)
	{}
	//С bool
	good(bool eve) : type("Не определён"), price(0)
	{
		obj.set(eve);
	}
	good(string word1, bool eve) : type(word1), price(0)
	{
		obj.set(eve);
	}
	good(float number, bool eve) : type("Не определён"), price(number)
	{
		obj.set(eve);
	}
	good(string word1, float number, bool eve) : type(word1), price(number)
	{
		obj.set(eve);
	}
public:
	void get() const;
	void set();
	void set(string word1);
	void set(float number);
	void set(string word1, float number);
	void setbool(bool eve);
	virtual void toConsole() = 0;
};

class product : public good
{
private:
	string kind;
	static int count;
	const int MAXcount = 20;
	bool reject = false;
protected:
	~product()
	{
		count--;
		kind = "Не определён";
		good::~good();
	}
	product(string word1, string word2) : kind(word2), good(word1)
	{
		count++;
		good::setbool(reject);
		if (count>MAXcount)
		{
			product::~product();
			cout << "Создание элемента невозможно, так как превышено их максимальное кол-во." << endl;
			count--;

		}
	}
	product(float number) : kind("Не определён"), good(number)
	{
		count++;
		good::setbool(reject);
		if (count>MAXcount)
		{
			product::~product();
			cout << "Создание элемента невозможно, так как превышено их максимальное кол-во." << endl;
			count--;

		}
	}
	product(string word1, string word2, float number) : kind(word2), good(word1, number)
	{
		count++;
		good::setbool(reject);
		if (count>MAXcount)
		{
			product::~product();
			cout << "Создание элемента невозможно, так как превышено их максимальное кол-во." << endl;
			count--;

		}
	}
	product(string word1, string word2, int number) : kind(word2), good(word1, number)
	{
		count++;
		good::setbool(reject);
		if (count>MAXcount)
		{
			product::~product();
			cout << "Создание элемента невозможно, так как превышено их максимальное кол-во." << endl;
			count--;

		}
	}
public:
	product() : kind("Не определён"), good()
	{
		count++;
		good::setbool(reject);
		if (count>MAXcount)
		{
			product::~product();
			cout << "Создание элемента невозможно, так как превышено их максимальное кол-во." << endl;
			count--;

		}
	}
	void get() const;
	void set();
	void set(string word1, string word2);
	void set(float number);
	void set(string word1, string word2, float number);
	void getcount()
	{
		cout << "Кол-во созданных продуктов: " << count << endl;
	}
	void toConsole()
	{}
};

////Реальные объекты
class cake : public product
{
private:
	string name;
	friend class Inspector;
	friend class Curator;
public:
	~cake()
	{
		name = "Безымянный";
		product::~product();
	}
	cake() : name("Безымянный"), product()
	{}
	cake(string word1, string word2, string word3) : name(word3), product(word1, word2)
	{}
	cake(float number) : name("Безымянный"), product(number)
	{}
	cake(string word1, string word2, string word3, float number) : name(word3), product(word1, word2, number)
	{}
	cake(string word1, string word2, string word3, int number) : name(word3), product(word1, word2, number)
	{}
	void get() const;
	void set();
	void set(string word1, string word2, string word3);
	void set(float number);
	void set(string word1, string word2, string word3, float number);
	void toConsole();
};

class Inspector
{
public:
	Inspector()
	{}
	void IKnowAllAboutYou(cake &any) const
	{
		cout << "                           class Inspector(cake's friend):" << endl;
		cout << "Имя: " << any.name << endl;
	}
};

class Curator
{
public:
	void ICanModify(cake &ck)
	{
		cout << "Впишите новое имя: "; cin >> ck.name;
	}
};

class candys : public product
{
private:
	string name;
public:
	~candys()
	{
		name = "Безымянный";
		product::~product();
	}
	candys() : name("Безымянный"), product()
	{}
	candys(string word1, string word2, string word3) : name(word3), product(word1, word2)
	{}
	candys(float number) : name("Безымянный"), product(number)
	{}
	candys(string word1, string word2, string word3, float number) : name(word3), product(word1, word2, number)
	{}
	candys(string word1, string word2, string word3, int number) : name(word3), product(word1, word2, number)
	{}
	void get() const;
	void set();
	void set(string word1, string word2, string word3);
	void set(float number);
	void set(string word1, string word2, string word3, float number);
	void toConsole();
};

class watch : public good
{
private:
	string model;
public:
	~watch()
	{
		model = "Не определена";
		good::~good();
	}
	watch() : model("Не определёна"), good()
	{}
	watch(string word1, string word2) : model(word2), good(word1)
	{}
	watch(float number) : model("Не определёна"), good(number)
	{}
	watch(string word1, string word2, float number) : model(word2), good(word1, number)
	{}
	watch(string word1, string word2, int number) : model(word2), good(word1, number)
	{}
	//C bool
	watch(bool eve) : model("Не определёна"), good(eve)
	{}
	watch(string word1, string word2, bool eve) : model(word2), good(word1, eve)
	{}
	watch(float number, bool eve) : model("Не определёна"), good(number, eve)
	{}
	watch(string word1, string word2, float number, bool eve) : model(word2), good(word1, number, eve)
	{}
	void get() const;
	void set();
	void set(string word1, string word2);
	void set(float number);
	void set(string word1, string word2, float number);
	void toConsole();
};

class flowers : public good
{
private:
	string kind;
public:
	~flowers()
	{
		kind = "Не определён";
		good::~good();
	}
	flowers() : kind("Не определён"), good()
	{}
	flowers(string word1, string word2) : kind(word2), good(word1)
	{}
	flowers(float number) : kind("Не определён"), good(number)
	{}
	flowers(string word1, string word2, float number) : kind(word2), good(word1, number)
	{}
	flowers(string word1, string word2, int number) : kind(word2), good(word1, number)
	{}
	//C bool
	flowers(bool eve) : kind("Не определён"), good(eve)
	{}
	flowers(string word1, string word2, bool eve) : kind(word2), good(word1, eve)
	{}
	flowers(float number, bool eve) : kind("Не определён"), good(number, eve)
	{}
	flowers(string word1, string word2, float number, bool eve) : kind(word2), good(word1, number, eve)
	{}
	virtual void get() const;
	void set();
	void set(string word1, string word2);
	void set(float number);
	void set(string word1, string word2, float number);
	void toConsole();
};

class bouquet : public flowers
{
private:
	int static count;
	const static int MAX = 9;
	flowers flows[MAX];
public:
	~bouquet()
	{
		for (int i = 0; i < count; i++)
		{
			flows[i].~flowers();
		}
		count = 0;
	}
	bouquet()
	{}
	bouquet(flowers fws[])
	{
		for (int i = 0; i < MAX; i++)
		{
			flows[i] = fws[i];
			count++;
			if (count > MAX)
			{
				cout << "Создание элемента не возможно, так как превышено\nмаксимально допустимое кол-во элементов класса flowers" << endl;
				flows[count].~flowers();
				count--;
				break;
			}
		}
	}
	void get() const;
	void set();
	void set(flowers fws[]);
	void toConsole();
};

//IamPrinting
class good;
class Printer
{
public:
	void IamPrinting(good *obj)
	{
		cout << typeid(this).name() << endl;
		obj->toConsole();
	}
};