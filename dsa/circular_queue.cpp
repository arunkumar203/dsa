#include<iostream>
using namespace std;

class queue {
    int *a;
    int cs, ms, front, rear;

public:
    queue(int size = 5) {
        ms = size;
        a = new int[ms];
        cs = 0;
        front = 0;
        rear = ms - 1;
        for (int i = 0; i < ms; i++) {
            a[i] = 0;
        }
    }

    bool full() {
        return cs == ms;
    }

    bool empty() {
        return cs == 0;
    }

    void push(int data) {
        if (!full()) {
            rear = (rear + 1) % ms;
            a[rear] = data;
            cs++;
        }
    }

    void pop() {
        if (!empty()) {
        	a[front]=0;
            front = (front + 1) % ms;
            cs--;
        }
    }

    int getFront() { // Renamed the member function to getFront()
        return a[rear];
    }

    void print1() {
        for (int i = 0; i < ms; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void print2() {
        int n = front;
        for (int i = 0; i < ms; i++) {
            cout << a[n] << " ";
            n = (n + 1) % ms;
        }
        cout << endl; // Added a semicolon here
    }
    void print(queue q){
    	q.print1();
    	q.print2();
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.print(q);
    q.pop();
    q.pop();
    q.print(q);
    q.push(6);
    // q.push(7);
    q.print(q);

    return 0;
}
