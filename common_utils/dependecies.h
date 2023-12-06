// Libs proprias
#include "coluna.h"
#include "common_utils/file_utils.h"
#include "common_utils/print_utils.h"
#include "common_utils/globals.h"

#include "common_utils/globals.h"

// Usadas aqui
#include <stddef.h>

#include <sys/stat.h>

// Risco de redefinição
#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef ERRNO_H
#define ERRNO_H
#include <errno.h>
#endif

#ifndef STRING_H
#define STRING_H
#include <string.h>
#endif

#ifndef STDBOOL_H
#define STDBOOL_H
#include <stdbool.h>
#endif