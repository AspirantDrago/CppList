#include "List.h"

#include <exception>

using namespace std;

class IndexError : std::exception {
};

List::List() : size(0), capacity(ZAPAS), array(new int[ZAPAS]) {
    // cout << "Конструктор по-умолчанию" << endl;
}

List::List(const List &lst) {
    // cout << "Конструктор копирования" << endl;
    size = lst.size;
    capacity = lst.capacity;
    array = new int[capacity];
    for (int i = 0; i < size; i++) {
        array[i] = lst.array[i];
    }
}

List::List(List &&lst) {
    // cout << "Конструктор перемещения" << endl;
    size = lst.size;            // Забираем у исходного объекта все члены
    capacity = lst.capacity;
    array = lst.array;
    lst.size = 0;               // Удаляем у исходного объекта
    lst.array = nullptr;
}

List::~List() {
    if (array != nullptr) {
        delete[] array;
    }
}

unsigned int List::getSize() const {
    return size;
}

int List::operator[](int index) const {
    if (index >= 0) {
        if (index >= size) {
            throw IndexError();
        }
        return array[index];
    } else {
        if (index < -size) {
            throw IndexError();
        }
        return array[size + index]; // т.к. index - отрицательное число
    }
}

int& List::operator[](int index) {
    if (index >= 0) {
        if (index >= size) {
            throw IndexError();
        }
        return array[index];
    } else {
        if (index < -size) {
            throw IndexError();
        }
        return array[size + index]; // т.к. index - отрицательное число
    }
}

void List::append(int value) {
    array[size++] = value;
}

void List::clear() {
    size = 0;
}

void List::operator*=(const unsigned int value) {
    if (value == 0) {
        clear();
        return;
    }
    unsigned int oldSize = size;
    for (int j = 1; j < value; j++) {
        for (unsigned int i = 0; i < oldSize; i++) {
            append(array[i]);
        }
    }
}

std::ostream& operator<<(std::ostream& os, const List& lst) {
    os << '[';
    if (lst.getSize() > 0) {
        os << lst[0];
    }
    for (int i = 1; i < lst.getSize(); i++) {
        os << ", " << lst[i];
    }
    os << ']';
    return os;
}

List operator*(const List& lst, int value) {
    List result;
    while (value--) {
        for (int i = 0; i < lst.getSize(); i++) {
            result.append(lst[i]);
        }
    }
    return result;
}

List operator*(int value, const List& lst) {
    return lst * value;
}

List& List::operator=(const List& lst) {
    // cout << "Оператор присваивания с копированием" << endl;
    if (this == &lst) {             // Проверка на самокопирование
        return *this;
    }
    delete[] array;                 // Очистка старых динамических данных
    size = lst.size;                // Копирование новых динамических данных
    capacity = lst.capacity;
    array = new int[capacity];
    for (int i = 0; i < size; i++) {
        array[i] = lst.array[i];
    }
    return *this;
}

List& List::operator=(List&& lst) {
    // cout << "Оператор присваивания с перемещением" << endl;
    size = lst.size;
    capacity = lst.capacity;
    array = lst.array;
    lst.array = nullptr;
    lst.size = 0;
    return *this;
}