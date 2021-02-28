#include <stdio.h>
#include <string.h>
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
    printf("\n****************************************\n"
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
            printf("\nMode is Octal");
            strncpy(mode,"Oct",3);
            print_menu();
            break;

        case 'H':
            printf("\nMode is Hexadecimal");
            strncpy(mode,"Hex",3);
            print_menu();
            break;

        case 'D':
            printf("\nMode is Decimal");
            strncpy(mode,"Dec",3);
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