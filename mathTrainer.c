#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h> //for sleep function; Sleep - with capital S

#define TAB "    "
#define TITLE "\e[3;32m" //italic green for title
#define SCRED "\e[0;31m" //red for score and answers
#define SCGREEN "\e[0;32m" //green for score
#define ADD "\e[1;31m" //red
#define SUB "\e[1;34m" //blue
#define MUL "\e[1;38;5;208m" //orange
#define DIV "\e[1;35m" //violet
#define BOLD "\e[1m" //for menu choices
#define RESET "\e[0m"
//colors reference: https://gist.github.com/iamnewton/8754917

void additionRandomizer();
void subtractionRandomizer();
void multiplicationRandomizer();
void divisionRandomizer();

int i, ind, num1, num2, correctAnswer, choice, userAnswer, score = 0;
int *correctAnswers, *userAnswers;

void printMenu(){
    system("cls");
    score = 0;
    printf(TITLE"MATH TRAINER");
    printf(RESET "\n\n----- MENU -----\n\n");
    printf("Press ["BOLD"1"RESET "] for "ADD"Addition\n"RESET);
    printf("Press ["BOLD"2"RESET "] for "SUB"Subtraction\n"RESET);
    printf("Press ["BOLD"3"RESET "] for "MUL"Multiplication\n"RESET);
    printf("Press ["BOLD"4"RESET "] for "DIV"Division\n"RESET);
    printf("Press ["BOLD"5"RESET "] to "BOLD"Exit "RESET""TITLE"MATH TRAINER\n"RESET);
}

void errorChoiceInput(){
   printf("\nThat's an invalid choice. Please choose from the menu above ["BOLD"1"RESET" to "BOLD"5"RESET"].\n", choice);
}

int problemErrorHandling(){
    if(scanf("%d", &ind) != 1 ){
        printf("\nThat is not a number! Enter a number from 1 to 20.\n");
        return 0;
    }
    else if(ind < 1){
        printf("\nYou need to answer at least 1 problem!\n");
        return 0;
    }
    else if(ind > 20){
        printf("\n%d problems are too many! Just answer another set of problems later if you want to practice more.\n", ind);
            //21 is too many compared to 20?? nevermind
        return 0;
    }
    return 1;
}

void loadingEllipsis(){
    for(i = 0; i < 3; i++){
        printf(" .");
        Sleep(500);
    }
}

void exitProgram(){
    printf(BOLD"\nExiting "RESET TITLE"MATH TRAINER\n"RESET);
    printf("\nPress any key to continue . . . ");
    getch();
    printf("\33[2K\r");
    printf("Come back anytime! Remember that practice makes perfect :)");
}

int main(){
    printMenu();

    while (1){
        printf("\nEnter your choice: ");
        if(scanf("%d", &choice) != 1 || choice < 1 || choice > 5){
            errorChoiceInput();
            while (getchar() != '\n');
            continue;
        }
        break;
    }

    switch (choice){
        case 1: additionRandomizer();
            break;
        case 2: subtractionRandomizer();
            break;
        case 3: multiplicationRandomizer();
            break;
        case 4: divisionRandomizer();
            break;
        case 5: exitProgram();   
    }
    
    free(correctAnswers);
    return 0;
}

void printScoreAndAnswers(){
    printf("\nYour total score is "BOLD"%d/%d\n", score, ind);

    printf("\nCorrect Answers:\n"RESET);

    for(i = 0; i < ind; i++){
        if(userAnswers[i]==correctAnswers[i]){
            printf("\n"TAB"Problem (%d): "SCGREEN"%d"RESET, i + 1, correctAnswers[i]);
        }
        else{
            printf("\n"TAB"Problem (%d): "SCRED"%d"RESET, i + 1, correctAnswers[i]);
        }
    }

    printf("\n\n");
    system("pause");
    main();
}

void additionRandomizer(){
    printMenu();

    srand(time(NULL));
    printf("\nHow many "ADD"Addition"RESET" problems would you like to answer? [up to 20 only]: ");
    while(!problemErrorHandling()){
        while (getchar() != '\n');
        printf("\nHow many "ADD"Addition"RESET" problems would you like to answer? [up to 20 only]: ");
    }

    system("cls");
    printf("Loading ("BOLD"%d"RESET") "ADD"Addition"RESET" Problems", ind);
    loadingEllipsis();
    printf("\n\n");

    correctAnswers = (int *)malloc(ind * sizeof(int));
    userAnswers = (int *)malloc(ind * sizeof(int));

    for(i = 1; i <= ind; i++){
        num1 = rand()%100;
        num2 = rand()%100;
        correctAnswer = num1 + num2;
        correctAnswers[i - 1] = correctAnswer;
        printf(TAB"Problem (%d): %d + %d = ", i, num1, num2);
        scanf("%d", &userAnswer);

        userAnswers[i - 1] = userAnswer;
        if(correctAnswer == userAnswer){
            score += 1;
        }
    }

    printScoreAndAnswers();
}

void subtractionRandomizer(){
    printMenu();

    srand(time(NULL));
 	printf("\nHow many "SUB"Subtraction"RESET" problems would you like to answer? [up to 20 only]: ");
    while(!problemErrorHandling()){
        while (getchar() != '\n');
        printf("\nHow many "SUB"Subtraction"RESET" problems would you like to answer? [up to 20 only]: ");
    }

    system("cls");
    printf("Loading ("BOLD"%d"RESET") "SUB"Subtraction"RESET" Problems", ind);
    loadingEllipsis();
    printf("\n\n");

    correctAnswers = (int *)malloc(ind * sizeof(int));
    userAnswers = (int *)malloc(ind * sizeof(int));

    for(i = 1; i <= ind; i++){
		num1 = 1 + rand() % 100;
        num2 = rand() % num1;
        correctAnswer = num1 - num2;
        correctAnswers[i - 1] = correctAnswer;
        printf(TAB"Problem (%d): %d - %d = ", i, num1, num2);
        scanf("%d", &userAnswer);

        userAnswers[i - 1] = userAnswer;
        if(correctAnswer == userAnswer){
            score += 1;
        }
    }

    printScoreAndAnswers();
}

void multiplicationRandomizer(){
    printMenu();

    srand(time(NULL));
	printf("\nHow many "MUL"Multiplication"RESET" problems would you like to answer [up to 20 only]: ");
    while(!problemErrorHandling()){
        while (getchar() != '\n');
        printf("\nHow many "MUL"Multiplication"RESET" problems would you like to answer [up to 20 only]: ");
    }

    system("cls");
    printf("Loading ("BOLD"%d"RESET") "MUL"Multiplication"RESET" Problems", ind);
    loadingEllipsis();
    printf("\n\n");
    
    correctAnswers = (int *)malloc(ind * sizeof(int));
    userAnswers = (int *)malloc(ind * sizeof(int));
    for(i = 1; i <= ind; i++){
		num1 = 1 + rand() % 10;
        num2 = 1 + rand() % (200 / num1);
        correctAnswer = num1 * num2;
        correctAnswers[i - 1] = correctAnswer;
        printf(TAB"Problem (%d): %d x %d = ", i, num1, num2);
        scanf("%d", &userAnswer);

        userAnswers[i - 1] = userAnswer;
        if(correctAnswer == userAnswer){
            score += 1;
        }
    }

    printScoreAndAnswers();
}

void divisionRandomizer(){
    printMenu();

    srand(time(NULL));
  	printf("\nHow many "DIV"Division"RESET" problems would you like to answer [up to 20 only]: ");
    while(!problemErrorHandling()){
        while (getchar() != '\n');
      	printf("\nHow many "DIV"Division"RESET" problems would you like to answer [up to 20 only]: ");
    }

    system("cls");
    printf("Loading ("BOLD"%d"RESET") "DIV"Division"RESET" Problems", ind);
    loadingEllipsis();
    printf("\n\n");
    
    correctAnswers = (int *)malloc(ind * sizeof(int));
    userAnswers = (int *)malloc(ind * sizeof(int));
    for(i = 1; i <= ind; i++){
		num2 = 1 + rand() % 10;
        num1 = num2 * (1 + rand() % 10);
        correctAnswer = num1 / num2;
        correctAnswers[i - 1] = correctAnswer;
        printf(TAB"Problem (%d): %d / %d = ", i, num1, num2);
        scanf("%d", &userAnswer);

        userAnswers[i - 1] = userAnswer;
        if(correctAnswer == userAnswer){
            score += 1;
        }
    }

    printScoreAndAnswers();
}