#include<string>
#include <iostream>
using std::string;
/*
	外观模式：为子系统中的一组接口提供了一个一致的界面，定义了一个高级接口，使得子系统更便于使用。
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