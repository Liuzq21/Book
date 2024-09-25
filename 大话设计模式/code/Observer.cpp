#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::cin;
/*
	观察者模式：定义了一种一对多的依赖关系，让多个观察者对象同时监听某一个主题对象。这个主题对象在状态发生改变时，
	会通知所有观察者对象，使得他们能够自动更新自己。
*/


class Observer
{
public:
	virtual ~Observer() {};
	virtual void Update(int) = 0;
};


class Subject
{
public:
	virtual ~Subject() {};
	virtual void Attach(Observer*) = 0;
	virtual void Detach(Observer*) = 0;
	virtual void Notify() = 0;
};


class ConcreteObserver : public Observer
{
private:
	Subject* _pSubject;

public:
	ConcreteObserver(Subject* pSubject) :_pSubject(pSubject)
	{
		//在目标中注册当前观察者（此处的观察者是广义上的观察者，目标并不知道具体谁要观察它，目标只进行广播即可）
		this->_pSubject->Attach(this);
		cout << "I'm the observer \" 1 \".\n";
	}

	void Update(int value) override
	{
		cout << "ConcreteObserver get the update.New State:" << value << endl;
	}
};



class ConcreteObserver2 : public Observer
{
private:
	Subject* _pSubject;

public:
	ConcreteObserver2(Subject* pSubject) :_pSubject(pSubject)
	{
		//在目标中注册当前观察者（此处的观察者是广义上的观察者，目标并不知道具体谁要观察它，目标只进行广播即可）
		this->_pSubject->Attach(this);
		cout << "I'm the observer \" 2 \".\n";
	}

	void Update(int value) override
	{
		cout << "ConcreteObserver2 get the update.New State:" << value << endl;
	}
};


class ConcreteSubject :public Subject
{
private:
	std::list<Observer*> _pObserverList;  // 关键
	int _iState;
public:
	void SetState(int state)
	{
		_iState = state;
	}

	void Attach(Observer* pObserver) override
	{
		_pObserverList.push_back(pObserver);
	}


	void Detach(Observer* pObserver) override
	{
		_pObserverList.remove(pObserver);
	}


	void Notify() override
	{
		auto begin = _pObserverList.begin();
		auto end = _pObserverList.end();
		while (begin != end)
		{
			(*begin)->Update(_iState);
			begin++;
		}
	}
};

//int main()
//{
//	//创建目标
//	ConcreteSubject* pSubject = new ConcreteSubject();
//
//	//创建观察者
//	Observer* pObserver = new ConcreteObserver(pSubject);
//	Observer* pObserver2 = new ConcreteObserver2(pSubject);
//
//	//改变当前状态
//	pSubject->SetState(2);
//
//	//广播给所有广义上的观察者
//	pSubject->Notify();
//
//	//去除某个观察者
//	pSubject->Detach(pObserver);
//
//	//改变当前状态
//	pSubject->SetState(3);
//
//	//重新广播
//	pSubject->Notify();
//
//
//	//结束，释放对象
//	delete pObserver;
//	delete pObserver2;
//	delete pSubject;
//	return 0;
//}
