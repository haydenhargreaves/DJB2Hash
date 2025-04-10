#define _GNU_SOURCE   
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hashbat.h"

#define LIST 40
#define MAX_LINE_LENGTH 256

FileReader* fileAnalyzer(FileReader* r) {
    FILE *file = NULL;
    char fileName[SIZE];  
    LineList* l = (LineList*)malloc(sizeof(LineList)); 
    if (l == false) {
        printf("the cant allocate error 1\n");
        free(l);
        return NULL;
    }

    r = (FileReader*)malloc(sizeof(FileReader));
        if (r == false) {
            printf("the cant allocate error 2\n");
            fclose(file);
            free(l);
        return NULL;
    }
    
    printf("Enter file name: ");
    scanf("%s", fileName);

    file = fopen(fileName, "r");
    if (file == false) {
        printf("the couldmnt find file error.\n");
        free(l);
        return NULL;
    }

    char* line = NULL;
    size_t len = 0;
    size_t read;
    int i = 0;

    while ((read = getline(&line, &len, file)) != -1 && i < SIZE) {
        r->line[i] = atoi(line);  
        l->list[i] = i; 
        i++;
    }


    free(line);
    fclose(file);

    return r;
}

void crackAnalyzer(LineList* l, FileReader* r){
    FILE *rTable = NULL;
    char crackTable[SIZE];


    printf("Enter rainbow table file: ");
    scanf("%s", crackTable);

    rTable = fopen(crackTable, "r");
    if (rTable == false) {
        printf("the couldmnt find file error.\n");
        free(l);
        return NULL;
    }
   
    if (l == false) {
        printf("the couldnmnt allocate like anything error");
        return NULL;
}
    char* line = NULL;
    size_t len = 0;
    size_t read;
    int i = 0;
    int compare = 0;
    int g = 0;

    while ((read = getline(&line, &len, rTable)) != -1 && i < SIZE) {
        // Split the line from rainbow table into words (assuming space-separated)
        char* word = strtok(line, " \n");  // Tokenize line into words (splitting by space or newline)
        
        while (word != NULL) {
            // Generate the hash of the current word
            unsigned long currentHash = djb2(word);

            // Debug print to check the generated hash
            printf("Hash of word '%s': %lu\n", word, currentHash);

            // Compare the generated hash against previously stored hashes
            for (g = 0; g < i; g++) {
                if (currentHash == l->list[g]) {
                    printf("Found hash! Word '%s' with hash %lu matches stored hash %lu\n", word, currentHash, l->list[g]);
                }
            }

            word = strtok(NULL, " \n");  // Get the next word
        }
        i++;
    }

}


int main() {
    char choice[30];    

    FileReader* r = NULL;
    LineList* l = NULL;
      
   /* if (l == false) {
        printf("the cant allocate error 19\n");
        free(l);
        return NULL;
    }

    r = (FileReader*)malloc(sizeof(FileReader));
        if (r == false) {
            printf("the cant allocate error 20\n");
            free(l);
        return NULL;
    }
*/
    printf("Enter a single hash or cycle through file?(hash/file) ");
    scanf("%s", choice);
    printf("%s", choice);
    
    if (strcmp(choice, "file") == 0) {
    r = fileAnalyzer(r);
    crackAnalyzer(r, l);   

    } else if (strcmp(choice, "hash") == 0) {
      
    } else {
        printf("error!\n");
    }
    
    return 0;
}
