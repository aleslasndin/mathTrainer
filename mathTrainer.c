#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h> // for sleep function; Sleep - with capital S!
#include <math.h>

#define TAB "    "
#define TITLE "\e[3;32m" // italic green for title
#define SCRED "\e[0;31m" // red for score and answers
#define SCGREEN "\e[0;32m" // green for score
#define BOLD "\e[1m" // for menu choices
#define RESET "\e[0m"

// colors for opperation names
#define ADDCOLOR "\e[1;31m" // red
#define SUBCOLOR "\e[1;34m" // blue
#define MULCOLOR "\e[1;38;5;208m" // orange
#define DIVCOLOR "\e[1;35m" // violet
// colors reference: https://gist.github.com/iamnewton/8754917

#define OPERATION_NAME_AND_COLOR_MAX 15

void additionRandomizer();
void subtractionRandomizer();
void multiplicationRandomizer();
void divisionRandomizer();

int i, numOfProblems, num1, num2, correctAnswer, userAnswer, score = 0;
float choice;
int *correctAnswers, *userAnswers;
char operationName[OPERATION_NAME_AND_COLOR_MAX]; // size is exact for "multiplication\0", is it ok?
char operationColor[OPERATION_NAME_AND_COLOR_MAX]; // will hold the color string value from the respective macro

void printMenu(){
    system("cls");
    score = 0;
    printf(TITLE"MATH TRAINER");
    printf(RESET "\n\n----- MENU -----\n\n");
    printf("Press ["BOLD"1"RESET "] for "ADDCOLOR"Addition\n"RESET);
    printf("Press ["BOLD"2"RESET "] for "SUBCOLOR"Subtraction\n"RESET);
    printf("Press ["BOLD"3"RESET "] for "MULCOLOR"Multiplication\n"RESET);
    printf("Press ["BOLD"4"RESET "] for "DIVCOLOR"Division\n"RESET);
    printf("Press ["BOLD"0"RESET "] to "BOLD"Exit "RESET""TITLE"MATH TRAINER\n"RESET);
}

int problemErrorHandling(){
    float numOfProblemsFloat;

    if(scanf("%f", &numOfProblemsFloat) != 1 ){
        printf("\nThat is not a number! "BOLD"Enter a number from 1 to 20.\n"RESET);
        return 0;
    }
    else if(numOfProblemsFloat < 1){
        printf(BOLD"\nYou need to answer at least 1 problem!\n"RESET);
        return 0;
    }
    else if(floor(numOfProblemsFloat) != numOfProblemsFloat){
        printf("\nThere are no fractional amount of problems! "BOLD"Enter a whole number.\n"RESET);
        return 0;
    }
    else if(numOfProblemsFloat > 20){
        numOfProblems = numOfProblemsFloat;
        printf(BOLD"\n%d problems are a lot!"RESET" Just answer another set of problems later if you want to practice more.\n", numOfProblems);
            // 21 is too many compared to 20?? nevermind
        return 0;
    }

    numOfProblems = numOfProblemsFloat;
    return 1;
}

void loadingEllipsis(){ // prints an ellipsis in 1.5 seconds
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
    printf("Come back anytime! Remember that practice makes perfect "BOLD":)"RESET);
}

int main(){
    printMenu();

    while (1){
        printf("\nEnter your choice: ");
        if(scanf("%f", &choice) != 1 || choice < 0 || choice > 4 || (floor(choice) != choice)){
            printf("\nThat's an invalid choice. Please choose from the menu above ["BOLD"1"RESET" to "BOLD"4"RESET", or "BOLD"0"RESET"].\n", choice);
            while (getchar() != '\n');
            continue;
        }
        break;
    }
    
    int choiceInt;
    choiceInt = choice; // convert (float) choice into int, as switch-case function only accepts int
    
    switch (choiceInt){
        case 1: additionRandomizer();
            break;
        case 2: subtractionRandomizer();
            break;
        case 3: multiplicationRandomizer();
            break;
        case 4: divisionRandomizer();
            break;
        case 0: exitProgram();   
    }
    
    free(correctAnswers);
    return 0;
}

