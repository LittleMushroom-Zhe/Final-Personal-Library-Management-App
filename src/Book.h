#ifndef BOOK_H
#define BOOK_H

#include <vector>
#include <string>
#include "LibraryItem.h"

struct BorrowRecord {
    std::string name;
    int daysBorrowed;
};

class Book : public LibraryItem {
 private:
    std::string author;
    std::string borrowedBy;

    bool read;
    bool favorite;
    bool toBeRead;
    bool borrowed;

    int rating;
    int borrowDays;
    int totalCopies;
    int borrowedCopies;

    std::vector<BorrowRecord> borrowers;

public:
    Book(std::string title, std::string author, std::string genre);
    Book(std::string title);
    Book(std::string title, std::string author);

    std::string getAuthor() const;
    std::string getBorrowedBy() const;

    void setCopies(int copies);
    void markAsRead();
    void markAsUnread();
    void setRating(int rating);
    void display() const;
    void markFavorite();
    void removeFavorite();
    void addToTBR();
    void removeFromTBR();
    void borrowBook(std::string person, int days);
    void returnByName(std::string person);

    bool isTBR() const;
    bool isRead() const;
    bool isFavorite() const;
    bool isBorrowed() const;

    int getBorrowedDays() const;
    int getCopies() const;
    int getAvailableCopies() const;
    int getTotalCopies() const;
    int getRating() const;

    std::vector<BorrowRecord> getBorrowers() const;
};

#endif