/****************************************************************
 * File:    test.c
 * Author:  Group 6: CS125
 * Purpose: Main application tests.
 * Date:    4/16/2025
 ***************************************************************/

#include "hash_tests.h"
#include <stdio.h>

int main() {
  /* Test the hash module */
  int status_1 = test_djb2();
  if (status_1 == 0) {
    printf("Test Passed! test_djb2 [status: %d]\n", status_1);
  } else {
    printf("Test failed! test_djb2 [status: %d]\n", status_1);
  }

  return status_1;
}
