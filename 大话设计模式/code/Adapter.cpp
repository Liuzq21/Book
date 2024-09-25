#include<iostream>
#include<string>
using namespace std;
/*
	适配器模式：将一个类的接口转换成客户希望的另一个接口。
	可以使得接口不兼容的类一起工作。
	适配器应该干两件事： 1. 继承Target 2. 包装Adaptee
*/

class Target {  // 这是客户所期待的接口
public:
	virtual void request() {
		cout << "普通请求！" << endl;
	}
};

class Adaptee {  // 这是现有的接口
public:
	void SpecificRequest() {
		cout << "特殊请求！" << endl;
	}
};

class Adapter : public Target {  // 1. 继承Target
	Adaptee* adaptee;           //  2. 包装Adaptee
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