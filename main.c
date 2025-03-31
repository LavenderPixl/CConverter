#include <stdio.h>
#include <string.h>
#include <tgmath.h>

//pragma region Declarations.

//Decimal
int get_user_decimal();

void decimal_to_binary(int);

void decimal_to_hex(int);

//Binary
void binary_to_decimal(char []);

void binary_to_hexadecimal(char []);


//Hexadecimals


//Etc.
void get_user_string(char []);

void reverse_array(char []);

int power_of(int, int);

void decimal();

void binary();

void hexadecimal();

//pragma endregion

//Initiations.
int main(void) {
    printf("What would you like to start with? \n\n 1. Decimal | 2. Binary | 3. Hexadecimal\n\nChoice: ");
    int user_input = 0;
    scanf("%i", &user_input);

    if (user_input == 1) {
        decimal();
    } else if (user_input == 2) {
        binary();
    } else if (user_input == 3) {
        hexadecimal();
    } else {
        return 0;
    }
}


//Decimal
int get_user_decimal() {
    printf("Enter your decimal number: ");
    // Get user input.
    int user_input = 0;
    scanf("%d", &user_input);
    return user_input;
}

void decimal_to_binary(int decimal_number) {
    int quotient;
    char temp_array[40];
    int i = 0;

    do {
        quotient = decimal_number / 2;
        int remainder = decimal_number % 2;
        decimal_number = quotient;
        temp_array[i] = (remainder + '0');
        i++;
    } while (quotient != 0);


    printf("Binary: ");
    reverse_array(temp_array);

    printf("%s", temp_array);
    printf("\n");
}

void decimal_to_hex(int decimal_number) {
    char temp_array[64] = {0};
    int quotient = 1;
    int i = 0;

    do {
        const int remainder = decimal_number % 16;
        if (remainder < 10) {
            temp_array[i] = (48 + remainder);
        } else {
            temp_array[i] = (55 + remainder);
        }

        quotient = decimal_number / 16;
        decimal_number = quotient;

        i++;
    } while (quotient != 0);


    reverse_array(temp_array);
    printf("Hexadecimal: 0x");
    for (int d = 0; d < i; d++) {
        printf("%c", temp_array[d]);
    }
    printf("\n");
}


//Binary
void binary_to_decimal(char user_input[]) {
    const unsigned long size = strlen(user_input);
    unsigned long sum = 0;
    unsigned long l = size - 1;

    for (int i = 0; i < size; i++) {
        if (user_input[i] == '0') {
            l--;
            continue;
        }
        sum = sum + (power_of(2, l));
        l--;
    }
    printf("Decimal: ");
    printf("%lu\n", sum);
}

void binary_to_hexadecimal(char user_input[]) {


}


//Etc.
void get_user_string(char user_input[]) {
    printf("Enter your number: ");
    scanf("%s", user_input);
}

void reverse_array(char arr[]) {
    long size = strlen(arr);

    int a = 0;
    int b = size - 1;

    while (b - a > 0) {
        arr[a] = arr[a] ^ arr[b];
        arr[b] = arr[a] ^ arr[b];
        arr[a] = arr[a] ^ arr[b];

        a++;
        b--;
    }
}

int power_of(int x, int n) {
    int number = 1;

    for (int i = 0; i < n; ++i)
        number *= x;

    return (number);
}


void decimal() {
    const int user_input = get_user_decimal();
    decimal_to_binary(user_input);
    decimal_to_hex(user_input);
}

void binary() {
    char user_input[40];
    get_user_string(user_input);
    binary_to_decimal(user_input);
    // binary_to_hexadecimal(user_input);
}

void hexadecimal() {
}
