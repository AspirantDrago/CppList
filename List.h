#pragma once
#define ZAPAS 50
#include <ostream>

class List {
    unsigned int size;          // Размер с данными
    unsigned int capacity;      // Реальный размер с учётом "запаса"
    int* array;

public:
    List();
    List(const List& lst);
    List(List&& lst);
    ~List();
    unsigned int getSize() const;
    int getAt(int index) const;
    void setAt(int index, int value);
    void append(int value);
    void clear();

    friend std::ostream& operator<<(std::ostream& os, const List& lst);
    friend List operator*(const List& lst, int value);
    friend List operator*(int value, const List& lst);
    void operator*=(unsigned int value);
    List& operator=(const List& lst);
    List& operator=(List&& lst);
};
