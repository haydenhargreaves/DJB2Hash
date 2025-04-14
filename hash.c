/****************************************************************
 * File:    hash.c
 * Author:  Group 6: CS125
 * Purpose: Implementation of the hashing algorithm.
 * Date:    4/6/2025
 ***************************************************************/

#include "include/hash.h"

uint32_t djb2(const char *str) {
  uint32_t hash = 5381;
  int c;

  while ((c = *str++)) {
    hash = ((hash << 5) + hash) + c;
  }

  return hash;
}
