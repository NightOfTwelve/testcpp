//
// Created by ThinkPad on 2025-05-08.
//

#include <stdio.h>
#include <unistd.h>

typedef struct Point3d {
    float x;
    float y;
    float z;
} Point3d;

void Point3d_print(const Point3d *pd) {
    printf("(%f,%f,%f)",pd->x,pd->y,pd->z);
}

