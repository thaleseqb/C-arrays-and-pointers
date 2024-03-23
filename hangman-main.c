#include <stdio.h>
#include <string.h>

int main() {

    int attempt_number;

    printf("Insert the number of attempts\n");
    scanf("%d", &attempt_number);
    printf("----------------------\n");

    char secret_word[attempt_number];
    sprintf(secret_word, "MELANCIA");

    int won = 0;
    int hanged = 0;

    char kicks[26];
    int attempts = 0;

    do {

        for (int idx = 0; idx < strlen(secret_word); idx++) {

            int found = 0;
            
            for (int jidx = 0; jidx < attempts; jidx++) {
                if (kicks[jidx] == secret_word[idx]) {
                    found = 1;
                    break;
                }
            }

                if (found) {
                    printf("%c ", secret_word[idx]);
                } else {
                    printf("_ ");
                }
        }

        printf("\n");

        char attempt;
        printf("Qual a letra ?\n");
        scanf(" %c", &attempt);

        kicks[attempts] = attempt;
        attempts++;

    } while (!won && !hanged);
}