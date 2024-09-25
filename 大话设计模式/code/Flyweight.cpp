#include<iostream>
#include<string>
#include<map>
using namespace std;
/*
	享元模式: 共享相同元素，不必为相同的元素new大量的实例，在需要时调取该对象即可, 一种是单纯享元，一种是复合享元，
    单纯享元的特点是所有元素都是共享的，而复合享元角色对象是不共享的，但是一个复合享元内部对象可以划分为多个共享享元表示；
	应用：如果一个应用程序使用了大量的对象，并且造成了很大的存储开销。如果删掉对象的大多数外部状态，可以用较少的共享对象取代。
*/
class WebSite {
public:
	virtual void use() = 0; // 这个方法是可以带参数的即可以携带外部状态
};

class ConcreteWebSite : public WebSite {
	string name;
public:
	ConcreteWebSite(string s) :name(s) {}
	void use() override {
		cout << "网站分类" << name << endl;
	}
};

class WebSiteFactory {
	map<string, ConcreteWebSite*> map;  // 关键在于工厂里面用map存，做到不必为相同的元素new大量的实例
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
//	WebSite* fx = f.getWeb("产品展示");
//	fx->use();
//	WebSite* fy = f.getWeb("产品展示");
//	fy->use();
//	WebSite* fz = f.getWeb("产品展示");
//	fz->use();
//
//	WebSite* fl = f.getWeb("博客");
//	fl->use();
//	WebSite* fm = f.getWeb("博客");
//	fm->use();
//	WebSite* fn = f.getWeb("博客");
//	fn->use();
//
//	cout<<f.getWebCount();
//}