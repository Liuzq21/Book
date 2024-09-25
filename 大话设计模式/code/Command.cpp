#include<iostream>
#include<string>
#include<list>
using namespace std;
/*
	����ģʽ���������װΪһ�����󣬴Ӷ�ʹ������ò�ͬ������Կͻ����в�������
	�ŵ�
		- �����ò����Ķ�����֪�����ʵ�ָò����Ķ�����
		- ������չ�������µ���������ף�����Ҫ�ı������ࡣ
		- ���Խ����������ɸ���ָ�
*/

class Barbecuer {  // ����ľ���ִ����
public:
	void BakeMutton() { cout << "�����⴮��" << endl; }
	void BakeChickenWing() { cout << "�����ᣡ" << endl; }
};

class Command {  // ����ĳ���
protected:
	Barbecuer m_babecuer;  // ָ����˭ִ��
public:
	Command(Barbecuer& babecuer) : m_babecuer(babecuer) {} ;
	virtual void excutecommand() = 0;
};

class BakeMuttonCommand : public Command {  // ���������1
public:
	BakeMuttonCommand(Barbecuer& babecuer) : Command(babecuer) {};
	void excutecommand() {
		m_babecuer.BakeMutton();
	}
};

class BakeChickenWingCommand : public Command { // ���������1
public:
	BakeChickenWingCommand(Barbecuer& babecuer) : Command(babecuer) {};
	void excutecommand() {
		m_babecuer.BakeChickenWing();
	}
};

class Waiter {  // ��������ִ������
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