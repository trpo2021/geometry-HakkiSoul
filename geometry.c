#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define K 50

int main()
{
    int radius = 0;
    int i, j, k; //счётчики
    char figure[6] = "Circle";
    char array[K];
    char input_array[K] = {0};
    float area = 0, perimetr = 0;

    FILE *psyh = NULL;

    psyh = fopen("text.txt", "r");
    if (!psyh) {
        printf("Cant open this file\n");
    } else {
        i = 0;
        while (i < K) {
            fscanf(psyh, "%c", &input_array[i]);
            ++i;
        }
    }

    fclose(psyh);

    k = 0;
    for(i = 0; i < 6; i++) {
        if(input_array[i] != figure[i]) {
            k = k + 1;
            break;
        }
    }

    int s = 7;
    j = 0;
    while (input_array[s] != ' ') {
        if ((input_array[s] != '-') && (!(((input_array[s] <= '9') && (input_array[s] >= '0')) || (input_array[s] == '.'))) && (input_array[s] != ' ')) {
            j++;
            break;
        } else {
            s++;
        }
    }


    while ((input_array[s] != ',') && (input_array[s + 1] != ' ')) {
        if ((input_array[s] != '-') && (!(((input_array[s] <= '9') && (input_array[s] >= '0')) || (input_array[s] == '.'))) && (input_array[s] != ' ')) {
            j++;
            break;
        }
        s++;
    }

    if (input_array[s + 1] != ' ') {
        s++;
    }

    s++;

    while (input_array[s] != ')') {
        if ((input_array[s] != '-') && (!(((input_array[s] <= '9') && (input_array[s] >= '0')) || (input_array[s] == '.'))) && (input_array[s] != ' ')) {
            j++;
            break;
        } else {
            s++;
        }
    }

    if (k > 0) {
        for(j = 0; j < K; j++) {
            printf("%c", input_array[j]);
        }
        printf("incorrect figure name\n");
    } else {
        if (j > 0) {
            for(j = 0; j < K; j++) {
                printf("%c", input_array[j]);
            }
            printf("incorrect value\n");
        } else {
            for (j = 0; j < K; j++) {
                if ((input_array[j] == ',') && (input_array[j + 1] == ' ')) {
                    for (k = j; input_array[k + 1] != ')'; k++) {
                        array[k - j] = input_array[k + 1];
                    }
                }

            }

            radius = atoi(array);
            area = M_PI * radius * radius;
            perimetr = 2 * M_PI * radius;

            printf("\n");
            for(j = 0; j < K; j++) {
                printf("%c", input_array[j]);
            }

            printf("\n");
            printf("perimeter = %.3f\n",perimetr);
            printf("area = %.3f\n",area);
        }

    }

    return 0;
}