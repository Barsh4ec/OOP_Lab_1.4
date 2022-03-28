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
    cout << "Введіть кількість книг, вмістиму в бібліотеці: "; cin >> n;
    
    Library b;
    b.Library::Library(n);
    int no;
    do {
        cout << "Виберіть дію:" << endl;
        cout << "[1] - Пошук книги" << endl;
        cout << "[2] - Добавити книгу в бібліотеку" << endl;
        cout << "[3] - Видалити книгу з бібліотеки" << endl;
        cout << "[4] - Сортування книг" << endl;
        cout << "[5] - Показати всі книги" << endl;
        cout << "[0] - завершити виведення" << endl;
        cout << "Введіть значення: "; cin >> no;
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