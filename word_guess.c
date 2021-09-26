// Word Guess (Hangman)
// word_guess.c
//
// This program was written by Pollapat Timratana (z5331004)
// on 27/09/2021
//
// 6 character hangman where take input (lowercase character) each turn to find the word. There are only ten words in the set. Can add more using rand().

#include <stdio.h>
#include <stdlib.h>

#define WORDSET 10

struct character_word {
    char one;
    char two;
    char three;
    char four;
    char five;
    char six;
};

struct character_keep {
    char one;
    char two;
    char three;
    char four;
    char five;
    char six;

};

struct wrong_character {
    char one;
    char two;
    char three;
    char four;
    char five;
    char six;
    char seven;
};

int main (void) {

    int life;
    int again = 1;
    struct character_word word;
    struct character_keep keep;
    struct wrong_character wrong;
    char guess;
    int score = 0;
    char input_again;

    while (again == 1) {

        int random_number = rand() % (WORDSET);
        
        if (random_number == 0) {
            word.one    = 'a';
            word.two    = 'c';
            word.three  = 't';
            word.four   = 'i';
            word.five   = 'o';
            word.six    = 'n';
        }
        else if (random_number == 1) {
            word.one    = 'e';
            word.two    = 'n';
            word.three  = 'e';
            word.four   = 'r';
            word.five   = 'g';
            word.six    = 'y';
        }
        else if (random_number == 2) {
            word.one    = 'c';
            word.two    = 'o';
            word.three  = 'd';
            word.four   = 'i';
            word.five   = 'n';
            word.six    = 'g';
        }
        else if (random_number == 3) {
            word.one    = 'o';
            word.two    = 'n';
            word.three  = 'l';
            word.four   = 'i';
            word.five   = 'n';
            word.six    = 'e';
        }
        else if (random_number == 4) {
            word.one    = 'n';
            word.two    = 'u';
            word.three  = 'm';
            word.four   = 'b';
            word.five   = 'e';
            word.six    = 'r';
        }
        else if (random_number == 5) {
            word.one    = 'r';
            word.two    = 'e';
            word.three  = 'p';
            word.four   = 'e';
            word.five   = 'a';
            word.six    = 't';
        }
        else if (random_number == 6) {
            word.one    = 's';
            word.two    = 'e';
            word.three  = 'r';
            word.four   = 'v';
            word.five   = 'e';
            word.six    = 'r';
        }
        else if (random_number == 7) {
            word.one    = 'u';
            word.two    = 'p';
            word.three  = 'd';
            word.four   = 'a';
            word.five   = 't';
            word.six    = 'e';
        }
        else if (random_number == 8) {
            word.one    = 's';
            word.two    = 'y';
            word.three  = 's';
            word.four   = 't';
            word.five   = 'e';
            word.six    = 'm';
        }
        else if (random_number == 9) {
            word.one    = 'r';
            word.two    = 'e';
            word.three  = 't';
            word.four   = 'u';
            word.five   = 'r';
            word.six    = 'n';
        }

        keep.one = '_';
        keep.two = '_';
        keep.three = '_';
        keep.four = '_';
        keep.five = '_';
        keep.six = '_';

        wrong.one = 0;
        wrong.two = 0;
        wrong.three = 0;
        wrong.four = 0;
        wrong.five = 0;
        wrong.six = 0;
        wrong.seven = 0;

        life = 7;
        score = 0;

        while (life > 0 && score < 6) {
           
            
            
            printf("\n");
            printf("%c%c%c%c%c%c\tHP: %d\t", keep.one, keep.two, keep.three, keep.four, keep.five, keep.six, life);
            printf("Enter a character: ");
            scanf(" %c", &guess);


            if ((guess == word.one) || (guess == word.two) || (guess == word.three) || (guess == word.four) || (guess == word.five) || (guess == word.six)) {
                // first character
                if (guess == word.one){
                    if (keep.one != guess) {
                        keep.one = guess;
                        score ++;
                    }
                }
                // second character
                if (guess == word.two){
                    if (keep.two != guess) {
                        keep.two = guess;
                        score ++;
                    }
                }
                // second character
                if (guess == word.three){
                    if (keep.three != guess) {
                        keep.three = guess;
                        score ++;
                    }
                }
                // second character
                if (guess == word.four){
                    if (keep.four != guess) {
                        keep.four = guess;
                        score ++;
                    }
                }
                // second character
                if (guess == word.five){
                    if (keep.five != guess) {
                        keep.five = guess;
                        score ++;
                    }
                }
                // second character
                if (guess == word.six){
                    if (keep.six != guess) {
                        keep.six = guess;
                        score ++;
                    }
                }

            }
            else {
                printf("\n");
                
                
                if (life == 7) {
                    wrong.one = guess;
                    life --;
                }
                else if (life == 6) {
                    if(guess != wrong.one) {
                        wrong.two = guess;
                        life --;
                    }
                }
                else if (life == 5) {
                    if((guess != wrong.one) && (guess != wrong.two)) {
                        wrong.three = guess;
                        life --;
                    }
                }
                else if (life == 4) {
                    if((guess != wrong.one) && (guess != wrong.two) && (guess != wrong.three)) {
                    wrong.four = guess;
                    life --;
                    }
                }
                else if (life == 3) {
                     if((guess != wrong.one) && (guess!= wrong.two) && (guess != wrong.three) && (guess != wrong.four)) {
                    wrong.five = guess;
                    life --;
                     }
                }
                else if (life == 2) {
                     if((guess != wrong.one) && (guess!= wrong.two) && (guess != wrong.three) && (guess != wrong.four) && (guess != wrong.five)) {
                    wrong.six = guess;
                    life --;
                     }
                }
                else if (life == 1) {
                     if((guess != wrong.one) && (guess!= wrong.two) && (guess != wrong.three) && (guess != wrong.four) && (guess != wrong.five) && (guess != wrong.six)) {
                    wrong.seven = guess;
                    life --;
                     }
                }
                printf("Wrong Character! There are no: %c %c %c %c %c %c %c\n", wrong.one, wrong.two, wrong.three, wrong.four, wrong.five, wrong.six, wrong.seven);
                
            }
                        
        }
        if (life == 0 ) {
            printf("\n");
            printf("\033[0;31mYou lose!\t Answer is");
            printf("  %c%c%c%c%c%c\033[0m\n", word.one, word.two, word.three, word.four, word.five, word.six);
            printf("\n");
        }

        if (score == 6){
            printf("\n");
            printf("\033[0;32m%c%c%c%c%c%c\t", keep.one, keep.two, keep.three, keep.four, keep.five, keep.six);
            printf("You win!!!\033[0m\n");
            printf("\n");
        }
        printf("Enter 'y ' to play again. Enter anything else to exit:  ");
        scanf(" %c", &input_again);
        if (input_again != 'y') {
            again = 0;
        }
    }
    return 0;
}