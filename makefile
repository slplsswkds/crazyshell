CC = clang
OPTLVL = 3
TARGET = x86_64-unknown-linux-musl
CFLAGS = --target=$(TARGET) -O$(OPTLVL)
CFLAGSLIB = -c -Wall 
BLD_DIR = build
SRCDIR = src

BINNAME=crsh

compile: 
	$(CC) $(CFLAGS) $(CFLAGSLIB) -o $(BLD_DIR)/config.o $(SRCDIR)/config.c
	$(CC) $(CFLAGS) $(CFLAGSLIB) -o $(BLD_DIR)/input.o $(SRCDIR)/input.c
	$(CC) $(CFLAGS) $(CFLAGSLIB) -o $(BLD_DIR)/main.o $(SRCDIR)/main.c

link:
	$(CC) -o $(BINNAME) $(BLD_DIR)/*

clean:
	rm -rf $(BLD_DIR)/*

.PHONY: config crsh clean