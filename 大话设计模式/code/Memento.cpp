#include<iostream>
#include<string>
using namespace std;
/*
	备忘录模式：在不破坏封装性的情况下，捕获一个对象的内部状态，并在该对象之外保存这个状态
	与原型模式Prototype的区别：原型模式是通过Clone()方法拷贝一整个对象，这暴露的接口细节。
	而备忘录模式可以仅保存状态不暴露接口，且需要保存可以仅是部分信息，而非全部信息。

	key： 发起人类，备忘录类，管理者类
*/
class PlayerMem { // 备忘录
	int vit; // 生命
public:
	PlayerMem(int _vit) : vit(_vit) {}
	int getVit() { return vit; }
};
class PlayerCareTaker {  // 管理备忘录
	PlayerMem p;
public:
	PlayerCareTaker(PlayerMem& pm):p(pm){}
	PlayerMem& getPlayerMem() {
		return p;
	}
};
class GamePlayer {  // 需要被记录的类
	int vit; // 生命     可以有多个状态
public:
	GamePlayer():vit(5){}
	void show() {
		cout << "current vit = " << vit << endl;
	}
	void fight() {
		vit = 0;
	}
	PlayerMem createMem() {
		PlayerMem p = PlayerMem(vit);
		return p;
	}
	void setMem(PlayerMem& pm) {
		vit = pm.getVit();
	}
};

//int main() {
//	GamePlayer gp = GamePlayer();
//	gp.show();
//	PlayerMem pm = gp.createMem();
//	PlayerCareTaker pc = PlayerCareTaker(pm);
//	
//	gp.fight();
//	gp.show();
//
//	gp.setMem(pc.getPlayerMem());
//	gp.show();
//}