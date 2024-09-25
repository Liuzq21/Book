#include<iostream>
#include<string>

using namespace std;
/*
	桥接模式：将抽象部分与实现部分分离开来，使它们都可以独立的变化
	与模板方法模式对比：
		模板方法模式是将通用接口虚函数化，通过子类对虚函数接口重载实现，这样就不需要定义大量的函数污染函数空间。
		而桥接模式与模板模式的不同在于桥接模式多了一个虚拟的桥接类，通过这个类的继承类来完成具体实现。
*/

class HandsetSoft {
public:
	virtual void run() = 0;
};
class HandsetGame : public HandsetSoft {
public:
	void run() override {
		cout << "运行手机游戏" << endl;
	}
};
class HandsetAddressList : public HandsetSoft {
public:
	void run() override {
		cout << "运行手机通讯录" << endl;
	}
};
// 如果是模板方法模式就是上面这样子了，把公共方法抽象出来。

class HandsetBrand {
public:
	virtual void run(HandsetSoft* soft)=0;  // 桥接就体现在这个参数
};

class HandsetBrandN : public HandsetBrand {
public:
	void run(HandsetSoft* soft) {
		cout << "品牌N" << endl;
		soft->run();
	}
};

class HandsetBrandM : public HandsetBrand {
public:
	void run(HandsetSoft* soft) {
		cout << "品牌M" << endl;
		soft->run();
	}
};

//int main() {
//	HandsetSoft* game = new HandsetGame();
//	HandsetSoft* list = new HandsetAddressList();
//
//	HandsetBrand* ab = new HandsetBrandN();
//	ab->run(game);
//	ab->run(list);
//
//	
//	ab = new HandsetBrandM();
//	ab->run(game);
//	ab->run(list);
//}