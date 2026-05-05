#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include "Book.h"

using namespace std;

int getIntInput(string prompt) {
    int value;

    while (true) {
        cout << prompt;

        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number.\n";
    }
}

/// Main Menu

void displayMenu() {
    cout << "\n=== Personal Library ===\n";
    cout << "1. Add Book\n";
    cout << "2. View Library\n";
    cout << "3. View TBR List\n";
    cout << "4. View Ratings and Favorites\n";
    cout << "5. View Borrowed Books\n";
    cout << "6. Borrow Book\n";
    cout << "7. Return Book\n";
    cout << "8. Remove Book\n";
    cout << "9. Exit\n";
}

/// 1. Add Book

void addBook(vector<Book>& library) {
string title, author, genre, input;
    

auto isCancel = [](const string& s) {
    return s == "q" || s == "Q";
};

auto header = []() {
    cout << "\n=== Add A Book ===\n";
    cout << "Type q to cancel\n";
};

    // Title ?
    header();
    cout << "Title: ";
    getline(cin, title);
    if (isCancel(title)) return;

    // Author ?
    header();
    cout << "Author: ";
    getline(cin, author);
    if (isCancel(author)) return;

    // Genre ?
    header();
    cout << "Genre: ";
    getline(cin, genre);
    if (isCancel(genre)) return;

    Book book(title, author, genre);


    // Copies ?
    header();
    cout << "How many copies do you own? ";
    getline(cin, input);
    if (isCancel(input)) return;

    try {
        int copies = stoi(input);
        book.setCopies(copies);
    } catch (...) {
        cout << "Invalid number.\n";
        return;
    }

    // Borrowed ?
    header();
    cout << "Is this book currently being borrowed? (y/n): ";
    getline(cin, input);
    if (isCancel(input)) return;

    if (input == "y" || input == "Y") {
        string name;

        header();
        cout << "Who is borrowing it? ";
        getline(cin,name);
        if (isCancel(name)) return;

        header();
        cout << "For how many days? ";
        getline(cin, input);
        if (isCancel(input)) return;

        try {
            int days = stoi(input);
            book.borrowBook(name, days);
        } catch (...) {
            cout << "Invalid number of days.\n";
            return;
        }
    }
    
    // Read ?
    header();
    cout << "Have you read this book? (y/n): ";
    getline(cin, input);
    if (isCancel(input)) return;

    if (input == "y" || input == "Y"){
        book.markAsRead();

        header();
        cout << "Enter rating (0-5): ";
        getline(cin, input);
        if (isCancel(input)) return;

       try {
        int rating = stoi(input);
        book.setRating(rating);
       } catch (...) {
        cout << "Invalid rating.\n";
        return;
       }

        header();
        cout << "Do you want to mark this book as a favorite? (y/n): ";
        getline(cin, input);
        if (isCancel(input)) return;

        if(input == "y" || input == "Y"){
            book.markFavorite();
        }
    } else {
        header();
        cout << "Add this book to your TBR list? (y/n): ";
        getline(cin, input);
        if (isCancel(input)) return;

        if (input == "y" || input == "Y") {
            book.addToTBR();
        }
    }

    library.push_back(book);

    cout << "\nBook added!\n";
}

/// 2. View Library

void sortLibrary(vector<Book>& library){
    sort(library.begin(), library.end(), [](const Book& a, const Book& b) {
        if (a.getGenre() == b.getGenre()) {
            return a.getAuthor() <b.getAuthor();
        }
        return a.getGenre() < b.getGenre();
    });
}

