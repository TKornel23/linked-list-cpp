#include <memory>
#include <iostream>

template <typename T>
class LinkedList
{
	template <typename T>
	struct Node {
		T body;
		std::shared_ptr<Node<T>> next;
		Node(const T _body) : body(_body), next(nullptr) {}
	};

private:
	std::shared_ptr<Node<T>> head;

public:
	LinkedList() : head(nullptr) {}

	LinkedList& addNode(const T body) {

		if (head == nullptr) {
			head = std::make_shared<Node<T>>(body);
		}
		else {
			std::shared_ptr<Node<T>> p = head;
			while (p->next) {
				p = p->next;
			}
			p->next = std::make_shared<Node<T>>(body);
		}

		return *this;
	}

	LinkedList& RemoveFromList(T body) {

		std::shared_ptr<Node<T>> p = head;
		std::shared_ptr<Node<T>> e(nullptr);

		while (p->body != body && p) {
			e = p;
			p = p->next;
		}
		if (p) {
			if (e) {
				head = p->next;
			}
			else {
				e->next = p->next;
			}
			delete p;
		}
		return *this;
	}

	LinkedList& DeleteList() {
		while (head) {
			std::shared_ptr<Node<T>> p = head;
			head = head->next;
		}
		return *this;
	}

	LinkedList& ThroughtList() {
		std::shared_ptr<Node<T>> p = head;

		while (p) {
			std::cout << p->body << std::endl;
			p = p->next;
		}

		return *this;
	}

	LinkedList& SearchNode(T body) {
		std::shared_ptr<Node<T>> p = head;

		while (p && p->body != body) {
			p = p->next;
		}
		if (p) {
			std::cout << "Item found" << std::endl;
		}
		else {
			std::cout << "Item not Found" << std::endl;
		}
		return *this;
	}
};