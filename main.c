#include "movies.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    movie *head = read_movies_from_file(argv[1]);

    while (1) {
        printf("\n1. Show movies released in the specified year\n");
        printf("2. Show highest rated movie for each year\n");
        printf("3. Show the title and year of release of all movies in a specific language\n");
        printf("4. Exit from the program\n");
        printf("\nEnter a choice from 1 to 4: ");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            int year;
            printf("Enter the year for which you want to see movies: ");
            scanf("%d", &year);
            display_movies_by_year(head, year);
        } else if (choice == 2) {
            display_highest_rated_movies(head);
        } else if (choice == 3) {
            char language[MAX_LANGUAGE_LENGTH];
            printf("Enter the language for which you want to see movies: ");
            scanf("%s", language);
            display_movies_by_language(head, language);
        } else if (choice == 4) {
            break;
        } else {
            printf("You entered an incorrect choice. Try again.\n");
        }
    }

    free_movie_list(head);
    return 0;
}
