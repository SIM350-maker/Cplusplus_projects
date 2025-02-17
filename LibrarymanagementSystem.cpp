#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Book class
    class Book {
        public:
        string title;
        string author;
        bool isBorrowed;
        Book(string t, string a) {
          title = t;
          author = a;
          isBorrowed = false;
           }
          }; 

        // Library class
      class Library {

        private:
        vector<Book> books;
    
        public:
        // Add a new book
      void addBook(string title, string author) {
      books.push_back(Book(title, author));
      cout << "Book added successfully!\n";
            }
        // Display all books
      void displayBooks() {
       if (books.empty()) {
      cout << "No books in the library.\n";
        return;
            }
        cout << "\nAvailable Books:\n";
          for (size_t i = 0; i < books.size(); i++) {
          cout << i + 1 << ". " << books[i].title << " by " << books[i].author;
          if (books[i].isBorrowed) cout << " [Borrowed]";
          cout << endl;
            }
          }

          // Search for a book
      void searchBook(string query) {
       bool found = false;
        for (const auto& book : books) {
        if (book.title.find(query) != string::npos || book.author.find(query) != string::npos) {
       cout << "Found: " << book.title << " by " << book.author << endl;
        found = true;
          }
        }
      if (!found) cout << "No matching books found.\n";
    }
 // Borrow a book
 void borrowBook(int index) {
 if (index < 1 || index > books.size()) {
 cout << "Invalid book number!\n";
 return;
 }
 if (books[index - 1].isBorrowed) {
 cout << "Sorry, this book is already borrowed.\n";
 } else {
 books[index - 1].isBorrowed = true;
 cout << "You borrowed: " << books[index - 1].title << endl;
 }
 }
 // Return a book
 void returnBook(int index) {
 if (index < 1 || index > books.size()) {
 cout << "Invalid book number!\n";
 return;
 }
 if (!books[index - 1].isBorrowed) {
 cout << "This book was not borrowed.\n";
 } else {
 books[index - 1].isBorrowed = false;
 cout << "You returned: " << books[index - 1].title << endl;
 }
 }
};
// Main menu
int main() {
 Library library;
 int choice;
 
 while (true) {
 cout << "\nLibrary Management System\n";
 cout << "1. Add Book\n2. View Books\n3. Search Book\n4. Borrow Book\n5. Return Book\n6. Exit\n";
 cout << "Enter choice: ";
 cin >> choice;
 cin.ignore(); // Ignore newline left in the buffer
 if (choice == 1) {
 string title, author;
 cout << "Enter book title: ";
 getline(cin, title);
 cout << "Enter author name: ";
 getline(cin, author);
 library.addBook(title, author);
 } 
 else if (choice == 2) {
 library.displayBooks();
 } 
 else if (choice == 3) {
 string query;
 cout << "Enter book title or author to search: ";
 getline(cin, query);
 library.searchBook(query);
 } 
 else if (choice == 4) {
 library.displayBooks();
 int index;
 cout << "Enter book number to borrow: ";
 cin >> index;
 library.borrowBook(index);
 } 
 else if (choice == 5) {
 library.displayBooks();
 int index;
 cout << "Enter book number to return: ";
 cin >> index;
 library.returnBook(index);
 } 
 else if (choice == 6) {
 cout << "Exiting program...\n";
 break;
 } 
 else {
 cout << "Invalid choice, try again.\n";
 }
 }
 return 0;
}