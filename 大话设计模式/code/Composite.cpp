#include<iostream>
#include<string>
#include<list>
using namespace std;
/*
	���ģʽ����������ϳ����νṹ��ʾ������-���塯�Ĳ�νṹ��
	��Ϊ͸����ʽ�밲ȫ��ʽ��͸����ʽ���ǣ���leaf����о߱�����Ч��add��remove����
*/

class Company { // ������
	
public:
	string name;
	Company(string _name) : name(_name) {}
	virtual void add(Company* c) {};   // ��������1
	virtual void remove(Company* c) {};  // ��������2
	virtual void display(int depth) {};
};

class ConcreteCompany : public Company {  // ���ڵ�
	list<Company*> children;
public:
	ConcreteCompany(string name) : Company(name){
		children = list<Company*>();
	}
	void add(Company* c) override{
		children.push_back(c);
	}
	void remove(Company* c) override {
		children.remove(c);
	}
	void display(int depth) override {
		cout << string(depth, '-') << name << endl;
		for (auto c : children) {
			c->display(depth + 2);
		}
	}

};

class HRDepartment : public Company {  // Ҷ�ڵ�
public:
	HRDepartment(string name) : Company(name) {}
	void display(int depth) override {
		cout << string(depth, '-') << name << endl;
	}
};

//int main() {
//	ConcreteCompany* root = new ConcreteCompany("�����ܹ�˾");
//	root->add(new HRDepartment("�ܹ�˾������Դ����"));
//	ConcreteCompany* comp = new ConcreteCompany("�Ϻ������ֹ�˾");
//	root->add(comp);
//	root->display(1);
//}