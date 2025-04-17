/****************************************************************
 * File:    test.c
 * Author:  Group 6: CS125
 * Purpose: Main application tests.
 * Date:    4/16/2025
 ***************************************************************/

#include "cli_tests.h"
#include "hash_tests.h"
#include "io_tests.h"
#include <stdio.h>

int main() {
  /* Test the hash module */
  int status_1 = test_djb2();
  if (status_1 == 0) {
    printf("Test Passed: [status %d] test_djb2\n", status_1);
  } else {
    printf("Test Failed: [status %d] test_djb2\n", status_1);
  }

  /* Test the cli module */
  int status_2 = test_flag_parsers();
  if (status_2 == 0) {
    printf("Test Passed: [status %d] test_flag_parsers\n", status_2);
  } else {
    printf("Test Failed: [status %d] test_flag_parsers\n", status_2);
  }

  int status_3 = test_find_word_by_hash();
  if (status_3 == 0) {
    printf("Test Passed: [status %d] test_find_word_by_hash\n", status_3);
  } else {
    printf("Test Failed: [status %d] test_find_word_by_hash\n", status_3);
  }

  return status_1;
}
