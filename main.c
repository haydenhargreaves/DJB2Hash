/****************************************************************
 * File:    hash.c
 * Author:  Group 6: CS125
 * Purpose: Main application
 * Date:    4/6/2025
 ***************************************************************/

#include "hash.h"
#include "io.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define WORD_LIST "word-list-extra-large.txt"

int main() {
  /*
  const char *string1 = "hello";
  const char *string2 = "world";
  const char *string3 = "Hello";
  const char *string4 = "zysk";

  printf("Case-sensitive Hash of \"%s\": %u\n", string1, djb2(string1));
  printf("Case-sensitive Hash of \"%s\": %u\n", string2, djb2(string2));
  printf("Case-sensitive Hash of \"%s\": %u\n", string3, djb2(string3));
  printf("Case-sensitive Hash of \"%s\": %u\n", string4, djb2(string4));
  */

  /* Open words list */
  FILE *f = fopen(WORD_LIST, "r");
  if (f == NULL) {
    printf("Failed to located word list file: %s. Exit 1.\n", WORD_LIST);
    return 1;
  }

  /* hash for: world */
  uint32_t hash = 279393645;

  /* Search for a word provided a hash */
  char *word = find_word_by_hash(f, hash);
  if (word == NULL) {
    printf("Failed to locate a match. Hash: %d. Exit 1.\n", hash);

    fclose(f);
    return 1;
  }

  printf("Located match: %s\n", word);
  fclose(f);

  return 0;
}
