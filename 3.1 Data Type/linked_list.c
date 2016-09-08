#include <stdio.h>
#include <stdlib.h>


/*
 * UNFINISHED
 */

typedef struct element element;
typedef struct list list;

struct element {
    int a;
    element * next;
    element * previous;
};

struct list{
    element * first_element;
};

element * init_element(int a, element * previous, element * next);
list * list_init(element * el);
int list_append(list * l, element * list_element);
void print(list * l);


int main(int argc, char * argv[]){
    element * el0 = init_element(0, NULL, NULL);
    element * el1 = init_element(1, NULL, NULL);
    element * el2 = init_element(2, NULL, NULL);
    element * el3 = init_element(3, NULL, NULL);
    element * el4 = init_element(4, NULL, NULL);

    list * l = list_init(el0);
    list_append(l,el1);
    list_append(l,el2);
    list_append(l,el3);
    list_append(l,el4);
    print(l);

    exit(0);
}


element * init_element(int a, element * previous, element * next){
    element * el = malloc(sizeof(element));
    el->a = a;
    el->previous = previous;
    el->next = next;
    return el;
}

list * list_init(element * first_element){
    list * l = malloc(sizeof(l));
    l->first_element = first_element;
    printf("Initialised list with value %i for element 0\n",first_element->a);
    return l;
}

int list_append(list * l, element * list_element) {
    list * lc = l;
    static int i =1;
    static element * last_element;
    if(lc->first_element->next==NULL){
        lc->first_element->next = list_element;
        list_element->previous = lc->first_element;
        printf("First element to be appended:\n"
               "Value of element %i: %i\n",i++,list_element->a);
        last_element = list_element;
        return 0;
    } else {
        printf("Value of element %i: %i\n",i++,list_element->a);
        last_element->next = list_element;
        list_element->previous = last_element;
        list_element->next = NULL;
        last_element=last_element->next;
        return 1;
    }
}

void print(list * l){
    printf("\nPrinting values\n");

    int i=0;
    element * el = l->first_element;
    if(el!=NULL){
        do{
            printf("Value of element %i: %i\n",i++,el->a);
            el=el->next;
        } while (el!=NULL);

    } else {
        printf("This is an emtpy list.\n");
    }
}


