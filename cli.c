/****************************************************************
 * File:    cli.c
 * Author:  Group 6: CS125
 * Purpose: Implementation of the command line interface.
 * Date:    4/13/2025
 ***************************************************************/

#include "include/cli.h"
#include "include/cmds.h"

int parse_arguments(char **args, int len) {
  /* Default flag arguments */
  bool verbose = false;
  int input_idx = 0;

  int i = 0;

  while (i < len) {
    if (f_verbose(args[i])) {
      /* Set the verbose state */
      verbose = true;
    } else if (f_help(args[i])) {
      /* Help flag provided, we can run the cmd here and exit */
      return cmd_help();
    } else {
      /* If it wasn't parsed, assume it was target input */
      input_idx = i;
    }

    i++;
  }

  /*
   * If this is still 0, then no string was provided, and we
   * need to error out!
   */
  if (input_idx == 0) {
    fprintf(stderr, "Invalid usage. Please provide an input.\n%s", HELP_MSG);
    return 1;
  }

  return cmd_hash_string(args[input_idx], verbose);
}

bool f_verbose(char *str) {
  return (strcmp(F_VERBOSE_S, str) == 0) || (strcmp(F_VERBOSE_L, str) == 0);
}

bool f_help(char *str) {
  return (strcmp(F_HELP_S, str) == 0) || (strcmp(F_HELP_L, str) == 0);
}

bool f_output(char *str) {
  return (strcmp(F_OUTPUT_S, str) == 0) || (strcmp(F_OUTPUT_L, str) == 0);
}

bool f_list(char *str) {
  return (strcmp(F_LIST_S, str) == 0) || (strcmp(F_LIST_L, str) == 0);
}

bool f_rainbow(char *str) {
  return (strcmp(F_RAINBOW_S, str) == 0) || (strcmp(F_RAINBOW_L, str) == 0);
}
