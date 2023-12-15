COMPILER=gcc
CFLAGS=-I.
HEADER_CODE = $(wildcard *.h)
SOURCE_CODE = $(wildcard *.c) $(wildcard common_utils/*.c) $(wildcard pesquisar_registro_utils/*.c)
OBJDIR = obj
BINDIR = bin
OBJECT_FILE = $(patsubst %.c,$(OBJDIR)/%.o,$(SOURCE_CODE))
PROGRAM = sgbd

all: $(BINDIR)/$(PROGRAM)

$(OBJDIR)/%.o: %.c $(HEADER_CODE)
	mkdir -p $(OBJDIR)
	$(COMPILER) -c -o $@ $< $(CFLAGS)
	if [ ! -d "tabelas" ]; then mkdir tabelas; fi

$(OBJDIR)/common_utils/%.o: common_utils/%.c $(HEADER_CODE)
	mkdir -p $(OBJDIR)/common_utils
	$(COMPILER) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/pesquisar_registro_utils/%.o: pesquisar_registro_utils/%.c $(HEADER_CODE)
	mkdir -p $(OBJDIR)/pesquisar_registro_utils
	$(COMPILER) -c -o $@ $< $(CFLAGS)

$(BINDIR)/$(PROGRAM): $(OBJECT_FILE)
	mkdir -p $(BINDIR)
	$(COMPILER) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJDIR)/*.o $(OBJDIR)/common_utils/*.o $(OBJDIR)/pesquisar_registro_utils/*.o $(BINDIR)/$(PROGRAM)