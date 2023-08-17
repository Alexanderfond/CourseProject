#include "librer.h"
#include <iostream>

#include <Windows.h>
#include <string>
#include <fstream>


using namespace std;

stocks kl[20];

int s1, s2, s3, s4, nn = 0;


int  filling() {
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Stock" << i + 1 << ": ";  cin >> kl[i].stock;
        cout << "Received: ";  cin >> kl[i].z;
        cout << "In stock: ";  cin >> kl[i].p;
        cout << "Issued: ";  cin >> kl[i].v;
        cout << endl;
        kl[i].r = kl[i].z + kl[i].p - kl[i].v;
        s1 += kl[i].z;
        //s1 =FUNC(s1, kl[i].z);
        s2 += kl[i].p;
        s3 += kl[i].v;
        s4 += kl[i].r;
    }
    return n;
}

void outputting(int nn) {
    if (nn == 0) {
        cout << "Array is not filled yet\n";
        return;
    }
    else {
        cout << "------------------------------------------------------" << endl;
        cout << "|N|   Stock   | Received | In stock | Issued | Total |" << endl;
        cout << "------------------------------------------------------" << endl;
        for (int i = 0; i < nn; i++) {
            cout << "|" << i + 1 << "|\t" << kl[i].stock << " |\t" << kl[i].z << " |\t" << kl[i].p << " |\t" << kl[i].p << " |\t" << kl[i].v << " |\t" << kl[i].r << " |" << endl;
            cout << "------------------------------------------------------" << endl;
        }
    }
}

void recording(int q) {
    ofstream f;
    char name[12];

    cout << "Enter the file name: ";
    cin >> name;

    f.open(name);
    if (!f) {
        cout << "\nError\n";
        cin.get();
        exit(1);
    }

    for (int i = 0; i < q; i++) {
        f << kl[i].stock << " " << kl[i].z << " " << kl[i].p << " " << kl[i].v << " " << kl[i].r << endl;
    }
    f.close();
    cout << "The data were recorded in the file.";
}

int read() {
    int i = 0;
    char name[12];
    cout << "Enter the file name: ";
    cin >> name;
    ifstream readFile;
    readFile.open(name);
    if (!readFile) {
        cout << "File opening error.\n";
        return 0;
    }
    else {
        while (1) {
            if (readFile.tellg() == -1) break;
            readFile >> kl[i].stock >> kl[i].z >> kl[i].p >> kl[i].v >> kl[i].r;
            i++;
        }
        i--;
        cout << "i= " << i << endl;
        cout << "Data is read from the " << name << endl;
        for (int j = 0; j < i; j++) {
            s1 += kl[i].z;
            s2 += kl[i].p;
            s3 += kl[i].v;
            s4 += kl[i].r;
        }
        return i;
    }
}

void edit(int v) {
    int rowsQuan = v;
    int num;
    int field;
    if (rowsQuan > 0) {
        cout << "Enter the sequence number of the row";
        cin >> num;
        num--;
        cout << "\nEnter the number of the field: ";
        cout << "\nStock - 1";
        cout << "\nRecaived - 2";
        cout << "\nIn stock - 3\n";
        cout << "\nIssued - 4";
        cout << "Field number: "; cin >> field; cout << endl;

        cout << "Enter a new value for the field";
        switch (field) {
        case 1: {cin >> kl[num].stock; } break;
        case 2: {cin >> kl[num].z; } break;
        case 3: {cin >> kl[num].p; } break;
        case 4: {cin >> kl[num].v; } break;
        default: {cout << "No such value"; field = 0; }
        }
        if (field != 0)cout << "\nChanges made\n";

        kl[num].r = kl[num].z + kl[num].p - kl[num].v;

        s1 = 0; s2 = 0; s3 = 0; s4 = 0;
        for (int i = 0; i < v; i++) {
            s1 += kl[i].z;
            s2 += kl[i].p;
            s3 += kl[i].v;
            s4 += kl[i].r;
        }
    }
}