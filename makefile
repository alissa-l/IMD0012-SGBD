COMPILER=gcc
CFLAGS=-I.
HEADER_CODE = $(wildcard *.h)
SOURCE_CODE = $(wildcard *.c)
OBJDIR = obj
BINDIR = bin
OBJECT_FILE = $(patsubst %.c,$(OBJDIR)/%.o,$(SOURCE_CODE))
PROGRAM = sgbd

all: $(BINDIR)/$(PROGRAM)

$(OBJDIR)/%.o: %.c $(HEADER_CODE)
	mkdir -p $(OBJDIR)
	$(COMPILER) -c -o $@ $< $(CFLAGS)

$(BINDIR)/$(PROGRAM): $(OBJECT_FILE)
	mkdir -p $(BINDIR)
	$(COMPILER) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/$(PROGRAM)