void getAndLoadNumberOfProblems(){
    do{
        while (getchar() != '\n');
        printf("\nHow many %s%s"RESET" problems would you like to answer? [up to 20 only]: ", operationColor, operationName);
    } while(!problemErrorHandling());

    system("cls");

    if(numOfProblems == 1){ // condition for "problem(s)"
        printf("Loading ("BOLD"%d"RESET") %s%s"RESET" Problem", numOfProblems, operationColor, operationName);
    }
    else{
        printf("Loading ("BOLD"%d"RESET") %s%s"RESET" Problems", numOfProblems, operationColor, operationName);
    }

    loadingEllipsis();
    printf("\n\n");
}

void checkUserAnswerAndCalculateScore(){
    scanf("%d", &userAnswer);

    userAnswers[i - 1] = userAnswer;
    if(correctAnswer == userAnswer){
        score += 1;
    }
}

void printScoreAndAnswers(){
    printf("\nYour total score is "BOLD"%d/%d\n", score, numOfProblems);

    printf("\nCorrect Answers:\n"RESET);

    for(i = 0; i < numOfProblems; i++){
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
    
    strcpy(operationName, "Addition");
    strcpy(operationColor, ADDCOLOR);
    getAndLoadNumberOfProblems();

    correctAnswers = (int *)malloc(numOfProblems * sizeof(int));
    userAnswers = (int *)malloc(numOfProblems * sizeof(int));
    srand(time(NULL));

    for(i = 1; i <= numOfProblems; i++){
        num1 = rand()%100;
        num2 = rand()%100;
        correctAnswer = num1 + num2;
        correctAnswers[i - 1] = correctAnswer;
        printf(TAB"Problem (%d): %d + %d = ", i, num1, num2);
       
       checkUserAnswerAndCalculateScore();
    }

    printScoreAndAnswers();
}

void subtractionRandomizer(){
    printMenu();

 	strcpy(operationName, "Subtraction");
    strcpy(operationColor, SUBCOLOR);
    getAndLoadNumberOfProblems();

    correctAnswers = (int *)malloc(numOfProblems * sizeof(int));
    userAnswers = (int *)malloc(numOfProblems * sizeof(int));
    srand(time(NULL));

    for(i = 1; i <= numOfProblems; i++){
		num1 = 1 + rand() % 100;
        num2 = rand() % num1;
        correctAnswer = num1 - num2;
        correctAnswers[i - 1] = correctAnswer;
        printf(TAB"Problem (%d): %d - %d = ", i, num1, num2);
        
        checkUserAnswerAndCalculateScore();
    }

    printScoreAndAnswers();
}

void multiplicationRandomizer(){
    printMenu();

	strcpy(operationName, "Multiplication");
    strcpy(operationColor, MULCOLOR);
    getAndLoadNumberOfProblems();
    
    correctAnswers = (int *)malloc(numOfProblems * sizeof(int));
    userAnswers = (int *)malloc(numOfProblems * sizeof(int));
    srand(time(NULL));

    for(i = 1; i <= numOfProblems; i++){
		num1 = 1 + rand() % 10;
        num2 = 1 + rand() % (200 / num1);
        correctAnswer = num1 * num2;
        correctAnswers[i - 1] = correctAnswer;
        printf(TAB"Problem (%d): %d x %d = ", i, num1, num2);
        
        checkUserAnswerAndCalculateScore();
    }

    printScoreAndAnswers();
}

void divisionRandomizer(){
    printMenu();

  	strcpy(operationName, "Division");
    strcpy(operationColor, DIVCOLOR);
    getAndLoadNumberOfProblems();
    
    correctAnswers = (int *)malloc(numOfProblems * sizeof(int));
    userAnswers = (int *)malloc(numOfProblems * sizeof(int));
    srand(time(NULL));

    for(i = 1; i <= numOfProblems; i++){
		num2 = 1 + rand() % 10;
        num1 = num2 * (1 + rand() % 10);
        correctAnswer = num1 / num2;
        correctAnswers[i - 1] = correctAnswer;
        printf(TAB"Problem (%d): %d / %d = ", i, num1, num2);
        
        checkUserAnswerAndCalculateScore();
    }

    printScoreAndAnswers();
}