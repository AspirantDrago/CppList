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

    List ls;
    cin >> ls;
    cout << ls << endl;

    return 0;
}
