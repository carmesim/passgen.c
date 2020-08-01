#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void generate_password(int pass_length){
        char arr_password_material[] = "abcdefghkjlmnopqrstuvwxyzABCDEFGHKJLMNOPQRSTUVWZYZ1234567890!@#$%%^&*()_+|\\=-{}][\"'.><,?";
        printf("Please copy your new password: ");
	printf("\033[0;32m"); // green color for the password
        for (int i = 0; i < pass_length; i++)
                printf("%c", arr_password_material[rand() % sizeof(arr_password_material)]);
        printf("\n");
        printf("\e[0m");
}

int main(int argc, char ** argv){
        time_t time_var;
        srand((unsigned)time(&time_var));
        if(argv[1] == NULL){
                printf("How to use this program:\npassgenc <password length in numbers>\nExamples:\npassgenc 10\npassgenc 25\n");
                return 1;
        } else {
                int pass_length = atoi(argv[1]);
                generate_password(pass_length);
                sleep(1);
        }
	return 0;
}
