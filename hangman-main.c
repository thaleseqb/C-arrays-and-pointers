#include <stdio.h>



int main() {

    int number_of_letters;

    printf("Insert the number of letters in your word\n");
    scanf("%d", &number_of_letters);
    printf("-------------------------\n");

    char secret_word[number_of_letters];
    
    sprintf(secret_word, "melancia");

    int won = 0;
    int hanged = 1; 

    do {

        char attempt;
        scanf("%c", &attempt);



    } while (!won && !hanged);
     

}