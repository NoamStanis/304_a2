#include <stdio.h>
#include <ctype.h>


char mode[3] = "Dec";
int dec_value,hex_value,oct_value = 0;

// read in numeric value in mode; return value
short get_operand(char mode) {
    return 0;
}

//print out accumulator values
void print_acc(short acc, char mode) {

}

// print menu; get option until valid; return option
char print_menu() {
    char option;
    char valid_options[12] = {'O','o','H','h','D','d','C','c','S','s','Q','q'};
    int option_valid = 0;
    printf("****************************************\n"
           "* Accumulator:         Input Mode: %.3s *\n"
           "* Hex : %.4x                           *\n"
           "* Octal : %.6o                       *\n"
           "* Decimal : %u                          *\n"
           "****************************************\n", mode,hex_value,oct_value,dec_value);

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
            printf("\nSelected Octal Mode");
            option_valid = 1;
            break;

        case 'H':
            printf("\nSelected Hexadecimal Mode");
            option_valid = 1;
            break;

        case 'D':
            printf("\nSelected Decimal Mode");
            option_valid = 1;
            break;

        case 'C':
            oct_value = 0;
            printf("\nCleared accumulator values.");
            option_valid = 1;
            break;

        case 'S':
            option_valid = 1;
            break;

        case 'Q':
            option_valid = 1;
            break;

        default:
            printf("\nInvalid input\n");
            print_menu();
            break;
    }

    return option;
}

int main() {
    print_menu();
}