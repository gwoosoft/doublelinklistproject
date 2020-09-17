#include <iostream>
#include <cstdlib>
#include <ctime>

//lets make linklist first

using namespace std;


template <class T>
class node {
public:
    T data;
    node<T>* next, * prev;
};

template <class T>
class link {
    node<T>* head, * tail;
public:
    link() { head = tail = nullptr; }
    link(const link<T>& rhs) {
        head = tail = nullptr;
        *this = rhs;
    }
    link<T>& operator=(const link<T>& rhs) {
        if (this == &rhs)
            return *this;
        clear();
        head = nullptr; tail = nullptr;
        //head = rhs.head; tail = rhs.tail;
        node<T>* curr = rhs.head;
        while (curr != nullptr) {
            this->push_head(curr->data);
            curr = curr->next;
        }
        return *this;
    }

    link<T>& operator+(const link<T> second) {
        //node<T>* first;
        node<T>* secondnode;
        link<T> thetoal;
        //first = this->head;
        secondnode = second.head;

        /*
        while (first != nullptr) {
            thetoal.push_back(first->data);
            first = first->next;
        }
        */

        while (secondnode != nullptr) {
            this->push_back(secondnode->data);
            secondnode = secondnode->next;
        }


        return *this;

    }

    ~link()
    {
        clear();
        head = tail = nullptr;

    }
    void clear() {
        if (head == nullptr)
            cout << "Memory is all clear" << endl;
        else {
            while (head != nullptr && head != tail) {
                node<T>* curr = head;
                head = head->next;
                delete curr;
            }
        }
    }
    void push_back(T data) {
        node<T>* curr = new node<T>;
        curr->data = data;
        curr->next = curr->prev = nullptr;
        if (head == nullptr) {
            head = tail = curr;
            return;
        }
        curr->prev = tail;
        tail->next = curr;
        tail = curr;
        return;
    }

    void push_head(T data) {
        node<T>* curr = new node<T>;
        curr->data = data;
        curr->next = curr->prev = nullptr;
        if (head == nullptr) {
            head = tail = curr;
            return;
        }
        curr->next = head;
        head->prev = curr;
        head = curr;
        return;

    }
    void print() {
        node<T>* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    void remove(T d) {
        if (head == nullptr) {
            cout << "no node in the link";
        }
        else {
            node<T>* curr = head;
            node<T>* prev = 0;
            while (curr != nullptr) {
                if (curr->data == d)
                    break;
                else {
                    prev = curr;
                    curr = curr->next;
                }
            }
            //case 2 
            if (curr == 0) {
                cout << "wrong name might be input" << endl;
            }
            else {
                //delete head
                if (head == curr) {
                    //head->prev = head->next->prev;
                    head = head->next;
                }
                // delete non-dead
                else {
                    prev->next = curr->next;

                }
                delete curr;
            }
        }
    }

};


template <class T>
T getmax(T x, T y) {
    if (x > y)
        return x;
    else return y;
}

int main()
{


    link<int> test, test2;

    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);


    test.push_head(1);
    test.push_head(2);
    test.push_head(3);
    test.push_head(4);
    test.print();

    cout << "show me something before equal" << endl;
    test2 = test;

    cout << "show our test number here" << endl;
    test2.print();

    cout << "right before the return" << endl;

    srand(time(0));

    int x = rand() % 10, y = rand() % 10;
    int z = getmax(x, y);
    cout << "show me the Z: " << z;


    link<string> test3, test4;
    test3.push_back("thedragon");
    test3.push_back("cockroach");
    test3.push_back("Vegeta");

    test4.push_back("apple");
    test4.push_back("orange");
    test4.push_back("zolomon");

    link<string> final = test3;
    final.print();
    final.remove("thedragon");
    cout << endl;
    cout << "after removing the dragon" << endl;
    final.print();
    cout << "print out test3 + test 4" << endl;
    link<string> combined = test3 + test4;
    combined.print();

    return 0;
}

