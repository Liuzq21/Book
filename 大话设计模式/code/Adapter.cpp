#include<iostream>
#include<string>
using namespace std;
/*
	������ģʽ����һ����Ľӿ�ת���ɿͻ�ϣ������һ���ӿڡ�
	����ʹ�ýӿڲ����ݵ���һ������
	������Ӧ�ø������£� 1. �̳�Target 2. ��װAdaptee
*/

class Target {  // ���ǿͻ����ڴ��Ľӿ�
public:
	virtual void request() {
		cout << "��ͨ����" << endl;
	}
};

class Adaptee {  // �������еĽӿ�
public:
	void SpecificRequest() {
		cout << "��������" << endl;
	}
};

class Adapter : public Target {  // 1. �̳�Target
	Adaptee* adaptee;           //  2. ��װAdaptee
public:
	void request() {
		adaptee->SpecificRequest();
	}
	Adapter() {
		adaptee = new Adaptee();
	}
};

//int main() {
//	Target* t = new Adapter();
//	t->request();
//}