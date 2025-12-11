#include <stdio.h>

struct Book {
    char title[50];
    char author[50];
    char isbn[20];
    char genre[20];
    float price;
    int year;
    int available; // 1 = available, 0 = borrowed
};

void printBook(struct Book b) {
    printf("Title       : %s\n", b.title);
    printf("Author      : %s\n", b.author);
    printf("ISBN        : %s\n", b.isbn);
    printf("Genre       : %s\n", b.genre);
    printf("Price       : %.2f\n", b.price);
    printf("Year        : %d\n", b.year);
    printf("Availability: %s\n", b.available ? "Available" : "Borrowed");
}

int countAvailable(struct Book books[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (books[i].available == 1)
            count++;
    }
    return count;
}

float averagePrice(struct Book books[], int n) {
    float sum = 0.0f;
    for (int i = 0; i < n; i++)
        sum += books[i].price;

    return (n == 0) ? 0 : sum / n;
}

int indexOfNewest(struct Book books[], int n) {
    if (n == 0) return -1;

    int newestIndex = 0;
    for (int i = 1; i < n; i++) {
        if (books[i].year > books[newestIndex].year)
            newestIndex = i;
    }
    return newestIndex;
}

int main(void) {
    int n;

    printf("Enter number of books: ");
    scanf("%d", &n);

    struct Book books[n];

    printf("\n--- Enter Book Details ---\n");

    for (int i = 0; i < n; i++) {
        printf("\nBook %d:\n", i + 1);

        printf("Enter Title: ");
        scanf(" %[^\n]", books[i].title);   // reads full string with spaces

        printf("Enter Author: ");
        scanf(" %[^\n]", books[i].author);

        printf("Enter ISBN: ");
        scanf(" %s", books[i].isbn);

        printf("Enter Genre: ");
        scanf(" %[^\n]", books[i].genre);

        printf("Enter Price: ");
        scanf("%f", &books[i].price);

        printf("Enter Publication Year: ");
        scanf("%d", &books[i].year);

        printf("Enter Availability (1 = available, 0 = borrowed): ");
        scanf("%d", &books[i].available);
    }

    printf("\n=== List of Books ===\n\n");
    for (int i = 0; i < n; i++) {
        printf("Book %d:\n", i + 1);
        printBook(books[i]);
        printf("\n");
    }

    int availableCount = countAvailable(books, n);
    float avgPrice = averagePrice(books, n);
    int newestIndex = indexOfNewest(books, n);

    printf("Total books     : %d\n", n);
    printf("Available books : %d\n", availableCount);
    printf("Average price   : %.2f\n", avgPrice);

    if (newestIndex != -1) {
        printf("\n=== Newest Book ===\n");
        printBook(books[newestIndex]);
    }

    return 0;
}