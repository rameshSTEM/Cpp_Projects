#include <iostream>
using namespace std;

class Book
{
private:
    string title;
    string author;
    string isbn;
    bool available;

public:
    //setters
    void setTitle(const string newTitle)
    {
        title = newTitle;
    }

    void setAuthor(const string name)
    {
        author = name;
    }

    void setISBN(const string booknum)
    {
        isbn = booknum;
    }

    void setAvailable(bool isAvaliable)
    {
        available = isAvaliable;
    }

    //getters
    string getTitle() const
    {
        return title;
    }

    string getAuthor() const
    {
        return author;
    }

    string getISBN() const
    {
        return isbn;
    }

    bool getAvailable() const
    {
        return available ? "Available" : "Checked out";
    }

    // borrow book  function
    void borrowBook()
    {
        if (available)
        {
            available = false;
            cout << "Book borrowed successfully." << endl;
        }
        else
        {
            cout << "Book already checked out." << endl;
        }
    }

    // return book function
    void returnBook()
    {
        if (!available)
        {
            available = true;
            cout << "Book returned successfully" << endl;
        }
        else
        {
            cout << "Book is already available." << endl;
        }
    }
};

int main(){
    const int maxBooks = 100;
    Book* library= new Book[maxBooks]; //pointer array pointing to book objects

    int bookCount = 0;
 int choice;
    do {
        std::cout << "1. Add Book\n2. Remove Book\n3. Search for Book\n4. Exit\n";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Add Book
                int index;
                std::cout << "Enter the index to add the book: ";
                std::cin >> index;

                if (index >= 0 && index < maxBooks) {
                    std::string title, author, isbn;
                    bool available;

                    std::cout << "Enter title: ";
                    std::cin >> title;
                    std::cout << "Enter author: ";
                    std::cin >> author;
                    std::cout << "Enter ISBN: ";
                    std::cin >> isbn;
                    std::cout << "Is the book available? (1 for true, 0 for false): ";
                    std::cin >> available;

                    library[index].setTitle(title);
                    library[index].setAuthor(author);
                    library[index].setISBN(isbn);
                    library[index].setAvailable(available);
                } else {
                    std::cout << "Invalid index.\n";
                }
                break;
            }
            case 2: {
                // Remove Book
                int index;
                std::cout << "Enter the index to remove the book: ";
                std::cin >> index;

                if (index >= 0 && index < maxBooks) {
                    // Remove the book by setting its title to an empty string
                    library[index].setTitle("");
                } else {
                    std::cout << "Invalid index.\n";
                }
                break;
            }
            case 3: {
                // Search for Book
                int index;
                std::cout << "Enter the index to search for the book: ";
                std::cin >> index;

                if (index >= 0 && index < maxBooks && !library[index].getTitle().empty()) {
                    std::cout << "Title: " << library[index].getTitle() << "\n";
                    std::cout << "Author: " << library[index].getAuthor() << "\n";
                    std::cout << "ISBN: " << library[index].getISBN() << "\n";
                    std::cout << "Availability: " << library[index].getAvailable() << "\n";
                } else {
                    std::cout << "Book not found.\n";
                }
                break;
            }
            case 4:
                // Exit
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    delete[] library;  // Free the dynamically allocated memory

    return 0;
}
