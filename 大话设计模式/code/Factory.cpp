#include<iostream>
#include<string>
/*
	����ģʽ��򵥹���ģʽ�Աȣ�
	����ģʽ����������Ϊһ���࣬��ͬ�ļӹ����ֱ�̳����������
	�ô����˷��˼򵥹����Ŀ��ŷ��ԭ�򣬽��Ϳͻ��������Ʒ����������
	������ÿ����һ����Ʒ�඼Ҫ����һ����Ʒ�����࣬�����˴��뿪����
*/
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