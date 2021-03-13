#ifndef PERSON_H
#define PERSON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int isSet;
    char name[100];
    char email[100];
}person_t;

void set_person(char* argv[], person_t* person)
{
    if(strcmp("-n", argv[1]) == 0) {
        strcpy(person->name, argv[2]);
    }

    if(strcmp("-n", argv[3]) == 0) {
        strcpy(person->name, argv[4]);
    }

    if(strcmp("-e", argv[1]) == 0) {
        strcpy(person->email, argv[2]);
    }

    if(strcmp("-e", argv[3]) == 0) {
        strcpy(person->email, argv[4]);
    }

    person->isSet = 1;
}

void print_person(person_t* person) {
    printf("Name: %s \n", person->name);
    printf("Email: %s \n", person->email);
}

#endif