#include<iostream>
#include<string>
using std::string;
/*动态地给一个对象添加一些额外的职责，就增加功能来说，装饰模式比生成子类更为灵活*/
/*与策略模式的不同：
	策略模式是在工厂(与基类无关)中添加基类指针管理派生类。
	装饰模式是在 在派生的抽象基类中，设置基类的指针管理的派生类。并且需要在派生类中手动执行父类虚函数
*/
class Person {  // 基类
	string _name;
public:
	Person() {}
	Person(string name):_name(name) {}
	virtual ~Person() {}
	virtual void show() { std::cout << "装扮的" << _name ; } // 虚函数接口

};

class Finery : public Person {  // 派生的基类
protected:
	Person* _component;  // 关键1，在派生的抽象基类(Finery)中，设置基类(Person)的指针
public:
	Finery(Person* component):_component(component) {} // 这样子需要默认构造函数
	virtual ~Finery() {}
	void decorate(Person* component) {
		_component = component;
	}
	virtual void show() {
		_component->show();  // 关键2，调用由基类指针管理的派生类的函数	
	}
};

class Tshirt : public Finery {  // 派生类
public:
	Tshirt(Person* p) : Finery(p) {}
	void show() {
		Finery::show();     // 关键3，这样子调用父类的函数，进而调用绑定的派生类(Tshirt, BigTrouser)
		std::cout << " T恤" ;
	}
};

class BigTrouser : public Finery {
public:
	BigTrouser(Person* p) : Finery(p) {}
	void show() {
		Finery::show();
		std::cout << " 垮裤" ;
	}
};

//int main(){
//	Person* p = new Person("lzq");
//	Person* t = new Tshirt(p);
//	t->show();
//	std::cout << std::endl;
//	Person* b = new BigTrouser(t);
//	/*
//		解释具体过程：继承关系为 Person--》Finery--》BigTrouser
//		b 调用 自己的show() ，由于在show中写了Finery::show();，因此先找Finery的show。
//		而Finery中show()为 _component->show();  // 调用由基类指针管理的派生类的函数
//		这个基类指针管理的派生类 正好是 前一个绑定的Tshirt类对象t
//		因此先调用t的show(), 同理又得先调用p的show()。
//		最终倒推回去，即真正的调用顺序为 Person::show() , Finery::show() , BigTrouser::show()
//		正好与绑定顺序相同。
//		由此可以看出，装饰模式可以动态的添加功能，并且功能间有顺序。
//	*/
//	b->show();
//
//	delete p;
//	delete t;
//	delete b;
//}

