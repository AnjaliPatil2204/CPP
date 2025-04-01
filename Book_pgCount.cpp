#include <iostream>
#include <cstring>
using namespace std;
class Book {
private:
    char* title;
    char* author;
    int pageCount;
    bool formatType; // true for hardcover, false for paperback
    float* chapterPages;
    int numChapters;

public:
    // Default Constructor
    Book() {
        title = new char[1];
        title[0] = '\0';
        author = new char[1];
        author[0] = '\0';
        pageCount = 0;
        formatType = false;
        numChapters = 0;
        chapterPages = '\0';
    }

    // Parameterized Constructor
    Book(const char* t, const char* a, int pages, bool format, int chapters, float* chapterPg) {
        title = new char[strlen(t) + 1];
        strcpy(title, t);

        author = new char[strlen(a) + 1];
        strcpy(author, a);

        pageCount = pages;
        formatType = format;
        numChapters = chapters;

        chapterPages = new float[numChapters];
        for (int i = 0; i < numChapters; i++) {
            chapterPages[i] = chapterPg[i];
        }
    }

    // Copy Constructor (Deep Copy)
    Book(const Book& other) {
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);

        author = new char[strlen(other.author) + 1];
        strcpy(author, other.author);

        pageCount = other.pageCount;
        formatType = other.formatType;
        numChapters = other.numChapters;

        chapterPages = new float[numChapters];
        for (int i = 0; i < numChapters; i++) {
            chapterPages[i] = other.chapterPages[i];
        }
    }

    // Destructor
    ~Book() {
        delete[] title;
        delete[] author;
        delete[] chapterPages;
    }

    // Modify Chapter Pages
    void modifyChapterPages(int index, float newPages) {
        if (index >= 0 && index < numChapters) {
            chapterPages[index] = newPages;
        } else {
            cout << "Invalid chapter index!\n";
        }
    }

    // Display Book Details
    void display() const {
        cout<< "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "Page Count: " << pageCount << "\n";
        cout << "Format: " << (formatType ? "Hardcover" : "Paperback") << "\n";
        cout << "Number of Chapters: " << numChapters << "\n";
        cout << "Chapter Pages: ";
        for (int i = 0; i < numChapters; i++) {
            std::cout << chapterPages[i] << " ";
        }
        cout << "\n";
    }
      // Getter methods for title, author and page count
    const char* getTitle() const {
        return title;
    }

    const char* getAuthor() const {
        return author;
    }

    int getPageCount() const {
        return pageCount;
    }

    bool getIsHardcover() const {
        return formatType;
    }

    int getNumChapters() const {
        return numChapters;
    }

    float* getChapterPages() const {
        return chapterPages;
    }


};

int main() {
    float chapters1[] = {15.5, 20.4, 18};
    // 1. Testing Default Constructor
        Book book1;
        cout << "Book 1 :\n";
        book1.display();

        // 2. Testing Parameterized Constructor
        Book book2("Shamchi Aai", "Sane Guruji", 252, true, 3, chapters1);
        cout << "\nBook 2 :\n";
        book2.display();

        // 3. Testing Copy Constructor
        Book book3 = book2;  // Using copy constructor
        cout << "\nBook 3 :\n";
        book3.display();

        // 4. Testing Memory Management with Chapter Modification
        book2.modifyChapterPages(2, 25);
        cout << "\nBook 2 after modifying chapter 3 page count:\n";
        book2.display();

    return 0;
}
