#include<string>
#include <iostream>
using std::string;
/*
	模板方法模式：把公共部分抽象出来，不同的地方可以封装为一个虚方法。在不同子类中实现不同的版本。
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