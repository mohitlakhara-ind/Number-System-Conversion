#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
void reverseString(char*);
char* decimalToBinary(int);
int binaryToDecimal(const char[]);
char* decimalToOctal(int);
int octalToDecimal(const char[]);
char* hexadecimalToBinary(const char[]);
char* binaryToHexadecimal(const char[]);

// Function to reverse a string in place
void reverseString(char* str) {
    int i = 0;
    int j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to convert decimal to binary
char* decimalToBinary(int decimal) {
    // Allocate memory for a 32-bit binary number (plus null terminator)
    char* binary = (char*)malloc(33);
    int i = 0;

    // Convert decimal to binary
    while (decimal) {
        binary[i++] = '0' + (decimal & 1);
        decimal >>= 1;
    }

    // Terminate the string and reverse it
    binary[i] = '\0';
    reverseString(binary);
    return binary;
}

// Function to convert binary to decimal
int binaryToDecimal(const char binary[]) {
    int decimal = 0;
    int length = strlen(binary);

    // Traverse each character in the binary string
    for (int i = 0; i < length; i++) {
        decimal = decimal * 2 + (binary[i] - '0');
    }
    return decimal;
}

// Function to convert decimal to octal
char* decimalToOctal(int decimal) {
    // Allocate memory for the octal string
    char* octal = (char*)malloc(12);
    if (octal == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Convert decimal to octal using sprintf
    sprintf(octal, "%o", decimal);
    return octal;
}

// Function to convert octal to decimal
int octalToDecimal(const char octal[]) {
    int decimal = 0;
    int length = strlen(octal);

    // Traverse each character in the octal string
    for (int i = 0; i < length; i++) {
        decimal = decimal * 8 + (octal[i] - '0');
    }
    return decimal;
}

// Function to convert hexadecimal to binary
char* hexadecimalToBinary(const char hex[]) {
    unsigned int hexNum;
    sscanf(hex, "%x", &hexNum); // Convert hexadecimal string to unsigned int

    // Allocate memory for a 32-bit binary number (plus null terminator)
    char* binary = (char*)malloc(33);
    int i = 0;

    // Convert hexadecimal to binary
    while (hexNum) {
        binary[i++] = '0' + hexNum % 2;
        hexNum /= 2;
    }

    // Terminate and reverse the string
    binary[i] = '\0';
    reverseString(binary);
    return binary;
}

// Function to convert binary to hexadecimal
char* binaryToHexadecimal(const char binary[]) {
    // Pad binary string to make it a multiple of 4
    int length = strlen(binary);
    int padding = (4 - (length % 4)) % 4;
    char paddedBinary[129];  // Allocate space for padded binary
    memset(paddedBinary, '0', padding); // Fill with leading zeros
    strcpy(paddedBinary + padding, binary); // Append binary to padded section

    // Define binary to hexadecimal mapping
    const char* binaryHexDigits[] = {
        "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"
    };

    // Allocate memory for hexadecimal string
    char hexadecimal[33] = "";
    char group[5]; // To store a group of 4 binary digits

    // Traverse binary string in groups of 4
    for (int i = 0; i < length + padding; i += 4) {
        strncpy(group, paddedBinary + i, 4); // Extract 4 digits
        group[4] = '\0'; // Null-terminate the group

        // Match binary group with corresponding hexadecimal digit
        for (int j = 0; j < 16; j++) {
            if (strcmp(group, binaryHexDigits[j]) == 0) {
                char hexDigit[2];
                sprintf(hexDigit, "%X", j); // Convert to hexadecimal character
                strcat(hexadecimal, hexDigit); // Append to result
                break;
            }
        }
    }
    return strdup(hexadecimal); // Duplicate string for dynamic memory allocation
}

// Main program to drive the conversion tool
int main() {
    int choice;
    while (1) {
        printf("\nConversion Tool Menu:\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Decimal to Octal\n");
        printf("4. Octal to Decimal\n");
        printf("5. Hexadecimal to Binary\n");
        printf("6. Binary to Hexadecimal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Thank you for using the Conversion Tool. Goodbye!\n");
            break;
        }

        char input[100];
        char* result = NULL;

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &choice);
                result = decimalToBinary(choice);
                printf("Decimal to Binary: %s\n", result);
                free(result); // Free dynamically allocated memory
                break;
            case 2:
                printf("Enter a binary number: ");
                scanf("%s", input);
                int binaryResult = binaryToDecimal(input);
                printf("Binary to Decimal: %d\n", binaryResult);
                break;
            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &choice);
                result = decimalToOctal(choice);
                printf("Decimal to Octal: %s\n", result);
                free(result); // Free dynamically allocated memory
                break;
            case 4:
                printf("Enter an octal number: ");
                scanf("%s", input);
                int octalResult = octalToDecimal(input);
                printf("Octal to Decimal: %d\n", octalResult);
                break;
            case 5:
                printf("Enter a hexadecimal number: ");
                scanf("%s", input);
                result = hexadecimalToBinary(input);
                printf("Hexadecimal to Binary: %s\n", result);
                free(result); // Free dynamically allocated memory
                break;
            case 6:
                printf("Enter a binary number: ");
                scanf("%s", input);
                result = binaryToHexadecimal(input);
                printf("Binary to Hexadecimal: %s\n", result);
                free(result); // Free dynamically allocated memory
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

// Credits Section
/*
 * Program: Conversion Tool - Binary, Octal, Decimal, and Hexadecimal
 * Author: Mohit Lakhara
 * GitHub: https://github.com/mohitlakhara-ind
 * Description: A simple and interactive tool to perform conversions between 
 *              binary, octal, decimal, and hexadecimal number systems.
 * Date: 2024
 *
 * Acknowledgements:
 * - Open-source community for invaluable guidance and resources.
 * 
 * License: MIT License
 */
