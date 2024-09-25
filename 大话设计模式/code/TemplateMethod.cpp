#include<string>
#include <iostream>
using std::string;
/*
	ģ�巽��ģʽ���ѹ������ֳ����������ͬ�ĵط����Է�װΪһ���鷽�����ڲ�ͬ������ʵ�ֲ�ͬ�İ汾��
*/
class TestPaper {
public:
	void TestQuestion1() { std::cout << "Question1 : xxxxxx\n" << Answer1() << std::endl; }
	void TestQuestion2() { std::cout << "Question2: xxxxxxxx\n" << Answer2() << std::endl; }
	virtual string Answer1() = 0;
	virtual string Answer2() = 0;
	virtual ~TestPaper() {}
};

class TestPaperA : public TestPaper {
	string Answer2() { return "b"; }
	string Answer1() { return "a"; }
	~TestPaperA() {}
};

class TestPaperB : public TestPaper {
	string Answer2() { return "a"; }
	string Answer1() { return "b"; }
	~TestPaperB() {}
};

//int main() {
//	TestPaper* t = new TestPaperA();
//	t->TestQuestion1();
//	TestPaper* t2 = new TestPaperB();
//	t2->TestQuestion1();
//	delete t;
//	delete t2;
//}