
#include "geometry.h"

float area(float radius)
{
    return (M_PI * radius * radius);
}

float perimetr(float radius)
{
    return (2 * M_PI * radius);
}

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
        || (input_array[s] == '.') || (input_array[s] == '-')) {
        j++;
    } else {
        while (input_array[s] != ' ') {
            if ((input_array[s] == ',') || (input_array[s] == '-')
                || (input_array[s] == '.')) {
                j++;
            }
            if ((input_array[s] != '-')
                && (!(((input_array[s] <= '9') && (input_array[s] >= '0'))
                      || (input_array[s] != '.')))
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
                      || (input_array[s] != '.')))
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
                      || (input_array[s] != '.')))
                && (input_array[s] != ' ')) {
                j++;
                break;
            } else {
                s++;
            }
        }
    }

    if (j > 0) {
        j = 1;
    }

    return j;
}

void circle_intersects(int circles_number, struct circle* circles_data)
{
    for (int k = 1; k < circles_number; k++) {
        for (int j = k + 1; j < circles_number + 1; j++) {
            double m = abs(circles_data[k].x - circles_data[j].x);
            double s = abs(circles_data[k].y - circles_data[j].y);

            if (sqrt(m * m + s * s)
                <= (circles_data[k].r + circles_data[j].r)) {
                printf("Circle №%d intersects Circle №%d \n", k, j);
            }
        }
    }
}