#include<iostream>
#include<string>
#include<vector>
using namespace std;
/* 
    ������ģʽ���ṩһ�ַ���˳�����һ���ۺ϶����и���Ԫ�أ����ֲ���¶�ö�����ڲ���ʾ��������������Ʒ���ģ�����ģ�˫��ĵȵȡ�
    �ⶫ��������ʵ�ַ��ļ���д��
*/

/*
template<class Item>
class Iterator
{
public:
    Iterator() {}
    virtual ~Iterator() {}
    virtual void first() = 0;
    virtual void next() = 0;
    virtual Item* currentItem() = 0;
    virtual bool isDone() = 0;
};

template<class Item>
class Aggregate
{
public:
    Aggregate() {}
    virtual ~Aggregate() {}
    virtual int getSize() = 0;
    virtual void push(Item item) = 0;
    virtual Item* at(const int nIndex) = 0;
    virtual Iterator<Item>* createIterator() = 0;
};


template <class Item>
class ConcreteAggregate : public Aggregate<Item>
{
public:
    ConcreteAggregate() {}
    virtual ~ConcreteAggregate() {}

    virtual int getSize() {
        return m_data.size();
    }
    virtual void push(Item item) {
        m_data.push_back(item);
    }
    virtual Item* at(const int nIndex) {
        return &m_data[nIndex];
    }
    virtual Iterator<Item>* createIterator() {
        return new ConcreteIterator<Item>(this);
    }
    
private:
    vector<Item> m_data;
};

template<class Item>
class ConcreteIterator : public Iterator <Item>
{
public:
    ConcreteIterator(Aggregate<Item>* aggregate) : m_aggregate(aggregate), m_current(0) {}
    virtual ~ConcreteIterator() {}

    virtual void first() {
        m_current = 0;
    }
    virtual void next() {
        if (m_current < m_aggregate->getSize())
        {
            ++m_current;
        }
    }
    virtual Item* currentItem() {
        if (m_current < m_aggregate->getSize())
        {
            return (m_aggregate->at(m_current));
        }
        else
        {
            return NULL;
        }
    }
    virtual bool isDone() {
        return m_current >= m_aggregate->getSize();
    }
private:
    Aggregate<Item>* m_aggregate;
    int m_current;
};

int main()
{

    printf("Templete is int.\n");
    Aggregate<int>* aggr = new ConcreteAggregate<int>;
    int num = 3;
    aggr->push(num--);
    aggr->push(num--);
    aggr->push(num--);
    Iterator<int>* iter = aggr->createIterator();
    for (iter->first(); !iter->isDone(); iter->next())
    {
        printf("Num is %d .\n", *(iter->currentItem()));
    }

    printf("Templete is float.\n");
    Aggregate<float>* aggr1 = new ConcreteAggregate<float>;
    float num1 = 9;
    aggr1->push(num1--);
    aggr1->push(num1--);
    aggr1->push(num1--);
    Iterator<float>* iter1 = aggr1->createIterator();
    for (iter1->first(); !iter1->isDone(); iter1->next())
    {
        printf("Num is %f .\n", *(iter1->currentItem()));
    }

}

��������������������������������

��Ȩ����������Ϊ����ԭ�����£���ѭ CC 4.0 BY - NC - SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӻͱ�������

ԭ�����ӣ�https ://blog.csdn.net/Bing_Lee/article/details/108608431

*/