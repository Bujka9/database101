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

    int getSize() {
        return size;
    }
};

class Queue {
private:
    // Queue дотроо LinkedList ашиглана
    LinkedList list;

    int size;

public:
    Queue() {
        size = 0;
    }

    // Index дээрх утгыг харна
    int get(int index) {

        if (index < 0 || index >= size) {
            throw out_of_range("Bad index");
        }

        return list.get(index);
    }

    // Queue-ийн хамгийн ард шинэ элемент нэмнэ
    void enqueue(int item) {

        // Одоогийн size index дээр нэмбэл
        // жагсаалтын төгсгөлд орно
        list.insert(size, item);

        size++;
    }

    // Queue-ийн хамгийн эхний элементийг гаргана
    int dequeue() {

        if (size == 0) {
            throw underflow_error("Queue is empty");
        }

        // index 0 буюу хамгийн эхний элементийг устгана
        int value = list.remove(0);

        size--;

        return value;
    }

    int getSize() {
        return size;
    }

    // Queue-ийн хамгийн эхний элемент
    int getHead() {

        if (size == 0) {
            throw underflow_error("Queue is empty");
        }

        return list.get(0);
    }

    // Queue-ийн хамгийн сүүлийн элемент
    int getTail() {

        if (size == 0) {
            throw underflow_error("Queue is empty");
        }

        return list.get(size - 1);
    }
};

// g++ queue.cpp -o queue.exe
//  .\queue.exe
int main() {

    Queue queue;

    // Queue:
    // 10
    queue.enqueue(10);

    // 10 20
    queue.enqueue(20);

    // 10 20 30
    queue.enqueue(30);

    cout << "Head = "
         << queue.getHead()
         << endl;

    cout << "Tail = "
         << queue.getTail()
         << endl;

    cout << "Size = "
         << queue.getSize()
         << endl;

    // Хамгийн эхний 10 гарна
    cout << "Dequeue = "
         << queue.dequeue()
         << endl;

    // Одоо хамгийн эхний элемент 20
    cout << "New Head = "
         << queue.getHead()
         << endl;

    return 0;
}