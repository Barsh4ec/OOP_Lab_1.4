#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Book.h"
using namespace std;

class Library {
    Book* books;
    int size;
public:
    bool Init(int, int);
    void Read(int);
    void Display(int) const;
    string ToString(int) const;

    Library(int n = 1)
        : size(n)
    {
        books = new Book[size];
    }

    ~Library() { delete []books; }

    void Search();
    void AddBook();
    void DeleteBook();
    void SortBooks();
    void ShowBooks();
};
