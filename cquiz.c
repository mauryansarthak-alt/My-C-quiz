#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TOTAL_QUESTIONS 10

void getQuestionFromAPI(int questionID, 
                        char* questionText, 
                        char* optA, 
                        char* optB, 
                        char* optC, 
                        char* correctOpt) {

    switch(questionID) {
        
        case 1:
            strcpy(questionText, "What is the capital of India?");
            strcpy(optA, "Mumbai");
            strcpy(optB, "New Delhi");
            strcpy(optC, "Kolkata");
            *correctOpt = 'B';
            break;

        case 2:
            strcpy(questionText, "What is the basic data type for whole numbers in C?");
            strcpy(optA, "char");
            strcpy(optB, "float");
            strcpy(optC, "int");
            *correctOpt = 'C';
            break;
            
        case 3:
            strcpy(questionText, "Which loop is guaranteed to run at least once?");
            strcpy(optA, "for loop");
            strcpy(optB, "while loop");
            strcpy(optC, "do-while loop");
            *correctOpt = 'C';
            break;

        case 4:
            strcpy(questionText, "What symbol is used for 'address of' operator?");
            strcpy(optA, "& (Ampersand)");
            strcpy(optB, "* (Asterisk)");
            strcpy(optC, "# (Hash)");
            *correctOpt = 'A';
            break;

        case 5:
            strcpy(questionText, "Which header file is needed for 'printf' and 'scanf'?");
            strcpy(optA, "string.h");
            strcpy(optB, "stdio.h");
            strcpy(optC, "math.h");
            *correctOpt = 'B';
            break;

        case 6:
            strcpy(questionText, "What does 'float' data type store?");
            strcpy(optA, "Single character");
            strcpy(optB, "Decimal number");
            strcpy(optC, "Whole number");
            *correctOpt = 'B';
            break;

        case 7:
            strcpy(questionText, "How do you start a single-line comment in C?");
            strcpy(optA, "//");
            strcpy(optB, "/*");
            strcpy(optC, "#");
            *correctOpt = 'A';
            break;

        case 8:
            strcpy(questionText, "An 'array' in C is a collection of items of...?");
            strcpy(optA, "Different data types");
            strcpy(optB, "Same data type");
            strcpy(optC, "Only int data type");
            *correctOpt = 'B';
            break;

        case 9:
            strcpy(questionText, "What keyword is used to define a constant?");
            strcpy(optA, "const");
            strcpy(optB, "final");
            strcpy(optC, "static");
            *correctOpt = 'A';
            break;

        case 10:
            strcpy(questionText, "Must every C function return a value?");
            strcpy(optA, "Yes, always");
            strcpy(optB, "Only if it is 'int'");
            strcpy(optC, "No (if return type is 'void')");
            *correctOpt = 'C';
            break;

        default:
            strcpy(questionText, "Error: Question not found.");
            strcpy(optA, "-"); 
            strcpy(optB, "-"); 
            strcpy(optC, "-"); 
            *correctOpt = ' ';
            break;
    }
}


int main() {
    
    char question[256]; 
    char optA[50], optB[50], optC[50];
    char correctOption;
    char userAnswer;
    char inputBuffer[10];
    int score = 0;

    printf("Welcome to the C Quiz Game!\n");
    printf("------------------------------\n");

    for (int i = 1; i <= TOTAL_QUESTIONS; i++) {
        
        getQuestionFromAPI(i, question, optA, optB, optC, &correctOption);
        
        printf("\nQ%d: %s\n", i, question);
        printf("  A. %s\n", optA);
        printf("  B. %s\n", optB);
        printf("  C. %s\n", optC);
        
        printf("Your Answer (A, B, or C): ");
        
        fgets(inputBuffer, sizeof(inputBuffer), stdin);
        userAnswer = toupper(inputBuffer[0]);
        
        if (userAnswer == correctOption) {
            printf("Correct Answer!\n");
            score++;
        } else {
            printf("Wrong! The correct answer was: %c\n", correctOption);
        }
        
        printf("------------------------------\n");
    }
    
    printf("\nQuiz Finished!\n");
    printf("Your Final Score: %d out of %d\n", score, TOTAL_QUESTIONS);

    return 0;

}
