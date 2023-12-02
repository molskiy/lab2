#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include <string.h>
void searchDatabase(){
    FILE *file = fopen("database.txt", "r");
    if (file == NULL) {
        printf("Ошибка при открытии файла\n");
        return;
    }
    int quantity;
    fread(&quantity, sizeof(int), 1, file);
    perfume *perfumes = (perfume *) malloc(quantity * sizeof(perfume));
    if (perfumes == NULL){
        printf("Ошибка выделения памяти\n");
        return;
    }
    fread(perfumes, sizeof(perfume), quantity, file);
    char searchName[50];
    printf("Введите название товара для поиска: ");
    scanf("%s", searchName);
    int found = 0;
    for (int i = 0; i < quantity; i++) {
        if (strcmp(perfumes[i].name, searchName) == 0) {
            printf("Товар %d:\n", i + 1);
            printf("Название: %s\n", perfumes[i].name);
            printf("Цена: %.2f\n", perfumes[i].price);
            printf("Характеристики: %s\n\n", perfumes[i].colour);
            found = 1;
        }
    }
    if (!found)
        printf("Товар с названием %s не найден\n", searchName);
    free(perfumes);
    fclose(file);
}
