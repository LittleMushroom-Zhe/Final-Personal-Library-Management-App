#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <string>
#include <iostream>

class LibraryItem {
protected:
std::string title;
std::string genre;

public:
LibraryItem(std::string title, std::string genre)
: title(title), genre(genre) {}

std::string getTitle() const {
    return title;
}

std::string getGenre() const {
    return genre;
}

virtual void display() const {
    std::cout << "Title: " << title << std::endl;
    std::cout << "Genre: " << genre << std::endl;
}

virtual ~LibraryItem() {}
};

#endif