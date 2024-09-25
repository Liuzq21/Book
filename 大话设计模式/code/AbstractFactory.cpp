#include<iostream>
#include<string>
using namespace std;
/*
	后期产品会越来越多了，建立的工厂也会越来越多，工厂进行了增长，工厂变的凌乱而难于管理；
	由于工厂方法模式创建的对象都是继承于Product的，所以工厂方法模式中，每个工厂只能创建单一种类的产品，
	当需要生产一种全新的产品（不继承自Product）时，发现工厂方法是心有余而力不足。
    问题：新增产品C时，要在工厂基类中增添语句，也要新增工厂类，非常复杂而且丑陋。java中有用反射+读取配置文件的方式解决这种问题。
    c++有什么办法呢？
*/

// Product A
class ProductA
{
public:
    virtual void Show() = 0;
};

class ProductA1 : public ProductA
{
public:
    void Show()
    {
        cout << "I'm ProductA1" << endl;
    }
};

class ProductA2 : public ProductA
{
public:
    void Show()
    {
        cout << "I'm ProductA2" << endl;
    }
};

// Product B
class ProductB
{
public:
    virtual void Show() = 0;
};

class ProductB1 : public ProductB
{
public:
    void Show()
    {
        cout << "I'm ProductB1" << endl;
    }
};

class ProductB2 : public ProductB
{
public:
    void Show()
    {
        cout << "I'm ProductB2" << endl;
    }
};

// Factory
class Factory
{
public:
    virtual ProductA* CreateProductA() = 0;
    virtual ProductB* CreateProductB() = 0;
};

class Factory1 : public Factory
{
public:
    ProductA* CreateProductA()
    {
        return new ProductA1();
    }

    ProductB* CreateProductB()
    {
        return new ProductB1();
    }
};

class Factory2 : public Factory
{
    ProductA* CreateProductA()
    {
        return new ProductA2();
    }

    ProductB* CreateProductB()
    {
        return new ProductB2();
    }
};

//int main(int argc, char* argv[])
//{
//    Factory* factoryObj1 = new Factory1();
//    ProductA* productObjA1 = factoryObj1->CreateProductA();
//    ProductB* productObjB1 = factoryObj1->CreateProductB();
//
//    productObjA1->Show();
//    productObjB1->Show();
//
//    Factory* factoryObj2 = new Factory2();
//    ProductA* productObjA2 = factoryObj2->CreateProductA();
//    ProductB* productObjB2 = factoryObj2->CreateProductB();
//
//    productObjA2->Show();
//    productObjB2->Show();
//
//    if (factoryObj1 != NULL)
//    {
//        delete factoryObj1;
//        factoryObj1 = NULL;
//    }
//
//    if (productObjA1 != NULL)
//    {
//        delete productObjA1;
//        productObjA1 = NULL;
//    }
//
//    if (productObjB1 != NULL)
//    {
//        delete productObjB1;
//        productObjB1 = NULL;
//    }
//
//    if (factoryObj2 != NULL)
//    {
//        delete factoryObj2;
//        factoryObj2 = NULL;
//    }
//
//    if (productObjA2 != NULL)
//    {
//        delete productObjA2;
//        productObjA2 = NULL;
//    }
//
//    if (productObjB2 != NULL)
//    {
//        delete productObjB2;
//        productObjB2 = NULL;
//    }
//}