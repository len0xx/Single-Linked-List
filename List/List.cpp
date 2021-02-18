#include <iostream>

using namespace::std;

// A structure of each node in the list
struct Node {
    int value = 0;
    Node* next = 0;
};

// Just a function to print the given node value
void PrintNodeValue(Node* node) {
    cout << "Element " << node->value << endl;
}

// Single-Linked List Class description
class List {
private:
    Node* head = new Node();
    Node* last = head;
    unsigned long long counter = 0;

public:
    // Constructor
    List() { }

    // Destructor
    ~List() {
        Clear();
    }

    // Append to the list with new Node value
    void Append(int val) {
        Node* newNode, * current;
        newNode = new Node({ val });

        if (!counter) {
            head = newNode;
            last = newNode;
        }
        else {
            current = last;
            while (current->next)
                current = current->next;
            current->next = newNode;
            last = newNode;
        }
        counter++;
    }

    // Append to the list with new Node itself
    void Append(Node* newNode) {
        Node* current, * modifiedNode;

        modifiedNode = new Node({newNode->value, NULL});

        if (!counter) {
            head = modifiedNode;
            last = modifiedNode;
        }
        else {
            current = last;
            while (current->next)
                current = current->next;
            current->next = modifiedNode;
            last = modifiedNode;
        }
        counter++;
    }

    // Duplicating the given Node
    void Duplicate(Node* newNode) {
        Append(newNode);
    }

    // Removing the given Node
    Node* Remove(Node* entry = {NULL}) {
        Node* current = head;

        while (current->next && current->next != entry)
            current = current->next;

        if (current->next != NULL) {
            current->next = entry->next;
            cout << "Deleting " << entry->value << endl;
            delete entry;
            counter--;
            return current->next;
        }
        else {
            cout << "Could not find the entry " << entry->value << " in this list" << endl;
            return current;
        }
    }

    // Displaying all the values in the list on the screen
    void Print(void) {
        Node* current = head;

        while (current->next != NULL) {
            PrintNodeValue(current);
            current = current->next;
        } PrintNodeValue(current);
    }

    // Getting the length of this list
    unsigned long long Count(void) {
        return counter;
    }

    // Getting the Node with given value
    Node* Get(int val) {
        Node* current = head;

        while (current->next && current->value != val)
            current = current->next;
        
        return current;
    }

    // Removing all the elements in the list
    void Clear(void) {
        Node* current = head->next;

        if (counter) {
            while (current->next)
                current = Remove(current);

            cout << "Deleting " << head->next->value << endl;
            delete head->next;
            counter--;
            cout << "Deleting " << head->value << endl;
            delete head;
            counter--;
        }
    }
};

int main() {
    // Creating the linked list
    List numbers = List();
    
    // Filling it up with numbers in range [1;10000]
    for (int i = 1; i <= 10000; i++)
        numbers.Append(i);
    
    // Displaying current list length
    cout << "Current amount: " << numbers.Count() << endl;
    
    // Clearing the list
    numbers.Clear();

    // Displaying current list length
    cout << "Current amount: " << numbers.Count() << endl;
    
    // Now appending again..
    numbers.Append(1000);
    numbers.Append(2000);
    numbers.Append(3000);

    // .. and displaying the current list elements and its length
    numbers.Print();
    cout << "Current amount: " << numbers.Count() << endl;
}