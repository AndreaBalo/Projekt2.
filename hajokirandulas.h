#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#ifndef PROJEKT2_HAJOKIRANDULAS_H
#define PROJEKT2_HAJOKIRANDULAS_H

typedef struct person
{
    char *firstName;
    char *lastName;
    int ID;
    int szemelyekSzama;
}Person;
typedef struct Date
{
    int day;
    int month;
    int year;
}Date;
typedef struct Node
{
    int ID;
    struct Date date;
    struct Node *left, *right;
} Node;
Node *create();
void insert(Node ** root,Date,int);
void inorder(Node *root);
int compareDate(Date,Date);
bool isValidDate(int year,int month,int day);
Person *insertPerson(Person * persons,const char *firstname,const char* lastname,int counter,int szemelyszam);
Person *createPerson();
int leapYear(int year);
bool search(Node *root,Date date);
int returnID(Node *root,Date date);
Node * minValueNode(Node * node);
Node* deleteNode( Node* root, Date key);
Date  formatToDate(int year,int month,int day);
#endif //PROJEKT2_HAJOKIRANDULAS_H
