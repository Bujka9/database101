#include <iostream>
#include <stdexcept>

using namespace std;

class ArrayList {
private:
    // Хамгийн ихдээ 100 элемент хадгална
    int items[100];

    // Одоогоор хэдэн элемент байгааг хадгална
    int size;

public:
    // Constructor
    ArrayList() {
        size = 0;
    }

    // Тухайн index дээрх элементийг буцаана
    int get(int index) {

        // Index буруу байгаа эсэхийг шалгана
        if (index < 0 || index >= size) {
            throw out_of_range("Bad index");
        }

        return items[index];
    }

    // Тухайн index дээр шинэ элемент оруулна
    void insert(int index, int item) {

        // Жагсаалт дүүрсэн эсэх
        if (size >= 100) {
            throw overflow_error("Array is full");
        }

        // Insert хийх үед index нь 0..size байж болно
        if (index < 0 || index > size) {
            throw out_of_range("Bad index");
        }

        // Шинэ элементэд зай гаргахын тулд
        // элементүүдийг баруун тийш нэг алхам шилжүүлнэ
        for (int i = size; i > index; i--) {
            items[i] = items[i - 1];
        }

        // Шинэ элементийг index дээр байрлуулна
        items[index] = item;

        // Элементийн тоог нэмнэ
        size++;
    }

    // Тухайн index дээрх элементийг устгана
    int remove(int index) {

        // Index зөв эсэхийг шалгана
        if (index < 0 || index >= size) {
            throw out_of_range("Bad index");
        }

        // Устгаж байгаа утгыг хадгалж авна
        int deletedItem = items[index];

        // Устгасан элементийн дараах бүх элементийг
        // зүүн тийш нэг алхам шилжүүлнэ
        for (int i = index; i < size - 1; i++) {
            items[i] = items[i + 1];
        }

        // Элементийн тоог нэгээр багасгана
        size--;

        // Устгасан элементийг буцаана
        return deletedItem;
    }

    // Жагсаалтын хэмжээг буцаана
    int getSize() {
        return size;
    }

    // Жагсаалтыг хэвлэх нэмэлт method
    void print() {

        cout << "[ ";

        for (int i = 0; i < size; i++) {
            cout << items[i] << " ";
        }

        cout << "]" << endl;
    }
};


// g++ array_list.cpp -o array_list.exe .\array_list.exe
int main() {

    ArrayList list;

    // Эхэнд 10 оруулна
    list.insert(0, 10);

    // Дараа нь 20
    list.insert(1, 20);

    // Дараа нь 30
    list.insert(2, 30);

    cout << "Ehnii list: ";
    list.print();

    // index 1 дээр 15 оруулна
    list.insert(1, 15);

    cout << "15-iig 1dh index deer insert hiisnii daraa: ";
    list.print();

    // index 2 дээрх элементийг устгана
    int deleted = list.remove(2);

    cout << "Ustgasan element: " << deleted << endl;

    cout << "Delete hiisnii daraa: ";
    list.print();

    cout << "Size = " << list.getSize() << endl;

    return 0;
}