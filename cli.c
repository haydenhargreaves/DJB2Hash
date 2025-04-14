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
  bool rainbow = false;

  /* Index state, this is to prevent memory allocation. */
  /* TODO: We might actually need to allocate memory... */
  int input_idx = 0;
  int list_idx = 0;

  int i = 0;

  while (i < len) {
    if (f_verbose(args[i])) {
      /* Set the verbose state */
      verbose = true;
    } else if (f_help(args[i])) {
      /* Help flag provided, we can run the cmd here and exit */
      return cmd_help();
    } else if (f_rainbow(args[i])) {
      /* Set the rainbow state */
      rainbow = true;
    } else if (f_list(args[i])) {
      /* This arg is the index flag, the next arg should be the path */
      if (i < len - 1) {
        if (!f_flag(args[++i])) {
          list_idx = i;
        } else {
          fprintf(stderr, "Invalid usage. Please provide a valid filepath.\n%s",
                  HELP_MSG);
          return 1;
        }
      } else {
        fprintf(stderr, "Invalid usage. Please provide a filepath.\n%s",
                HELP_MSG);
        return 1;
      }
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

  /* Rainbow flag was provided, execute the rainbow command */
  if (rainbow) {
    return cmd_rainbow_lookup(args[input_idx], args[list_idx], verbose);
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

/* TODO: Update this when new flags are implemented */
bool f_flag(char *str) {
  return f_verbose(str) && f_help(str) && f_output(str) && f_list(str) &&
         f_rainbow(str);
}
