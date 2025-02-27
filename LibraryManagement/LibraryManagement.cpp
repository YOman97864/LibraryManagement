#include <iostream>
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







int main() {
    
    return 0;
}