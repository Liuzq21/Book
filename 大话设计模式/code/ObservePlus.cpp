#include <iostream>
#include <functional>
#include <map>
#include <string>
using namespace std;
/*
	�۲�ģʽ���װ棺ʵ�ֲ�ͬ�۲��߶�������£������Զ���ķ��������Ĵ�������
	typedef function<int(int)> EventHandler;
	map<Observer*, EventHandler> observers;  // �������й۲��߼���updateʱҪ���õĺ���
	ConcreteObserver1 observer = ConcreteObserver1(concreteSubject);
	EventHandler eh1 = bind(&ConcreteObserver1::update1, &observer, placeholders::_1);  // bind���β������壺ִ�еĴ��룬���ôδ�����Ҫ�Ķ��󣬴���Ĵ��θ���
	concreteSubject->Attach(&observer, eh1); // �ѹ۲��߼���update�����ӽ�ȥ
*/

// �����¼�����������
typedef function<int(int)> EventHandler;

class Observer {
public:
	virtual ~Observer() {};
	// virtual void Update(int) = 0;  // �����Ҫ�ˣ�ʹ���������Լ��ĺ���
};


class Subject {
public:
	virtual ~Subject() {};
	virtual void Attach(Observer* pObserver, EventHandler eventHandler) = 0;
	virtual void Detach(Observer* pObserver, EventHandler eventHandler) = 0;
	virtual void Notify() = 0;
};

class ConcreteSubject : public Subject {
	map<Observer*, EventHandler> observers;  // �������й۲��߼���updateʱҪ���õĺ���
	int state;   // Subject ��״̬
public:

	void Attach(Observer* pObserver, EventHandler eventHandler) override
	{
		observers[pObserver] = eventHandler;
	}

	void Detach(Observer* pObserver, EventHandler eventHandler) override
	{
		observers.erase(pObserver);
	}
	void Notify() override {
		for (const auto& pair : observers) {
			pair.second(state);   // ����һ��ʾ������
		}
	}
	void setState(int state) {
		this->state = state;
	}
};

class ConcreteObserver1 : public Observer {
	Subject* subject; // �۲��Ŀ��
public:
	ConcreteObserver1(Subject* s): subject(s) {

	}
	int update1(int state) {
		cout << "this is ConcreteObserver1 , the state is " << state << endl;
		return 1;
	}
};

class ConcreteObserver2 : public Observer {
	Subject* subject; // �۲��Ŀ��
public:
	ConcreteObserver2(Subject* s) : subject(s) {}
	int update2(int state) {
		cout << "this is ConcreteObserver2 , the state is " << state << endl;
		return 1;
	}
};

//��ĳ�Ա��������ľ�̬��Ա����
class CTest
{
public:
	int Func(int a)
	{
		return a;
	}
};

//int main() {
//	ConcreteSubject* concreteSubject = new ConcreteSubject();
//	ConcreteObserver1 observer = ConcreteObserver1(concreteSubject);
//	EventHandler eh1 = bind(&ConcreteObserver1::update1, &observer, placeholders::_1);  // bind���β������壺ִ�еĴ��룬���ôδ�����Ҫ�Ķ��󣬴���Ĵ��θ���
//	concreteSubject->Attach(&observer, eh1); // �ѹ۲��߼���update�����ӽ�ȥ
//	ConcreteObserver2 observer2 = ConcreteObserver2(concreteSubject);
//	EventHandler eh2 = bind(&ConcreteObserver2::update2, &observer2, placeholders::_1);
//	concreteSubject->Attach(&observer2, eh2);
//
//	concreteSubject->setState(33);
//	concreteSubject->Notify();
//
//	concreteSubject->setState(2333);
//	concreteSubject->Notify();
//}