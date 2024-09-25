#include<iostream>
#include<string>

using namespace std;
/*
	�н���ģʽ����һ���н��������װ����֮��Ľ�����Ϊ���н���ʹ����֮�䲻����ʽ�����ã����������֮�����ϡ�
	�����ģʽ������
		�����ߺͱ������߶��Ǽ̳���ͬһ���ӿڡ������Ǵ�����ӵ��һ���������ߵĶ���
		�н��ߺ�ί���������Բ�ͬ���ࡣί����ӵ��һ���н��߶����н����ӵ�ж��ί���ˡ�
*/
class Colleague;
class Mediator {  // �����н�
public:
	virtual void send(string message, Colleague* c) = 0;
};

class Colleague {  // ����ί����
protected:
	Mediator* mediator;
public:
	Colleague(Mediator* m) : mediator(m) {}
};

class ConcreteColleague1 : public Colleague {
public:
	ConcreteColleague1(Mediator* m) :Colleague(m) {}
	void send(string m) { mediator->send(m, this); }  // ͨ���н�ת��
	void notify(string m) { cout << "colleague 1 " << m << endl; }
};
class ConcreteColleague2 : public Colleague {
public:
	ConcreteColleague2(Mediator* m) :Colleague(m) {}
	void send(string m) { mediator->send(m, this); } // ͨ���н�ת��
	void notify(string m) { cout << "colleague 2 " << m << endl; }
};

class ConcreteMediator : public Mediator {
	ConcreteColleague1* c1;
	ConcreteColleague2* c2;  // ������һί���˶��������ǡ�����������ί����ҲΥ���˷�տ���ԭ��
public:
	void setConcreteColleague1(ConcreteColleague1* c) { c1 = c; }
	void setConcreteColleague2(ConcreteColleague2* c) { c2 = c; }
	void send(string message, Colleague* c) {
		if (c == c1) c1->notify(message);  // �н�ת��
		else c2->notify(message);
	}
};

//int main() {
//	ConcreteMediator* m = new ConcreteMediator();
//	// ί���˰��н�
//	ConcreteColleague1* c1 = new ConcreteColleague1(m);
//	ConcreteColleague2* c2 = new ConcreteColleague2(m);
//	// �н��ί����
//	m->setConcreteColleague1(c1);
//	m->setConcreteColleague2(c2);
//
//	c1->send("������");
//	c2->send("����");
//}
