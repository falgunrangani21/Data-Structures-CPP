/*
Program to implement queue using array.
IDE : Code::Blocks
MingW GCC Compiler
*/

#include <iostream>
#define MAX 10

using namespace std;

class Queue {
    private:
        int queueArray[MAX];
        int front = -1, rear = -1, choice;
    public:
        int insertElement(int *val) {
            if(rear == MAX - 1) {
                cout << "\n\nQueue overflow!";
                return -1;
            } else if(front == -1 && rear == -1) {
                front = rear = 0;
                queueArray[rear] = *val;
                return 0;
            } else {
                rear++;
                queueArray[rear] = *val;
                return 0;
            }
        }

        int deleteElement() {
            if(front == -1 || front > rear) {
                cout << "\n\nQueue underflow!";
                front = rear = -1;
                return -1;
            } else {
                int temp = queueArray[front];
                front++;
                return temp;
            }
        }

        int peekElement() {
            if(front == -1 || front > rear) {
                cout << "\n\nQueue is empty!";
                front = rear = -1;
                return -1;
            } else {
                return queueArray[front];
            }
        }

        void displayQueue() {
            if(front == -1 || front > rear) {
                cout << "\n\nQueue is empty!";
            } else {
                cout << "\n\n";
                for(int i = front; i <= rear; i++) {
                    cout << queueArray[i] << " ";
                }
            }
        }
};

int main() {
    Queue queue;
    int val, choice;

    do {
        cout << "\n**********Main Menu";
        cout << "\n1. Insert element";
        cout << "\n2. Delete element";
        cout << "\n3. Peek element";
        cout << "\n4. Display Queue";
        cout << "\n5. EXIT";
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "\n\nEnter value of element : ";
                cin >> val;
                if(queue.insertElement(&val) != -1) {
                    cout << "\n\nElement inserted!";
                }
                break;
            case 2:
                val = queue.deleteElement();
                if(val != -1) {
                    cout << "\n\n" << val << " removed from queue.";
                }
                break;
            case 3:
                val = queue.peekElement();
                if(val != -1) {
                    cout << "\n\nFront element of the queue is " << val;
                }
                break;
            case 4:
                queue.displayQueue();
                break;
        }
    } while(choice != 5);

    return 0;
}
