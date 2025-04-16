/****************************************************************
 * File:    hash_test.c
 * Author:  Group 6: CS125
 * Purpose: Implementation of the testing of the hash module.
 * Date:    4/16/2025
 ***************************************************************/

#include "hash_tests.h"

int test_djb2() {
  char *str_1 = "hello";
  char *str_2 = "Hello";
  char *str_3 = "world";
  char *str_4 = "World";

  uint32_t hash_1 = djb2(str_1);
  uint32_t hash_2 = djb2(str_2);
  uint32_t hash_3 = djb2(str_3);
  uint32_t hash_4 = djb2(str_4);

  if (hash_1 != 261238937 || hash_2 != 223289465 || hash_3 != 279393645 ||
      hash_4 != 241444173)
    return 1;

  uint32_t hash_1_1 = djb2(str_1);
  uint32_t hash_2_1 = djb2(str_2);
  uint32_t hash_3_1 = djb2(str_3);
  uint32_t hash_4_1 = djb2(str_4);

  if (hash_1 != hash_1_1 || hash_2 != hash_2_1 || hash_3 != hash_3_1 ||
      hash_4 != hash_4_1)
    return 1;

  return 0;
}
