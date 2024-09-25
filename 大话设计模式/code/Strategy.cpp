#include<iostream>
#include<string>
using std::string;
/*
	1. 减少耦合
	2. 不同策略方便测试
	3. 客户选择策略模式，具体实现交由Context对象
*/
class CashSuper { // Strategy
public:
	virtual double acceptCash(double money) = 0;
};

class CashNormal : public CashSuper { // 派生类StrategyA
	double acceptCash(double money) {
		return money;
	}
};

class CashRebate : public CashSuper { // 派生类StrategyB
private:
	double _moneyRebate;
public:
	CashRebate(double moneyRebate) : _moneyRebate(moneyRebate) {}

	double acceptCash(double money) { 
		return money*_moneyRebate;
	}
};

class CashReturn : public CashSuper { // 派生类StrategyC
	double _moneyCondition;
	double _moneyReturn;
public:
	CashReturn(double moneyCondition, double moneyReturn) : _moneyCondition(moneyCondition), _moneyReturn(moneyReturn) {}
	double acceptCash(double money) {
		if (money >= _moneyCondition) return money - _moneyReturn;
		return money;
	}
};

class CashContext { // 策略模式 + 简单工厂模式
private:
	CashSuper* cs;  // 感觉与简单工厂的区别在于多个私有成员。一直存在
public:
	CashContext(string type) {
		cs = nullptr;
		if (type == "normal") {
			cs = new CashNormal();
		}
		else if (type == "rebate") {
			cs = new CashRebate(0.8); // 这里写死了0.8，能否在不增加新策略的情况下修改？
		}
		else if (type == "return") {
			cs = new CashReturn(300, 30); // 同理，能否修改？
		}
	}

	double getResult(double money) {
		return cs->acceptCash(money);
	}
};
/*

int main() {
	// 模拟客户端行为 
	double price = std::stod("12.5");
	int numbers = std::stoi("5");
	double totalPrice = price * numbers;
	string strategyStr = "rebate";

	CashContext cc = CashContext(strategyStr);
	std::cout << cc.getResult(totalPrice);

}
*/