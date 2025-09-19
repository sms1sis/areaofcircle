#include <stdio.h>
#include <stdarg.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>

void print_centered(const char *fmt, ...) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int term_width = w.ws_col;

    char buffer[256];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    int len = strlen(buffer);
    int padding = (term_width - len) / 2;

    for (int i = 0; i < padding; ++i) {
        putchar(' ');
    }
    printf("%s", buffer);
}

int main() {
    printf("\033[1m");
    printf("\033[36m");
    printf("\033[1;36m");
    print_centered("**************************************************\n");
    print_centered("*                                                *\n");
    print_centered("*          Welcome to the Coding World!          *\n");
    print_centered("*                                                *\n");
    print_centered("**************************************************\n");
    printf("\n");

    printf("\033[1;31m");
    print_centered("Presented by:\n");
    print_centered("Sadi Mahmud Sajid / Devildon\n");
    print_centered("(devil㉿kali)\n");
    print_centered("Contact Number:01890731620\n");
    print_centered("Gmail:sadimahmudsajid@gmail.com\n");
    printf("\033[0m");
    printf("\033[0m");
    printf("\033[0m");
    printf("\n");
    print_centered("\033[1;32m        >>>C program to calculate the area of a circle<<<\n");

    char choice;
    do {
        float pi = 3.1416;
        float r;
        float sum;
        int input_check;

        do {
            printf("\n");
            print_centered("\033[1;33m     Enter the value of r: ");
            input_check = scanf("%f", &r);
            while(getchar() != '\n'); // Clear the input buffer

            if (input_check != 1) {
                printf("\n");
                print_centered("\033[1;31m       Please enter only numbers.\n");
            } else if (r <= 0) {
                printf("\n");
                print_centered("\033[1;31m       Please enter 'r > 0': \n");
            }
        } while (input_check != 1 || r <= 0);

        sum = pi * r * r;
        print_centered("\033[1;33m    The area is %f\n", sum);

        printf("\n");
        print_centered("\033[1;35m       Do you want to calculate another area? (y/n): ");
        scanf(" %c", &choice);

        while (choice != 'y' && choice != 'n') {
            printf("\n");
            print_centered("\033[1;31m       Please enter 'y' or 'n': ");
            scanf(" %c", &choice);
        }
    } while (choice == 'y');

    return 0;
}
