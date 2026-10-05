#include <iostream>
#include <stdexcept>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {

        if (index < 0 || index >= size) {
            throw out_of_range("Bad index");
        }

        Node* current = head;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->value;
    }

    void insert(int index, int value) {

        if (index < 0 || index > size) {
            throw out_of_range("Bad index");
        }

        Node* newNode = new Node(value);

        if (index == 0) {

            newNode->next = head;
            head = newNode;
        }
        else {

            Node* current = head;

            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }

        size++;
    }

    int remove(int index) {

        if (index < 0 || index >= size) {
            throw out_of_range("Bad index");
        }

        Node* deletedNode;

        if (index == 0) {

            deletedNode = head;

            head = head->next;
        }
        else {

            Node* current = head;

            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }

            deletedNode = current->next;

            current->next = deletedNode->next;
        }

        int value = deletedNode->value;

        delete deletedNode;

        size--;

        return value;
    }
};

class Stack {
private:
    LinkedList list;

    // Stack-ийн хамгийн дээд элементийн index
    int top;

public:
    Stack() {
        top = -1;
    }

    // Stack-ийн хамгийн дээд элементийг харна
    int getTop() {

        if (top < 0) {
            throw underflow_error("Stack is empty");
        }

        return list.get(top);
    }

    // Stack-д шинэ элемент хийнэ
    void push(int item) {

        // top-ийн index-ийг нэгээр нэмнэ
        top++;

        // Шинэ элементийг төгсгөлд оруулна
        list.insert(top, item);
    }

    // Stack-аас хамгийн дээд элементийг гаргана
    int pop() {

        // Stack хоосон бол
        if (top < 0) {
            throw underflow_error("Stack is empty");
        }

        // top дээрх элементийг устгана
        int value = list.remove(top);

        // top index буурна
        top--;

        return value;
    }

    // Stack-ийн хэмжээг буцаана
    int getSize() {

        // top = -1 үед size = 0
        // top = 0 үед size = 1
        // top = 1 үед size = 2
        return top + 1;
    }
};

// g++ stack.cpp -o stack.exe 
//  .\stack.exe
int main() {

    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Stack:
    //
    // 30 <- top
    // 20
    // 10

    cout << "Top = "
         << stack.getTop()
         << endl;

    cout << "Size = "
         << stack.getSize()
         << endl;

    // 30 гарна
    cout << "Pop = "
         << stack.pop()
         << endl;

    // Одоо top = 20
    cout << "New Top = "
         << stack.getTop()
         << endl;

    cout << "Size = "
         << stack.getSize()
         << endl;

    return 0;
}