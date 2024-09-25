#include<iostream>
#include<string>
#include<list>
using namespace std;

/*
	������ģʽ��������ĳ�����ݽṹ�еĸ�Ԫ�صĲ������������װ�ɶ������࣬ʹ���ڲ��ı����ݽṹ��ǰ���¿��������������ЩԪ�ص��µĲ�����Ϊ���ݽṹ�е�ÿ��Ԫ���ṩ���ַ��ʷ�ʽ��
	���������ݵĲ��������ݽṹ���з��룬����Ϊ��ģʽ����ӵ�һ��ģʽ��
	�ŵ�
		��չ�Ժá��ܹ��ڲ��޸Ķ���ṹ�е�Ԫ�ص�����£�Ϊ����ṹ�е�Ԫ������µĹ��ܡ�
		�����Ժá�����ͨ����������������������ṹͨ�õĹ��ܣ��Ӷ����ϵͳ�ĸ��ó̶ȡ�
		����Ժá�������ģʽ�����ݽṹ�������ڽṹ�ϵĲ������ʹ�ò������Ͽ�������ɵ��ݻ�����Ӱ��ϵͳ�����ݽṹ��
		���ϵ�һְ��ԭ�򡣷�����ģʽ����ص���Ϊ��װ��һ�𣬹���һ�������ߣ�ʹÿһ�������ߵĹ��ܶ��Ƚϵ�һ��
	ȱ��
		�����µ�Ԫ��������ѡ��ڷ�����ģʽ�У�ÿ����һ���µ�Ԫ���࣬��Ҫ��ÿһ���������������������Ӧ�ľ����������Υ���ˡ�����ԭ�򡱡�
		�ƻ���װ��������ģʽ�о���Ԫ�ضԷ����߹���ϸ�ڣ����ƻ��˶���ķ�װ�ԡ�
��������������������������������

��Ȩ����������Ϊ����ԭ�����£���ѭ CC 4.0 BY-NC-SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӻͱ�������

ԭ�����ӣ�https://blog.csdn.net/Bing_Lee/article/details/108314146
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
		cout << "A �� ConcreteVisitor1 ����" << endl;
	}
	void visitElementB(ElementB& b) {
		cout << "B �� ConcreteVisitor1 ����" << endl;
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

