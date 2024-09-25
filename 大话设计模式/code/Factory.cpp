#include<iostream>
#include<string>
/*
	工厂模式与简单工厂模式对比：
	工厂模式将工厂抽象为一个类，不同的加工厂分别继承这个工厂。
	好处：克服了简单工厂的开放封闭原则，降低客户程序与产品对象的耦合性
	坏处：每增加一个产品类都要增加一个产品工厂类，增加了代码开发。
*/
class Operation { // 抽象类
private:
	double _numberA;
	double _numberB;
public:
	Operation() :_numberA(0), _numberB(0) {}
	virtual double getResult() = 0;     // 纯虚函数
	void setNumberA(double numberA) { _numberA = numberA; }
	void setNumberB(double numberB) { _numberB = numberB; }
	double getNumberB() { return _numberB; }
	double getNumberA() { return _numberA; }
};

class OperationAdd : public Operation { // 派生类A
public:
	double getResult() {
		return getNumberA() + getNumberB();
	}
};

class OperationSub : public Operation { // 派生类B
public:
	double getResult() {
		return getNumberA() - getNumberB();
	}
};

class OperationDiv : public Operation { // 派生类C
public:
	double getResult() {
		if (!getNumberB()) {
			std::cout << "除数不能为0" << std::endl;
			return 0;
		}
		return getNumberA() / getNumberB();
	}
};

class OperationMul : public Operation { // 派生类D
public:
	double getResult() {
		return getNumberA() * getNumberB();
	}
};

class IFacotry {
public:
	virtual Operation* createOperation() = 0;
	virtual ~IFacotry() {} ;
};

class AddFactory : public IFacotry {
public:
	Operation* createOperation() {
		return new OperationAdd();
	}
	
};

class SubFactory : public IFacotry {
public:
	Operation* createOperation() {
		return new OperationSub();
	}
	
};

//int main() {
//	IFacotry* operFactory = new AddFactory();
//	Operation* opadd = operFactory->createOperation();
//	opadd->setNumberA(3);
//	opadd->setNumberB(4);
//	std::cout << opadd->getResult();
//	delete opadd;
//	delete operFactory;
//
//}