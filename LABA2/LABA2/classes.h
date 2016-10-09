#pragma once

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

//count--

//��������
//����������� ����� good
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
				cout << "������ ����� �������� ������" << endl;
		}
	};
	Reject obj;
protected:
	~good()
	{
		type = "�� ��������";
		price = 0;
		obj.~Reject();
	}
	good() : type("�� ��������"), price(0)
	{}
	good(string word1) : type(word1), price(0)
	{}
	good(float number) : type("�� ��������"), price(number)
	{}
	good(string word1, float number) : type(word1), price(number)
	{}
	good(string word1, int number) : type(word1), price(number)
	{}
	//� bool
	good(bool eve) : type("�� ��������"), price(0)
	{
		obj.set(eve);
	}
	good(string word1, bool eve) : type(word1), price(0)
	{
		obj.set(eve);
	}
	good(float number, bool eve) : type("�� ��������"), price(number)
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
		kind = "�� ��������";
		good::~good();
	}
	product(string word1, string word2) : kind(word2), good(word1)
	{
		count++;
		good::setbool(reject);
		if (count>MAXcount)
		{
			product::~product();
			cout << "�������� �������� ����������, ��� ��� ��������� �� ������������ ���-��." << endl;
			count--;

		}
	}
	product(float number) : kind("�� ��������"), good(number)
	{
		count++;
		good::setbool(reject);
		if (count>MAXcount)
		{
			product::~product();
			cout << "�������� �������� ����������, ��� ��� ��������� �� ������������ ���-��." << endl;
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
			cout << "�������� �������� ����������, ��� ��� ��������� �� ������������ ���-��." << endl;
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
			cout << "�������� �������� ����������, ��� ��� ��������� �� ������������ ���-��." << endl;
			count--;

		}
	}
public:
	product() : kind("�� ��������"), good()
	{
		count++;
		good::setbool(reject);
		if (count>MAXcount)
		{
			product::~product();
			cout << "�������� �������� ����������, ��� ��� ��������� �� ������������ ���-��." << endl;
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
		cout << "���-�� ��������� ���������: " << count << endl;
	}
	void toConsole()
	{}
};

////�������� �������
class cake : public product
{
private:
	string name;
	friend class Inspector;
	friend class Curator;
public:
	~cake()
	{
		name = "����������";
		product::~product();
	}
	cake() : name("����������"), product()
	{}
	cake(string word1, string word2, string word3) : name(word3), product(word1, word2)
	{}
	cake(float number) : name("����������"), product(number)
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
		cout << "���: " << any.name << endl;
	}
};

class Curator
{
public:
	void ICanModify(cake &ck)
	{
		cout << "������� ����� ���: "; cin >> ck.name;
	}
};

class candys : public product
{
private:
	string name;
public:
	~candys()
	{
		name = "����������";
		product::~product();
	}
	candys() : name("����������"), product()
	{}
	candys(string word1, string word2, string word3) : name(word3), product(word1, word2)
	{}
	candys(float number) : name("����������"), product(number)
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
		model = "�� ����������";
		good::~good();
	}
	watch() : model("�� ���������"), good()
	{}
	watch(string word1, string word2) : model(word2), good(word1)
	{}
	watch(float number) : model("�� ���������"), good(number)
	{}
	watch(string word1, string word2, float number) : model(word2), good(word1, number)
	{}
	watch(string word1, string word2, int number) : model(word2), good(word1, number)
	{}
	//C bool
	watch(bool eve) : model("�� ���������"), good(eve)
	{}
	watch(string word1, string word2, bool eve) : model(word2), good(word1, eve)
	{}
	watch(float number, bool eve) : model("�� ���������"), good(number, eve)
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
		kind = "�� ��������";
		good::~good();
	}
	flowers() : kind("�� ��������"), good()
	{}
	flowers(string word1, string word2) : kind(word2), good(word1)
	{}
	flowers(float number) : kind("�� ��������"), good(number)
	{}
	flowers(string word1, string word2, float number) : kind(word2), good(word1, number)
	{}
	flowers(string word1, string word2, int number) : kind(word2), good(word1, number)
	{}
	//C bool
	flowers(bool eve) : kind("�� ��������"), good(eve)
	{}
	flowers(string word1, string word2, bool eve) : kind(word2), good(word1, eve)
	{}
	flowers(float number, bool eve) : kind("�� ��������"), good(number, eve)
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
				cout << "�������� �������� �� ��������, ��� ��� ���������\n����������� ���������� ���-�� ��������� ������ flowers" << endl;
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