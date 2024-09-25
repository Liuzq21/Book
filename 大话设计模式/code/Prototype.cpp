#include<string>
#include <iostream>
using std::string;
/*
	原型模式：
Prototype模式对于**“如何创建易变类的实体对象“采用”原型克隆“的方法来做**， 它使得我们可以非常灵活地动态创建”拥有某些稳定接口“的新对象 —— 所需工作仅仅是注册一个新类的对象(即原型)， 然后在任何需要的地方Clone
Prototype模式中的Clone方法可以利用某些框架中的序列化来实现深拷贝
优点
可以克隆对象，而无需与他们所属的具体类相耦合
可以克隆预生成原型，避免反复运行初始化代码
可以更方便地生成复杂对象
可以用继承以外的方式来处理复杂对象的不同配置
缺点：
需要为每一个类都配置一个clone方法
clone方法位于类的内部，当对已有类进行改造时，需要修改代码，违背了开闭原则
当进行深拷贝的时候，需要编写较为复杂的代码，而且当对象之间存在多重嵌套时，为了实现深克隆，每一层对象对应的类都必须支持深克隆，实现复杂
适用场景
对象之间相同或相似，及只是个别的几个属性不同时
创建对象成本较大，例如初始化时间长，占用CPU太多，或者占用网络资源太多，需要优化资源
创建一个对象需要频繁的数据准备或访问权限等，需要提高性能或者提高安全性
系统中大量使用该类对象，且各个调用者都需要给它的属性重新赋值
————————————————

版权声明：本文为博主原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。
                        
原文链接：https://blog.csdn.net/qq_37281656/article/details/139970423
*/
class Prototype {
	
public:
	Prototype() {}
	virtual ~Prototype() {}
	virtual Prototype* Clone() = 0;
};

class Resume :public Prototype {
	string name;
	string sex;
public:
	Resume(string n, string s) : name(n), sex(s){}
	~Resume() {}
	Resume* Clone() { return new Resume(*this); }  // 这里是调用拷贝构造
	Resume(const Resume& rhs) {  // 注意在拷贝构造里的深浅拷贝问题
		this->name = rhs.name;
		this->sex = rhs.sex;
	}
	void display() { std::cout << name << sex << std::endl; }
};

//int main() {
//	Resume* a = new Resume("lzq", "female");
//	Resume* b = a->Clone();
//
//	a->display();
//	b->display();
//	delete a;
//	delete b;
//}
