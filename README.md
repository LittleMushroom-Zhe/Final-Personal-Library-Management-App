[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mIiIeHnO)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=23768744)
# 14 final project

## Assignment spec

(20 points) Final project is about putting together a small app. It's not about functionality of the app or size of code, but showing various language and design features that we have learned. Assignment provides a shell of a project with just `src/main.cpp` file and `domain/` folder. There are only tasks for building/running/debugging one executable - `bin/lms`. Codespace and build/run/debug experience is the same as before. 

## Steps

- Please accept assignment `14` from *BlackBoard* as usual. Visit generated repo `OU-CTCH1330/14-final-project-yourGitHubId` on GitHub
<br /><span style='color: yellow'>Warning:</span> From acceptance page please don't go to Codespace straight, instead please first open repo with a link. Confirm **5** commits showing, with last commit being _"Add assignment deadline url"_. If not all of commits appear wait before opening Codespace. Repo setup takes few seconds and if Codespace is opened prematurely some commits will be missed. This will create sync conflicts later. 
- Please read present instruction before making further choices. 
- The context of your submission can be a simple app, for instance "inventory management app" or "a shopping cart". When designing and coding it, please feel free to re-use design and code we've had in LMS app. Feel free to go back to past assignments and re-use code from old repos. However it can not be a blind copy paste. It can be similar ideas, same language and design features, but adapted to a new task. For this reason, please don't make your app for this assignment LMS again. 
- It's perfectly fine to reach out and ask questions (to peers or instructor), search online, use Google or StackOverflow sort of resources. However, please refrain from using "ready to serve" AI tools, like ChatGPT. I am happy to help if you get stuck.
- Below is a rubric that will be used to evaluate your submission. Points available add to more than assignment's worth, thus one can get full credit with meeting just enough goals. Obviously I encourage you to meet them all, extra points will serve as bonus.


