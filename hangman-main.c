#include <stdio.h>
#include <string.h>

#define ATT_NUM 20

// global variables
char secret_word[ATT_NUM];
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

void select_word() {
    sprintf(secret_word, "MELANCIA");
}

int main() {

    int won = 0;
    int hanged = 0;

    select_word();
    opening();

    do {

        draw_hang_design();
        tryfin_word();

    } while (!won && !hanged);
}