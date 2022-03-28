#include "Library.h"
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    int n;
    cout << "������ ������� ����, ������� � ��������: "; cin >> n;
    
    Library b;
    b.Library::Library(n);
    int no;
    do {
        cout << "������� ��:" << endl;
        cout << "[1] - ����� �����" << endl;
        cout << "[2] - �������� ����� � ��������" << endl;
        cout << "[3] - �������� ����� � ��������" << endl;
        cout << "[4] - ���������� ����" << endl;
        cout << "[5] - �������� �� �����" << endl;
        cout << "[0] - ��������� ���������" << endl;
        cout << "������ ��������: "; cin >> no;
        cout << endl;

        switch (no)
        {
        case 1:
            b.Search();
            break;
        case 2:
            b.AddBook();
            break;
        case 3:
            b.DeleteBook();
            break;
        case 4:
            b.SortBooks();
            break;
        case 5:
            b.ShowBooks();
            break;
        }
        cout << endl;
    } while (no != 0);
    b.~Library();
   
    return 0;
}