| Goal | Points |
| -- | -- |
| 1. Your solution has **at least** 100 lines of code total across **all** `*.h` and `*.cpp` files | 2 points |
| 2. Your solution runs at least in baseline scenario | 2 points |
| 3. Instructor can not find a test scenario to bring your app to unhandled error/crash | 2 points || 3. You used structured code, with various tasks logically structured in properly names functions | 2 points |
| 4. You used some standard library class or function, eg `std::string` | 2 points |
| 5. You used structured error handling and exceptions | 2 points |
| 6. You designed and used a class | 2 points |
| 7. You split class design in header and implementations files | 2 points |
| 8. You use function overloading, for instance overloaded class constructor | 2 points |
| 9. You use private and public class members, class is designed with encapsulation in mind | 2 points |
| 10. You use class inheritance | 2 points |
| 11. You use pointers and/or pass-by-reference | 2 points | 
| 12. You provided app documentation in `Readme.md` file (doesn't need to be long) +1 bonus points if you use [markdown](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax) | 2 points |
| 13. You added class diagram to app documentation | 2 points | 
| 14. You recorded a demo showcasing the UI and included (accessible) link in documentation | 2 points |
| 15. Early bird: assignment is submitted by `Early bird` deadline (see in BlackBoard, under assignment folder) | 2 points |

- If you record a demo, you can use [Panopto](https://www.panopto.com/) or [MS Streams](https://www.microsoft365.com) for screen capture. Using university email will help with these services, you'll have instant account with premium features. Another approach is to schedule a bogus Teams meeting (please invite me for access), start that meeting, share screen and turn screen recording on. You can use other service if you prefer. Don't forget to provide access to my user/email (or make recording public, at your discretion).
- Don't worry too much about UI. You can add menu, user input and interactivity, however you don't have to. Just producing console output alone as a result of the app execution is perfectly fine.
- I suggest not to overdo it. All goals set in the rubric can be satisfied with a single key class, inheriting from single base class. Don't worry about user input, menus and selections, feel free to imitate user input by hardcoding data.
- To make sure none of your goals are missed, please either:
  - Add the third column to above table indicating file and line in code where you've met that goal, like `domain/warehouse.cpp#72`; **OR**
  - Add comment in code next to the place where you met the goal, something like <br /><span style='color: green'>// goal 4, stl lib used</span>
- Stage, commit and sync your code. 
- Please submit at BlackBoard assignment, a short comment will suffice:

> Submitted calendar app, see repo [https://github.com/OU-CTCH1330/14-final-project-id](https://github.com/OU-CTCH1330/14-final-project-id)

## General tips

These tips are general, not specific to current assignment.

- If something goes wrong, please reach out early on, <span style='color: #8ae234'>**DO NOT STRUGGLE**</span>.
- Use GitHub PR, BlackBoard Discussions, MS Teams, email, or any other means for reaching out for instructor's help. Also feel free to collaborate with fellow students, especially now that sprint project has fostered an excellent teamwork. 
- Please remember, instructor can't see your code until sync'd with GitHub repo. Further, if you want to let fellow students examine your code your repo needs to be [made public](https://docs.github.com/en/repositories/managing-your-repositorys-settings-and-features/managing-repository-settings/setting-repository-visibility#changing-a-repositorys-visibility) (it's private at creation). Peer collaboration is highly encouraged, as long as it's genuine learning as opposed to mechanical copy/paste (see policies in the syllabus at BlackBoard > CTCH1330 > Docs).
- Syncing incremental progress milestones is recommended. Autograder doesn't care about repeated failures, only final success matters. 
- GitHub PR is an excellent place for code-centric discussions. This is also a standard in industry.
- Each assignment/repo expects a dedicated Codespace
- Please try not to spam Codespaces. If you've already created an instance for given repo, it's available at  [https://github.com/codespaces](https://github.com/codespaces) and they load faster (than a cold start of a fresh Codespace). Having multiple instances will fragment your work, as each Codespace has its individual local file system and one doesn't see changes in others, unless obviously synced through GitHub repo, to which they are all linked. Multiple instances may also create conflicts between different code edits, you will be unable to commit/sync (please reach out if that has happened).
- Consider cleaning up CodeSpaces for past assignments. They can be deleted (if running, stopped and deleted) by clicking `...` next to them. This is optional, as old Codespaces are discarded anyway after a period of inactivity.  

## App spec

If you decide to supply documentation, your markdown can go here. You can use a different `*.md` file if you like. 

## Personal Library Manager 
This application allows users to organize and manage their book collection.  Users can add books, manage favorites and TBR lists, and manage borrowing of books.
```
Features:
- Book Management
- Reading and Favorites
- TBR List
- Borrowing System
```
```
Usage Example:
1. Run the program using:
    - g++ src/Main.cpp src/Book.cpp -o library
    - ./library
2. Type 1 (Add Book) - Enter
3. Enter book details (title, author, genre)
4. Return to main screen, press 2, enter
5. In Library, type in number of book you added to 
    - View details
    - Rate
    - Borrow/return
    -Add/remove favorite or TBR
```
```mermaid
classDiagram
class LibraryItem {
  -string title
  -string genre
  +LibraryItem(string title, string genre)
  +string getTitle()
  +string getGenre()
  +void display()
}

class Book {
  -string author
  -bool read
  -bool favorite
  -bool toBeRead
  -bool borrowed
  -int rating
  -int borrowDays
  -int totalCopies
  -string borrowedBy
  -vector~BorrowRecord~ borrowers

  +Book(string title)
  +Book(string title, string author, string genre)
  +string getAuthor()
  +void setCopies(int copies)
  +void markAsRead()
  +void markAsUnread()
  +void setRating(int rating)
  +void markFavorite()
  +void removeFavorite()
  +void addToTBR()
  +void removeFromTBR()
  +void borrowBook(string person, int days)
  +void returnByName(string person)
  +void display()
}

class BorrowRecord {
  +string name
  +int daysBorrowed
}

LibraryItem <|-- Book
Book "1" o-- "*" BorrowRecord
```

[Demo](https://youtu.be/g0_RKgqw_0g)

~ Lisette Credeur
