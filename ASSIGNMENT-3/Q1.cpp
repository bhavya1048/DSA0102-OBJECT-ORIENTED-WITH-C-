#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Book {
    string title, author;
    int copies;

public:
    Book() : Book("", "", 0) {}

    explicit Book(string t) : Book(t, "Unknown", 1) {}

    Book(string t, string a, int c)
        : title(t), author(a), copies(c) {
        if (c < 0)
            throw invalid_argument("Invalid number of copies");
    }

    void display() {
        cout << title << " " << author << " " << copies << endl;
    }
};

int main() {
    Book b1;
    Book b2("C++ Programming");
    Book b3("Java", "James", 5);

    b1.display();
    b2.display();
    b3.display();

    return 0;
}