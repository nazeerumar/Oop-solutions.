#include <iostream>
using namespace std;

class ReadingMaterial {
protected:
    string title;
    string author;
    int id;

public:
    ReadingMaterial(string t, string a, int i) {
        title = t;
        author = a;
        id = i;
    }

    virtual void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ID: " << id << endl;
    }

    virtual void checkLength() {}

    virtual ~ReadingMaterial() {}
};

class Book : public ReadingMaterial {
private:
    int pages;
    string genre;

public:
    Book(string t, string a, int i, int p, string g)
        : ReadingMaterial(t, a, i) {
        pages = p;
        genre = g;
    }

    void display() override {
        ReadingMaterial::display();
        cout << "Pages: " << pages << endl;
        cout << "Genre: " << genre << endl;
        checkLength();
        cout << "------------------------\n";
    }

    void checkLength() override {
        if (pages > 300)
            cout << "This is a long reading material.\n";
        else
            cout << "This is a short reading material.\n";
    }
};

class Magazine : public ReadingMaterial {
private:
    int issueNumber;
    string month;

public:
    Magazine(string t, string a, int i, int issue, string m)
        : ReadingMaterial(t, a, i) {
        issueNumber = issue;
        month = m;
    }

    void display() override {
        ReadingMaterial::display();
        cout << "Issue Number: " << issueNumber << endl;
        cout << "Month: " << month << endl;
        cout << "This is a short reading material.\n";
        cout << "------------------------\n";
    }
};

class AudioBook : public ReadingMaterial {
private:
    int duration;
    string narrator;

public:
    AudioBook(string t, string a, int i, int d, string n)
        : ReadingMaterial(t, a, i) {
        duration = d;
        narrator = n;
    }

    void display() override {
        ReadingMaterial::display();
        cout << "Duration (minutes): " << duration << endl;
        cout << "Narrator: " << narrator << endl;
        checkLength();
        cout << "------------------------\n";
    }

    void checkLength() override {
        if (duration > 60)
            cout << "This is a long reading material.\n";
        else
            cout << "This is a short reading material.\n";
    }
};

int main() {

   
    Book b1("C++ Basics", "Bjarne", 101, 350, "Education");
    Book b2("Short Stories", "Ali Khan", 102, 150, "Fiction");

    Magazine m1("Tech Monthly", "Editor A", 201, 12, "March");
    Magazine m2("Science World", "Editor B", 202, 5, "July");

    AudioBook a1("Learn Programming", "John Doe", 301, 90, "Michael");
    AudioBook a2("Quick Motivation", "Sara Lee", 302, 45, "David");

    ReadingMaterial* library[6] = { &b1, &b2, &m1, &m2, &a1, &a2 };

    for (int i = 0; i < 6; i++) {
        library[i]->display();
    }

    return 0;
}
