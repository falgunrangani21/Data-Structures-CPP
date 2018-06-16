#include <iostream>

using namespace std;

typedef struct node {
    int data;
    struct node *next;
} Node;

class CircularQueueLinkedList {
    private:
        Node *front = NULL, *rear = NULL;
    public:
        Node *createNewNode(int *val) {
            Node *newNode = new Node;
            if(newNode == NULL) {
                cout << "\n\nUnable to allocate memory for new node.";
                return 0;
            } else {
                newNode -> data = *val;
                newNode -> next = NULL;
                return newNode;
            }
        }

        void insertElement(int *val) {
            Node *newNode = createNewNode(val);
            if(front == NULL && rear == NULL) {
                front = newNode;
            } else {
                rear -> next = newNode;
            }
            rear = newNode;
            rear -> next = front;
        }

        int deleteElement() {
            Node *temp = front;
            int val;
            if(front == NULL) {
                cout << "\n\nQueue underflow!";
                return -1;
            } else {
                if(front == rear) {
                    val = temp -> data;
                    delete(temp);
                    front = rear = NULL;
                    return val;
                } else {
                    val = temp -> data;
                    front = front -> next;
                    delete(temp);
                    rear -> next = front;
                    return val;
                }
            }
        }

        int peekElement() {
            if(front == NULL) {
                cout << "\n\nCan not return front element from empty queue.";
                return -1;
            } else {
                return (front -> data);
            }
        }

        void displayQueue() {
            Node *ptr = front, *temp = NULL;
            if(front == NULL) {
                cout << "\n\nQueue is empty.";
            } else {
                cout << "\n\n";
                while(ptr != temp) {
                    cout << ptr -> data << " ";
                    ptr = ptr -> next;
                    temp = front;
                }
            }
        }
};

int main() {
    int val, choice;
    CircularQueueLinkedList queue;

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
                queue.insertElement(&val);
                    cout << "\n\nElement inserted!";
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
