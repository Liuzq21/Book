#include<iostream>
#include<string>
#include<list>
using namespace std;

/*
	访问者模式：作用于某种数据结构中的各元素的操作分离出来封装成独立的类，使其在不改变数据结构的前提下可以添加作用于这些元素的新的操作，为数据结构中的每个元素提供多种访问方式。
	它将对数据的操作与数据结构进行分离，是行为类模式中最复杂的一种模式。
	优点
		扩展性好。能够在不修改对象结构中的元素的情况下，为对象结构中的元素添加新的功能。
		复用性好。可以通过访问者来定义整个对象结构通用的功能，从而提高系统的复用程度。
		灵活性好。访问者模式将数据结构与作用于结构上的操作解耦，使得操作集合可相对自由地演化而不影响系统的数据结构。
		符合单一职责原则。访问者模式把相关的行为封装在一起，构成一个访问者，使每一个访问者的功能都比较单一。
	缺点
		增加新的元素类很困难。在访问者模式中，每增加一个新的元素类，都要在每一个具体访问者类中增加相应的具体操作，这违背了“开闭原则”。
		破坏封装。访问者模式中具体元素对访问者公布细节，这破坏了对象的封装性。
————————————————

版权声明：本文为博主原创文章，遵循 CC 4.0 BY-NC-SA 版权协议，转载请附上原文出处链接和本声明。

原文链接：https://blog.csdn.net/Bing_Lee/article/details/108314146
*/
class ElementA;
class ElementB;
class Visitor {
public:
	virtual void visitElementA(ElementA& a) = 0;
	virtual void visitElementB(ElementB& a) = 0;
};

class Element {
public:
	virtual void accept(Visitor* v) = 0;
};

class ElementA:public Element {
public:
	void accept(Visitor* v) {
		v->visitElementA(*this);
	}
};
class ElementB: public Element {
public:
	void accept(Visitor* v) {
		v->visitElementB(*this);
	}

};

class ConcreteVisitor1 :public Visitor {
public:
	void visitElementA(ElementA& a) {
		cout << "A 被 ConcreteVisitor1 访问" << endl;
	}
	void visitElementB(ElementB& b) {
		cout << "B 被 ConcreteVisitor1 访问" << endl;
	}
};

class ObjectStructure {
	list<Element*> elements;
public:
	void attach(Element* e) {
		elements.push_back(e);
	}
	void detach(Element* e) {
		elements.remove(e);
	}
	void accept(Visitor* v) {
		for (auto e : elements) {
			e->accept(v);
		}
	}
};

//int main() {
//	ObjectStructure o = ObjectStructure();
//	Element* a = new ElementA();
//	o.attach(a);
//	Element* b1 = new ElementB();
//	o.attach(b1);
//	o.attach((Element*)new ElementB());
//	Visitor* v = new ConcreteVisitor1();
//	o.accept(v);
//}

