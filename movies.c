#include "movies.h"

// Read movie data from CSV file
movie* read_movies_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    char buffer[512];
    fgets(buffer, sizeof(buffer), file); // Skip header line

    movie *head = NULL, *tail = NULL;
    int count = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        movie *new_movie = malloc(sizeof(movie));
        if (!new_movie) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        new_movie->next = NULL;

        char title[256], languages[128];
        int year;
        float rating;

        // Use sscanf to correctly extract fields
        int parsed = sscanf(buffer, " %255[^,],%d,%127[^,],%f", title, &year, languages, &rating);

        if (parsed < 4) {  // Ensure all fields are present
            fprintf(stderr, "Error: Incorrect CSV format or missing data in line: %s\n", buffer);
            free(new_movie);
            continue;
        }

        new_movie->title = strdup(title);
        new_movie->year = year;
        new_movie->rating = rating;

        // Parse languages manually
        new_movie->language_count = 0;
        char *lang_token = strtok(languages + 1, ";]"); // Skip opening bracket `[`
        while (lang_token && new_movie->language_count < MAX_LANGUAGES) {
            strncpy(new_movie->languages[new_movie->language_count], lang_token, MAX_LANGUAGE_LENGTH - 1);
            new_movie->languages[new_movie->language_count][MAX_LANGUAGE_LENGTH - 1] = '\0';
            new_movie->language_count++;
            lang_token = strtok(NULL, ";]");
        }

        // Append to linked list
        if (!head) {
            head = new_movie;
        } else {
            tail->next = new_movie;
        }
        tail = new_movie;
        count++;
    }

    fclose(file);
    printf("Processed file %s and parsed data for %d movies\n", filename, count);
    return head;
}

// Free linked list memory
void free_movie_list(movie *head) {
    while (head) {
        movie *temp = head;
        head = head->next;
        free(temp->title);
        free(temp);
    }
}
