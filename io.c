/****************************************************************
 * File:    hash.c
 * Author:  Group 6: CS125
 * Purpose: Implementation of the file IO module
 * Date:    4/9/2025
 ***************************************************************/
#include "io.h"
#include "hash.h"
#include <string.h>

char *find_word_by_hash(FILE *f, uint32_t hash) {
  /* Allocate the word we are searching for */
  char *word = (char *)malloc(sizeof(char) * WORD_SIZE);

  while (fgets(word, WORD_SIZE, f)) {
    /* Remove newline char, it will change the hash */
    word[strlen(word) - 1] = 0;

    /* hashes match! Happy dance! */
    uint32_t cur_hash = djb2(word);
    if (cur_hash == hash) {
      return word;
    }
  }

  /* Nothing was found. Sad dance :( */
  return NULL;
}
