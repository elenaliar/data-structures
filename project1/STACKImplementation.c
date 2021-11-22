//
//  filename: STACKImplementation.c
//  askisi4 protis ergasias


#include <stdio.h>
#include <stdlib.h>
#include "Item.h"

typedef struct STACKnode* link;//stack.h
struct STACKnode{
    letter let;
    link next;
};
static link head;

link NEW(letter let, link next){//implementation.c
    link x = malloc(sizeof*x);
    x->let=let;
    x->next = next;
    return x;
}

void STACKinit(int maxN){
    head = NULL;
}

int STACKempty(){
    return head == NULL;
}

void STACKpush(letter let){
    head = NEW(let, head);
}

letter STACKpop(){
    letter let;
    let = head->let;
    link t= head->next;
    free(head);
    head=t;
    return let;
}
