#include<string>
#include <iostream>
using std::string;
/*
	ԭ��ģʽ��
Prototypeģʽ����**����δ����ױ����ʵ����󡰲��á�ԭ�Ϳ�¡���ķ�������**�� ��ʹ�����ǿ��Էǳ����ض�̬������ӵ��ĳЩ�ȶ��ӿڡ����¶��� ���� ���蹤��������ע��һ������Ķ���(��ԭ��)�� Ȼ�����κ���Ҫ�ĵط�Clone
Prototypeģʽ�е�Clone������������ĳЩ����е����л���ʵ�����
�ŵ�
���Կ�¡���󣬶����������������ľ����������
���Կ�¡Ԥ����ԭ�ͣ����ⷴ�����г�ʼ������
���Ը���������ɸ��Ӷ���
�����ü̳�����ķ�ʽ�������Ӷ���Ĳ�ͬ����
ȱ�㣺
��ҪΪÿһ���඼����һ��clone����
clone����λ������ڲ���������������и���ʱ����Ҫ�޸Ĵ��룬Υ���˿���ԭ��
�����������ʱ����Ҫ��д��Ϊ���ӵĴ��룬���ҵ�����֮����ڶ���Ƕ��ʱ��Ϊ��ʵ�����¡��ÿһ������Ӧ���඼����֧�����¡��ʵ�ָ���
���ó���
����֮����ͬ�����ƣ���ֻ�Ǹ���ļ������Բ�ͬʱ
��������ɱ��ϴ������ʼ��ʱ�䳤��ռ��CPU̫�࣬����ռ��������Դ̫�࣬��Ҫ�Ż���Դ
����һ��������ҪƵ��������׼�������Ȩ�޵ȣ���Ҫ������ܻ�����߰�ȫ��
ϵͳ�д���ʹ�ø�������Ҹ��������߶���Ҫ�������������¸�ֵ
��������������������������������

��Ȩ����������Ϊ����ԭ�����£���ѭ CC 4.0 BY-SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӻͱ�������
                        
ԭ�����ӣ�https://blog.csdn.net/qq_37281656/article/details/139970423
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
	Resume* Clone() { return new Resume(*this); }  // �����ǵ��ÿ�������
	Resume(const Resume& rhs) {  // ע���ڿ������������ǳ��������
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
