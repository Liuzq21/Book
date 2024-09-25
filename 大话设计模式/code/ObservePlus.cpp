#include <iostream>
#include <functional>
#include <map>
#include <string>
using namespace std;
/*
	观察模式进阶版：实现不同观察者对主题更新，调用自定义的方法。核心代码如下
	typedef function<int(int)> EventHandler;
	map<Observer*, EventHandler> observers;  // 绑定了所有观察者极其update时要调用的函数
	ConcreteObserver1 observer = ConcreteObserver1(concreteSubject);
	EventHandler eh1 = bind(&ConcreteObserver1::update1, &observer, placeholders::_1);  // bind依次参数含义：执行的代码，调用次代码需要的对象，代码的传参个数
	concreteSubject->Attach(&observer, eh1); // 把观察者及其update函数加进去
*/

// 定义事件处理函数类型
typedef function<int(int)> EventHandler;

class Observer {
public:
	virtual ~Observer() {};
	// virtual void Update(int) = 0;  // 这个不要了，使用派生类自己的函数
};


class Subject {
public:
	virtual ~Subject() {};
	virtual void Attach(Observer* pObserver, EventHandler eventHandler) = 0;
	virtual void Detach(Observer* pObserver, EventHandler eventHandler) = 0;
	virtual void Notify() = 0;
};

class ConcreteSubject : public Subject {
	map<Observer*, EventHandler> observers;  // 绑定了所有观察者极其update时要调用的函数
	int state;   // Subject 的状态
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
			pair.second(state);   // 传递一个示例参数
		}
	}
	void setState(int state) {
		this->state = state;
	}
};

class ConcreteObserver1 : public Observer {
	Subject* subject; // 观察的目标
public:
	ConcreteObserver1(Subject* s): subject(s) {

	}
	int update1(int state) {
		cout << "this is ConcreteObserver1 , the state is " << state << endl;
		return 1;
	}
};

class ConcreteObserver2 : public Observer {
	Subject* subject; // 观察的目标
public:
	ConcreteObserver2(Subject* s) : subject(s) {}
	int update2(int state) {
		cout << "this is ConcreteObserver2 , the state is " << state << endl;
		return 1;
	}
};

//类的成员函数和类的静态成员函数
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
//	EventHandler eh1 = bind(&ConcreteObserver1::update1, &observer, placeholders::_1);  // bind依次参数含义：执行的代码，调用次代码需要的对象，代码的传参个数
//	concreteSubject->Attach(&observer, eh1); // 把观察者及其update函数加进去
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