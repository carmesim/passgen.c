#include "stdio.h"
#include "stdlib.h"
#include "time.h"
void delay();
void main()
{
        delay();
        time_t time_var;
        int pass_length;
        char arr_password_material[] = "abcdefghkjlmnopqrstuvwxyzABCDEFGHKJLMNOPQRSTUVWZYZ1234567890!@#$%%^&*()_+|\\=-{}][\"'.><,?";
        // Options for the password generation
        printf("How many digits do you want your password to be? ");
        scanf("%d", &pass_length);

        srand((unsigned)time(&time_var));
        printf("Your new password: ");

        for (int i = 0; i < pass_length; i++)
        {
                printf("%c", arr_password_material[rand() % sizeof(arr_password_material)]);
        }
        printf("\n");
}

void delay()
{
        /* If you generate random numbers fast, they will be repeated
           that's why I'm doing a delay, just to make sure that the
           numbers are indeed random */
        for (int c = 1; c <= 31276; c++)
                for (int d = 1; d <= 5876; d++) { }
}
