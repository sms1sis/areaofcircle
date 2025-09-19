#include <stdio.h>
#include <stdarg.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include <math.h> // For M_PI

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
    if (padding < 0) padding = 0;

    for (int i = 0; i < padding; ++i) putchar(' ');
    printf("%s", buffer);
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    printf("\033[1;36m");
    print_centered("**************************************************\n");
    print_centered("*                                                *\n");
    print_centered("*          Welcome to the Coding World!          *\n");
    print_centered("*                                                *\n");
    print_centered("**************************************************\n");

printf("\033[1;31m");
print_centered("Presented by:\n");
print_centered("Sadi Mahmud Sajid / Devildon\n");
print_centered("(devil㉿kali)\n");
print_centered("Contact: 01890731620\n");
print_centered("Email: sadimahmudsajid@gmail.com\n");
printf("\033[0m\n");

    print_centered("\033[1;32m        >>>C program to calculate the area of a circle<<<\n");

    char choice;
    do {
        float r, area;
        int input_check;

        // Input loop
        do {
            printf("\n");
            print_centered("\033[1;33m     Enter the value of r: ");
            input_check = scanf("%f", &r);
            clear_input_buffer();

            if (input_check != 1) {
                printf("\n");
                print_centered("\033[1;31m       Please enter only numbers.\n");
            } else if (r <= 0) {
                printf("\n");
                print_centered("\033[1;31m       Please enter 'r > 0': \n");
            }
        } while (input_check != 1 || r <= 0);

        area = M_PI * r * r;
        print_centered("\033[1;33m    The area is %.2f\n", area);

        printf("\n");
        print_centered("\033[1;35m       Do you want to calculate another area? (y/n): ");
        scanf(" %c", &choice);
        clear_input_buffer();

        while (choice != 'y' && choice != 'n') {
            printf("\n");
            print_centered("\033[1;31m       Please enter 'y' or 'n': ");
            scanf(" %c", &choice);
            clear_input_buffer();
        }
    } while (choice == 'y');

    printf("\033[0m"); // Ensure color reset at end
    return 0;
}