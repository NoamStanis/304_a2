#include <stdio.h>
#include <string.h>
#include <ctype.h>


char value_mode[4] = "Dec";
short dec_value,hex_value,oct_value = 0;
short actual_value = 0;

// return the correct value given the mode
short get_operand(char mode) {
    return 0;
}

//print out accumulator values
void print_acc(short acc, char mode) {

}

// print menu; get option until valid; return option
char print_menu() {
    char option;
    int *value;
    char valid_options[12] = {'O','o','H','h','D','d','C','c','S','s','Q','q'};
    printf("\n****************************************\n"
           "* Accumulator:         Input Mode: %.3s *\n"
           "* Hex : %04hX                           *\n"
           "* Octal : %06ho                       *\n"
           "* Decimal : %-6hd                     *\n"
           "****************************************\n", value_mode, actual_value, actual_value, actual_value);

    printf("\nPlease select one of the following options: \n");
    printf("\nO Octal Mode\n"
           "H Hexidecimal Mode\n"
           "D Decimal Mode\n\n"
           "C Clear Accumulator\n"
           "S Set Accumulator\n\n"
           "Q Quit\n\n");

    printf("Option: ");

    scanf(" %c", &option);
    char upper_option = toupper(option);
    switch (upper_option) {
        case 'O':
            printf("\nMode is Octal");
            strncpy(value_mode, "Oct", 3);
            print_menu();
            break;

        case 'H':
            printf("\nMode is Hexadecimal");
            strncpy(value_mode, "Hex", 3);
            print_menu();
            break;

        case 'D':
            printf("\nMode is Decimal");
            strncpy(value_mode, "Dec", 3);
            print_menu();
            break;

        case 'C':
            actual_value = 0;
            printf("\nCleared accumulator values.");
            print_menu();
            break;

        case 'S':
            printf("Set the value in the given mode: ");
            short new_value;

            if (strcmp(value_mode, "Oct") == 0) {
                scanf("%ho",&new_value);
                printf("%ho",new_value);
                actual_value = new_value;
            }

            if (strcmp(value_mode, "Dec") == 0) {
                scanf("%hd",&new_value);
                printf("%hd",new_value);
                actual_value = new_value;
            }

            if (strcmp(value_mode, "Hex") == 0) {
                scanf("%hx",&new_value);
                actual_value = new_value;
            }

            print_menu();
            break;

        case 'Q':
            break;

        default:
            printf("\nan invalid option has been entered.\n");
            print_menu();
            break;
    }

    return option;
}

int main() {
    print_menu();
}