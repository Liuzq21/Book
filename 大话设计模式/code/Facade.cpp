#include<string>
#include <iostream>
using std::string;
/*
	���ģʽ��Ϊ��ϵͳ�е�һ��ӿ��ṩ��һ��һ�µĽ��棬������һ���߼��ӿڣ�ʹ����ϵͳ������ʹ�á�
*/

class SubSystemA {
public:
	void method1() { std::cout << "A" << std::endl; }
};

class SubSystemB {
public:
	void method1() { std::cout << "B" << std::endl; }
};
class SubSystemC {
public:
	void method1() { std::cout << "C" << std::endl; }
};

class Facade {
	SubSystemA* subA;
	SubSystemB* subB;
	SubSystemC* subC;
public:
	void methodCombine() {
		subA->method1();
		subB->method1();
		subC->method1();
	}
	Facade(){
		subA = new SubSystemA();
		subB = new SubSystemB();
		subC = new SubSystemC();
	}
	~Facade() {
		delete subA;
		delete subB;
		delete subC;
	}
};

//int main() {
//	Facade* f = new Facade();
//	f->methodCombine();
//	delete f;
//}