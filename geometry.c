#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define K 50

int main()
{
    int R;
    float S = 0, P = 0;

    FILE *psyh = NULL;

    char arr[K] = {0};
    char a[K] = {0};

    psyh = fopen("text.txt", "r");
    if(!psyh) {
        printf("Cant open the file\n");
    } else {
        int i = 0;

        while(i < K) {
            fscanf(psyh, "%c", &a[i]);
            ++i;
        }
    }

    fclose(psyh);

    int j = 0;
    for(int i = 0; i < K - 1; i++) {
        if((a[i] == '(') || (a[i] == ' ') || (a[i] == ',')) {
            arr[j] = a[i + 1];
            j++;
        };
        if(a[i] == ')') {
            break;
        };
    }

    R = arr[3] - '0';
    S = M_PI * R * R;
    P = 2 * M_PI * R;

    for(int i = 0; i < K; i++) {
        printf("%c", a[i]);
    }

    printf("\n");
    printf("area = %.2f\n", S);
    printf("perimeter = %.2f\n", P);

    return 0;
}