#include <stdio.h>
#include <stdlib.h>
#include "func.h"
int main(){
	perfume *perfumes = NULL;
	int quantity=0;
	int flag=1;
	int tempKey=0;
	while(flag){
		int key = 0;
		key += tempKey;
		tempKey = 0;
		if (!key){
		    printf("Меню:\n");
            printf("1. Создание базы данных\n");
            printf("2. Загрузка базы данных\n");
            printf("3. Поиск по базе данных\n");
            printf("0. Выход\n");
            printf("Выберите вариант: ");
			scanf("%i", &key);
		}
		switch (key){
			case 1:{
				int key2;
				printf("1. Создать новую базу данных\n");
                printf("2. Загрузить существующую базу данных\n");
				scanf("%i", &key2);
				if (key2==1){	
					create(&perfumes, &quantity);
					if(perfumes==NULL){
						printf("Ошибка создания\n");
						flag = 0;
						break;
					}
					else{
						printf("Создано %d записей\n\n", quantity);
					}
					write(perfumes,quantity);
					}
				else if(key2==2){
					read(&perfumes, &quantity);
					if(perfumes==NULL){
						printf("Ошибка чтения\n");
						flag = 0;
						break;
					}
					else{
						printf("Загружено %d записей\n\n", quantity);
					}
				}
				break;
			}
			case 2:
				if(perfumes==NULL){
						int key3;
						printf("База данных не найдена. Создать новую?\n");
						printf("1-Да\n");
						printf("2-Нет\n");
						scanf("%i", &key3);
						if(key3==1) 
						    tempKey=1;
						else 
						    flag = 0;
						break;
					}
					else{
						for(int i = 0; i<quantity; i++){
					    printf("Название: %s;\n", perfumes[i].name);
						printf("Цена: %f;\n", perfumes[i].price);
						printf("Цвет: %s;\n", perfumes[i].colour);
						printf("\n");
					}
				
				break;
			case 3:
				if(perfumes==NULL) 
					{
						int key3;
						printf("База данных не найдена. Создать новую?\n");
						printf("1-Да\n");
						printf("2-Нет\n");
						scanf("%i", &key3);
						if(key3==1) 
						    tempKey=1;
						else 
						    flag = 0;
						break;
					}
					else
					{
						search(perfumes,quantity);
					}
				break;
			default:
				flag = 0;
				break;
		}
	}
	if (perfumes) 
	    free(perfumes);
    return 0;
}
