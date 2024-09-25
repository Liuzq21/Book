#include<iostream>
#include<string>
using std::string;
/*
	代理模式，为其他对象提供一种代理以控制这个对象的访问
	远程代理
	虚拟代理：打开大网页时只显示文本，代理存储了图片的路径，图片有需要再由代理下载
	安全代理：控制对象的访问权限
	智能指引：比如当对象没人使用的时候，释放管理的对象。
*/
class SchoolGirl {
public:
	string m_name;
	SchoolGirl(string name) : m_name(name) {}
};
class IGiveGift { // 公共接口
public:
	virtual void giveDolls() = 0;
	virtual void giveFlowers() = 0;
	virtual void giveChocolate() = 0;

	virtual ~IGiveGift() {}; 
};

class Pursuit : public IGiveGift {
	SchoolGirl* mm;     // 这个不是必要的
public:
	Pursuit(SchoolGirl* m) :mm(m) {}
	void giveDolls() { std::cout << mm->m_name << "send dolls" << std::endl; }
	void giveFlowers() { std::cout << mm->m_name << "send flowers" << std::endl; }
	void giveChocolate() { std::cout << mm->m_name << "send chocolate" << std::endl; }
	~Pursuit() { delete mm; std::cout << "deleted pursuit " << std::endl;  }
};

class Proxy : public IGiveGift {
	Pursuit* _gg;    // 这个是关键
public:
	Proxy(Pursuit* gg) : _gg(gg) {}
	void giveDolls() { _gg->giveDolls(); }
	void giveFlowers() { _gg->giveFlowers(); }
	void giveChocolate() { _gg->giveChocolate(); }
	~Proxy() { delete _gg; std::cout << "deleted proxy " << std::endl;  }
};

//int main() {
//	SchoolGirl* mm = new SchoolGirl("lzq");
//	Pursuit* p = new Pursuit(mm); 
//	Proxy pr = Proxy(p); // 这里当然也可以用指针啦
//	/*
//		与装饰模式看起来很像。也是层层嵌套了。
//		但两者完全不一样。Pursuit和Proxy均是IGiveGift的派生类。而SchoolGirl是不相关的类。
//	*/
//	pr.giveDolls();
//	pr.giveFlowers();
//	pr.giveChocolate();
//}