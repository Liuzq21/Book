#include<iostream>
#include<string>

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

class SimpleFactory {  // 工厂，由工厂决定产出哪种对象
public:
	static Operation* createOperation(char opc) { // 静态方法
		Operation* op;
		switch (opc) {
		case '+':
			op = new OperationAdd();
			break;
		case '-':
			op = new OperationSub();
			break;
		case '*':
			op = new OperationMul();
			break;
		case '/':
			op = new OperationDiv();
			break;
		default:
			op = new OperationAdd();
		}
		return op;
	}
};
/*
int main()
{
	std::cout << "Hello World!\n";
	Operation* op;
	op = SimpleFactory::createOperation('+');  // 可以这样子调用静态方法
	std::cout<< op->getNumberA() << std::endl;
	op->setNumberA(3);
	op->setNumberB(4);
	std::cout << op->getResult() << std::endl;
	delete op;
}
*/