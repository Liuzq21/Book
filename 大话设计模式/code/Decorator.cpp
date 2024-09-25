#include<iostream>
#include<string>
using std::string;
/*��̬�ظ�һ���������һЩ�����ְ�𣬾����ӹ�����˵��װ��ģʽ�����������Ϊ���*/
/*�����ģʽ�Ĳ�ͬ��
	����ģʽ���ڹ���(������޹�)����ӻ���ָ����������ࡣ
	װ��ģʽ���� �������ĳ�������У����û����ָ�����������ࡣ������Ҫ�����������ֶ�ִ�и����麯��
*/
class Person {  // ����
	string _name;
public:
	Person() {}
	Person(string name):_name(name) {}
	virtual ~Person() {}
	virtual void show() { std::cout << "װ���" << _name ; } // �麯���ӿ�

};

class Finery : public Person {  // �����Ļ���
protected:
	Person* _component;  // �ؼ�1���������ĳ������(Finery)�У����û���(Person)��ָ��
public:
	Finery(Person* component):_component(component) {} // ��������ҪĬ�Ϲ��캯��
	virtual ~Finery() {}
	void decorate(Person* component) {
		_component = component;
	}
	virtual void show() {
		_component->show();  // �ؼ�2�������ɻ���ָ������������ĺ���	
	}
};

class Tshirt : public Finery {  // ������
public:
	Tshirt(Person* p) : Finery(p) {}
	void show() {
		Finery::show();     // �ؼ�3�������ӵ��ø���ĺ������������ð󶨵�������(Tshirt, BigTrouser)
		std::cout << " T��" ;
	}
};

class BigTrouser : public Finery {
public:
	BigTrouser(Person* p) : Finery(p) {}
	void show() {
		Finery::show();
		std::cout << " ���" ;
	}
};

//int main(){
//	Person* p = new Person("lzq");
//	Person* t = new Tshirt(p);
//	t->show();
//	std::cout << std::endl;
//	Person* b = new BigTrouser(t);
//	/*
//		���;�����̣��̳й�ϵΪ Person--��Finery--��BigTrouser
//		b ���� �Լ���show() ��������show��д��Finery::show();���������Finery��show��
//		��Finery��show()Ϊ _component->show();  // �����ɻ���ָ������������ĺ���
//		�������ָ������������ ������ ǰһ���󶨵�Tshirt�����t
//		����ȵ���t��show(), ͬ���ֵ��ȵ���p��show()��
//		���յ��ƻ�ȥ���������ĵ���˳��Ϊ Person::show() , Finery::show() , BigTrouser::show()
//		�������˳����ͬ��
//		�ɴ˿��Կ�����װ��ģʽ���Զ�̬����ӹ��ܣ����ҹ��ܼ���˳��
//	*/
//	b->show();
//
//	delete p;
//	delete t;
//	delete b;
//}

