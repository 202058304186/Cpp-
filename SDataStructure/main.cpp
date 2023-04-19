#include<iostream>
#include<memory>
#include"BadLinkList.h"

using std::unique_ptr;
using std::make_unique;

class Test {
private:
	int* data;
	static unsigned int nodes;
public:
	Test(int v = 5) {
		data = new int(v);
		std::cout << "һ�����Խڵ㱻����.���������������캯��\n";
		nodes++;
	}
	Test(const Test& t) {
		data = new int(*t.data);
		std::cout << "һ�����Խڵ㱻���������������ƹ��캯����\n";
		nodes++;
	}
	~Test() {
		std::cout << "һ�����Խڵ㱻����.\n";
		delete data;
		nodes--;
	}
	friend std::ostream& operator<<(std::ostream& os, const Test& t);
	friend std::ostream& operator<<(std::ostream& os, const Test* t);
};

unsigned int Test::nodes = 0;

unique_ptr<Test> make_Test(int i) {
	unique_ptr<Test> temp(new Test(i));
	return temp;
}

int main() {
	BadLinkList<Test> test;
	for (int i = 0; i < 10; ++i) {
		test.insert(new Test(i), test.size());
	}
	for (int i = 0; i < 10; ++i) {
		test.insert(new Test(5), 2 * i);
	}
	test.push_back(new Test(500));
	test.push_front(new Test(250));
	std::cout << "test size: " << test.size() << '\n';
	std::cout << test << std::endl;

	std::cout << "ȡ��һ���ڵ�: " << test.pop_first() << std::endl;
	std::cout << "ȡ�����ڵ�: " << test.pop() << std::endl;
	std::cout << test << std::endl;
	return 0;
}

std::ostream& operator<<(std::ostream& os, const Test& t)
{
	os << *t.data;
	return os;
}


std::ostream& operator<<(std::ostream& os, const Test* t)
{
	os << *t->data;
	return os;
}
