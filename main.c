/****************************************************************
 * File:    main.c
 * Author:  Group 6: CS125
 * Purpose: Main application
 * Date:    4/6/2025
 ***************************************************************/

#include "include/cli.h"
#include "include/hash.h"
#include "include/io.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  /* Execute the command parser */
  return parse_arguments(argv, argc);
}

int example() {
  char *WORD_LIST = "word-list-extra-large.txt";

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
