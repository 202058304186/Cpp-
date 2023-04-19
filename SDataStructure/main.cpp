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
		std::cout << "一个测试节点被创建.————基本构造函数\n";
		nodes++;
	}
	Test(const Test& t) {
		data = new int(*t.data);
		std::cout << "一个测试节点被创建————复制构造函数。\n";
		nodes++;
	}
	~Test() {
		std::cout << "一个测试节点被销毁.\n";
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

	std::cout << "取第一个节点: " << test.pop_first() << std::endl;
	std::cout << "取第最后节点: " << test.pop() << std::endl;
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
