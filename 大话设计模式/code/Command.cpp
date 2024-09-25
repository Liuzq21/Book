#include<iostream>
#include<string>
#include<list>
using namespace std;
/*
	命令模式：将请求封装为一个对象，从而使你可以用不同的请求对客户进行参数化。
	优点
		- 将调用操作的对象与知道如何实现该操作的对象解耦。
		- 方便扩展，增加新的命令很容易，不需要改变已有类。
		- 可以将多个命令配成复合指令。
*/

class Barbecuer {  // 命令的具体执行者
public:
	void BakeMutton() { cout << "烤羊肉串！" << endl; }
	void BakeChickenWing() { cout << "烤鸡翅！" << endl; }
};

class Command {  // 命令的抽象
protected:
	Barbecuer m_babecuer;  // 指定由谁执行
public:
	Command(Barbecuer& babecuer) : m_babecuer(babecuer) {} ;
	virtual void excutecommand() = 0;
};

class BakeMuttonCommand : public Command {  // 具体的命令1
public:
	BakeMuttonCommand(Barbecuer& babecuer) : Command(babecuer) {};
	void excutecommand() {
		m_babecuer.BakeMutton();
	}
};

class BakeChickenWingCommand : public Command { // 具体的命令1
public:
	BakeChickenWingCommand(Barbecuer& babecuer) : Command(babecuer) {};
	void excutecommand() {
		m_babecuer.BakeChickenWing();
	}
};

class Waiter {  // 传递命令执行请求
	list<Command*> orders;
public:
	void setOrder(Command* c) {
		orders.push_back(c);
	}
	void cancelOrder(Command* c) {
		orders.remove(c);
	}
	void notify() {
		for (auto& c : orders) {
			c->excutecommand();
		}
	}
};

//int main() {
//	Barbecuer b = Barbecuer();
//	Command* c1 = new BakeMuttonCommand(b);
//	Command* c2 = new BakeChickenWingCommand(b);
//	Waiter w = Waiter();
//
//	w.setOrder(c1);
//	w.setOrder(c2);
//	w.setOrder(c1);
//	w.setOrder(c1);
//	w.notify();
//}