#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nastolki
{
        char name[20];
        char type[20];
        int min_age;
        char complexity[20];
        int max_players;
        int price;
        struct nastolki *next;
}ni;

typedef struct list
{
        ni * first;
        ni * last;
        int n;
}list;
void product(list*l);
void push(list*l, char * name, char * type, int min_age, char * complexity, int max_players, int price);
void load(list * l, const char *  igri1)
void deletes(list*l, int index)
void search(list *l, int n)
void edit(list *l)
