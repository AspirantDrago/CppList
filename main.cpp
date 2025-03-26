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
    cout << lst[0] << ' ' << lst[-1] << endl;

    lst[0] = 0;
    lst[-1] = 777;
    cout << lst << endl;

    return 0;
}
