/*
Program to implement multistack using array.
IDE : Code::Blocks
MingW Compiler
*/
#include <iostream>
#define MAX 10

using namespace std;

class MultiStack {
    private:
        int multiStack[MAX];
        int topA = -1;
        int topB = MAX;
    public:
        /*
        *Operation on Stack A
        */
        int pushA(int *val) {
            if(topA == topB - 1) {
                cout << "\nStack overflow!";
                return -1;
            } else {
                multiStack[++topA] = *val;
                return 0;
            }
        }

        int popA() {
            if(topA == -1) {
                cout << "\n\nStack underflow!";
                return -1;
            } else {
                int temp = multiStack[topA];
                topA--;
                return temp;
            }
        }

        int peekA() {
            if(topA == -1) {
                cout << "\n\nStack is empty!";
                return -1;
            } else {
                return multiStack[topA];
            }
        }

        void displayA() {
            if(topA == -1) {
                cout << "\n\nStack is empty!";
            } else {
                cout << "\n\n";
                for(int i = topA; i >= 0; i--) {
                    cout << multiStack[i] << " ";
                }
            }
        }

        /*
        * Operation on stack B
        */
        int pushB(int *val) {
            if(topB == topA + 1) {
                cout << "\n\nStack overflow!";
                return -1;
            } else {
                multiStack[--topB] = *val;
                return 0;
            }
        }

        int popB() {
            if(topB == MAX) {
                cout << "\n\nStack underflow!";
                return -1;
            } else {
                int temp = multiStack[topB];
                topB++;
                return temp;
            }
        }

        int peekB() {
            if(topB == MAX) {
                cout << "\n\nStack is empty!";
                return -1;
            } else {
                return multiStack[topB];
            }
        }

        void displayB() {
            if(topB == MAX) {
                cout << "\n\nStack is empty!";
            } else {
                for(int i = topB; i < MAX; i++) {
                    cout << multiStack[i] << " ";
                }
            }
        }
};

int main() {
    int val, choice;
    MultiStack mStack;
    do {
        cout << "\n**********Main Menu";
        cout << "\n1. PUSHA";
        cout << "\n2. POPA";
        cout << "\n3. PEEKA";
        cout << "\n4. DisplayA";
        cout << "\n5. PUSHB";
        cout << "\n6. POPB";
        cout << "\n7. PEEKB";
        cout << "\n8. DisplayB";
        cout << "\n9. EXIT";
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "\n\nEnter data : ";
                cin >> val;
                if(mStack.pushA(&val) != -1) {
                    cout << "\nInserted!";
                }
                break;
            case 2:
                val = mStack.popA();
                if(val != -1) {
                    cout << val << " is removed from stackA!";
                }
                break;
            case 3:
                val = mStack.peekA();
                if(val != -1) {
                    cout << "Top most element on stackA is " << val;
                }
                break;
            case 4:
                mStack.displayA();
                break;
            case 5:
                cout << "\n\nEnter data : ";
                cin >> val;
                if(mStack.pushB(&val) != -1) {
                    cout << "\nInserted!";
                }
                break;
            case 6:
                val = mStack.popB();
                if(val != -1) {
                    cout << val << " is removed from stackB!";
                }
                break;
            case 7:
                val = mStack.peekB();
                if(val != -1) {
                    cout << "Top most element on stackB is " << val;
                }
                break;
            case 8:
                mStack.displayB();
                break;
        }
    } while(choice != 9);
    return 0;
}
