#pragma once

struct stocks {
    char stock[10];
    int z, p, v, r;
};

int filling();
void outputting(int);
void recording(int);
int read();
void edit(int);
