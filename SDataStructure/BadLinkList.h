#if 0
#ifndef MYBASE_LINK_LIST
#define MYBASE_LINK_LIST
#include<memory>
#include<iostream>
using std::unique_ptr;
using std::make_unique;
using std::ostream;
template<class T>
struct Node {
	T* data;
	struct Node* next;
};


template <class T>
class BadLinkList
{
private:
	Node<T>* head;
	unsigned int length;

public:
	BadLinkList() { length = 0; head = new Node<T>; head->next = nullptr; }
	bool insert(T* value, int pos);
	~BadLinkList();
	bool insert(T* value) {
		Node<T>* temp = new Node<T>;
		std::cout << "创造链表节点" << temp << '\n';
		temp->data = value;
		temp->next = head->next;
		head->next = temp;
		length++;
		return true;
	};
	unsigned int size() { return length; }

	template<class T>
	friend ostream& operator<<(ostream& os, const BadLinkList<T>& List);
};


template<class T>
ostream& operator<<(ostream& os, const BadLinkList<T>& List)
{
	Node<T>* curr = List.head->next;
	while (curr) {
		os << *curr->data << '\t';
		curr = curr->next;
	}
	os << "\n";
	return os;
}


template<class T>
BadLinkList<T>::~BadLinkList() {
	Node<T>* pH = head->next;
	while (pH) {
		head->next = head->next->next;
		std::cout << "销毁链表节点" << pH << '\n';
		delete pH->data;
		delete pH;
		length--;
		pH = head->next;
	}
	delete head;
}
template<class T>
inline bool BadLinkList<T>::insert(T* value， int pos)
{
	return false;
}
#endif // !MYBASE_LINK_LIST
#endif

#ifndef MYBASE_LINK_LIST
#define MYBASE_LINK_LIST
#include<memory>
#include<iostream>
using std::unique_ptr;
using std::make_unique;
using std::ostream;

//链表节点
template<class T>
struct Node {
	unique_ptr<T> data;
	struct Node* next;
};


//单链表
template <class T>
class BadLinkList
{
	 
	typedef class linkListIterator iterator;

	class iterator {
		Node<T>* pn;
	public:
		iterator() : pt(nullptr) {}
		iterator(Node* pn) : pt(pn) {}
		~iterator() {};
		T operator*() { return move(pn->data) };
		iterator& operator++() {
			pn = pn->next;
			return *this;
		}
		iterator& operator++(int) {
			iterator tmp = *this;
			pn = pn->next;
			return tmp;
		}
	};

private:
	Node<T>* head;			//头结点
	uint32_t length;	//长度
	iterator _end;
	iterator _begin;

public:
	BadLinkList() { 
		length = 0; 
		head = new Node<T>; 
		_end = new Node<T>
		head->next = _end; 
		_begin = head->next;
	}
	~BadLinkList();

	bool clear();
		//将该表置位空表
	bool insert(T* value,  int pos = 0);
		//插入一个节点（包括头插、尾插、中插）
	bool push_back(T* value) { return insert(value, length); }
		//头插
	unique_ptr<T> pop_first();
		//从链表中取出第一个节点
	unique_ptr<T> pop();
		//从链表中取出最后一个节点
	bool push_front(T* value) { return insert(value, 0); }
		//尾插

	void merge(BadLinkList& another);
		//合并
	unsigned int size() { return length; }
		//返回链表长度

	template<class T>
	friend ostream& operator<<(ostream& os, const BadLinkList<T>& List);
		//模板友元显示逻辑
	//==========================================================STL方法
	iterator begin() { return _begin(); }
	iterator end() { return _end; }
};


/**
 * 往链表里面插入数据，根据pos执行不同的插入.
 * 
 * \param T* value 指向插入的值得指针
 * \param pos 插入位置
 * \return 返回插入结果，当插入位置不合法时返回false。
 */
template<class T>
bool BadLinkList<T>::insert(T* value, int pos) {
	Node<T>* temp = new Node<T>;
	Node<T>* pH = head->next;
	std::cout << "创造链表节点" << temp << '\n';
	temp->data = unique_ptr<T>(value);
	if (pos == length) {
		if (length == 0) {
			head->next = temp;
			temp->next = nullptr;
		}
		else {
			while (pH->next) {
				pH = pH->next;
			}
			pH->next = temp;
			temp->next = _end;
		}
	}
	else if (pos == 0) {
		temp->next = head->next;
		head->next = temp;
	}
	else if (pos > 0 && pos < length) {
		while (--pos > 0) {
			pH = pH->next;
		}
		temp->next = pH->next;
		pH->next = temp;
	}
	else {
		return false;
	}
	length++;
	return true;
};


/**
 * 友元模板函数.
 * 
 * \param os 输出流
 * \param List 链表
 * \return 返回输出流的引用
 */
template<class T>
ostream& operator<<(ostream& os, const BadLinkList<T>& List)
{
	Node<T>* curr = List.head->next;
	while (curr) {
		os << *curr->data << '\t';
		curr = curr->next;
	}
	os << "\n";
	return os;
}


/**
 * 析构函数.
 */
template<class T>
BadLinkList<T>::~BadLinkList() {
	Node<T>* pH = head->next;
	while (pH) {
		head->next = head->next->next;
		std::cout << "销毁链表节点" << pH << '\n';
		delete pH;
		length--;
		pH = head->next;
	}
	delete _end;
	delete head;
}


/**	未完工
 * 合并.
 * 
 * \param another
 */
template<class T>
inline void BadLinkList<T>::merge(BadLinkList& another)
{
	Node<T>* pH1;
	Node<T>* pH2;

}


/**
 * 清空链表，保留头结点.
 * 
 * \return 操作结果
 */
template<class T>
inline bool BadLinkList<T>::clear()
{
	Node<T>* next;
	while (length-- > 0) {
		next = head->next->next;
		delete head->next;
		head->next = next;
	}
	length = 0;
	return true;
}


/**
 * 取出第一个节点，当第一个节点为null时，返回nullptr指针.
 * 
 * \return 
 */
template<class T>
inline unique_ptr<T> BadLinkList<T>::pop_first()
{
	Node<T>* fir = head->next;
	if (fir != nullptr) {
		head->next = head->next->next;
	}
	unique_ptr<T> res = move(fir->data);
	delete fir;
	length--;
	return res;
}


/**
 * 返回最后一个节点，并将其删除.
 * 
 * \return 
 */
template<class T>
inline unique_ptr<T> BadLinkList<T>::pop()
{
	uint32_t index = 0;
	Node<T>* pNode = head;
	while (index < length - 1 ) {
		pNode = pNode->next;
		index++;
	}

	unique_ptr<T> res(move(pNode->next->data));
	delete pNode->next;
	pNode->next = nullptr;
	length--;
	return res;
}
#endif // !MYBASE_LINK_LIST
