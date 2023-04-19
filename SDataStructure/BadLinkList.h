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
		std::cout << "��������ڵ�" << temp << '\n';
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
		std::cout << "��������ڵ�" << pH << '\n';
		delete pH->data;
		delete pH;
		length--;
		pH = head->next;
	}
	delete head;
}
template<class T>
inline bool BadLinkList<T>::insert(T* value�� int pos)
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

//����ڵ�
template<class T>
struct Node {
	unique_ptr<T> data;
	struct Node* next;
};


//������
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
	Node<T>* head;			//ͷ���
	uint32_t length;	//����
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
		//���ñ���λ�ձ�
	bool insert(T* value,  int pos = 0);
		//����һ���ڵ㣨����ͷ�塢β�塢�в壩
	bool push_back(T* value) { return insert(value, length); }
		//ͷ��
	unique_ptr<T> pop_first();
		//��������ȡ����һ���ڵ�
	unique_ptr<T> pop();
		//��������ȡ�����һ���ڵ�
	bool push_front(T* value) { return insert(value, 0); }
		//β��

	void merge(BadLinkList& another);
		//�ϲ�
	unsigned int size() { return length; }
		//����������

	template<class T>
	friend ostream& operator<<(ostream& os, const BadLinkList<T>& List);
		//ģ����Ԫ��ʾ�߼�
	//==========================================================STL����
	iterator begin() { return _begin(); }
	iterator end() { return _end; }
};


/**
 * ����������������ݣ�����posִ�в�ͬ�Ĳ���.
 * 
 * \param T* value ָ������ֵ��ָ��
 * \param pos ����λ��
 * \return ���ز�������������λ�ò��Ϸ�ʱ����false��
 */
template<class T>
bool BadLinkList<T>::insert(T* value, int pos) {
	Node<T>* temp = new Node<T>;
	Node<T>* pH = head->next;
	std::cout << "��������ڵ�" << temp << '\n';
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
 * ��Ԫģ�庯��.
 * 
 * \param os �����
 * \param List ����
 * \return ���������������
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
 * ��������.
 */
template<class T>
BadLinkList<T>::~BadLinkList() {
	Node<T>* pH = head->next;
	while (pH) {
		head->next = head->next->next;
		std::cout << "��������ڵ�" << pH << '\n';
		delete pH;
		length--;
		pH = head->next;
	}
	delete _end;
	delete head;
}


/**	δ�깤
 * �ϲ�.
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
 * �����������ͷ���.
 * 
 * \return �������
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
 * ȡ����һ���ڵ㣬����һ���ڵ�Ϊnullʱ������nullptrָ��.
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
 * �������һ���ڵ㣬������ɾ��.
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
