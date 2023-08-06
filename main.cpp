#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 5
#define MAX_BOOK_NAME_LENGTH 50

// Global variables
char books[MAX_BOOKS][MAX_BOOK_NAME_LENGTH];
int numBooks = 0;

// Function prototypes
void showAvailableBooks();
void issueBook();
void returnBook();

int main() {
    int choice;
    
    // Dummy book names
    strcpy(books[0], "Book 1");
    strcpy(books[1], "Book 2");
    strcpy(books[2], "Book 3");
    numBooks = 3;
    
    do {
        printf("\nLibrary Management System\n");
        printf("1. Show available books\n");
        printf("2. Issue a book\n");
        printf("3. Return a book\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showAvailableBooks();
                break;
            case 2:
                issueBook();
                break;
            case 3:
                returnBook();
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void showAvailableBooks() {
    printf("\nAvailable Books:\n");
    if (numBooks == 0) {
        printf("No books available.\n");
    } else {
        for (int i = 0; i < numBooks; i++) {
            printf("%d. %s\n", i + 1, books[i]);
        }
    }
}

void issueBook() {
    showAvailableBooks();
    if (numBooks == 0) {
        printf("No books available to issue.\n");
        return;
    }

    int bookIndex;
    printf("Enter the book number you want to issue: ");
    scanf("%d", &bookIndex);

    if (bookIndex < 1 || bookIndex > numBooks) {
        printf("Invalid book number. Please try again.\n");
        return;
    }

    printf("You have issued the book: %s\n", books[bookIndex - 1]);

    // Remove the issued book from the list
    for (int i = bookIndex - 1; i < numBooks - 1; i++) {
        strcpy(books[i], books[i + 1]);
    }
    numBooks--;

    showAvailableBooks();
}

void returnBook() {
    char bookName[MAX_BOOK_NAME_LENGTH];
    printf("Enter the name of the book you want to return: ");
    getchar(); // Clear the input buffer before reading the book name
    fgets(bookName, MAX_BOOK_NAME_LENGTH, stdin);

    // Remove the trailing newline character from the book name
    bookName[strcspn(bookName, "\n")] = '\0';

    if (numBooks == MAX_BOOKS) {
        printf("The library is already full. Cannot accept more books.\n");
        return;
    }

    strcpy(books[numBooks], bookName);
    numBooks++;

    printf("You have returned the book: %s\n", bookName);
    showAvailableBooks();
}
