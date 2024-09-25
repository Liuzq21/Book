#include<iostream>
#include<string>
#include<map>
using namespace std;
/*
	��Ԫģʽ: ������ͬԪ�أ�����Ϊ��ͬ��Ԫ��new������ʵ��������Ҫʱ��ȡ�ö��󼴿�, һ���ǵ�����Ԫ��һ���Ǹ�����Ԫ��
    ������Ԫ���ص�������Ԫ�ض��ǹ���ģ���������Ԫ��ɫ�����ǲ�����ģ�����һ��������Ԫ�ڲ�������Ի���Ϊ���������Ԫ��ʾ��
	Ӧ�ã����һ��Ӧ�ó���ʹ���˴����Ķ��󣬲�������˺ܴ�Ĵ洢���������ɾ������Ĵ�����ⲿ״̬�������ý��ٵĹ������ȡ����
*/
class WebSite {
public:
	virtual void use() = 0; // ��������ǿ��Դ������ļ�����Я���ⲿ״̬
};

class ConcreteWebSite : public WebSite {
	string name;
public:
	ConcreteWebSite(string s) :name(s) {}
	void use() override {
		cout << "��վ����" << name << endl;
	}
};

class WebSiteFactory {
	map<string, ConcreteWebSite*> map;  // �ؼ����ڹ���������map�棬��������Ϊ��ͬ��Ԫ��new������ʵ��
public:
	WebSite* getWeb(string key) {
		if (!map.count(key)) {    
			map[key] = new ConcreteWebSite(key);
		}
		return map[key];
	}

	int getWebCount() {
		return map.size();
	}
};

//int main() {
//	WebSiteFactory f = WebSiteFactory();
//
//	WebSite* fx = f.getWeb("��Ʒչʾ");
//	fx->use();
//	WebSite* fy = f.getWeb("��Ʒչʾ");
//	fy->use();
//	WebSite* fz = f.getWeb("��Ʒչʾ");
//	fz->use();
//
//	WebSite* fl = f.getWeb("����");
//	fl->use();
//	WebSite* fm = f.getWeb("����");
//	fm->use();
//	WebSite* fn = f.getWeb("����");
//	fn->use();
//
//	cout<<f.getWebCount();
//}