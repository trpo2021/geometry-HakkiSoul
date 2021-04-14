#include "geometry.h"
#include <stdio.h>
#include <stdlib.h>

int figur_name_check(char* input_array)
{
    char figure[6] = "Circle";
    int i = 0;
    int k = 0;

    for (i = 0; i < 6; i++) {
        if (input_array[i] != figure[i]) {
            k = k + 1;
            break;
        }
    }

    return k;
}

int data_check(int s, char* input_array)
{
    int j = 0;

    if ((input_array[s] == ' ') || (input_array[s] == '(')
        || input_array[s] == '-') {
        j++;
    } else {
        while (input_array[s] != ' ') {
            if ((input_array[s] != '-')
                && (!(((input_array[s] <= '9') && (input_array[s] >= '0'))
                      || (input_array[s] == '.')))
                && (input_array[s] != ' ')) {
                j++;
                break;
            } else {
                s++;
            }
        }

        while ((input_array[s] != ',') && (input_array[s + 1] != ' ')) {
            if ((input_array[s] == '-')
                && (!(((input_array[s] <= '9') && (input_array[s] >= '0'))
                      || (input_array[s] == '.')))
                && (input_array[s] != ' ')) {
                j++;
                break;
            } else {
                s++;
            }
        }

        if (input_array[s] != ',') {
            j++;
        }

        if (input_array[s + 1] != ' ') {
            s++;
        }

        s++;
        while (input_array[s] != ')') {
            if ((input_array[s] != '-')
                && (!(((input_array[s] <= '9') && (input_array[s] >= '0'))
                      || (input_array[s] == '.')))
                && (input_array[s] != ' ')) {
                j++;
                break;
            } else {
                s++;
            }
        }
    }

    if(j > 0) {
        j = 1;
    }
    
    return j;
}