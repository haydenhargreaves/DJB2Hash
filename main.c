/****************************************************************
 * File:    hash.c
 * Author:  Group 6: CS125
 * Purpose: Main application
 * Date:    4/6/2025
 ***************************************************************/

#include "hash.h"
#include <stdio.h>

int main() {
  const char *string1 = "hello";
  const char *string2 = "world";
  const char *string3 = "Hello";
  const char *string4 = "world";

  printf("Case-sensitive Hash of \"%s\": %u\n", string1, djb2(string1));
  printf("Case-sensitive Hash of \"%s\": %u\n", string2, djb2(string2));
  printf("Case-sensitive Hash of \"%s\": %u\n", string3, djb2(string3));
  printf("Case-sensitive Hash of \"%s\": %u\n", string4, djb2(string4));

  return 0;
}
