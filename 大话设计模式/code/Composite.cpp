#include<iostream>
#include<string>
#include<list>
using namespace std;
/*
	组合模式：将对象组合成树形结构表示‘部分-整体’的层次结构。
	分为透明方式与安全方式。透明方式就是，在leaf结点中具备但无效的add与remove功能
*/

class Company { // 抽象类
	
public:
	string name;
	Company(string _name) : name(_name) {}
	virtual void add(Company* c) {};   // 基本方法1
	virtual void remove(Company* c) {};  // 基本方法2
	virtual void display(int depth) {};
};

class ConcreteCompany : public Company {  // 树节点
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

class HRDepartment : public Company {  // 叶节点
public:
	HRDepartment(string name) : Company(name) {}
	void display(int depth) override {
		cout << string(depth, '-') << name << endl;
	}
};

//int main() {
//	ConcreteCompany* root = new ConcreteCompany("北京总公司");
//	root->add(new HRDepartment("总公司人力资源部门"));
//	ConcreteCompany* comp = new ConcreteCompany("上海华东分公司");
//	root->add(comp);
//	root->display(1);
//}