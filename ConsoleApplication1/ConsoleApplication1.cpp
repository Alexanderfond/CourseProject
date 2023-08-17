#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include "librer.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "КУРСОВА РОБОТА\nСистемне Програмування\nстудента групи У-94\nЦаплюка Олександра\nВаріант 21\n\n";

    int k, v = 2;

    do {
        cout << "Enter 0 to exit\n";
        cout << "Enter 1 to fill the array\n";
        cout << "Enter 2 to output the array\n";
        cout << "Enter 3 to record the file\n";
        cout << "Enter 4 to read from the file\n";
        cout << "Enter 5 to edit the file\n";

        cin >> k;

        switch (k) {
        case 0: break;
        case 1: v = filling(); break;
        case 2: outputting(v); break;
        case 3: recording(v); break;
        case 4: v = read(); break;
        case 5: edit(v); break;
        }
    } while (k != 0);
}