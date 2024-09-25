#include<iostream>
#include<string>

class Operation { // ������
private:
	double _numberA;
	double _numberB;
public:
	Operation() :_numberA(0), _numberB(0) {}
	virtual double getResult() = 0;     // ���麯��
	void setNumberA(double numberA) { _numberA = numberA; }
	void setNumberB(double numberB) { _numberB = numberB; }
	double getNumberB() { return _numberB; }
	double getNumberA() { return _numberA; }
};

class OperationAdd : public Operation { // ������A
public:
	double getResult() {
		return getNumberA() + getNumberB();
	}
};

class OperationSub : public Operation { // ������B
public:
	double getResult() {
		return getNumberA() - getNumberB();
	}
};

class OperationDiv : public Operation { // ������C
public:
	double getResult() {
		if (!getNumberB()) {
			std::cout << "��������Ϊ0" << std::endl;
			return 0;
		}
		return getNumberA() / getNumberB();
	}
};

class OperationMul : public Operation { // ������D
public:
	double getResult() {
		return getNumberA() * getNumberB();
	}
};

class SimpleFactory {  // �������ɹ��������������ֶ���
public:
	static Operation* createOperation(char opc) { // ��̬����
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
	op = SimpleFactory::createOperation('+');  // ���������ӵ��þ�̬����
	std::cout<< op->getNumberA() << std::endl;
	op->setNumberA(3);
	op->setNumberB(4);
	std::cout << op->getResult() << std::endl;
	delete op;
}
*/