#include<iostream>
#include<string>
#include<vector>
using std::string;
/*
	建造者模式：将一个复杂对象的构建和表示分离，使得同样的构建过程可以创造不同的表示
*/

class Product {
	std::vector<string> parts;
public: 
	void add(string part) {
		parts.emplace_back(part);
	}
	void show() {
		for (const auto& s : parts) {
			std::cout << s << " ";
		}
		std::cout << std::endl;
	}
};

class Builder {
public:
	virtual void buildPartA() = 0;
	virtual void buildPartB() = 0;
	virtual Product* getResult() = 0;
	virtual ~Builder() {};
};

class ConcreteBuilderA : public Builder {
	Product* p;
public:
	ConcreteBuilderA() { p = new Product(); }
	void buildPartA() { p->add("part a"); }
	void buildPartB() { p->add("part b"); }
	Product* getResult() { return p;}
};

class ConcreteBuilderB : public Builder {
	Product* p;
public:
	ConcreteBuilderB() { p = new Product(); }
	void buildPartA() { p->add("part x"); }
	void buildPartB() { p->add("part y"); }
	Product* getResult() { return p; }
};

class Director {
public:
	void construct(Builder* builder) {
		builder->buildPartA();
		builder->buildPartB();
	}
};

//int main() {
//	Director* d = new Director();
//	Builder* b1 = new ConcreteBuilderA();
//	Builder* b2 = new ConcreteBuilderB();
//	d->construct(b1);
//	Product* p1 = b1->getResult();
//	p1->show();
//	d->construct(b2);
//	Product* p2 = b2->getResult();
//	p2->show();
//}