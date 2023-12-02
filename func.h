#include <stdio.h>
#include <stdlib.h>
typedef struct Perfume{
    char name[50];
    float price;
    char characteristics[50];
} Perfume;
void create(Perfume **perfumes, int *quantity);
void write(Perfume *perfumes, int quantity);
void read(Perfume **perfumes, int *quantity);
void search(Perfume *perfumes, int quantity);
