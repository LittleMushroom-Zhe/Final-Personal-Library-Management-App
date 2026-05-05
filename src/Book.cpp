#include "Book.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// Constructor with title, author, genre

Book::Book(string title, string author, string genre)
: LibraryItem(title, genre),
  author(author), 
  read(false), 
  rating(0), 
  favorite(false), 
  toBeRead(false), 
  totalCopies(1), 
  borrowedCopies(0), 
  borrowed(false), 
  borrowedBy(""), 
  borrowDays(0) {}

// Constructor with only title

Book::Book(string title)
: LibraryItem(title, "Unknown"),
author("Unknown"),
read(false), 
rating(0), 
favorite(false), 
toBeRead(false), 
totalCopies(1), 
borrowedCopies(0), 
borrowed(false), 
borrowedBy(""), 
borrowDays(0) {}

// Constructor with title and author

Book::Book(string title, string author)
: LibraryItem(title, "Unknown"),
author(author),
read(false),
rating(0), 
favorite(false), 
toBeRead(false), 
totalCopies(1), 
borrowedCopies(0), 
borrowed(false), 
borrowedBy(""), 
borrowDays(0) {}


string Book::getAuthor() const {
	return author;
}


void Book::setCopies(int copies) {
	if (copies < 1) {
		throw invalid_argument("Copies must be at least 1. ");
	}

	totalCopies = copies;

}

int Book::getCopies() const {
	return totalCopies;
}

void Book::markAsRead() {
	read = true;
	toBeRead = false;  //auto remove
}

void Book::markAsUnread() {
	read = false;
	rating = 0;
}

void Book::setRating(int rating) {
	if (!read) {
		throw invalid_argument("Cannot rate a book that has not been read.");

	}

	if (rating <0 || rating > 5){
		throw invalid_argument("Rating must be between 0 and 5.");
	}

	this->rating = rating;

}

void Book::display() const {
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Genre: " << genre << endl;
	cout << "Copies owned: " << totalCopies << endl;
	cout << "Available copies: " << getAvailableCopies() << endl;

	if (borrowedCopies > 0) {
		cout << "Borrowed copies: " << borrowedCopies << endl;
	}

	cout << "Read: " << (read ? "Yes" : "No") << endl;

	if (read) {
		cout << "Rating: " << rating << "/5" << endl;
		cout << "Favorite: " << (favorite ? "Yes" : "No") << endl;
	} else {
		cout << "TBR: " << (toBeRead ? "Yes" : "No") << endl;
	}

	if (borrowedCopies > 0) {
		cout << "Borrowed by: " << endl;
		
		for (const BorrowRecord& record : borrowers) {
			cout << "- " << record.name;

			if (record.daysBorrowed > 0) {
				cout << " | Due in " << record.daysBorrowed << " day(s)";
			} else {
				cout << " | OVERDUE";
			}
	

		cout << endl;
		}
	}
}

void Book::markFavorite() {
	favorite = true;
}

void Book::removeFavorite() {
	favorite = false;
}

bool Book::isFavorite() const {
	return favorite;
}

void Book::addToTBR() {
	toBeRead = true;
}

void Book::removeFromTBR() {
	toBeRead = false;
}

bool Book::isTBR() const {
	return toBeRead;
}

void Book::borrowBook(string person, int days) {
	if (person.empty() || days <= 0) {
		throw invalid_argument("Invalid borrower name or days.");
	}
	

	if (borrowedCopies >= totalCopies) {
		throw runtime_error("No copies available.");
	}


	borrowedCopies++;
	borrowers.push_back({person, days});

	borrowed = true;
	borrowedBy = person;
	borrowDays = days;
}

 

 void Book::returnByName(string person) {
	for (int i = 0; i < borrowers.size(); i++) {
		if (borrowers[i].name == person) {
			borrowers.erase(borrowers.begin() + i);
			borrowedCopies--;

			if (borrowedCopies == 0) {
				borrowed = false;
				borrowedBy = "";
				borrowDays = 0;
			}

			return;
		}
	}

	throw runtime_error("Borrower not found.");
 }

 bool Book::isBorrowed() const {
	return borrowedCopies > 0;
 }

 vector<BorrowRecord> Book::getBorrowers() const {
	return borrowers;
 }

 string Book::getBorrowedBy() const {
	return borrowedBy;
 }

 int Book::getBorrowedDays() const {
	return borrowDays;
 }

 int Book::getAvailableCopies() const{
	return totalCopies - borrowedCopies;
 }

 int Book::getTotalCopies() const {
	return totalCopies;
 }

 int Book::getRating() const {
	return rating;
 }

 bool Book::isRead() const{
	return read;
 }
