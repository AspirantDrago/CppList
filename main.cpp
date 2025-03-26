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

    List lst = getRandomList(10);
    cout << lst << endl;
    cout << lst(2, -1, 2) << endl;
    cout << lst(2, -1) << endl;
    cout << lst(-1, 0, -1) << endl;

    return 0;
}
