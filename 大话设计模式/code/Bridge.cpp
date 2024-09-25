#include<iostream>
#include<string>

using namespace std;
/*
	�Ž�ģʽ�������󲿷���ʵ�ֲ��ַ��뿪����ʹ���Ƕ����Զ����ı仯
	��ģ�巽��ģʽ�Աȣ�
		ģ�巽��ģʽ�ǽ�ͨ�ýӿ��麯������ͨ��������麯���ӿ�����ʵ�֣������Ͳ���Ҫ��������ĺ�����Ⱦ�����ռ䡣
		���Ž�ģʽ��ģ��ģʽ�Ĳ�ͬ�����Ž�ģʽ����һ��������Ž��࣬ͨ�������ļ̳�������ɾ���ʵ�֡�
*/

class HandsetSoft {
public:
	virtual void run() = 0;
};
class HandsetGame : public HandsetSoft {
public:
	void run() override {
		cout << "�����ֻ���Ϸ" << endl;
	}
};
class HandsetAddressList : public HandsetSoft {
public:
	void run() override {
		cout << "�����ֻ�ͨѶ¼" << endl;
	}
};
// �����ģ�巽��ģʽ���������������ˣ��ѹ����������������

class HandsetBrand {
public:
	virtual void run(HandsetSoft* soft)=0;  // �ŽӾ��������������
};

class HandsetBrandN : public HandsetBrand {
public:
	void run(HandsetSoft* soft) {
		cout << "Ʒ��N" << endl;
		soft->run();
	}
};

class HandsetBrandM : public HandsetBrand {
public:
	void run(HandsetSoft* soft) {
		cout << "Ʒ��M" << endl;
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