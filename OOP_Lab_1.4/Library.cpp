#include "Library.h"
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
using namespace std;

bool Library::Init(int yr, int n) {
	if (yr > 0 && yr <= 2022) {
		books[n].SetYear(yr);
		return true;
	}
	else {
		books[n].SetYear(0);
		return false;
	}
}
void Library::Read(int n) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string author, name;
	int year;
	do {
		cout << "����� �����: "; cin >> author;
		books[n].SetAuthor(author);
		cout << "г� �������: "; cin >> year;
		books[n].SetYear(year);
		cout << "����� �����: "; cin >> name;
		books[n].SetName(name);
	} while (!Init(year, n));
}
void Library::Display(int n) const {
	cout << ToString(n);
}
string Library::ToString(int n) const {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	stringstream sout;
	sout << "����� ����� - " << books[n].GetAuthor() << ", �� ������� - " << books[n].GetYear() << ", ����� - " << books[n].GetName() << ", ����������� � ������ " << n << endl;
	return sout.str();
}

void Library::Search() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string prizvysche, nazva;
	int no, rik;
	do {
		cout << "������� ����� ������:" << endl;
		cout << "[1] - ����� ����� �� �������" << endl;
		cout << "[2] - ����� ����� �� ����� �������" << endl;
		cout << "[3] - ����� ����� �� ������" << endl;
		cout << "[0] - ����������� �����" << endl;
		cout << "������ ��������: "; cin >> no;
		cout << endl;

		switch (no)
		{
		case 1:
		{
			cout << "������ ������� ������: "; cin >> prizvysche;
			for (int i = 0; i < size; i++)
			{
				if (books[i].GetAuthor() == prizvysche && books[i].GetZminna())
					Display(i);
			}
		}
			break;
		case 2:
		{
			cout << "������ �� �������: "; cin >> rik;
			for (int k = 0; k < size; k++)
			{
				if (books[k].GetYear() == rik && books[k].GetZminna())
					Display(k);
			}
		}
		case 3:
		{
			cout << "������ ����� �����: "; cin >> nazva;
			for (int i = 0; i < size; i++)
			{
				if (books[i].GetName() == nazva && books[i].GetZminna())
					Display(i);
			}
		}
			break;
		}
		cout << endl;
	} while (no != 0);
}

void Library::AddBook() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	do {
		do {
			cout << "������ ����� ������ � ��� ���� ������� �����: "; cin >> n;
		} while (!(n > 0 && n < size));
	} while (books[n].GetZminna());
	books[n].SetZminna(true);
	Read(n);
	Display(n);
}

void Library::DeleteBook() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	do {
		do {
			cout << "������ ����� ������ � ��� ���� �������� �����: "; cin >> n;
		} while (!(n >= 0 && n < size));
	} while (!books[n].GetZminna());
	books[n].SetZminna(false);
}

void Library::SortBooks() {
	int* arr;
	arr = new int[size];
	string* strarr;
	strarr = new string[size];
	string* namearr;
	namearr = new string[size];
	
	for (int i = 0; i < size; i++) {
		if (books[i].GetZminna()) {
			arr[i] = books[i].GetYear();
		}
		else
			arr[i] = 0;
	}

	for (int i = 0; i < size; i++) {
		if (books[i].GetZminna()) {
			namearr[i] = books[i].GetName();
		}
	}
	
	for (int i = 0; i < size; i++) {
		if (books[i].GetZminna()) {
			strarr[i] = books[i].GetAuthor();
			books[i].SetZminna(false);
		}
	}
	
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j] < arr[j + 1]) {
				int tmp = arr[j];
				string strtmp = strarr[j];
				string nametmp = namearr[j];

				arr[j] = arr[j + 1];
				strarr[j] = strarr[j + 1];
				namearr[j] = namearr[j + 1];

				arr[j + 1] = tmp;
				strarr[j + 1] = strtmp;
				namearr[j + 1] = nametmp;

			}
		}
	}
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] > 0) {
			books[i + 1].SetYear(arr[i]);
			books[i + 1].SetZminna(true);
		}
	}
	for (int i = 0; i < size - 1; i++) {
		if (books[i + 1].GetZminna()) {
			books[i + 1].SetAuthor(strarr[i]);
		}
	}
	for (int i = 0; i < size - 1; i++) {
		if (books[i + 1].GetZminna()) {
			books[i + 1].SetName(namearr[i]);
		}
	}
	delete[] arr;
	delete[] namearr;
	delete[] strarr;
	
}

void Library::ShowBooks() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	for (int i = 0; i < size; i++) {
		if (books[i].GetZminna()) {
			Display(i);
		}
	}
}