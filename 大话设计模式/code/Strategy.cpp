#include<iostream>
#include<string>
using std::string;
/*
	1. �������
	2. ��ͬ���Է������
	3. �ͻ�ѡ�����ģʽ������ʵ�ֽ���Context����
*/
class CashSuper { // Strategy
public:
	virtual double acceptCash(double money) = 0;
};

class CashNormal : public CashSuper { // ������StrategyA
	double acceptCash(double money) {
		return money;
	}
};

class CashRebate : public CashSuper { // ������StrategyB
private:
	double _moneyRebate;
public:
	CashRebate(double moneyRebate) : _moneyRebate(moneyRebate) {}

	double acceptCash(double money) { 
		return money*_moneyRebate;
	}
};

class CashReturn : public CashSuper { // ������StrategyC
	double _moneyCondition;
	double _moneyReturn;
public:
	CashReturn(double moneyCondition, double moneyReturn) : _moneyCondition(moneyCondition), _moneyReturn(moneyReturn) {}
	double acceptCash(double money) {
		if (money >= _moneyCondition) return money - _moneyReturn;
		return money;
	}
};

class CashContext { // ����ģʽ + �򵥹���ģʽ
private:
	CashSuper* cs;  // �о���򵥹������������ڶ��˽�г�Ա��һֱ����
public:
	CashContext(string type) {
		cs = nullptr;
		if (type == "normal") {
			cs = new CashNormal();
		}
		else if (type == "rebate") {
			cs = new CashRebate(0.8); // ����д����0.8���ܷ��ڲ������²��Ե�������޸ģ�
		}
		else if (type == "return") {
			cs = new CashReturn(300, 30); // ͬ���ܷ��޸ģ�
		}
	}

	double getResult(double money) {
		return cs->acceptCash(money);
	}
};
/*

int main() {
	// ģ��ͻ�����Ϊ 
	double price = std::stod("12.5");
	int numbers = std::stoi("5");
	double totalPrice = price * numbers;
	string strategyStr = "rebate";

	CashContext cc = CashContext(strategyStr);
	std::cout << cc.getResult(totalPrice);

}
*/