void viewLibrary(vector<Book>& library) {
    if (library.empty()) {
        cout << "\nYour library is empty.\n";
        return;
    }

    sortLibrary(library);

    cout << "\n=== Library ===\n";

    string currentGenre = "";

    for (int i = 0; i < library.size(); i++){
        if (library[i].getGenre() != currentGenre) {
            currentGenre = library[i].getGenre();
            cout << "\n== " << currentGenre << " ==\n";
        }

        cout << i + 1 << ". "
        << library[i].getAuthor()
        << " - "
        << library[i].getTitle()
        << endl;
    }

    int choice = getIntInput("\nSelect a book number to view details, or enter 0 to go back: ");

    if (choice == 0) {
        return;
    }

    if (choice < 1 || choice > library.size()) {
        cout << "Invalid selection.\n";
        return;
    }

        /// Quick Book Menu

  

    Book& selected = library[choice - 1];


    while (true) {

    cout << "\nWhat would you like to do?\n";
    cout << "1. View details\n";

   if (selected.isFavorite()) {
    cout << "2. Remove from favorites\n";
 } else {
    cout << "2. Mark as favorite\n";
 }

    cout << "3. Rate book\n";
    cout << "4. Borrow book\n";
    cout << "5. Return book\n";

    if (selected.isTBR()) {
    cout << "6. Remove from TBR\n";
    } else {
    cout << "6. Add to TBR\n";
    }

    cout << "0. Go back\n";

    int action = getIntInput("Enter choice: ");

    switch (action) {
        case 1: 
        selected.display();
        break;

        case 2:
       if (selected.isFavorite()) {
        selected.removeFavorite();
        cout << "Book removed from favorites.\n";
       } else {
        selected.markFavorite();
        cout << "Book marked as favorite.\n";
       }
       break;

        case 3: {
            int rating  = getIntInput("Enter rating (0-5): ");

            try {
            selected.markAsRead();
            selected.setRating(rating);
            cout << "Rating added.\n";
            } catch (exception& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        
        case 4: {
            string name;
        
            cout << "Who is borrowing it? ";
            getline(cin, name);

            int days = getIntInput("For how many days? ");

            try {
                selected.borrowBook(name, days);
                cout << "Book borrowed.\n";
            } catch (exception& e) {
                cout << "Error: " << e.what() << endl;
            }

            break;
        }


        case 5: {
            string name;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Who is returning the book? ";
            getline(cin, name);

            try {
                selected.returnByName(name);
                cout << "Book returned.\n";
            } catch (exception& e) {
                cout << "Error: " << e.what() << endl;
            }

            break;
        }
        
        case 6:
        if (selected.isTBR()) {
            selected.removeFromTBR();
            cout << "Book removed from TBR.\n";
        } else {
            selected.addToTBR();
            selected.markAsUnread();
            cout << "Book added to TBR.\n";
        }
        break;

        case 0:
        return;

        default:
        cout << "Invalid choice.\n";
    }

}
}


/// 3. View TBR

void viewTBR(vector<Book>& library) {
    cout << "\n=== To Be Read List ===\n";

    vector<int> tbrIndexes;

    for (int i = 0; i < library.size(); i++) {
        if (library [i].isTBR()) {
            tbrIndexes.push_back(i);
        }
    }

    if (tbrIndexes.empty()) {
        cout << "Your TBR list is empty.\n";
        return;
    }

    for (int i = 0; i < tbrIndexes.size(); i++) {
        Book& b = library[tbrIndexes[i]];

        cout << i + 1 << ". "
        << b.getAuthor()
        << " - "
        << b.getTitle()
        << " (" << b.getGenre() << ")"
        <<endl;
    }

    int choice;
    choice = getIntInput("\nSelect a book to remove from TBR, or enter 0 to go back: ");

    if (choice == 0) return;

    if (choice < 1 || choice > tbrIndexes.size()) {
        cout << "Invalid selection.\n";
        return;
    }

    library[tbrIndexes[choice - 1]].removeFromTBR();
    cout << "Book removed from TBR.\n";
}

/// 4. View Ratings and Favorites

void viewRatingsAndFavorites(const vector<Book>& library) {
    vector<Book> ratedBooks;

    for (const Book& b : library) {
        if (b.isRead()) {
            ratedBooks.push_back(b);
        }
    }

    sort(ratedBooks.begin(), ratedBooks.end(), [](const Book& a, const Book& b) {
        return a.getRating() > b.getRating(); 
    });
    cout << "\n=== Ratings: Highest to Lowest ===\n";

    if (ratedBooks.empty()) {
    cout << "No rated books yet.\n";
    return;
    }

    for (const Book& b : ratedBooks) {
        cout << b.getTitle() << " by " << b.getAuthor()
        << " | Rating: " << b.getRating() << "/5";

        if (b.isFavorite()) {
            cout << " | Favorite";
        }

        cout << endl;
    }
}

/// 5. View Borrowed Books

void viewBorrowedBooks(const vector<Book>& library) {
    cout << "\n=== Borrowed Books ===\n";

    bool found = false;

    for (const Book& b : library) {

      int borrowedCount = b.getTotalCopies() - b.getAvailableCopies();

      if (borrowedCount > 0) {
        cout << "\n" << b.getTitle()
        << " by " << b.getAuthor() << endl;

        cout << "Borrowed copies: "
         << borrowedCount << "/"
          << b.getTotalCopies() << endl;

        vector<BorrowRecord> borrowers = b.getBorrowers();

        cout << "Borrowed by:\n";

        for (const BorrowRecord& record : borrowers) {
            cout << " - " << record.name;

            if (record.daysBorrowed > 0) {
                cout << " | Due in "
                << record.daysBorrowed
                << " day(s)";
            } else {
                cout << " | OVERDUE";
            }

            cout << endl;
        }

        found = true;
      }
    }

if (!found) {
    cout << "No books are currently being borrowed. \n";
}
}

/// 6. Borrow Book

void borrowFromLibrary(vector<Book>& library) {
    if (library.empty()) {
        cout << "Library is empty.\n";
        return;
    }

    cout << "\n=== Borrow Book ===\n";

    for (int i = 0; i < library.size(); i++) {
        cout << i + 1 << ". "
        <<library[i].getTitle()
        << " by " << library[i].getAuthor()
        << " | Borrowed: "
        << library[i].getTotalCopies() - library[i].getAvailableCopies()
        << "/" << library[i].getTotalCopies()
        << endl;
    }

     int choice;
     choice = getIntInput("Select a book to borrow (0 to cancel): ");

    if (choice == 0) return;

    if (choice < 1 || choice > library.size()) {
        cout << "Invalid selection.\n";
        return;
    }

    Book& selected = library[choice - 1];

    if (selected.getAvailableCopies() <= 0) {
        cout << "No copies available to borrow.\n";
        return;
    }

    string name;

    cout << "Who is borrowing it? ";
    getline(cin, name);

    int days = getIntInput("For how many days? ");

    try{
    selected.borrowBook(name, days);
    cout << "Book borrowed successfully.\n";
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

}

/// 7. Return Book

void returnBookByName(vector<Book>& library) {
    cout << "\n=== Return Book ===\n";
    
    for (int i = 0; i < library.size(); i++) {
        cout << i + 1 << ". "
        << library[i].getTitle()
        << " by " << library[i].getAuthor() << endl;
    }

    int choice;
    choice = getIntInput("Select a book: ");

    if (choice < 1 || choice > library.size()) {
        cout << "Invalid selection.\n";
        return;
    }

    Book& selected = library[choice - 1];

    vector<BorrowRecord> borrowers = selected.getBorrowers();

    if (borrowers.empty()) {
        cout << "No one has borrowed this book.\n";
        return;
    }

    cout << "\nBorrowers:\n";
    for (int i = 0; i <borrowers.size(); i++) {
        cout << i + 1 << ". " << borrowers[i].name << endl;
    }

    int personChoice;
    personChoice = getIntInput("Select who is returning: ");

    if (personChoice <1 || personChoice > borrowers.size()) {
        cout << "Invalid selection.\n";
        return;
    }

    try {
        selected.returnByName(borrowers[personChoice - 1].name);
        cout << "Book returned successfully.\n";
    }
    
    catch (exception& e){
        cout << "Error: " << e.what() << endl;
    }

}

/// 8. Remove Book

void removeBook(vector<Book>& library) {
if (library.empty()) {
    cout << "\nLibrary is empty.\n";
    return;
}

cout << "\n=== Remove Book ===\n";

for (int i = 0; i < library.size(); i++) {
    cout << i + 1 << ". "
    << library[i].getAuthor()
    << " - "
    << library[i].getTitle()
    << endl;
}

int choice;
choice = getIntInput("Select a book to remove (0 to cancel): ");

if (choice == 0) {
    return;
}

if (choice < 1 || choice > library.size()) {
    cout << "Invalid selection.\n";
    return;
}

    /// Confirmation

char confirm;
cout << "Are you sure you want to remove \""
<< library[choice - 1].getTitle()
<<"\"? (y/n): ";
cin >> confirm;

if (confirm == 'y' || confirm == 'Y') {
    library.erase(library.begin() + (choice - 1));
    cout << "Book removed successfully.\n";
} else {
    cout << "Removal canceled.\n";
}

}


int main() {
    vector<Book> library;
    int choice;

    while (true) {
       displayMenu();
       
      choice = getIntInput ("Enter choice: ");
    
       switch (choice) {
        case 1:
        addBook(library);
        break;

        case 2:
        viewLibrary(library);
        break;

        case 3:
        viewTBR(library);
        break;

        case 4:
        viewRatingsAndFavorites(library);
        break;

        case 5:
        viewBorrowedBooks(library);
        break;

        case 6:
        borrowFromLibrary(library);
        break;

        case 7:
        returnBookByName(library);
        break;

        case 8:
        removeBook(library);
        break;

        case 9:
        cout << "Goodbye!\n";
        return 0;

        default:
        cout <<"Invalid choice.\n";
    }
}
    

    return 0;
}
