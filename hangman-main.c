#include <stdio.h>
#include <string.h>


int main() {

    int number_of_letters;

    printf("Insert the number of letters in your word\n");
    scanf("%d", &number_of_letters);
    printf("-------------------------\n");

    char secret_word[number_of_letters];

    sprintf(secret_word, "melancia");

    int won = 0;
    int hanged = 0; 

    do {
        // printf("%c", scanf("%c", &attempt));

        for (int idx = 0; idx < strlen(secret_word); idx++) {
            printf("_ ");
        }

        printf("\n");

        char attempt;
        scanf(" %c", &attempt);

    } while (!won && !hanged);
}