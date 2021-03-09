#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define K 50

int figure_name_check(char* input_array)
{
    char figure[6] = "Circle";
    int i = 0;
    int k = 0;

    for(i = 0; i < 6; i++) {
        if(input_array[i] != figure[i]) {
            k = k + 1;
            break;
        }
    }

    return k;
}

int data_check(int s, char* input_array)
{
    int j = 0;
    if(input_array[s] == ' ') {
        j++;
    } else {
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
            } else {
                s++;
            }
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
    }

    return j;
}

int main()
{
    char array[K];
    char input_array[K] = {0};

    FILE *psyh = NULL;

    psyh = fopen("text.txt", "r");
    
    int i;

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

    int k = 0;
    
    k = figure_name_check(input_array);

    int s = 7;
    int j = 0;
    int m;
    
    m = data_check(s, input_array);

    if (k > 0) {
        for(j = 0; j < K; j++) {
            printf("%c", input_array[j]);
        }

        printf("\n");
        printf("Invalid figure name\n");

    } else {
        if (m > 0) {
            for(m = 0; m < K; m++) {
                printf("%c", input_array[m]);
            }

            printf("\n");
            printf("Invalid value\n");

        } else {
            for (m = 0; m < K; m++) {
                if ((input_array[m] == ',') && (input_array[m + 1] == ' ')) {
                    for (k = m; input_array[k + 1] != ')'; k++) {
                        array[k - m] = input_array[k + 1];
                    }
                }

            }

            float area = 0, perimetr = 0;
            int radius = 0;

            radius = atoi(array);
            area = M_PI * radius * radius;
            perimetr = 2 * M_PI * radius;

            for(m = 0; m < K; m++) {
                printf("%c", input_array[m]);
            }

            printf("\n");
            printf("perimeter = %.3f\n", perimetr);
            printf("area = %.3f\n", area);
        }

    }

    return 0;
}