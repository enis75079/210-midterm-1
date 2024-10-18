#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

// creates class doubly linked list
class DoublyLinkedList {
private:
    // node structure in doubly linked list
    struct Node {
        int data; // data value in node
        Node* prev; // pointer that points to a previous node in the linked list
        Node* next; // pointer that points to a node ahead in the linked list

        // parameterized constructor initializing a value for data and assigning prev and next with empty pointers
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head; // pointer for the first node in the linked list
    Node* tail; // pointer for the last node in the linked list

public:
    // default constructor initialzing head and tail as an empty list
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    // insert_after function. takes in a value as well as a position. purpose is to add a node after the specific position with the parameter value
    void insert_after(int value, int position) {
        // if user enters a position that doesn't exist (position is less than 0)
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        // creates a node with the parameter value
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        // creates a temporary node to search list of the parameter position
        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        // if the parameter position exceeds the size of the linked list, output error message and returns the function
        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        // inserts the node after the parameter position
        newNode->next = temp->next;
        newNode->prev = temp;

        // if the next node in the linked list is not nullptr, have temp->next point to newNode
        if (temp->next)
            temp->next->prev = newNode;
        else
            // the last node of the linked lsit becomes newNode
            tail = newNode;
        temp->next = newNode;
    }

    // delete_val function. goes through the linked list and deletes the first node that has the parameter value.
    void delete_val(int value) {
        if (!head) return; // returns function if there head is nullptr

        // creates a temporary node at the first node in the linked list
        Node* temp = head;
        
        // while the temp node doesn't have the parameter value
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; // if the value doesn't exist in the linked list

        // changes the other nodes in the linked list to compensate for the deleted node
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            // if the head was the deleted node, assigns the node after head to head
            head = temp->next; 

        if (temp->next)
            temp->next->prev = temp->prev;
        else
            // if the tail was the deleted node, assigns the node before it to tail
            tail = temp->prev; 
        
        // deletes the temp node
        delete temp;
    }


    void delete_pos(int pos) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
    
        if (pos == 1) {
            pop_front();
            return;
        }
    
        Node* temp = head;
    
        for (int i = 1; i < pos; i++){
            if (!temp) {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next;
        }
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }
    
        if (!temp->next) {
            pop_back();
            return;
        }
    
        Node* tempPrev = temp->prev;
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp;
    }

    void push_back(int v) {
        Node* newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(int v) {
        Node* newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void pop_front() {

        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head;

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) { 
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS;  // dummy statement to avoid compiler warning

    
    return 0;
}