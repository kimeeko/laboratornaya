include "lab1.h"

void push(list*l, char * name, char * type, int min_age, char * complexity, int max_players, int price)
{
        ni * new = (ni*) malloc (sizeof(ni));
        strcpy(new->name, name);
        strcpy(new->type, type);
        new -> min_age = min_age;
        strcpy(new->complexity, complexity);
        new -> max_players = max_players;
        new -> price = price;
        new->next=NULL;
        if(l->n == 0)
        {
                l->first = new;
        }
        else
        {
                l->last->next = new;
        }
        l->last = new;
        l->n++;
}

void load(list * l, const char *  igri1)
{
        FILE *f=fopen(igri1, "r");
        if (!f)
        {
                puts("ERROR! Open another file");
                return;
        }
        char name[20];
        char type[20];
        int min_age;
        char complexity[20];
        int max_players;
        int price;

        while (fscanf(f, "%19s %19s %i %19s %i %i", name, type, &min_age, complexity, &max_players, &price)==6)
        {
                push(l, name, type, min_age, complexity, max_players, price);
        }
fclose(f);
}

void product(list *l)
{
        ni * current = l -> first;
        while(current)
        {
                printf("%i: name = %s, type = %s, min_age = %i, complexity = %s, max_players = %i, price = %i\n", curr>
                current = current -> next;
        }
}

ni * get(list * l, int index)
{
         if(index < 0 || index > l->n-1)
        {
                return NULL;
        }
        ni * current = l->first;
        for(int i = 0; i < index; i++)
{
                current = current -> next;
        }
        return current;
}


void deletes(list *l, int index)
{
        if(l->n == 0)
        {
                return;
        }
        if(index < 0 || index > l -> n-1)
        {
                return;
        }
        if(index == 0)
        {
                ni* temp = l -> first;
                l -> first = temp -> next;
free(temp);
        }
        else
        {
                ni * prev = get(l, index - 1);
                if(prev)
                {
                        return;
                }
                ni * current = prev -> next;
                if(current == l->last)
                {
                        prev -> next = NULL;
                        l -> last = prev;
                        free(current);
                }
                else
                {
                        prev -> next = current -> next;
                        free(current);
                }
}
    l -> n--;
}

void search(list *l, int n)
{
        ni *current = l->first;
        char type[20];
        int min_age;
        printf("Enter the product type:\n");
        scanf("%19s", type);
        printf("Enter the minimum age of the player:\n");
        scanf("%i", &min_age);
        printf("Results:\n");
        for (int i=0; i<n; i++)
        {
                current=current->next;
                if ((strcmp(current->type, type)==0) && ((current->min_age)==min_age))
                {
                        printf("%i %19s %19s %i %19s %i %i",i, current->name, current->type, current->min_age, current->complexity, current->max_players, current->price);
                }
        }
}

void edit(list *l)
{
        ni* current=NULL;
        int y;
        product(l);
        printf("Enter number product:\n");
        scanf("%i", &y);
        current = l->first;
        for (int i=0; i<y; i++)
        {
                current=current->next;
                printf("Enter new name:\n");
                scanf("%19s",current->name);
                printf("Enter new type:\n");
                scanf("%19s", current->type);
                printf("Enter new min_age:\n");
                scanf("%i", &(current->min_age));
                printf("Enter new complexity:\n");
                scanf("%19s", current->complexity);
                printf("Enter new max_players:\n");
                scanf("%i", &(current->max_players));
                printf("Enter new price:\n");
                scanf("%i", &(current->price));
        }
}
