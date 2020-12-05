#include "h/cli.h"
#include <stdio.h>  // printf, fprintf, stderr
#include <string.h> // strstr, strcmp
#include <stdlib.h> // atoi

static inline void print_help()
{
  //printf(__BALEIA_USAGE);
  printf ("%-16s\tShow this message and exit.\n", "-h, --help");
  printf ("%-16s\tSet a vocabulary on which passwords are generated from.\n", "-v, --vocab");
  printf ("%-16s\tSet the size of the generated password.\n", "-s, --size");
}

cli_args_t parse_cli_args (int argc, char ** argv)
{
  cli_args_t flags_passed = {0, NULL};
  int i;
  if (argc == 1)
    {
      return flags_passed;
    }

  for (i = 1; i < argc; i++)
    {
      if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help"))
        {
	  print_help ();
	  exit (0);
        }
      else if (!strcmp(argv[i], "-v") ||!strcmp(argv[i], "--vocab"))
        {
	  if (i + 1 >= argc)
            {
	      fprintf (stderr, "error: missing value to --vocab");
	      exit (0);
            }
	  flags_passed.vocab = argv[++i];
        }
      else if (!strcmp (argv[i], "-s") || !strcmp (argv[i], "--size"))
        {
	  if (i + 1 >= argc)
            {
	      fprintf (stderr, "error: missing value to --size");
	      exit (0);
            }
	  flags_passed.size = atoi(argv[++i]);
	  if (flags_passed.size <= 0) {
	    fprintf (stderr, "spg: invalid value for size.\n");
	    exit (0);
	  }
        }
      else
        {
	  fprintf (stderr, "spg: unknown option %s", argv[i]);
	  exit (0);
        }
    }
  return flags_passed;
}
