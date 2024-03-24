#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
};

const int MAX_BOOKS = 100;
Book library[MAX_BOOKS];
int numBooks = 0;

void addBook(const Book& book) {
    if (numBooks < MAX_BOOKS) {
        library[numBooks++] = book;
    } else {
        cout << "Library is full. Cannot add more books." << endl;
    }
}

int main() {
    addBook({"The Catcher in the Rye", "J.D. Salinger"});
    addBook({"To Kill a Mockingbird", "Harper Lee"});

    string inputIsbn;
    cout << "Enter an ISBN: ";
    cin >> inputIsbn;

    bool bookFound = false;
    for (int i = 0; i < numBooks; ++i) {
        if (inputIsbn == library[i].isbn) {
            cout << "Book found:" << endl;
            cout << "Title: " << library[i].title << endl;
            cout << "Author: " << library[i].author << endl;
            bookFound = true;
            break;
        }
    }

    if (!bookFound) {
        cout << "Book with ISBN " << inputIsbn << " is not available in the library." << endl;
    }

    return 0;
}
