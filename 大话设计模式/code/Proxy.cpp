#include<iostream>
#include<string>
using std::string;
/*
	����ģʽ��Ϊ���������ṩһ�ִ����Կ����������ķ���
	Զ�̴���
	��������򿪴���ҳʱֻ��ʾ�ı�������洢��ͼƬ��·����ͼƬ����Ҫ���ɴ�������
	��ȫ�������ƶ���ķ���Ȩ��
	����ָ�������統����û��ʹ�õ�ʱ���ͷŹ���Ķ���
*/
class SchoolGirl {
public:
	string m_name;
	SchoolGirl(string name) : m_name(name) {}
};
class IGiveGift { // �����ӿ�
public:
	virtual void giveDolls() = 0;
	virtual void giveFlowers() = 0;
	virtual void giveChocolate() = 0;

	virtual ~IGiveGift() {}; 
};

class Pursuit : public IGiveGift {
	SchoolGirl* mm;     // ������Ǳ�Ҫ��
public:
	Pursuit(SchoolGirl* m) :mm(m) {}
	void giveDolls() { std::cout << mm->m_name << "send dolls" << std::endl; }
	void giveFlowers() { std::cout << mm->m_name << "send flowers" << std::endl; }
	void giveChocolate() { std::cout << mm->m_name << "send chocolate" << std::endl; }
	~Pursuit() { delete mm; std::cout << "deleted pursuit " << std::endl;  }
};

class Proxy : public IGiveGift {
	Pursuit* _gg;    // ����ǹؼ�
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
//	Proxy pr = Proxy(p); // ���ﵱȻҲ������ָ����
//	/*
//		��װ��ģʽ����������Ҳ�ǲ��Ƕ���ˡ�
//		��������ȫ��һ����Pursuit��Proxy����IGiveGift�������ࡣ��SchoolGirl�ǲ���ص��ࡣ
//	*/
//	pr.giveDolls();
//	pr.giveFlowers();
//	pr.giveChocolate();
//}