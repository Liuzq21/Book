#include<iostream>
#include<string>
#include<list>
using namespace std;

/*
	������ģʽ��ʹ��������л��ᴦ�����󣬴Ӷ����ⷢ���ߺͽ�����֮�����Ϲ�ϵ��
			   ����Щ��������һ��������������������������ֱ����һ����������Ϊֹ��
	��״̬ģʽ���ơ������Լ������˾Ͷ�����һ������ͬ�����ڣ�
		״̬ģʽ�ڲ���¼һ������״̬����������ж��Ƿ���
		������ģʽ�ڲ���¼һ�������ߣ�����һ�����󣬵��������Լ����ܴ���ʱ���ݽ��������ߡ�
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
		if (fee <= 2) { cout << "���� ��׼��" << endl; }
		else {
			if (m_supervisorManager != nullptr) m_supervisorManager->handleRequest(fee);
		}
	}
};

class Majordomo : public AbstractManager {
public:
	Majordomo() {}
	void handleRequest(const double& fee) {
		if (fee <= 5) { cout << "�ܼ� ��׼��" << endl; }
		else {
			if (m_supervisorManager != nullptr) m_supervisorManager->handleRequest(fee);
		}
	}
};

class GeneralManager : public AbstractManager {
public:
	GeneralManager() {}
	void handleRequest(const double& fee) {
		cout << "�ܾ��� ��׼��" << endl; 
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