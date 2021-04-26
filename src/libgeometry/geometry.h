#pragma once

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define pi 3.1416

struct circle {
    float x;
    float y;
    float r;
};

int figur_name_check(char* input_array);

int data_check(int s, char* input_array);

float area(float radius);

float perimetr(float radius);

void circle_intersects(int circles_number, struct circle* circles_data);