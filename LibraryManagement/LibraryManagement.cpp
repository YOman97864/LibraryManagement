﻿#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    string genre;
    int year;
    bool available;
    double rating;
};

vector<Book> books;
int nextId = 1;

void loadBooks() {
    ifstream file("books.txt");
    if (!file) return;
    Book b;
    while (file >> b.id >> ws && getline(file, b.title) && getline(file, b.author) && getline(file, b.genre) && file >> b.year >> b.available >> b.rating) {
        books.push_back(b);
        nextId = max(nextId, b.id + 1);
    }
    file.close();
}


void saveBooks() {
    ofstream file("books.txt");
    for (const auto& b : books) {
        file << b.id << '\n' << b.title << '\n' << b.author << '\n' << b.genre << '\n' << b.year << '\n' << b.available << '\n' << b.rating << '\n';
    }
    file.close();
}

void addBook() {
    Book b;
    b.id = nextId++;
    cout << "Title: "; getline(cin, b.title);
    cout << "Author: "; getline(cin, b.author);
    cout << "Genre: "; getline(cin, b.genre);
    cout << "Year: "; cin >> b.year;
    cout << "Available (1-yes, 0-no): "; cin >> b.available;
    cout << "Rating: "; cin >> b.rating;
    cin.ignore();
    books.push_back(b);
    saveBooks();
}

void listBooks() {
    for (const auto& b : books) {
        cout << b.id << ": " << b.title << " by " << b.author << " (" << b.year << ") " << (b.available ? "Available" : "Not Available") << " Rating: " << b.rating << endl;
    }
}

int main() {
    loadBooks();
    int choice;
    do {
        cout << "1. Add book\n2. List books\n0. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1: addBook(); break;
        case 2: listBooks(); break;
        }
    } while (choice != 0);
    return 0;
}