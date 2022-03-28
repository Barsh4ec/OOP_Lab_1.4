#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Book {
    string author;
    int year;
    string name;
    bool zminna = false;
public:
    string GetAuthor();
    int GetYear();
    string GetName();
    int GetZminna();
    void SetAuthor(string);
    void SetYear(int);
    void SetName(string);
    void SetZminna(int);
};