#include<iostream>
#include<string>
using namespace std;
/*
	����¼ģʽ���ڲ��ƻ���װ�Ե�����£�����һ��������ڲ�״̬�����ڸö���֮�Ᵽ�����״̬
	��ԭ��ģʽPrototype������ԭ��ģʽ��ͨ��Clone()��������һ���������Ⱪ¶�Ľӿ�ϸ�ڡ�
	������¼ģʽ���Խ�����״̬����¶�ӿڣ�����Ҫ������Խ��ǲ�����Ϣ������ȫ����Ϣ��

	key�� �������࣬����¼�࣬��������
*/
class PlayerMem { // ����¼
	int vit; // ����
public:
	PlayerMem(int _vit) : vit(_vit) {}
	int getVit() { return vit; }
};
class PlayerCareTaker {  // ������¼
	PlayerMem p;
public:
	PlayerCareTaker(PlayerMem& pm):p(pm){}
	PlayerMem& getPlayerMem() {
		return p;
	}
};
class GamePlayer {  // ��Ҫ����¼����
	int vit; // ����     �����ж��״̬
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