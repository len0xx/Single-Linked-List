#include <iostream>
#include <cstdint>

using namespace::std;

// A structure of each node in the list
struct Node {
    uint32_t value = 0;
    Node* next = 0;
};

// Just a function to print the given node value
void PrintNodeValue(Node* node) {
    cout << "Element " << node->value << endl;
}

// Single-Linked List Class description (with operators overload)
class List {
private:
    Node* head = new Node();
    Node* last = head;
    uint64_t counter = 0;

public:
    // Constructor
    List() { }

    List(uint32_t val) {
        Node* newNode = new Node({ val });
        head = newNode;
        last = newNode;
        counter++;
    }

    List(Node* newNode) {
        Node* modifiedNode = new Node({newNode->value});
        head = modifiedNode;
        last = modifiedNode;
        counter++;
    }

    List(const List& anotherList) {
        Node* current = anotherList.head;

        while (current->next) {
            Append(current->value);
            current = current->next;
        }
        Append(current->value);
    }

    // Destructor
    ~List() {
        Clear();
    }

    // Append to the list with new Node value
    void Append(uint32_t val) {
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
    uint64_t Count(void) {
        return counter;
    }

    // Getting the Node with the given value
    Node* Get(uint32_t val) {
        Node* current = head;

        while (current->next && current->value != val)
            current = current->next;

        return current;
    }

    // Getting the sum of all Nodes in the list
    uint64_t Sum(void) {
        Node* current = head;
        uint64_t result = 0;

        while (current->next) {
            result += current->value;
            current = current->next;
        } result += current->value;

        return result;
    }

    // Removing all the elements in the list
    void Clear(void) {
        Node* current;
        if (counter == 1) current = head;
        else current = head->next;

        if (counter) {
            while (current->next)
                current = Remove(current);

            if (counter > 1) {
                delete head->next;
                counter--;
                delete head;
                counter--;
            }
            else {
                delete head;
                counter--;
            }
        }
    }

    const List& operator-(const List& right) {
        cout << "Lists can not be subtracted from each other" << endl;
        return *this;
    }

    const List& operator-=(const List& right) {
        cout << "Lists can not be subtracted from each other" << endl;
        return *this;
    }

    const List& operator*(const List& right) {
        cout << "Lists can not be multiplied by each other" << endl;
        return *this;
    }

    const List& operator*=(const List& right) {
        cout << "Lists can not be multiplied by each other" << endl;
        return *this;
    }

    const List& operator/(const List& right) {
        cout << "Lists can not be divided by each other" << endl;
        return *this;
    }

    const List& operator/=(const List& right) {
        cout << "Lists can not be divided by each other" << endl;
        return *this;
    }

    const List& operator+=(const int right) {
        (*this).Append(right);
        return *this;
    }

    const List& operator+=(const List& right) {
        Node* currentR = right.head;

        while (currentR->next) {
            (*this).Append(currentR->value);
            currentR = currentR->next;
        }
        (*this).Append(currentR->value);

        return *this;
    }

    friend const List& operator+(const List& left, const List& right) {
        Node* currentR = right.head;
        List* result = new List(left);

        while (currentR->next) {
            (*result).Append(currentR->value);
            currentR = currentR->next;
        }
        (*result).Append(currentR->value);

        return *result;
    }

    const uint64_t operator+() {
        return Sum();
    }

    const int operator-() {
        return 0;
    }

    friend const bool operator==(const List& left, const List& right) {
        Node* currentL = left.head;
        Node* currentR = right.head;

        if (left.counter != right.counter)
            return false;

        bool flag = true;

        while (currentL->next && currentR->next) {
            if (currentL->value != currentR->value) {
                flag = false;
                break;
            }
            currentL = currentL->next;
            currentR = currentR->next;
        }
        if (currentL->value != currentR->value)
            flag = false;

        return flag;
    }

    friend const bool operator>(const List& left, const List& right) {
        return left.counter > right.counter;
    }

    friend const bool operator<(const List& left, const List& right) {
        return left.counter < right.counter;
    }

    friend const bool operator>=(const List& left, const List& right) {
        return left.counter >= right.counter;
    }

    friend const bool operator<=(const List& left, const List& right) {
        return left.counter <= right.counter;
    }

    const List& operator--() {
        cout << "Lists can not be incremented or decremented" << endl;
        return *this;
    }

    const List& operator++() {
        cout << "Lists can not be incremented or decremented" << endl;
        return *this;
    }

    const List& operator--(int) {
        cout << "Lists can not be incremented or decremented" << endl;
        return *this;
    }

    const List& operator++(int) {
        cout << "Lists can not be incremented or decremented" << endl;

        return *this;
    }

    operator int() {
        return +(*this);
    }

    operator char() {
        return +(*this);
    }

    operator long() {
        return +(*this);
    }
};

int main() {
    // Creating the linked list
    List numbers = List();
    List numbers2 = List();
    
    // Filling the first list up with numbers in range [1;5]
    for (int i = 1; i <= 5; i++)
        numbers += i;

    // Filling the second list up with numbers in range [10;13]
    for (int i = 10; i <= 13; i++)
        numbers2 += i;

    // Creating the new list which will contain both of the previous lists
    List numbers3 = numbers + numbers2;

    printf("Displaying the third list\n");
    numbers3.Print();

    // Copying the third list into the new one
    List numbers4 = List(numbers3);

    // And now comparing them
    if (numbers4 == numbers3) cout << "These two lists are identical" << endl;
    else if (numbers4 > numbers3) cout << "First list is larger than the second one" << endl;
    else if (numbers4 < numbers3) cout << "Second list is larger than the first one" << endl;
    else cout << "These two lists are different" << endl;

    // Displaying the fourth list length
    cout << "Fourth list length: " << numbers4.Count() << endl;
    numbers4.Print();
    
    // Clearing the first list
    cout << "Clearing the first list" << endl;
    numbers.Clear();

    // Displaying current list length
    cout << "First list length: " << numbers.Count() << endl;
    return 0;
}