#include<iostream>
#include<string>
using namespace std;
/*
	״̬ģʽ����һ������ı�������״̬ʱ������ı�����Ϊ����������������Ǹı������ࡣ
	ʵ�ֵĹؼ�����1.���û���ʹ��״̬����ָ���¼��ǰ״̬��2. �ڲ�ͬ״̬��ͨ���û������趨��һ��״̬�����á�
*/
// ǰ������.����ʹ����������ĳ�Ա��ֻ�ܶ���ָ�롣�����Ӳ�����ǰ�����������������Ҫ��ֶ���൥������Ȼ������ͷ�ļ�������������
/*

class Work;

class State {
public:
	virtual void writeProgam(Work* w) = 0;
};


class Work {
	State* curstate;   // �ؼ�
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

		cout << "����ʱ���� " << w->Hour << " ���磬���°���" << endl;

	}
};

class NoonState : public State {
	void writeProgam(Work* w) override {
		if (w->Hour < 13)
			cout << "����ʱ���� " << w->Hour << " ���磬������������" << endl;
		else {
			w->SetState(new AfternoonState());
			w->writeProgam();
		}
	}
};

class ForenoonState : public State {
	void writeProgam(Work* w) override {
		if (w->Hour < 12)
			cout << "����ʱ���� " << w->Hour << " ���繤��������ٱ�" << endl;
		else {
			w->SetState(new NoonState());   // �ؼ�
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