#include <stdio.h>
#include <string.h>

void opening() {
    printf("*********************\n");
    printf("*   Jogo de Forca   *\n");
    printf("*********************\n\n");
}

void tryfin_word(char kicks[26], int* attempts) {
    
    char attempt;
    printf("Qual a letra ?\n");
    scanf(" %c", &attempt);

    kicks[(*attempts)] = attempt;
    (*attempts)++;
}

int return_found(char letter, char kicks[26], int attempts) {
    int found = 0;
    
    for (int jidx = 0; jidx < attempts; jidx++) {
        if (kicks[jidx] == letter) {
            found = 1;
            break;
        }
    }

    return found;
}

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

    opening();

    do {

        for (int idx = 0; idx < strlen(secret_word); idx++) {
            
            int found = return_found(secret_word[idx], kicks, attempts);

            if (found) {
                printf("%c ", secret_word[idx]);
            } else {
                printf("_ ");
            }
        }

        printf("\n");

        tryfin_word(kicks, &attempts);


    } while (!won && !hanged);
}