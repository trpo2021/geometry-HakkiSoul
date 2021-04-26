#include <libgeometry/geometry.h>
#define K 40

int main()
{
    struct circle circles_data[K];

    int circles_number = 0;

    FILE* fuf = NULL;

    fuf = fopen("text.txt", "r");

    if (!fuf) {
        printf("Can`t open the file\n");
    } else {
        while (!feof(fuf)) {
            char x_array[K] = {0};
            char y_array[K] = {0};
            char r_array[K] = {0};

            char input_array[K] = {0};

            fgets(input_array, 40, fuf);
            printf("\n");

            int s = 7;
            int check_1 = 0, check_2 = 0;

            if ((check_1 = figur_name_check(input_array)) > 0) {
                for (int i = 0; i < K; i++) {
                    printf("%c", input_array[i]);
                }
                printf("Invalid name of figure\n");
            } else {
                if ((check_2 = data_check(s, input_array)) > 0) {
                    for (int i = 0; i < K; i++) {
                        printf("%c", input_array[i]);
                    }
                    printf("Invalid value\n");
                } else {
                    for (int i = 0; i < K; i++) {
                        if (input_array[i] == '(') {
                            for (int k = i; input_array[k + 1] != ' '; k++) {
                                x_array[k - i] = input_array[k + 1];
                            }
                        }

                        if (input_array[i] == ' ') {
                            for (int k = i - 1; input_array[k] != ','; k++) {
                                y_array[k - i] = input_array[k];
                            }
                        }

                        if ((input_array[i] == ',')
                            && (input_array[i + 1] == ' ')) {
                            for (int k = i; input_array[k + 1] != ')'; k++) {
                                r_array[k - i] = input_array[k + 1];
                            }
                        }
                    }

                    circles_number++;

                    float radius = atof(r_array);
                    float a = 0, p = 0;

                    circles_data[circles_number].x = atof(x_array);
                    circles_data[circles_number].y = atof(y_array);
                    circles_data[circles_number].r = radius;

                    a = area(radius);
                    p = perimetr(radius);

                    printf("Circle №%d: ", circles_number);

                    for (int i = 0; i < K; i++) {
                        printf("%c", input_array[i]);
                    }

                    printf("\n");
                    printf("area = %.2f\n", a);
                    printf("perimeter = %.2f\n", p);
                }
            }
        }
    }

    fclose(fuf);
    printf("\n");

    if (circles_number > 1) {
        circle_intersects(circles_number, circles_data);
    }

    return 0;
}