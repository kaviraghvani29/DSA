#include <iostream>
using namespace std;


class StackBase 
{
public:
    virtual void push(int value) = 0;
    virtual void pop() = 0;
    virtual void peek() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual void display() = 0;
    virtual ~StackBase() {}
};


class EscalatorStack : public StackBase 
{
private:
    int top;
    int size;
    int* arr;

public:
    EscalatorStack(int s) 
    {
        size = s;
        arr = new int[size];
        top = -1;
    }

    void push(int value) override 
    {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << "Pushed: " << value << endl;
        }
    }
    
    void pop() override 
    {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop." << endl;
        } else {
            cout << "Popped: " << arr[top--] << endl;
        }
    }

    void peek() override 
    {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
        } else {
            cout << "Top Element: " << arr[top] << endl;
        }
    }
    
    bool isEmpty() override 
    {
        return (top == -1);
    }

    bool isFull() override 
    {
        return (top == size - 1);
    }

    void display() override 
    {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack Elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    
    ~EscalatorStack() 
    {
        delete[] arr;
        cout << "\nMemory released and program closed." << endl;
    }
};


int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    StackBase* stack = new EscalatorStack(size);

    int choice, value;

    do {
        cout << "\n===== ESCALATOR STACK MENU =====\n";
        cout << "1. Push Element\n";
        cout << "2. Pop Element\n";
        cout << "3. Display Top Element\n";
        cout << "4. Check if Stack is Empty\n";
        cout << "5. Check if Stack is Full\n";
        cout << "6. Display Stack\n";
        cout << "7. Exit\n";
        cout << "Enter Option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack->push(value);
                break;

            case 2:
                stack->pop();
                break;

            case 3:
                stack->peek();
                break;

            case 4:
                cout << (stack->isEmpty() ? "Stack is Empty" : "Stack is Not Empty") << endl;
                break;

            case 5:
                cout << (stack->isFull() ? "Stack is Full" : "Stack is Not Full") << endl;
                break;

            case 6:
                stack->display();
                break;

            case 7:
                cout << "Exiting…" << endl;
                break;

            default:
                cout << "Invalid Option! Try Again.\n";
        }

    } while (choice != 7);

    delete stack;
    return 0;
}