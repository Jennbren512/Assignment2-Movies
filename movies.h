#ifndef MOVIES_H
#define MOVIES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LANGUAGES 5
#define MAX_LANGUAGE_LENGTH 20

// Struct to store movie details
typedef struct movie {
    char *title;
    int year;
    char languages[MAX_LANGUAGES][MAX_LANGUAGE_LENGTH];
    int language_count;
    float rating;
    struct movie *next;
} movie;

// Function prototypes
movie* read_movies_from_file(const char *filename);
void display_movies_by_year(movie *head, int year);
void display_highest_rated_movies(movie *head);
void display_movies_by_language(movie *head, const char *language);
void free_movie_list(movie *head);

#endif
