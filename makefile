CC=gcc
CFLAGS=-I.
DEPS = $(wildcard *.h)
SRC = $(wildcard *.c)
OBJDIR = obj
BINDIR = bin
OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))

all: $(BINDIR)/program

$(OBJDIR)/%.o: %.c $(DEPS)
	mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BINDIR)/program: $(OBJ)
	mkdir -p $(BINDIR)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/program