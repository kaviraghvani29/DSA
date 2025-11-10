#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {     
        data = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {         
        head = NULL;
    }

    void insert_at_beginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << value << " inserted at beginning.\n";
    }

    void display() {
        Node* temp = head;
        if (!temp) {
            cout << "List is empty.\n";
            return;
        }
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << key << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << key << " not found in the list.\n";
    }

    void delete_node(int key) {
        Node* temp = head;
        Node* prev = NULL;

        if (temp != NULL && temp->data == key) {
            head = temp->next;
            delete temp;
            cout << key << " deleted from the list.\n";
            return;
        }

        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << key << " not found in the list.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << key << " deleted from the list.\n";
    }

    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
        cout << "Linked list reversed successfully.\n";
    }
};

int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Display List\n";
        cout << "3. Search Element\n";
        cout << "4. Delete Node\n";
        cout << "5. Reverse List\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insert_at_beginning(value);
                break;
            case 2:
                list.display();
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;
            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                list.delete_node(value);
                break;
            case 5:
                list.reverse();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
