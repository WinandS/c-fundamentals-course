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
list * list_append(list * l, element * list_element);
void print(list * l);


int main(int argc, char * argv[]){
    element * el1 = init_element(1, NULL, NULL);
    element * el2 = init_element(2, NULL, NULL);
    element * el3 = init_element(3, NULL, NULL);
    element * el4 = init_element(3, NULL, NULL);
    element * el5 = init_element(3, NULL, NULL);

    list * l = list_init(el1);
    list_append(l,el2);
    list_append(l,el3);
    list_append(l,el4);
    list_append(l,el5);
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
    return l;
}

list * list_append(list * l, element * list_element){
    list * le = l;
    int i =0;
    while(le->first_element->next!=NULL){
        i++;
//        printf("%i\n",i);
        le->first_element = le->first_element->next;
    }
    le->first_element->next = list_element;
    list_element->previous = le->first_element;
    list_element->previous = NULL;
    return l;
}

void print(list * l){
    int i=0;
    printf("Value of element %i: %i\n",i,l->first_element->a);
//    while(l->first_element->next!=NULL){
//        printf("Value of element %i: %i\n",i,l->first_element->a);
//    }
}
