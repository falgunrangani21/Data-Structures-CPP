#include <iostream>
#define MAX 10

using namespace std;

class StackDemo {
    private:
        int top = -1, num;
        int arr[MAX];
        int choice;
    public:
        bool checkOverflow() {
            return (top == MAX - 1);
        }

        bool checkUnderflow() {
            return (top == -1);
        }

        int push(int *n) {
            if(checkOverflow()) {
                cout << "Stack Overflow!";
                return -1;
            } else {
                top += 1;
                arr[top] = *n;
                return 0;
            }
        }

        int pop() {
            if(checkUnderflow()) {
                cout << "Stack underflow!";
                return -1;
            } else {
                num = arr[top];
                top--;
                return num;
            }
        }

        int peek() {
            if(top == -1) {
                cout << "Stack is empty!";
                return -1;
            } else {
                return arr[top];
            }
        }

        void display() {
            cout << "\n";
            if(top == -1) {
                cout << "Stack is empty!";
            } else {
                int i = top;
                while(i >= 0) {
                    cout << arr[i] << " ";
                    i--;
                }
            }
        }

        void run() {
            do {
                cout << "\n**********Main Menu";
                cout << "\n1. PUSH";
                cout << "\n2. POP";
                cout << "\n3. PEEK";
                cout << "\n4. Display";
                cout << "\n5. EXIT";
                cout << "\nEnter your choice : ";
                cin >> choice;

                switch(choice) {
                case 1:
                    cout << "\nEnter element : ";
                    cin >> num;
                    if(push(&num) != -1) {
                        cout << "Inserted!";
                    }
                    break;
                case 2:
                    num = pop();
                    if(num != -1) {
                        cout << num << " is removed from stack!";
                    }
                    break;
                case 3:
                    num = peek();
                    if(num != -1) {
                        cout << "Top most element is " << num;
                    }
                    break;
                case 4:
                    display();
                    break;
                }
            } while(choice != 5);
        }
};

int main(void) {
    StackDemo s;
    s.run();
    return 0;
}
