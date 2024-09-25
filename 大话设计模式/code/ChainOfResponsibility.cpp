#include<iostream>
#include<string>
#include<list>
using namespace std;

/*
	责任链模式：使多个对象都有机会处理请求，从而避免发送者和接收者之间的耦合关系。
			   将这些对象连成一条链，并沿着这条链传递请求，直到有一个对象处理它为止。
	和状态模式类似。都是自己处理不了就丢给下一个。不同点在于：
		状态模式内部记录一个公共状态，对其进行判断是否处理。
		责任链模式内部记录一个继任者，接收一个请求，当请求不是自己的能处理时，递交给继任者。
*/

class AbstractManager
{
public:
	AbstractManager() : m_supervisorManager(nullptr) {}
	void setNextManger(AbstractManager* manager) { m_supervisorManager = manager; }
    virtual void handleRequest(const double& fee) = 0;

protected:
    AbstractManager* m_supervisorManager;   //next respons chain
};

class CommonManager : public AbstractManager {
public:
	CommonManager() {}
	void handleRequest(const double& fee) {
		if (fee <= 2) { cout << "经理 批准！" << endl; }
		else {
			if (m_supervisorManager != nullptr) m_supervisorManager->handleRequest(fee);
		}
	}
};

class Majordomo : public AbstractManager {
public:
	Majordomo() {}
	void handleRequest(const double& fee) {
		if (fee <= 5) { cout << "总监 批准！" << endl; }
		else {
			if (m_supervisorManager != nullptr) m_supervisorManager->handleRequest(fee);
		}
	}
};

class GeneralManager : public AbstractManager {
public:
	GeneralManager() {}
	void handleRequest(const double& fee) {
		cout << "总经理 批准！" << endl; 
	}
};

/*int main() {
	CommonManager* c = new CommonManager();
	Majordomo* m = new Majordomo();
	GeneralManager* g = new GeneralManager();

	c->setNextManger(m);
	m->setNextManger(g);

	c->handleRequest(1);
	c->handleRequest(4);
	c->handleRequest(10);

}*/