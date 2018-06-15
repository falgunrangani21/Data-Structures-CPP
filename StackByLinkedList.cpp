/*
Program to implement stack using linked list.
IDE : Code::Blocks
MingW Compiler
*/

#include <iostream>

using namespace std;

typedef struct node {
    int data;
    struct node *next;
} Node;

class StackByLinkedList {
    private:
        Node *top = NULL;
    public:
        Node *createNewNode(int val) {
            Node *newNode = new Node;

            if(newNode == NULL) {
                cout << "\n\nUnable to allocate memory for new node.";
                return 0;
            } else {
                newNode -> data = val;
                newNode -> next = NULL;
                return newNode;
            }
        }

        void push(int val) {
            Node *newNode;
            newNode = createNewNode(val);
            newNode -> next = top;
            top = newNode;
        }

        void pop() {
            Node *temp;
            temp = top;
            if(top == NULL) {
                cout << "\n\nStack underflow!";
            } else {
                top = top -> next;
                cout << "\n\nDeleted element is " << temp -> data;
                delete(temp);
            }
        }

        int peek() {
           if(top == NULL) {
                cout << "\nStack is empty!";
                return -1;
            } else {
                return (top -> data);
            }
        }

        void display() {
            Node *ptr = top;
            cout << "\n\n";

            if(top == NULL) {
                cout << "\nStack is empty!";
            } else {
                while(ptr != NULL) {
                    cout << ptr -> data << " ";
                    ptr = ptr -> next;
                }
            }
        }
};

int main() {
    int val, choice;
    StackByLinkedList sList;

    do {
        cout << "\n\n**********Main Menu";
        cout << "\n1.PUSH";
        cout << "\n2.POP";
        cout << "\n3.PEEK";
        cout << "\n4.DISPLAY";
        cout << "\n5.EXIT";
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "\n\nEnter data : ";
                cin >> val;
                sList.push(val);
                break;
            case 2:
                sList.pop();
                break;
            case 3:
                val = sList.peek();
                if(val != -1) {
                    cout << "\n\nThe value stored at top of the stack is " << val;
                }
                break;
            case 4:
                sList.display();
                break;
        }
    } while(choice != 5);

    return 0;
}
