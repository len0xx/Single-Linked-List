#include <iostream>

using namespace::std;

struct Node {
    int value = 0;
    Node* next = 0;
};

void PrintNodeValue(Node* node) {
    cout << "Element " << node->value << endl;
}

class List {
private:
    Node* head = new Node();
    Node* last = head;
    unsigned long long counter = 0;

public:
    List() { }

    ~List() {
        if (counter) Clear();
    }

    void Append(int val) {
        Node* newNode, * current;
        newNode = new Node({ val });

        if (head->value == NULL) {
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

    void Append(Node* newNode) {
        Node* current;

        if (head->value == NULL) {
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

    void Duplicate(Node* newNode) {
        Append(newNode);
    }

    Node* Remove(Node* entry = {NULL}) {
        Node* current = head;

        while (current != entry && current->next != entry)
            current = current->next;

        current->next = entry->next;
        cout << "Deleting " << entry->value << endl;
        delete entry;
        counter--;
        return current->next;
    }

    void Print(void) {
        Node* current = head;

        while (current->next != NULL) {
            PrintNodeValue(current);
            current = current->next;
        } PrintNodeValue(current);
    }

    unsigned long long Count(void) {
        return counter;
    }

    Node* Get(int val) {
        Node* current = head;

        while (current->value != val)
            current = current->next;
        
        return current;
    }

    void Clear(void) {
        Node* current = head->next;

        while (current->next)
            current = Remove(current);

        cout << "Deleting " << head->next->value << endl;
        delete head->next;
        counter--;
        cout << "Deleting " << head->value << endl;
        delete head;
        counter--;
    }
};

int main() {
    List numbers = List();
    char* text = new char[100];
    cin >> text;
    for (int i = 1; i <= 10000; i++) {
        numbers.Append(i);
    }
    // numbers.Print();
    cout << "Current amount: " << numbers.Count() << endl;
    cin >> text;
    numbers.Clear();
    cin >> text;
    cout << "Current amount: " << numbers.Count() << endl;
    cout << "Done" << endl;
}