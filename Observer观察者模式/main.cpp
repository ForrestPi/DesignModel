// Observer观察者模式.cpp : 定义控制台应用程序的入口点。
//http://www.cnblogs.com/jiese/archive/2013/07/11/3183635.html

#include "stdafx.h"
#include "Observer.h"
#include <iostream>

using namespace std;

int main()
{
	Observer* p1 = new ConcreteObserverA();
	Observer* p2 = new ConcreteObserverB();
	Observer* p3 = new ConcreteObserverA();

	Subject* pSubject = new ConcreteSubjectA();
	pSubject->Attach(p1);
	pSubject->Attach(p2);
	pSubject->Attach(p3);

	pSubject->SetState("old");

	pSubject->Notify();

	cout << "-------------------------------------" << endl;
	pSubject->SetState("new");

	pSubject->Detach(p3);
	pSubject->Notify();

	return 0;
}
