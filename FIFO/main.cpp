// zad 5_1 FIFO
// Katarzyna Borkowska 7 Y1S1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int v;
    struct node *next;
}node;

node *head = NULL;
int IsEmpty(){
 if(head == NULL) return 1;
 else
     return 0;
}
bool Push() {
    node *nowenode = new node;
    if (nowenode == NULL) return false;

    nowenode->next = NULL;
    printf("Elm ktory chcesz dodac to: ");
    scanf("%d",&nowenode->v);
    if(IsEmpty())
        head = nowenode;
    else
    {
        node *nowenode2 = head;
        while(nowenode2->next != NULL)
            nowenode2 = nowenode2->next;

        nowenode2->next = nowenode;
        return true;
    }
    return false;
}

void Pop(){
    if(IsEmpty())
       printf("Kolejka jest pusta\n");
    else{

        node *tmp = head;
        node *pop = tmp;
        tmp = tmp->next;
        free(pop);
        head = tmp;
    }
}
void Front() {

    if(IsEmpty())
       printf("Kolejka jest pusta\n");
    else
        printf("Front = %d\n",head->v);
}
void Clear(){
    while(IsEmpty() != 1)
        Pop();
}

int main() {
    int n = -1;
    printf("Wybierz czynnosc:\n"
           "1 - odczytuje element z poczatku listy\n"
           "2 - wstawia element na koniec listy\n"
           "3 - usuwa element z poczatku listy\n"
           "4 - sprawdza czy lista jest pusta\n"
           "5 - czysci liste\n"
           "0 - KONIEC\n");
    while(n != 0)
    {
        scanf("%d",&n);
        switch (n) {
            case 1:
                Front();
                break;
            case 2:
                Push();
                break;
            case 3:
                Pop();
                break;
            case 4:
                if(IsEmpty() == 1)
                    printf("Lista jest Pusta\n");
                else
                    printf("Lista nie jest Pusta\n");
                break;
            case 5:
                Clear();
                printf("Wyczyszczone.\n");
                break;
                
            default:
                break;
        }
    }
    return 0;
}
