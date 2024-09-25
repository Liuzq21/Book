#include<iostream>
#include<string>

using namespace std;

/*
	单例模式：保证某一对象只能有一个实例，并且在全局提供一个访问的接口。
	懒汉式和饿汉式
*/

//Singleton类懒汉式，在第一次调用时实例化
class Singleton
{
public:
	static Singleton* getInstance()   // 通过getInstance来判断并在内部调用构造函数
	{	
		//m_mutex.lock(); 
		if (m_pSingleton == NULL)   // 这里在多线程环境下仍有可能创造多个对象。解决办法：上锁
		{
			m_pSingleton = new Singleton();
		}
		//m_mutex.unlock();
		return m_pSingleton;
	}
private:
	Singleton() {}      // 私有化构造函数使得外部无法调用
	static Singleton* m_pSingleton;
	//boost::mutex m_mutex;  
};

Singleton* Singleton::m_pSingleton = NULL;

class Singleton2 //饿汉式单例模式实现比较简单粗暴，直接在类外创建对象，当该类创建时对象即被创建，
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