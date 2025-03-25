#include <iostream>
#include <windows.h>
#include <random>
#include <ctime>

#include "List.cpp"

using namespace std;

List getRandomList(unsigned int size) {
    List result;
    for (int i = 0; i < size; i++) {
        result.append(rand() % 100);
    }
    return result;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(time(nullptr));

    List lst;

    lst = getRandomList(10);

    return 0;
}
