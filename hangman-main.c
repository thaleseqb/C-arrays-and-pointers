#include <stdio.h>
#include <string.h>

#define ATT_NUM 20
#define PICKED_SW "MELANCIA"

// global variables
char secret_word[ATT_NUM];
char kicks[ATT_NUM];
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
    sprintf(secret_word, PICKED_SW);
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
}