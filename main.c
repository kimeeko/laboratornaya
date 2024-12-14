#include "lab.h"

int main()
{
        char file[]="igri1";
        ni* current=NULL;
        int n;
        int x;
        list l;
        l.first = NULL;
        l.last = NULL;
        l.n = 0;
        load(&l, "igri1");
        product(&l);
        printf("Choose action:\n");
        printf("1-Show the contents of the file:\n");
        printf("2-File search\n");
        printf("3-Add a new element\n");
        printf("4-Delete an element\n");
        printf("5-Edit an element\n");
        printf("0-End the program\n");
        scanf("%i", &x);
while(x!=0){
        if (x == 1)
        {
                product(&l);
        }
        if (x == 2)
        {
                search(&l, n);
                product(&l);
        }
        if (x == 3)
        {
                char name[20];
                char type[20];
                int min_age;
                char complexity[20];
                int max_players;
                int price;
                puts("Add a product");
                puts("name= ");
                scanf("%s", name);
puts("type= ");
                scanf("%s", type);
                puts("min_age= ");
                scanf("%i", &min_age);
                puts("complexity= ");
                scanf("%s", complexity);
                puts("max_players= ");
                scanf("%i", &max_players);
                puts("price= ");
                scanf("%i", &price);
                push(&l, name, type, min_age, complexity, max_players, price); 
                product(&l);
        }
        if (x == 4)
        {
                puts("removing index");
                int index;
                scanf("%i", &index);
                deletes(&l, index);
                product(&l);
        }
if (x == 5)
        {
                int index;
                puts("edit index");
                scanf("%i", &index);
                edit(&l);
                product(&l);
                while(current)
                {
                        ni*temp = current -> next;
                        free(current);
                        current = temp;
                }
        }
        scanf("%i", &x);
        }
        return 0;
}
