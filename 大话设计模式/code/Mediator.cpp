#include<iostream>
#include<string>

using namespace std;
/*
	中介者模式：用一个中介对象来封装对象之间的交互行为。中介者使对象之间不用显式的引用，降低类对象之间的耦合。
	与代理模式的区别：
		代理者和被代理者都是继承自同一个接口。并且是代理者拥有一个被代理者的对象。
		中介者和委托人是来自不同的类。委托人拥有一个中介者对象。中介对象拥有多个委托人。
*/
class Colleague;
class Mediator {  // 抽象中介
public:
	virtual void send(string message, Colleague* c) = 0;
};

class Colleague {  // 抽象委托人
protected:
	Mediator* mediator;
public:
	Colleague(Mediator* m) : mediator(m) {}
};

class ConcreteColleague1 : public Colleague {
public:
	ConcreteColleague1(Mediator* m) :Colleague(m) {}
	void send(string m) { mediator->send(m, this); }  // 通过中介转发
	void notify(string m) { cout << "colleague 1 " << m << endl; }
};
class ConcreteColleague2 : public Colleague {
public:
	ConcreteColleague2(Mediator* m) :Colleague(m) {}
	void send(string m) { mediator->send(m, this); } // 通过中介转发
	void notify(string m) { cout << "colleague 2 " << m << endl; }
};

class ConcreteMediator : public Mediator {
	ConcreteColleague1* c1;
	ConcreteColleague2* c2;  // 这里万一委托人多起来岂不是。。而且增加委托人也违反了封闭开放原则
public:
	void setConcreteColleague1(ConcreteColleague1* c) { c1 = c; }
	void setConcreteColleague2(ConcreteColleague2* c) { c2 = c; }
	void send(string message, Colleague* c) {
		if (c == c1) c1->notify(message);  // 中介转发
		else c2->notify(message);
	}
};

//int main() {
//	ConcreteMediator* m = new ConcreteMediator();
//	// 委托人绑定中介
//	ConcreteColleague1* c1 = new ConcreteColleague1(m);
//	ConcreteColleague2* c2 = new ConcreteColleague2(m);
//	// 中介绑定委托人
//	m->setConcreteColleague1(c1);
//	m->setConcreteColleague2(c2);
//
//	c1->send("吃了吗？");
//	c2->send("吃了");
//}
