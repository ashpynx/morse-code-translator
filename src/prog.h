#ifndef PROG_H
#define PROG_H

#include "main.h"

#include "trie.h"

extern char * tokens[];

int 
handle_morse(FILE * f,int , Trie *);

int
handle_text(FILE *f,Trie *);

int 
init_tokens();

void
clearbuf(char *);

void 
printhelp();

#endif
