#ifndef HASHBAT_H
#define HASHBAT_H

#define SIZE 256

/* Define a struct for Hash */
typedef struct {
    int line[SIZE]; 
    int flag;
    int flagList[SIZE];
} FileReader;

typedef struct {
    int list[SIZE]; 
} LineList;

#endif