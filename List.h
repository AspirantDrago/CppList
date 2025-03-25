#pragma once
#define ZAPAS 50

class List {
    unsigned int size;          // Размер с данными
    unsigned int capacity;      // Реальный размер с учётом "запаса"
    int* array;

public:
    List();
    ~List();
};
