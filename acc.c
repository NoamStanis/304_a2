#include <stdio.h>
#include <string.h>


char value_mode = 'd';
short actual_value = 0;
short quit = 0;

//print out accumulator values
void print_acc(short acc, char mode) {
    char value_str_mode[4];
    switch(mode){

        case 'D':
        case 'd':
            strcpy(value_str_mode,"Dec");
            break;

        case 'O':
        case 'o':
            strcpy(value_str_mode,"Oct");
            break;

        case 'H':
        case 'h':
            strcpy(value_str_mode, "Hex");
            break;

    }
    printf("\n****************************************\n"
           "* Accumulator:         Input Mode: %.3s *\n"
           "*   Hex     :  %04hX                    *\n"
           "*   Octal   :  %06ho                  *\n"
           "*   Decimal :  %-6hd                  *\n"
           "****************************************\n", value_str_mode, acc, acc, acc);
}

// return the correct value given the mode
short get_operand(char mode) {
    short new_value; // stores user given value
    if(mode == 0 ) {
        return 0;
    }
    switch (mode) {

        case 'o':
        case 'O':
            printf("Mode is Octal\n");
            value_mode = 'o';
            print_acc(actual_value, value_mode);
            break;

        case 'h':
        case 'H':
            printf("Mode is Hexadecimal\n");
            value_mode = 'h';
            print_acc(actual_value, value_mode);
            break;

        case 'd':
        case 'D':
            printf("Mode is Decimal\n");
            value_mode = 'd';
            print_acc(actual_value, mode);
            break;

        case 'c':
        case 'C':
            actual_value = 0;
            print_acc(actual_value,value_mode);
            break;

        case 's':
        case 'S':
            if (value_mode == 'o' || value_mode == 'O') {
                printf("Enter octal value: ");
                scanf("%ho",&new_value);
                printf("%ho\n",new_value);
                actual_value = new_value;
            }

            if (value_mode == 'd' || value_mode == 'D') {
                printf("Enter decimal value: ");
                scanf("%hd",&new_value);
                printf("%hd\n",new_value);
                actual_value = new_value;
            }

            if (value_mode == 'h' || value_mode == 'H') {
                printf("Enter hex value: ");
                scanf("%hX", &new_value);
                printf("%hX\n", new_value);
                actual_value = new_value;
            }

            print_acc(actual_value, value_mode);
            break;

        case 'q':
        case 'Q':
            quit = 1;
            break;

        default:
            printf("\nInvalid option: %c\n", mode);
            break;
    }
    return 0;
}

// print menu; get option until valid; return option
char print_menu() {
    char option[10];

    printf("\nPlease select one of the following options: \n");
    printf("\nO  Octal Mode\n"
           "H  Hexadecimal Mode\n"
           "D  Decimal Mode\n\n"
           "C  Clear Accumulator\n"
           "S  Set Accumulator\n\n"
           "Q  Quit\n\n");

    printf("Option: ");

    scanf(" %s", option);
    //printf("%s\n", option);
    short new_value;

    printf("%s\n",option);

    if(option[1] != 0) {
        printf("\nInvalid option: %s\n", option);
        return 0;
    }

    char real_option = option[0];
    return real_option;
}

int main() {
    print_acc(actual_value,value_mode);
    while(!quit) {
        get_operand(print_menu());
    }
}