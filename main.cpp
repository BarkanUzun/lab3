#include <iostream>

using namespace std;

// define a node structure for linked list
struct Node {
    int data;
    Node* next;
};

// define the Queue class
class Queue {
private:
    Node* front;    // pointer to the front of the Queue
    Node* rear;     // pointer to the rear of the Queue
    int numElements;    // number of elements in the Queue

public:
    // constructor to initialize front and rear pointers
    Queue() {
        front = NULL;
        rear = NULL;
        numElements = 0;
    }

    // enqueue method to add a new element to the rear of the Queue
    void enqueue(int element) {
        Node* newNode = new Node;
        newNode->data = element;
        newNode->next = NULL;
        if (rear == NULL) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        numElements++;
    }

    // dequeue method to remove an element from the front of the Queue
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
        }
        else {
            Node* temp = front;
            front = front->next;
            delete temp;
            numElements--;
        }
    }

    // top method to return the front element of the Queue
    int top() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        else {
            return front->data;
        }
    }

    // isEmpty method to check if the Queue is empty
    bool isEmpty() {
        return (front == NULL);
    }

    // size method to return the number of elements in the Queue
    int size() {
        return numElements;
    }
};

int main() {
    Queue q;
    cout << "Queue is empty: " << q.isEmpty() << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Queue size: " << q.size() << endl;
    cout << "Front element: " << q.top() << endl;
    q.dequeue();
    cout << "Front element after dequeue: " << q.top() << endl;
    cout << "Queue size after dequeue: " << q.size() << endl;
    q.dequeue();
    q.dequeue();
    cout << "Queue is empty after dequeue: " << q.isEmpty() << endl;
    return 0;
}
