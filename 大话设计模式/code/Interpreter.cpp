#include<iostream>
#include<string>

using namespace std;

/*
	������ģʽ:����һ�����ԣ����������ķ���һ�ֱ�ʾ��������һ�������������������ʹ�øñ�ʾ�����������е����ӡ�
	�ŵ�
		���ڸı����չ�ķ���һ��ͨ���̳����ı����չ���ķ�
		����ʵ���ķ�����������﷨���и����������ʵ�ִ�������
	ȱ��
		���ӵ��ķ�����ά��
*/


class PlayContext {
public:
	string text;
};

class Expression {
public:
	void Interpret(PlayContext& context) {
		if (context.text.size() == 0) return;
		string playKey = context.text.substr(0, 1);
		context.text = context.text.substr(2, context.text.size() - 2);
		int len = 1 + context.text.find(" ");
		double playValue = stod(context.text.substr(0, len));
		context.text = context.text.substr(len, context.text.size() - len);

		excute(playKey, playValue);
	}

	virtual void excute(string key, double value) = 0;
};

class Note : public Expression {
	void excute(string key, double value) {
		string note = "";
		switch (key[0]) {
		case 'C':note = "1"; break;
		case 'D':note = "2"; break;
		case 'E':note = "3"; break;
		case 'F':note = "4"; break;
		case 'G':note = "5"; break;
		case 'A':note = "6"; break;
		case 'B':note = "7"; break;
		}
		cout << note << " ";
	}
};

class Scale :public Expression {
	void excute(string key, double value) {
		string scale = "";
		switch (int(value)) {
		case 1 :scale = "����"; break;
		case 2 :scale = "����"; break;
		case 3 :scale = "����"; break;
		
		}
		cout << scale << " ";
	}
};

int main() {
	PlayContext context = PlayContext();
	context.text = "O 2 E 0.5 G 0.5 A 3 B 0.5 D 0.5 O 3 C 0.5 O 1 F 0.5";
	Expression* exp = NULL;
	try {
		while (context.text.size() > 0) {
			char c = context.text[0];
			switch (c)
			{
			case 'O': exp = new Scale(); break;
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'A':
			case 'B':
				exp = new Note();
				break;
			default:
				break;
			}
			exp->Interpret(context);
		}
	}
	catch (exception e) {
		cout << "error" << endl;
	}
}
