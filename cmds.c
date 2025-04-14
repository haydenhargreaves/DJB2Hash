/****************************************************************
 * File:    cmds.c
 * Author:  Group 6: CS125
 * Purpose: Implementation of the command module.
 * Date:    4/13/2025
 ***************************************************************/

#include "include/cmds.h"

int cmd_hash_string(char *str, bool verbose) {
  /* Generate the hash */
  uint32_t hash = djb2(str);

  /* If verbose, print it, otherwise, nothing */
  if (verbose)
    printf("%d\n", hash);

  return 0;
}
