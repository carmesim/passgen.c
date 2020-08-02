#ifndef __SPG_ARGS
#define __SPG_ARGS

#include <stddef.h>     // size_t

struct cli_args_s {
    size_t size;                  //! The size of the password to be generated. If it wasn't indicated from the command-line, size == 0.
    char * vocab;                 //! The 'vocabulary' of chars on which the passwords are based off. If it wasn't indicated from the command-line, vocab == NULL.
};

typedef struct cli_args_s cli_args_t;

cli_args_t parse_cli_args(int argc, char ** argv);

#endif // __SPG_ARGS
