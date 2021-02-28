#include <stdio.h>
#include <string.h>
#include <ctype.h>


char value_mode[4] = "Dec";
int dec_value,hex_value,oct_value = 0;

// return the correct value given the mode
short get_operand(char mode) {
    int *og_value;
    switch(mode) {

        case 'O':
            og_value = &oct_value;
            break;

        case 'H':
            og_value = &hex_value;
            break;

        case 'D':
            og_value = &dec_value;
            break;
    }
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
           "* Hex : %.4x                           *\n"
           "* Octal : %.6o                       *\n"
           "* Decimal : %u                          *\n"
           "****************************************\n", value_mode, hex_value, oct_value, dec_value);

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
            oct_value = 0;
            dec_value = 0;
            hex_value = 0;
            printf("\nCleared accumulator values.");
            print_menu();
            break;

        case 'S':
            printf("Set the value in the given mode: ");
            int new_value;
            scanf("%i",&new_value);

            if (strcmp(value_mode, "Oct") == 0) {
                oct_value = new_value;
            }

            if (strcmp(value_mode, "Dec") == 0) {
                dec_value = new_value;
            }

            if (strcmp(value_mode, "Hex") == 0) {
                hex_value = new_value;
            }

            get_operand(value_mode);
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