/****************************************************************
 * File:    io_test.c
 * Author:  Group 6: CS125
 * Purpose: Implementation of the testing of the io module.
 * Date:    4/16/2025
 ***************************************************************/

#include "io_tests.h"

int test_find_word_by_hash() {
  /* Open example word list */
  FILE *f_list = fopen("./test/rainbow_table.txt", "r");
  if (f_list == NULL)
    return 1;

  /* hash for 'hello' and 'world' */
  uint32_t hash_1 = 261238937;
  uint32_t hash_2 = 279393645;

  char *word_1 = find_word_by_hash(f_list, hash_1);
  char *word_2 = find_word_by_hash(f_list, hash_2);
  fclose(f_list);

  if (word_1 == NULL || word_2 == NULL)
    return 1;
  if (strcmp(word_1, "hello") != 0)
    return 1;
  if (strcmp(word_2, "world") != 0)
    return 1;

  return 0;
}
