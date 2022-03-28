#include "Book.h"
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
using namespace std;

string Book::GetAuthor() {
	return author;
}
int Book::GetYear() {
	return year;
}
string Book::GetName() {
	return name;
}
int Book::GetZminna() {
	return zminna;
}
void Book::SetAuthor(string value) {
	author = value;
}
void Book::SetYear(int value) {
	year = value;
}
void Book::SetName(string value) {
	name = value;
}
void Book::SetZminna(int value) {
	zminna = value;
}
