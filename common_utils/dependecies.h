// Libs proprias
#include "coluna.h"
#include "common_utils/file_utils.h"
#include "common_utils/print_utils.h"
#include "common_utils/globals.h"

#include "common_utils/globals.h"

#include "criar_tabela.h"
#include "criar_registro.h"
#include "apagar_tabela.h"
#include "apagar_registro.h"
#include "listar_dados.h"

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

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif