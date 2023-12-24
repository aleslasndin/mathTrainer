#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED "\e[3;31m" //for title
#define SCRED "\e[0;31m" //for score, and answers
#define SCGREEN "\e[0;32m" //for score
#define ADD "\e[1;31m" //red
#define SUB "\e[1;34m" //blue
#define MUL "\e[1;32m" //green
#define DIV "\e[1;35m" //violet
#define BOLD "\033[1m" //for menu choices
#define RESET "\033[0m"
//colors reference: https://gist.github.com/iamnewton/8754917

void additionRandomizer();
void subtractionRandomizer();
void multiplicationRandomizer();
void divisionRandomizer();

int i, ind, num1, num2, correctAnswer, choice, userAnswer, score = 0;
int *correctAnswers, *userAnswers;

int errorChoiceInput(){
   printf("\nThat's an invalid choice. Please choose from the menu above ["BOLD"1"RESET" to "BOLD"5"RESET"].\n", choice);
}

int problemErrorHandling(){
    //error handling for inputting number of problems
    //*use pointers? later
    if (scanf("%d", &ind) != 1 ) {
        //if not a number
        printf("\nThat is not a number! Enter a number from 1 to 20.\n");
        return 0;
    }
    else if (ind < 1) {
        //if less than 1
        printf("\nYou need to answer at least 1 problem!\n");
        return 0;
    }
    else if (ind > 20){
        //if greater than 20
        printf("\n%d problems are too many! Just answer another set of problems later if you want to practice more.\n", ind);
            //21 is too many compared to 20?? nevermind
        return 0;
    }
    return 1;
}

int main() {
    system("cls");
    score = 0;
    printf(RED "MATH TUTOR V 2.0");
    printf(RESET "\n\n-----MENU-----\n\n");
    printf("Press [" BOLD "1" RESET "] for "ADD"Addition\n"RESET);
    printf("Press [" BOLD "2" RESET "] for "SUB"Subtraction\n"RESET);
    printf("Press [" BOLD "3" RESET "] for "MUL"Multiplication\n"RESET);
    printf("Press [" BOLD "4" RESET "] for "DIV"Division\n"RESET);
    printf("Press [" BOLD "5" RESET "] to "BOLD"Exit "RESET""RED"MATH TUTOR V 2.0\n"RESET);

    while (1) {
        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 5) {
            errorChoiceInput();
            while (getchar() != '\n');
            continue;
        }
        break;
    }

    switch (choice) {
        case 1: additionRandomizer();
            break;
        case 2: subtractionRandomizer();
            break;
        case 3: multiplicationRandomizer();
            break;
        case 4: divisionRandomizer();
            break;
        case 5:{
            printf(BOLD"\nExiting . . ."RESET"\n\nCome back anytime! Remember that practice makes perfect :)\n\n");
            system("pause");
        }
    }
    
    free(correctAnswers);
    return 0;
}

void additionRandomizer() {
    srand(time(NULL));
    
    printf("\nHow many "ADD"Addition"RESET" problems would you like to answer? [up to 20 only]: ");
    while(!problemErrorHandling()) {
        while (getchar() != '\n');
        printf("\nHow many "ADD"Addition"RESET" problems would you like to answer? [up to 20 only]: ");
    }

    printf("\n");

    correctAnswers = (int *)malloc(ind * sizeof(int));
    userAnswers = (int *)malloc(ind * sizeof(int));
    for(i = 1; i <= ind; i++){
        num1 = rand()%100;
        num2 = rand()%100;
        correctAnswer = num1 + num2;
        correctAnswers[i - 1] = correctAnswer;
        printf("Problem (%d): %d + %d = ", i, num1, num2);
        scanf("%d", &userAnswer);

        userAnswers[i - 1] = userAnswer;
        if(correctAnswer == userAnswer){
            score += 1;
        }
    }

    printf("\nYour total score is "BOLD"%d/%d\n"RESET, score, ind);

    printf(BOLD"\nCorrect Answers: "RESET);
    for (i = 0; i < ind; i++) {
        if (userAnswers[i]==correctAnswers[i]){
            printf("\nProblem (%d): "SCGREEN"%d"RESET, i + 1, correctAnswers[i]);
        }
        else {
            printf("\nProblem (%d): "SCRED"%d"RESET, i + 1, correctAnswers[i]);
        }
    }
    printf("\n\n");
    system("pause");
    main();
}

void subtractionRandomizer() {
    srand(time(NULL));

 	printf("\nHow many "SUB"Subtraction"RESET" problems would you like to answer? [up to 20 only]: ");
    while(!problemErrorHandling()) {
        while (getchar() != '\n');
        printf("\nHow many "SUB"Subtraction"RESET" problems would you like to answer? [up to 20 only]: ");
    }

    printf("\n");

    correctAnswers = (int *)malloc(ind * sizeof(int));
    userAnswers = (int *)malloc(ind * sizeof(int));
    for(i = 1; i <= ind; i++){
		num1 = 1 + rand() % 100;
        num2 = rand() % num1;
        correctAnswer = num1 - num2;
        correctAnswers[i - 1] = correctAnswer;
        printf("Problem (%d): %d - %d = ", i, num1, num2);
        scanf("%d", &userAnswer);

        userAnswers[i - 1] = userAnswer;
        if(correctAnswer == userAnswer){
            score += 1;
        }
    }

    printf("\nYour total score is "BOLD"%d/%d\n"RESET, score, ind);

    printf(BOLD"\nCorrect Answers: "RESET);
    for (i = 0; i < ind; i++) {
        if (userAnswers[i]==correctAnswers[i]){
            printf("\nProblem (%d): "SCGREEN"%d"RESET, i + 1, correctAnswers[i]);
        }
        else {
            printf("\nProblem (%d): "SCRED"%d"RESET, i + 1, correctAnswers[i]);
        }
    }
    printf("\n\n");
    system("pause");
    main();
}

void multiplicationRandomizer() {
    srand(time(NULL));

	printf("\nHow many "MUL"Multiplication"RESET" problems would you like to answer [up to 20 only]: ");
    while(!problemErrorHandling()) {
        while (getchar() != '\n');
        printf("\nHow many "MUL"Multiplication"RESET" problems would you like to answer [up to 20 only]: ");
    }

    printf("\n");
    
    correctAnswers = (int *)malloc(ind * sizeof(int));
    userAnswers = (int *)malloc(ind * sizeof(int));
    for(i = 1; i <= ind; i++){
		num1 = 1 + rand() % 10;
        num2 = 1 + rand() % (200 / num1);
        correctAnswer = num1 * num2;
        correctAnswers[i - 1] = correctAnswer;
        printf("Problem (%d): %d x %d = ", i, num1, num2);
        scanf("%d", &userAnswer);

        userAnswers[i - 1] = userAnswer;
        if(correctAnswer == userAnswer){
            score += 1;
        }
    }

    printf("\nYour total score is "BOLD"%d/%d\n"RESET, score, ind);

    printf(BOLD"\nCorrect Answers: "RESET);
    for (i = 0; i < ind; i++) {
        if (userAnswers[i]==correctAnswers[i]){
            printf("\nProblem (%d): "SCGREEN"%d"RESET, i + 1, correctAnswers[i]);
        }
        else {
            printf("\nProblem (%d): "SCRED"%d"RESET, i + 1, correctAnswers[i]);
        }
    }
    printf("\n\n");
    system("pause");
    main();
}

void divisionRandomizer() {
    srand(time(NULL));

  	printf("\nHow many "DIV"Division"RESET" problems would you like to answer [up to 20 only]: ");
    while(!problemErrorHandling()) {
        while (getchar() != '\n');
      	printf("\nHow many "DIV"division"RESET" problems would you like to answer [up to 20 only]: ");
    }

    printf("\n");
    
    correctAnswers = (int *)malloc(ind * sizeof(int));
    userAnswers = (int *)malloc(ind * sizeof(int));
    for(i = 1; i <= ind; i++){
		num2 = 1 + rand() % 10;
        num1 = num2 * (1 + rand() % 10);
        correctAnswer = num1 / num2;
        correctAnswers[i - 1] = correctAnswer;
        printf("Problem (%d): %d / %d = ", i, num1, num2);
        scanf("%d", &userAnswer);

        userAnswers[i - 1] = userAnswer;
        if(correctAnswer == userAnswer){
            score += 1;
        }
    }

    printf("\nYour total score is "BOLD"%d/%d\n"RESET, score, ind);

    printf(BOLD"\nCorrect Answers: "RESET);
    for (i = 0; i < ind; i++) {
        if (userAnswers[i]==correctAnswers[i]){
            printf("\nProblem (%d): "SCGREEN"%d"RESET, i + 1, correctAnswers[i]);
        }
        else {
            printf("\nProblem (%d): "SCRED"%d"RESET, i + 1, correctAnswers[i]);
        }
    }
    printf("\n\n");
    system("pause");
    main();
}