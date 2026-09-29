// Name: Vilina Prenko
// Assignment number: A04
// Assignment: Dual Doubly Linked Lists 
// File name: dualdoublelist.c
// Date last modified: September 28, 2026
// Sources: I coonsolted C programming textbook and class slides from chapter 4
//          for proper use of malloc and free functions. 
//          Looked up online the nessasery includes for printf and malloc functions.
//          Looked up how to use toupper() on https://www.geeksforgeeks.org/c/toupper-function-in-c/.
//          Besides the code provided by the instructor the rest of the code is mine.
//          I did not use any AI assistance 
//          for any part of this assignment.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dualdoublelist.h"

// 1. Define the ListNode type.

// 2. Add static helper functions as desired.

// 3. Implement the DualDoublyLinkedList functions 
//    declared in dualdoublelist.h.

struct listnode
{
    int id;
    char *name;
    struct listnode *prev_id;
    struct listnode *next_id;
    struct listnode *prev_name;
    struct listnode *next_name;
};

static int string_length(const char *s){
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

static int string_compare(const char *a, const char *b){
    int i = 0;
    while (a[i] != '\0' && a[i] == b[i]) {
        i++;
    }
    return (unsigned char) a[i] - (unsigned char) b[i];
}

DualDoublyLinkedList ddll_make_list(void){
    DualDoublyLinkedList list;

    list.first = malloc(sizeof(ListNode));
    list.last = malloc(sizeof(ListNode));

    if (list.first == NULL || list.last == NULL) {
        free(list.first);
        free(list.last);
        list.first = NULL;
        list.last = NULL;
        return list;
    }

    list.first->id = 0;
    list.first->name = NULL;
    list.first->prev_id = NULL;
    list.first->prev_name = NULL;
    list.first->next_id = list.last;
    list.first->next_name = list.last;

    list.last->id = 0;
    list.last->name = NULL;
    list.last->prev_id = list.first;
    list.last->prev_name = list.first;
    list.last->next_id = NULL;
    list.last->next_name = NULL;

    return list;
}

void ddll_dispose_list(DualDoublyLinkedList *list){
    ListNode *p = list->first;
    while (p != NULL) {
        ListNode *next = p->next_id;
        free(p->name);
        free(p);
        p = next;
    }
    list->first = NULL;
    list->last = NULL;
}

int ddll_insert(DualDoublyLinkedList *list, const char *name, int id)
{
    ListNode *id_next = list->first->next_id;
    while (id_next != list->last && id_next->id < id) {
        id_next = id_next->next_id;
    }
    if (id_next != list->last && id_next->id == id) {
        return 0;
    }

    ListNode *new_node = malloc(sizeof *new_node);

    if (new_node == NULL){
        return 0;
    } 

    new_node->name = malloc(string_length(name) + 1);

    if (new_node->name == NULL) {
        free(new_node);
        return 0;
    }

    int i;
    for (i = 0; name[i] != '\0'; i++) {
        new_node->name[i] = (char) toupper((unsigned char) name[i]);
    }
    new_node->name[i] = '\0';
    new_node->id = id;

    ListNode *name_next = list->first->next_name;
    while (name_next != list->last && string_compare(name_next->name, new_node->name) <= 0) {
        name_next = name_next->next_name;
    }

    new_node->prev_id = id_next->prev_id;
    new_node->next_id = id_next;
    id_next->prev_id->next_id = new_node;
    id_next->prev_id = new_node;

    new_node->prev_name = name_next->prev_name;
    new_node->next_name = name_next;
    name_next->prev_name->next_name = new_node;
    name_next->prev_name = new_node;

    return 1;
}

int ddll_remove(DualDoublyLinkedList *list, int id)
{
    ListNode *p = list->first->next_id;
    while (p != list->last && p->id < id) {
        p = p->next_id;
    }
    if (p == list->last || p->id != id) {
        return 0; 
    }

    p->prev_id->next_id = p->next_id;
    p->next_id->prev_id = p->prev_id;
    p->prev_name->next_name = p->next_name;
    p->next_name->prev_name = p->prev_name;

    free(p->name);
    free(p);
    return 1;
}

void ddll_print_by_ID(const DualDoublyLinkedList *list){
    for (ListNode *p = list->first->next_id; p != list->last; p = p->next_id){
        printf("(%s,%d)\n", p->name, p->id);
    }
}

void ddll_print_by_ID_reverse(const DualDoublyLinkedList *list){
    for (ListNode *p = list->last->prev_id; p != list->first; p = p->prev_id){
        printf("(%s,%d)\n", p->name, p->id);
    }
}

void ddll_print_by_name(const DualDoublyLinkedList *list){
    for (ListNode *p = list->first->next_name; p != list->last; p = p->next_name){
        printf("(%s,%d)\n", p->name, p->id);
    }
}

void ddll_print_by_name_reverse(const DualDoublyLinkedList *list){
    for (ListNode *p = list->last->prev_name; p != list->first; p = p->prev_name){
        printf("(%s,%d)\n", p->name, p->id);
    }
}
