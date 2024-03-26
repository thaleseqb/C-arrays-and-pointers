#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "header.h"

// global variables
char secret_word[WORD_LENGTH];
char kicks[26];
int attempts = 0;

void opening() {
    printf("*********************\n");
    printf("*   Jogo de Forca   *\n");
    printf("*********************\n\n");
}

void tryfin_word() {
    
    char attempt;
    printf("Qual a letra ?\n");
    scanf(" %c", &attempt);

    kicks[attempts] = attempt;
    attempts++;
}

int return_found(char letter) {
    int found = 0;
    
    for (int jidx = 0; jidx < attempts; jidx++) {
        if (kicks[jidx] == letter) {
            found = 1;
            break;
        }
    }

    return found;
}

void draw_hang_design() {
    for (int idx = 0; idx < strlen(secret_word); idx++) {
        
        int found = return_found(secret_word[idx]);

        if (found) {
            printf("%c ", secret_word[idx]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void add_word() {
    
    char want;
    printf("Do you want to add a new word on the database? (S/N)");
    scanf(" %c", &want);

    if (want == 'S') {

        char new_word[WORD_LENGTH];
        printf("Which is the new word ?\n");
        scanf("%s", new_word);

        FILE* file;
        file = fopen("data_base.txt", "r+");

        if (file == 0) {
            printf("database not available");
            exit(1);    
        }

        int qtt;
        fscanf(file, "%d", &qtt);
        qtt++;

        fseek(file, 0, SEEK_SET);
        fprintf(file, "%d", qtt);

        fseek(file, 0, SEEK_END);
        fprintf(file, "\n%s", new_word);

        fclose(file);
    }
}

void select_word() {
    FILE* file;

    file = fopen("data_base.txt", "r");

    if (file == 0) {
        printf("database not available");
        exit(1);
    }

    int word_number;
    fscanf(file, "%d", &word_number);
    srand(time(0));
    int random_number = rand() % word_number;

    for (int idx = 0; idx <= random_number; idx++) {
        fscanf(file, "%s", secret_word);
    }

    fclose(file);


}

int won() {
    for (int idx=0; idx < strlen(secret_word); idx++) {
        if (!return_found(secret_word[idx])) {
            return 0;
        }
    }

    return 1;
}

int get_hanged() {
    int errors = 0;

    for (int idx = 0; idx < attempts; idx++) {
        int exists = 0;

        for (int j = 0; j < strlen(secret_word); j++) {
            if (kicks[idx] == secret_word[j]) {
                exists = 1;
                break;
            }
        }
            if (!exists) {
                errors++;
            }
    }
    return errors >= 5;
}

int main() {

    select_word();
    opening();

    do {

        draw_hang_design();
        tryfin_word();

    } while (!won() && !get_hanged());

    add_word();

    if (won()) {
        printf("Congrats you won the hangman's game\n");
    } else {
        printf("Sorry, you loose, more luck for you next time\n");
    }
}