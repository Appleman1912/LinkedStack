using namespace std;
#include <iostream>


template <typename T>
class Stack {

private:
	struct Node {
		T data;
		Node* next;

		Node(T el) {
			this->data = el;
			next = nullptr;
		}
	};

	Node* head;

	void Free();
	void CopyFrom(const Stack<T>& other);

public:

	Stack();

	Stack(const Stack<T>& other);

	Stack<T>& operator=(const Stack<T>& other);

	~Stack();


public:

	void pop();

	void push(T el);

	T top();

	bool IsEmpty() const;

};

template <typename T>
Stack<T>::Stack(const Stack<T>& other) {
	CopyFrom(other);
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}
	return *this;
}
template <typename T>
Stack<T>::Stack() {
	head = nullptr;
}

template <typename T>
bool Stack<T>::IsEmpty() const {
	return head == nullptr;
}

template <typename T>
void Stack<T>::push(T el) {
	Node* ptr = new Node(el);

	if (IsEmpty()) {
		head = ptr;
	}
	else {
		ptr->next = head;
		head = ptr;
	}



}

template <typename T>
void Stack<T>::pop() {
	if (IsEmpty()) {
		return;
	}
	else if (head->next == nullptr) {
		delete head;
		head = nullptr;
		return;
	}
	else
	{
		cout << head->next << "  " << head->data << endl;
		Node* temp = head->next;
		delete head;
		head = temp;
		
	}

}

template <typename T>
Stack<T>::~Stack() {
	Free();
}
template <typename T>
T Stack<T>::top() {
	return head->data;
}


template <typename T>
void Stack<T>::Free() {
	Node* iter = head;

	while (iter != nullptr)
	{
		Node* prev = iter;
		iter = iter->next;
		delete prev;
	}
}

template <typename T>
void Stack<T>::CopyFrom(const Stack<T>& other) {
	if (other.IsEmpty()) {
		return;
	}
	Node* iterOther = other.head;
	head = new Node(iterOther->data);
	Node* iterThis = other.head;

	do 
	{
		iterOther = iterOther->next;
		if (iterOther) {
			iterThis->next = new Node(iterOther->data);
			cout << iterThis->data << " " << iterThis->next << endl;
			iterThis = iterThis->next;
			cout << iterThis->data << " " << iterThis->next << endl;
		}
	} while (iterOther);
}



int main() {

	Stack<int> s;
	s.push(3);
	s.push(4);
	s.push(5);
	Stack<int>p(s);

	return 0;
}