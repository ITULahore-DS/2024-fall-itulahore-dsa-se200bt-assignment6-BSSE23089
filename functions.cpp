#include "functions.h"

// Node constructor: Initializes a node with a given value and sets next to nullptr.
Node::Node(int value)
{
    data = value;
    next = nullptr;
}

// Node destructor: Currently does nothing but could be used for cleanup if needed.
Node::~Node()
{
}

// Set the next pointer of the node to another node.
void Node::setNext(Node *val)
{
    next = val;
}

// Get the next node that this node is pointing to.
Node *Node::getNext()
{
    return next;
}

// Set the data value of the node.
void Node::setData(int value)
{
    data = value;
}

// Get the data value of the node.
int Node::getData()
{
    return data;
}

// Stack constructor: Initializes an empty stack with top as nullptr and count as 0.
Stack::Stack()
{
    top = nullptr;
    count = 0;
}

// Stack destructor: Clears the stack and deletes all nodes.
Stack::~Stack()
{
    if (top != nullptr)
    {
        clear(); // Clear all nodes in the stack.
        top = nullptr;
    }
}

// Check if the stack is empty.
bool Stack::isEmpty()
{
    if (count == 0)
        return true;
    return false;
}

// Push a new element onto the stack.
void Stack::push(int data)
{
    Node *newNode = new Node(data); // Create a new node.
    if (top == nullptr)
    {
        top = newNode; // If stack is empty, set top to new node.
    }
    else
    {
        Node *temp = top;
        top = newNode;      // Set the new node as the top.
        top->setNext(temp); // Link new node to the previous top.
    }

    count++; // Increment the number of elements in the stack.
}

// Pop the top element from the stack.
void Stack::pop()
{
    if (isEmpty())
    {
        return; // Do nothing if stack is empty.
    }
    Node *temp = top;
    top = top->getNext(); // Set the top to the next element.
    delete temp;          // Delete the old top node.
    count--;              // Decrement the number of elements in the stack.
}

// Peek the value at the top of the stack without removing it.
int Stack::peek()
{
    if (top == nullptr)
    {
        return -1; // Return -1 if stack is empty.
    }
    return top->getData(); // Return the value of the top element.
}

// Return the number of elements in the stack.
int Stack::size()
{
    return count;
}

// Clear all elements from the stack.
void Stack::clear()
{
    while (!isEmpty())
    {
        pop(); // Pop elements until stack is empty.
    }
    count = 0;
}

// Recursively print all elements in the stack.
void Stack::printStack()
{
    if (top == nullptr)
    {
        return; // Do nothing if stack is empty.
    }
    int temp = top->getData();
    cout << temp << endl; // Print the value at the top.
    pop();                // Remove the top element.
    printStack();         // Recursive call to print the remaining stack.
    push(temp);           // Push the value back onto the stack.
}

// Queue constructor: Initializes an empty queue with top, end as nullptr and Size as 0.
Queue::Queue()
{
    top = nullptr;
    Size = 0;
    end = nullptr;
}

// Queue destructor: Clears the queue and deletes all nodes.
Queue::~Queue()
{
    if (top != nullptr)
    {
        while (!isEmpty())
        {
            dequeue(); // Dequeue elements until queue is empty.
        }
        top = nullptr;
        end = nullptr;
    }
}

// Check if the queue is empty.
bool Queue::isEmpty()
{
    if (top == nullptr)
        return true;
    return false;
}

// Enqueue a new element to the end of the queue.
void Queue::enqueue(int data)
{
    Node *newNode = new Node(data); // Create a new node.
    if (top == nullptr)
    {
        top = newNode; // If queue is empty, set top and end to the new node.
        end = newNode;
    }
    else
    {
        end->setNext(newNode); // Link the last node to the new node.
        end = newNode;         // Set the new node as the end of the queue.
    }
    Size++; // Increment the size of the queue.
}

// Dequeue an element from the front of the queue.
void Queue::dequeue()
{
    if (top == nullptr)
    {
        return; // Do nothing if queue is empty.
    }
    else
    {
        Node *temp = top;
        top = top->getNext(); // Set the top to the next element.
        delete temp;          // Delete the old front node.
    }
    Size--; // Decrement the size of the queue.
}

// Return the number of elements in the queue.
int Queue::size()
{
    return Size;
}

int Queue::peek()
{
    return top->getData();
}

// Print all elements in the queue.
void Queue::printQueue()
{
    if (top == nullptr)
    {
        return; // Do nothing if queue is empty.
    }
    Node *temp = top;
    int increment = 0;
    while (increment < size())
    {
        cout << temp->getData() << " "; // Print the value at the current node.
        temp = temp->getNext();         // Move to the next node.
        increment++;
    }
    cout << endl; // Print a new line after all elements.
}

void Queue::clear()
{
    
    while (!isEmpty())
    {
        dequeue(); // dequeue elements until queue is empty.
    }
    Size = 0;
}
