#include <stdio.h>
#include <stdlib.h>
#include "func.h"
void createDatabase() {
    FILE *file = fopen("database.txt", "w");
    if (file == NULL) {
        printf("Ошибка при открытии файла\n");
        return;
    }
    int quantity;
    printf("Введите количество товаров в базе данных: ");
    scanf("%d", &quantity);
    Perfume *perfumes = (Perfume *) malloc(quantity * sizeof(Perfume));
    if (perfumes == NULL) {
        printf("Ошибка выделения памяти\n");
        return;
    }
    for (int i = 0; i < quantity; i++) {
        printf("Товар %d:\n", i + 1);
        printf("Название: ");
        scanf("%s", perfumes[i].name);
        printf("Цена: ");
        scanf("%f", &perfumes[i].price);
        printf("Характеристики: ");
        scanf("%s", perfumes[i].characteristics);
    }
    fwrite(&quantity, sizeof(int), 1, file);
    fwrite(perfumes, sizeof(Perfume), quantity, file);
    free(perfumes);
    fclose(file);
    printf("База данных успешно создана и записана в файл\n");
}
void loadDatabase() {
    FILE *file = fopen("database.txt", "r");
    if (file == NULL) {
        printf("Ошибка при открытии файла\n");
        return;
    }
    int quantity;
    fread(&quantity, sizeof(int), 1, file);
    Perfume *perfumes = (Perfume *) malloc(quantity * sizeof(Perfume));
    if (perfumes == NULL) {
        printf("Ошибка выделения памяти\n");
        return;
    }
    fread(perfumes, sizeof(Perfume), quantity, file);
    printf("База данных:\n");
    for (int i = 0; i < quantity; i++) {
        printf("Товар %d:\n", i + 1);
        printf("Название: %s\n", perfumes[i].name);
        printf("Цена: %.2f\n", perfumes[i].price);
        printf("Характеристики: %s\n\n", perfumes[i].characteristics);
    }
    free(perfumes);
    fclose(file);
}
int main() {
    int choice;
    do {
        printf("Меню:\n");
        printf("1. Создание базы данных\n");
        printf("2. Загрузка базы данных\n");
        printf("3. Вывод содержимого базы данных\n");
        printf("4. Поиск по базе данных\n");
        printf("0. Выход\n");
        printf("Выберите вариант: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createDatabase();
                break;
            case 2:
                loadDatabase();
                break;
            case 3:
                loadDatabase();
                break;
            case 4:
                searchDatabase();
                break;
        }
    } while (choice != 0);
    return 0;
}
