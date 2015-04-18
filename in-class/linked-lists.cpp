#include <iostream>
#include <string>

// Singly-linked-list
// Parameterized type
template <typename T>
class Node {
public:
	Node(T d, Node * n, Node * p) { data = d; next = n; prev = p;}
    Node(T d, Node * n) { data = d; next = n; prev = NULL; }
    Node(T d)           { data = d; next = NULL; prev = NULL; }
    T data;
    Node * next;
	Node * prev;
};

template <typename T>
class Stack {
    Stack() {
        head = NULL;
    }
    void push(T element) {
        Node<T> * node = new Node<T>(element, head);
        head = node;
    }
    T peek() {
        return head->data;
    }
    void pop() {
        Node<T> * node;
        node = head->next;
        delete head;
        head = node;
    }
    bool empty() {
        return head == NULL;
    }
private:
    Node<T> * head;
};

template <typename T>
class List {
public:
    List() {
        head = NULL;
		tail = NULL;
    }
    void push_front(T element) {
        Node<T> * node = new Node<T>(element, head);
		if (head == NULL) {
			tail = node;
		}
		else {
			head->prev = node;
		}
        head = node;
    }
    T peek_front() {
        return head->data;
    }
    void pop_front() {
        Node<T> * node;
        node = head->next;
        delete head;
        head = node;
		if (head != NULL) {
			head->prev = NULL;
		} else {
			tail = NULL;
		}
		
    }
	void push_back(T element) {
		//work on this
		Node<T> * node = new Node<T>(element, tail);
		tail = node;
	}
	T peek_back() {
	//work on this
		return tail->data;
	}
	void pop_back() {
	//work on this
		Node<T> * node;
		node = tail->next;
		delete tail;
		tail = node;
	}
    bool empty() {
        return head == NULL && tail == NULL;
    }
	Node<T> * begin() {
		return head;
	}
	Node<T> * end() {
		return NULL;
	}
	Node<T> * tail() {
		return tail;
	}
	int size() {
		int result = 0;
		for (Node<T> * pointer = begin(); pointer != end(); pointer = pointer->next) {
			result++;
		}
		return result;
	}
private:
    Node<T> * head;
	Node<T> * tail;
};

int main() {
	List<int> numbers;
	numbers.push_back(42);
	numbers.push_front(10);
	numbers.push_front(3);
	numbers.push_back(87);
	std::cout << (3 == numbers.peek_front()) << std::endl;
	std::cout << (87 == numbers.peek_back()) << std::endl;
	numbers.pop_front();
	std::cout << (10 == numbers.peek_front()) << std::endl;
	numbers.pop_back();
	std::cout << (42 == numbers.peek_back()) << std::endl;
	std::cout << !numbers.empty() << std::endl;
	numbers.pop_front();
	numbers.pop_front();
	std::cout << numbers.empty() << std::endl;
    /*
	Node<std::string> * node2 = new Node<std::string>("world");
    Node<std::string> * node1 = new Node<std::string>("hello", node2);
    Node<float> number2(2.0);
    Node<float> number1(1.0, &number2);
    
    for (Node<std::string> * pointer = node1;
        pointer != NULL;
        pointer = pointer->next) {
        std::cout << pointer->data << " ";
    }
    */
    return 0;
}