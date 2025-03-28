// #include<bits/stdc++.h>
#include<iostream>  
#define line printf("\n");
using namespace std;

class node {
	int data;
	node* next;

public:
	node(int d) : data(d), next(NULL) {}
	int getdata() {
		return data;
	}
	friend class List;
};

class List {
	node* head;
	node* tail;

public:
	List() : head(NULL), tail(NULL) {}
	void push_front(int data) {
		node* n = new node(data);
		if (head == NULL) {
			head = tail = n;
		} else {
			n->next = head;
			head = n;
		}
	}

	void push_back(int data) {
		node* n = new node(data);
		if (head == NULL) {
			tail = head = n;
		} else {
			tail->next = n;
			tail = n;
		}
	} 
	void pop_front(){
		node *n=head;
		head=head->next;
		delete n;
	}
	void reverse() {
    node* current = head;
    node* previous = nullptr;
    node* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    head = previous;
}


	void insert(int data, int k) {
		node* c = head;
		node* n = new node(data);
		while (--k) {
			c = c->next;
		}
		n->next = c->next;
		c->next = n;
	}

	void print() {
		node* n = head;
		while (n) {
			cout << n->data << " ";
			n = n->next;
		}
		line
	}

	int search(int k) {
		return searchHelper(head, k);
	}

	int searchHelper(node* current, int k) {
		if (current == NULL) {
			return -1;
		}
		if (current->data == k) {
			return 1;
		}
		int result = searchHelper(current->next, k);
		if (result == -1) {
			return -1;
		}
		return 1 + result;
	}

	~List() {
		node* current = head;
		while (current != nullptr) {
			node* nextNode = current->next;
			cout<<"in destructor and deleting: "<<current->data<<endl;
			delete current;
			current = nextNode;
		}
	}
};

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	List l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_front(0);
	l.push_back(40);
	l.insert(5, 5);
	l.print();
	cout << l.search(30) << endl;
	l.pop_front();
	l.print();
	l.reverse();
	l.print();

	return 0;
}
