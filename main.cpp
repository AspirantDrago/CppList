#include <iostream>
#include <windows.h>

#include "List.cpp"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    List lst;
    for (int i = 1; i <= 10; i++) {
        lst.append(i);
    }
    cout << lst << endl;
    // lst *= 3;
    // cout << lst << endl;

    return 0;
}
