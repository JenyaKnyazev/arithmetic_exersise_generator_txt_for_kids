#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int count_digits(int n) {
    int count = 0;
    while (n) {
        count++;
        n /= 10;
    }
    return count;
}
char* spaces2(int digits) {
    char* p = malloc(digits + 1);
    memset(p, ' ', digits + 1);
    p[digits] = 0;
    return p;
}
int generate_number(int digits) {
    int n = rand() % 9 + 1;
    while (--digits) {
        n *= 10;
        n += rand() % 10;
    }
    return n;
}
char* spaces(int digits) {
    char* p = malloc(digits + 1);
    memset(p, '_', digits);
    p[digits] = 0;
    return p;
}
void plus(FILE *f,int digits) {
    int i, r;
    char* p = spaces(digits + 1);
    for (i = 1; i <= 20; i++) {
        switch (digits) {
        case 1:
            for (r = 1; r <= 4; r++) 
                fprintf(f,"%d + %d = %s,",generate_number(digits), generate_number(digits),p);
            fprintf(f, "%d + %d = %s", generate_number(digits), generate_number(digits), p);
            fprintf(f, "\n\n");
            break;
        case 2:
            for (r = 1; r <= 3; r++) 
                fprintf(f, "%d + %d = %s,", generate_number(digits), generate_number(digits), p);
            fprintf(f, "\n\n");
            break;
        default:
            for (r = 1; r <= 2; r++) 
                fprintf(f, "%d + %d = %s,", generate_number(digits), generate_number(digits), p);
            fprintf(f, "\n\n");
            break;
        }
    }
    free(p);
}
void plus_right(FILE* f, int digits) {
    int i, r;
    char* p = spaces(digits + 1);
    for (i = 1; i <= 20; i++) {
        switch (digits) {
        case 1:
            fprintf(f, "%s = %d + %d", p, generate_number(digits), generate_number(digits));
            for (r = 1; r <= 4; r++)
                fprintf(f, ",%s = %d + %d",p, generate_number(digits), generate_number(digits));
            fprintf(f, "\n\n");
            break;
        case 2:
            for (r = 1; r <= 3; r++) 
                fprintf(f, ",%s = %d + %d",p, generate_number(digits), generate_number(digits));
            fprintf(f, "\n\n");
            break;
        default:
            for (r = 1; r <= 2; r++) 
                fprintf(f, ",%s = %d + %d",p, generate_number(digits), generate_number(digits));
            fprintf(f, "\n\n");
            break;
        }
    }
    free(p);
}
void minus(FILE* f, int digits) {
    int i, r,num1,num2;
    char* p = spaces(digits );
    char* p2;
    for (i = 1; i <= 20; i++) {
        switch (digits) {
        case 1:
            for (r = 1; r <= 4; r++) {
                num1 = generate_number(digits);
                num2 = generate_number(digits);
                p2 = spaces2(digits+1 - count_digits(num1 + num2));
                fprintf(f, "%s%d - %d = %s,",p2,num1+num2, num1, p);
                free(p2);
            }
            num1 = generate_number(digits);
            num2 = generate_number(digits);
            p2 = spaces2(digits+1 - count_digits(num1 + num2));
            fprintf(f, "%s%d - %d = %s,", p2, num1 + num2, num1, p);
            fprintf(f, "\n\n");
            free(p2);
            break;
        case 2:
            for (r = 1; r <= 3; r++) {
                num1 = generate_number(digits);
                num2 = generate_number(digits);
                p2 = spaces2(digits+1 - count_digits(num1 + num2));
                fprintf(f, "%s%d - %d = %s,", p2, num1 + num2, num1, p);
                free(p2);
            }
            fprintf(f, "\n\n");
            break;
        default:
            for (r = 1; r <= 2; r++) {
                num1 = generate_number(digits);
                num2 = generate_number(digits);
                p2 = spaces2(digits+1 - count_digits(num1 + num2));
                fprintf(f, "%s%d - %d = %s,", p2, num1 + num2, num1, p);
                free(p2);
            }
            fprintf(f, "\n\n");
            break;
        }
    }
    free(p);
}
void minus_right(FILE* f, int digits) {
    int i, r, num1, num2;
    char* p = spaces(digits );
    char* p2;
    for (i = 1; i <= 20; i++) {
        switch (digits) {
        case 1:
            num1 = generate_number(digits);
            num2 = generate_number(digits);
            p2 = spaces2(digits + 1 - count_digits(num1 + num2));
            fprintf(f, "%s = %d - %d%s", p, num1, num1 + num2, p2);
            free(p2);
            for (r = 1; r <= 4; r++) {
                num1 = generate_number(digits);
                num2 = generate_number(digits);
                p2 = spaces2(digits + 1 - count_digits(num1 + num2));
                fprintf(f, ",%s = %d - %d%s", p,num1,num1+num2,p2);
                free(p2);
            }
            fprintf(f, "\n\n");
            break;
        case 2:
            for (r = 1; r <= 3; r++) {
                num1 = generate_number(digits);
                num2 = generate_number(digits);
                p2 = spaces2(digits + 1 - count_digits(num1 + num2));
                fprintf(f, ",%s = %d - %d%s", p, num1, num1 + num2, p2);
                free(p2);
            }
            fprintf(f, "\n\n");
            break;
        default:
            for (r = 1; r <= 2; r++) {
                num1 = generate_number(digits);
                num2 = generate_number(digits);
                p2 = spaces2(digits + 1 - count_digits(num1 + num2));
                fprintf(f, ",%s = %d - %d%s", p, num1, num1 + num2, p2);
                free(p2);
            }
            fprintf(f, "\n\n");
            break;
        }
    }
    free(p);
}
void multiply(FILE* f, int digits) {
    int i, r;
    char* p = spaces(digits * 2);
    for (i = 1; i <= 20; i++) {
        switch (digits) {
        case 1:
            for (r = 1; r <= 4; r++)
                fprintf(f, "%d * %d = %s,", generate_number(digits), generate_number(digits), p);
            fprintf(f, "%d * %d = %s", generate_number(digits), generate_number(digits), p);
            fprintf(f, "\n\n");
            break;
        case 2:
            for (r = 1; r <= 3; r++)
                fprintf(f, "%d * %d = %s,", generate_number(digits), generate_number(digits), p);
            fprintf(f, "\n\n");
            break;
        default:
            for (r = 1; r <= 2; r++)
                fprintf(f, "%d * %d = %s,", generate_number(digits), generate_number(digits), p);
            fprintf(f, "\n\n");
            break;
        }
    }
    free(p);
}
void multiply_right(FILE* f, int digits) {
    int i, r;
    char* p = spaces(digits * 2);
    for (i = 1; i <= 20; i++) {
        switch (digits) {
        case 1:
            fprintf(f, "%s = %d * %d", p, generate_number(digits), generate_number(digits));
            for (r = 1; r <= 4; r++)
                fprintf(f, ",%s = %d * %d", p, generate_number(digits), generate_number(digits));
            fprintf(f, "\n\n");
            break;
        case 2:
            for (r = 1; r <= 3; r++)
                fprintf(f, ",%s = %d * %d", p, generate_number(digits), generate_number(digits));
            fprintf(f, "\n\n");
            break;
        default:
            for (r = 1; r <= 2; r++)
                fprintf(f, ",%s = %d * %d", p, generate_number(digits), generate_number(digits));
            fprintf(f, "\n\n");
            break;
        }
    }
    free(p);
}
void divide(FILE* f, int digits) {
    int i, r, num1, num2;
    char* p = spaces(digits );
    char* p2;
    for (i = 1; i <= 20; i++) {
        switch (digits) {
        case 1:
            for (r = 1; r <= 4; r++) {
                num1 = generate_number(digits);
                num2 = generate_number(digits);
                p2 = spaces2(digits *2 - count_digits(num1 * num2));
                fprintf(f, "%s%d / %d = %s,", p2, num1 * num2, num1, p);
                free(p2);
            }
            num1 = generate_number(digits);
            num2 = generate_number(digits);
            p2 = spaces2(digits * 2 - count_digits(num1 * num2));
            fprintf(f, "%s%d / %d = %s", p2, num1 * num2, num1, p);
            fprintf(f, "\n\n");
            free(p2);
            break;
        case 2:
            for (r = 1; r <= 3; r++) {
                num1 = generate_number(digits);
                num2 = generate_number(digits);
                p2 = spaces2(digits * 2 - count_digits(num1 * num2));
                fprintf(f, "%s%d / %d = %s,", p2, num1 * num2, num1, p);
                free(p2);
            }
            fprintf(f, "\n\n");
            break;
        default:
            for (r = 1; r <= 2; r++) {
                num1 = generate_number(digits);
                num2 = generate_number(digits);
                p2 = spaces2(digits * 2 - count_digits(num1 * num2));
                fprintf(f, "%s%d / %d = %s,", p2, num1 * num2, num1, p);
                free(p2);
            }
            fprintf(f, "\n\n");
            break;
        }
    }
    free(p);
}
void divide_right(FILE* f, int digits) {
    int i, r, num1, num2;
    char* p = spaces(digits);
    char* p2;
    for (i = 1; i <= 20; i++) {
        switch (digits) {
        case 1:
            num1 = generate_number(digits);
            num2 = generate_number(digits);
            p2 = spaces2(digits * 2 - count_digits(num1 * num2));
            fprintf(f, "%s = %d / %d%s", p, num1, num1 * num2, p2);
            free(p2);
            for (r = 1; r <= 4; r++) {
                num1 = generate_number(digits);
                num2 = generate_number(digits);
                p2 = spaces2(digits * 2 - count_digits(num1 * num2));
                fprintf(f, ",%s = %d / %d%s", p, num1, num1 * num2, p2);
                free(p2);
            }
            fprintf(f, "\n\n");
            break;
        case 2:
            for (r = 1; r <= 3; r++) {
                num1 = generate_number(digits);
                num2 = generate_number(digits);
                p2 = spaces2(digits * 2 - count_digits(num1 * num2));
                fprintf(f, ",%s = %d / %d%s", p, num1, num1 * num2, p2);
                free(p2);
            }
            fprintf(f, "\n\n");
            break;
        default:
            for (r = 1; r <= 2; r++) {
                num1 = generate_number(digits);
                num2 = generate_number(digits);
                p2 = spaces2(digits * 2 - count_digits(num1 * num2));
                fprintf(f, ",%s = %d / %d%s", p, num1, num1 * num2, p2);
                free(p2);
            }
            fprintf(f, "\n\n");
            break;
        }
    }
    free(p);
}
void main(){
    int digits,oper,right_left;
    FILE* f = fopen("exersises.txt", "wt");
    srand(time(NULL));
    printf("Enter number of digits between 1-4: ");
    scanf("%d", &digits);
    puts("Enter from right to left = 1,or left to right = 2");
    scanf("%d", &right_left);
    puts("Enter arithmetic operator 1 = +,2 = -,3 = *,4 = /");
    scanf("%d",&oper);
    switch (oper) {
    case 1:
        switch (right_left) {
        case 2:
            plus(f, digits);
            break;
        default:
            plus_right(f, digits);
            break;
        }
        break;
    case 2:
        switch (right_left) {
        case 2:
            minus(f, digits);
            break;
        default:
            minus_right(f, digits);
            break;
        }
        break;
    case 3:
        switch (right_left) {
        case 2:
            multiply(f, digits);
            break;
        default:
            multiply_right(f, digits);
            break;
        }
        break;
    default:
        switch (right_left) {
        case 2:
            divide(f, digits);
            break;
        default:
            divide_right(f, digits);
            break;
        }
        break;
    }
    system("pause>0");
}