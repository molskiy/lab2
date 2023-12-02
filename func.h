typedef struct perfume{
    char name[50];
    float price;
    char colour[100];
} perfume;
void create(perfume **perfumes, int *quantity);
void write(perfume *perfumes, int quantity);
void read(perfume **perfumes, int *quantity);
void search(perfume *perfumes, int quantity);
