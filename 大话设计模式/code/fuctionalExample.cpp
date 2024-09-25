#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <functional>
#include <memory>
using namespace std;

//����һ��ģ��
typedef std::function<int(int)> Functional;


//normal function
int TestFunc(int a)
{
    return a;
}

//lambda expression
auto lambda = [](int a)->int {return a; };

//functor�º���
class Functor
{
public:
    int operator() (int a)
    {
        return a;
    }
};


//��ĳ�Ա��������ľ�̬��Ա����
class CTest
{
public:
    int Func(int a)
    {
        return a;
    }
    static int SFunc(int a)
    {
        return a;
    }
};


//int main(int argc, char* argv[])
//{
//    //��װ��ͨ����
//    Functional obj = TestFunc;
//    int res = obj(0);
//    cout << "normal function : " << res << endl;
//
//    //��װlambda���ʽ
//    obj = lambda;
//    res = obj(1);
//    cout << "lambda expression : " << res << endl;
//
//    //��װ�º���
//    Functor functorObj;
//    obj = functorObj;
//    res = obj(2);
//    cout << "functor : " << res << endl;
//
//    //��װ��ĳ�Ա������static��Ա����
//    CTest t;
//    obj = std::bind(&CTest::Func, &t, std::placeholders::_1);
//    res = obj(3);
//    cout << "member function : " << res << endl;
//
//    obj = CTest::SFunc;
//    res = obj(4);
//    cout << "static member function : " << res << endl;
//
//    return 0;
//}