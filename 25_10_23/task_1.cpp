#include <iostream>
using namespace std;
struct Node {
    string data;
    Node* next_ptr;
    
};
class Stack {
    private:
    Node* head;
    Node* tail;
    int size;
    int capacity;
    
    public:
    Stack(int maxCapacity) {
        head = nullptr;
        tail = nullptr;
        size = 0;
        capacity = maxCapacity;
    }

    void push(string value) {
        if (isFull()) {
            cout << "Stack overflow! cannot push\n";
            return;
        }
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next_ptr = head;
        head = newNode;
        if (tail == nullptr) {//if its the first node tail and head is the same
            tail = head;
        }
        size++;
        cout << "\nPushed: " << value << endl;
    }

    void pop(){
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop\n";
            return;
        }
        string popped = head->data;
        head = head->next_ptr;
        
        if(head == nullptr){ //if stack becomes empty the tail will be null
            tail = nullptr;
        }
        size--;
        cout << "\nPopped value: "<<popped<<endl;
    }

    void peek(){
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "\nTop element: " << head->data << endl;
    }
    bool isFull() {
        return size >= capacity;
    }
    bool isEmpty() {
        return head == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "\nStack is empty!" << endl;
            return;
        }
        cout << "\nStack elements: \n";
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next_ptr;
        }
        cout << endl;
    }

    int getCurrentSize() {
        return size;
    }

    int getMaxSize() {
        return capacity;
    }
};

int main() {
    int stack_size;
    int option;
    string value;
    cout << "Enter Stack size: ";
    cin >> stack_size;
    Stack myStack(stack_size);
    
    while(option!=7){
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Check if stack is full\n5. Check if stack is empty\n6. Display Stack\n7. EXIT\nEnter option: ";
        cin >> option;
        if(option == 1){
            cout << "Enter value to push: ";
            cin >> value;
            myStack.push(value);
        }else if(option == 2){
            myStack.pop();
        }else if(option==3){
            myStack.peek();
        }else if(option==4){
            if(myStack.isFull()) {
                cout << "\nStack is FULL";
            } else {
                cout << "\nStack is NOT FULL";
            }
            cout << "\nCurrent Size: " << myStack.getCurrentSize() << " Max Capacity: " <<myStack.getMaxSize()<<endl;
        }else if(option==5){
            if(myStack.isEmpty()) {
                cout << "\nStack is EMPTY";
            } else {
                cout << "\nStack is NOT empty";
            }
            cout << "\nCurrent Size: " << myStack.getCurrentSize() << " Max Capacity: " <<myStack.getMaxSize() <<endl;
        }else if(option==6){
            myStack.display();
        }else if(option==7){
            break;
        }else{
            cout <<"\nInvalid option";
        }
    }  
    return 0;
}
