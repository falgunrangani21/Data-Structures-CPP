#include <iostream>
#define MAX 5

using namespace std;

class CircularQueue {
    private:
        int circularQueue[MAX];
        int front = -1, rear = -1;
    public:
        int insertElement(int *val) {
            if((front == 0 && rear == MAX - 1) || rear == front - 1) {
                cout << "\n\nQueue overflow!";
                return -1;
            } else if(front == -1 && rear == -1) {
                front = rear = 0;
                circularQueue[rear] = *val;
                return 0;
            } else if(front > 0 && rear == MAX - 1) {
                rear = 0;
                circularQueue[rear] = *val;
                return 0;
            } else {
                circularQueue[++rear] = *val;
                return 0;
            }
        }

        int deleteElement() {
            if(front == -1 && rear == -1) {
                cout << "\n\nQueue underflow!";
                return -1;
            } else if(front == rear) {
                int temp = circularQueue[front];
                front = rear = -1;
                return temp;
            } else if(front == MAX - 1) {
                int temp = circularQueue[front];
                front = 0;
                return temp;
            } else {
                int temp = circularQueue[front];
                front++;
                return temp;
            }
        }

        int peekElement() {
            if(front == -1 && rear == -1) {
                cout << "\n\nCan not peek front element from empty queue.";
                return -1;
            } else {
                return circularQueue[front];
            }
        }

        void displayQueue() {
            int i;
            if(front == -1 && rear == -1) {
                cout << "\n\nCan not print empty queue.";
            } else if(front < rear) {
                cout << "\n\n";
                for(i = front; i <= rear; i++) {
                    cout << circularQueue[i] << " ";
                }
            } else {
                cout << "\n\n";
                for(i = front; i <= MAX - 1; i++) {
                    cout << circularQueue[i] << " ";
                }
                for(i = 0; i <= rear; i++) {
                    cout << circularQueue[i] << " ";
                }
            }
        }
};

int main() {
    int val, choice;
    CircularQueue queue;

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
