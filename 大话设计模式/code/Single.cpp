#include<iostream>
#include<string>

using namespace std;

/*
	����ģʽ����֤ĳһ����ֻ����һ��ʵ����������ȫ���ṩһ�����ʵĽӿڡ�
	����ʽ�Ͷ���ʽ
*/

//Singleton������ʽ���ڵ�һ�ε���ʱʵ����
class Singleton
{
public:
	static Singleton* getInstance()   // ͨ��getInstance���жϲ����ڲ����ù��캯��
	{	
		//m_mutex.lock(); 
		if (m_pSingleton == NULL)   // �����ڶ��̻߳��������п��ܴ��������󡣽���취������
		{
			m_pSingleton = new Singleton();
		}
		//m_mutex.unlock();
		return m_pSingleton;
	}
private:
	Singleton() {}      // ˽�л����캯��ʹ���ⲿ�޷�����
	static Singleton* m_pSingleton;
	//boost::mutex m_mutex;  
};

Singleton* Singleton::m_pSingleton = NULL;

class Singleton2 //����ʽ����ģʽʵ�ֱȽϼ򵥴ֱ���ֱ�������ⴴ�����󣬵����ഴ��ʱ���󼴱�������
{
private:
	Singleton2() {}

	static Singleton2* m_pSingleton;
public:
	static Singleton2* getInstance()
	{
		return m_pSingleton;
	}
};

Singleton2* Singleton2::m_pSingleton = new Singleton2(); // there

/*int main() {
	Singleton* s1 = Singleton::getInstance();
	Singleton* s2 = Singleton::getInstance();
	if (s1 == s2) cout << "same" << endl;

}*/