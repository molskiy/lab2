#include <stdio.h>
#include <stdlib.h>
#include "func.h"
void create(perfume **perfumes, int *quantity){
    printf("Введите количество товаров в базе данных: ");
    scanf("%d", quantity);
    if(*quantity<=0) return;
	*perfumes = (perfume *)calloc(*quantity, sizeof(perfume));
    if (perfumes == NULL){
        printf("Ошибка выделения памяти\n");
        return;
    }
	for (int i = 0; i < *quantity; i++){
        printf("Товар %d:\n", i + 1);
        printf("Название: ");
        scanf("%s", (*perfumes[i]).name);
        printf("Цена: ");
        scanf("%f", &(*perfumes[i]).price);
        printf("Характеристики: ");
        scanf("%s", (*perfumes[i]).colour);
  }
}
void read(perfume **perfumes, int *quantity){
	FILE *file = fopen("database.txt","r");
	if(!file) return;
	if(fscanf(file,"%d",quantity)!=1){
		fclose(file);
		return;
	};
	*perfumes = (perfume *)calloc(*quantity, sizeof(perfume));
	for(int i = 0; i < *quantity; i++){
		if(fscanf(file, "%s %f %s", (*perfumes)[i].name, &(*perfumes)[i].price, (*perfumes)[i].colour)!=3) break;
	};
	fclose(file);
}
void write(perfume *perfumes, int quantity){
	if(quantity<=0) return;
	FILE *file = fopen("database.txt", "w");
	if (file == NULL){
        printf("Ошибка при открытии файла\n");
        return;
	};
	fprintf(file, "%i\n" ,quantity);
	for(int i = 0; i < quantity; i++){
		fprintf(file, "%s %f %s\n" ,perfumes[i].name, perfumes[i].price, perfumes[i].colour);
	}
	fclose(file);
};
