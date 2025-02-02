#include "movies.h"

// Show movies released in a specified year
void display_movies_by_year(Movie *head, int year) {
    int found = 0;
    while (head) {
        if (head->year == year) {
            printf("%s\n", head->title);
            found = 1;
        }
        head = head->next;
    }
    if (!found) {
        printf("No data about movies released in the year %d\n", year);
    }
}

// Show highest-rated movie for each year
void display_highest_rated_movies(Movie *head) {
    Movie *highest[2022] = {NULL};

    while (head) {
        if (!highest[head->year] || head->rating > highest[head->year]->rating) {
            highest[head->year] = head;
        }
        head = head->next;
    }

    for (int i = 1900; i <= 2021; i++) {
        if (highest[i]) {
            printf("%d %.1f %s\n", i, highest[i]->rating, highest[i]->title);
        }
    }
}

// Show movies in a specific language
void display_movies_by_language(Movie *head, const char *language) {
    int found = 0;
    while (head) {
        for (int i = 0; i < head->language_count; i++) {
            if (strcmp(head->languages[i], language) == 0) {
                printf("%d %s\n", head->year, head->title);
                found = 1;
            }
        }
        head = head->next;
    }
    if (!found) {
        printf("No data about movies released in %s\n", language);
    }
}
