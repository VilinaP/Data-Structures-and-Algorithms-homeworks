// Name: Vilina Prenko
// Assignment number: A04
// Assignment: Dual Doubly Linked Lists 
// File name: dualdoublelist.h
// Date last modified: provided by the instructor
// Sources: provided by the instructor
#ifndef DUALDOUBLELIST_H_
#define DUALDOUBLELIST_H_

#include <string.h>

// Forward reference for a node in the dual doubly-linked list.
// This is an opaque type that clients cannot see from this header file.
struct listnode;

// Define a convenient type alias.
typedef struct listnode ListNode;


// A DualDoublyLinkedList object represents a dual doubly-linked 
// linear list.
typedef struct {
    ListNode *first;  // Points to the sentinel node at the head of the list
    ListNode *last;   // Points to the sentinel node at the tail of the list
} DualDoublyLinkedList;


// Creates a new, empty, dual doubly-linked list
DualDoublyLinkedList ddll_make_list(void);

// Properly deallocates the space held by a dual 
// doubly linked list object.
void ddll_dispose_list(DualDoublyLinkedList *list);

// Adds a new person to the list with the given last name
// and ID number. Returns 1 if the person was successfully 
// inserted; otherwise, returns 0.
// The only things preventing a successful insertion are an
// attempt to enter a duplicate ID number or not having enough
// memory.
int ddll_insert(DualDoublyLinkedList *list, const char *name, int id);

// Removes the person with the given ID number. Returns 1
// if the person was removed; otherwise, returns 0.
int ddll_remove(DualDoublyLinkedList *list, int id);

//  Print the contents of the list in order by ID number
void ddll_print_by_ID(const DualDoublyLinkedList *list);

//  Print the contents of the list in reverse order by ID number
void ddll_print_by_ID_reverse(const DualDoublyLinkedList *list);

//  Print the contents of the list in order by last name
void ddll_print_by_name(const DualDoublyLinkedList *list);

//  Print the contents of the list in reverse order by last name
void ddll_print_by_name_reverse(const DualDoublyLinkedList *list);

#endif
