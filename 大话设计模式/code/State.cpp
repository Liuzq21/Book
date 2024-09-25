#include<iostream>
#include<string>
using namespace std;
/*
	状态模式：当一个对象改变其内在状态时，允许改变其行为。这个对象看起来像是改变了其类。
	实现的关键在于1.在用户中使用状态基类指针记录当前状态。2. 在不同状态中通过用户重新设定下一个状态并调用。
*/
// 前向声明.不能使用声明类里的成员。只能定义指针。本例子不能用前向声明解决，所以需要拆分多个类单独编译然后引用头文件，但是我懒了
/*

class Work;

class State {
public:
	virtual void writeProgam(Work* w) = 0;
};


class Work {
	State* curstate;   // 关键
public:
	int Hour;
	Work() {
		curstate = new ForenoonState();
	}
	void SetState(State* s) {
		State* p = curstate;
		curstate = s;
		delete p;
	}
	void writeProgam() {
		curstate->writeProgam(this);
	}
};



class AfternoonState : public State {
	void writeProgam(Work* w) override {

		cout << "现在时间是 " << w->Hour << " 下午，该下班了" << endl;

	}
};

class NoonState : public State {
	void writeProgam(Work* w) override {
		if (w->Hour < 13)
			cout << "现在时间是 " << w->Hour << " 中午，饿了困困饭饭" << endl;
		else {
			w->SetState(new AfternoonState());
			w->writeProgam();
		}
	}
};

class ForenoonState : public State {
	void writeProgam(Work* w) override {
		if (w->Hour < 12)
			cout << "现在时间是 " << w->Hour << " 上午工作，精神百倍" << endl;
		else {
			w->SetState(new NoonState());   // 关键
			w->writeProgam();
		}
	}
};

*/
//int main() {
//	Work* lzq = new Work();
//	lzq->Hour = 9;
//	lzq->writeProgam();
//	lzq->Hour = 10;
//	lzq->writeProgam();
//	lzq->Hour = 12;
//	lzq->writeProgam();
//	lzq->Hour = 15;
//	lzq->writeProgam();
//}