#include "functions.h"
#include <iostream>
using namespace std;

void stackMenu() {
    Stack myStack;
    int choice, value;

    do {
        cout << "\n--- Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Check if empty" << endl;
        cout << "4. Get stack size" << endl;
        cout << "5. Display stack" << endl;
        cout << "0. Exit stack menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                myStack.push(value);
                cout << "Pushed " << value << " onto the stack." << endl;
                break;
            case 2:
                myStack.pop();
                cout << "Popped from the stack." << endl;
                break;
            case 3:
                if (myStack.isEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;
            case 4:
                cout << "Stack size: " << myStack.size() << endl;
                break;
            case 5:
                cout << "Stack contents: "<<endl;;
                myStack.printStack();
                break;
            case 0:
                cout << "Exiting stack menu." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);
}

void queueMenu() {
    Queue myQueue;
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Check if empty" << endl;
        cout << "4. Get queue size" << endl;
        cout << "5. Display queue" << endl;
        cout << "0. Exit queue menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                myQueue.enqueue(value);
                cout << "Enqueued " << value << " into the queue." << endl;
                break;
            case 2:
                myQueue.dequeue();
                cout << "Dequeued from the queue." << endl;
                break;
            case 3:
                if (myQueue.isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;
            case 4:
                cout << "Queue size: " << myQueue.size() << endl;
                break;
            case 5:
                cout << "Queue contents: "<<endl;
                myQueue.printQueue();
                break;
            case 0:
                cout << "Exiting queue menu." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);
}

int main() {
    int choice;

    do {
        cout << "\n--- Main Menu ---" << endl;
        cout << "1. Stack operations" << endl;
        cout << "2. Queue operations" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                stackMenu();
                break;
            case 2:
                queueMenu();
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
