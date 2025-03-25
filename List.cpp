#include "List.h"

#include <exception>

class IndexError : std::exception {
};

List::List() : size(0), capacity(ZAPAS), array(new int[ZAPAS]) {
}

List::~List() {
    delete[] array;
}

unsigned int List::getSize() const {
    return size;
}

int List::getAt(int index) const {
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

void List::setAt(int index, int value) {
    if (index >= 0) {
        if (index >= size) {
            throw IndexError();
        }
        array[index] = value;
    } else {
        if (index < -size) {
            throw IndexError();
        }
        array[size + index] = value; // т.к. index - отрицательное число
    }
}

void List::append(int value) {
    array[size++] = value;
}

std::ostream& operator<<(std::ostream& os, const List& lst) {
    os << '[';
    if (lst.getSize() > 0) {
        os << lst.getAt(0);
    }
    for (int i = 1; i < lst.getSize(); i++) {
        os << ", " << lst.getAt(i);
    }
    os << ']';
    return os;
}

List operator*(const List& lst, int value) {
    List result;
    while (value--) {
        for (int i = 0; i < lst.getSize(); i++) {
            result.append(lst.getAt(i));
        }
    }
    return result;
}

List operator*(int value, const List& lst) {
    return lst * value;
}