#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::cin;
/*
	�۲���ģʽ��������һ��һ�Զ��������ϵ���ö���۲��߶���ͬʱ����ĳһ���������������������״̬�����ı�ʱ��
	��֪ͨ���й۲��߶���ʹ�������ܹ��Զ������Լ���
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
		//��Ŀ����ע�ᵱǰ�۲��ߣ��˴��Ĺ۲����ǹ����ϵĹ۲��ߣ�Ŀ�겢��֪������˭Ҫ�۲�����Ŀ��ֻ���й㲥���ɣ�
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
		//��Ŀ����ע�ᵱǰ�۲��ߣ��˴��Ĺ۲����ǹ����ϵĹ۲��ߣ�Ŀ�겢��֪������˭Ҫ�۲�����Ŀ��ֻ���й㲥���ɣ�
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
	std::list<Observer*> _pObserverList;  // �ؼ�
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
//	//����Ŀ��
//	ConcreteSubject* pSubject = new ConcreteSubject();
//
//	//�����۲���
//	Observer* pObserver = new ConcreteObserver(pSubject);
//	Observer* pObserver2 = new ConcreteObserver2(pSubject);
//
//	//�ı䵱ǰ״̬
//	pSubject->SetState(2);
//
//	//�㲥�����й����ϵĹ۲���
//	pSubject->Notify();
//
//	//ȥ��ĳ���۲���
//	pSubject->Detach(pObserver);
//
//	//�ı䵱ǰ״̬
//	pSubject->SetState(3);
//
//	//���¹㲥
//	pSubject->Notify();
//
//
//	//�������ͷŶ���
//	delete pObserver;
//	delete pObserver2;
//	delete pSubject;
//	return 0;
//}
