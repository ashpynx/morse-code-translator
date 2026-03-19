#ifndef TRIE_H
#define TRIE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct TrieNode
{

    struct TrieNode *nodes[2];
    
    char type;
}TrieNode;

typedef struct 
{

    struct TrieNode * head;

    int size;

}Trie;


struct TrieNode * 
createNode();

int 
freeTrie(TrieNode * trie);

Trie * 
initTrie();

int 
insertTrie(Trie * trie,char * str,char type);

char 
getType(Trie * trie,char * str);

int 
findTrie(Trie *trie,char * str);

int 
isAlpha(char * str);
#endif
