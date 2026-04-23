#include "trie.h"
#include <ctype.h>
#include "main.h"
Trie * initTrie()

{
    Trie * temp;
        
    temp = malloc(sizeof(Trie));

    if(temp==0)
    {
        perror("initTree:Couldn't Allocate Memory!\n");
        exit(74);
    }
    
    temp->size =0;
    
    temp ->head = createNode();

    insertTrie(temp,".",'E');
    insertTrie(temp,"..",'I');
    insertTrie(temp,"...",'S');
    insertTrie(temp,"....",'H');
    insertTrie(temp,".-",'A');
    insertTrie(temp,".-.",'R');
    insertTrie(temp,".--",'W');
    insertTrie(temp,"..-",'U');
    insertTrie(temp,"-...",'B');
    insertTrie(temp,"-.-.",'C');
    insertTrie(temp,"-..",'D');
    insertTrie(temp,"..-.",'F');
    insertTrie(temp,"--.",'G');
    insertTrie(temp,".---",'J');
    insertTrie(temp,"-.-",'K');
    insertTrie(temp,".-..",'L');
    insertTrie(temp,"--",'M');
    insertTrie(temp,"-.",'N');
    insertTrie(temp,"---",'O');
    insertTrie(temp,".--.",'P');
    insertTrie(temp,"--.-",'Q');
    insertTrie(temp,"-",'T');
    insertTrie(temp,"...-",'V');
    insertTrie(temp,"-..-",'X');
    insertTrie(temp,"-.--",'Y');
    insertTrie(temp,"--..",'Z');

    insertTrie(temp,".----",'1');
    insertTrie(temp,"..---",'2');
    insertTrie(temp,"...--",'3');
    insertTrie(temp,"....-",'4');
    insertTrie(temp,".....",'5');
    insertTrie(temp,"-....",'6');
    insertTrie(temp,"--...",'7');
    insertTrie(temp,"---..",'8');
    insertTrie(temp,"----.",'9');
    insertTrie(temp,"-----",'0');

    insertTrie(temp,".-.-.-",'.');
    insertTrie(temp,"--..--",',');
    insertTrie(temp,"..--..",'?');
    insertTrie(temp,".----.",'\'');
    insertTrie(temp,"-..-.",'/');
    insertTrie(temp,"-.--.",'(');
    insertTrie(temp,"-.--.-",')');
    insertTrie(temp,".-...",'&');
    insertTrie(temp,"---...",':');
    insertTrie(temp,"-.-.-.",';');
    insertTrie(temp,"-...-",'=');
    insertTrie(temp,".-.-.",'+');
    insertTrie(temp,"-....-",'-');
    insertTrie(temp,"..--.-",'_');
    insertTrie(temp,".-..-.",'"');
    insertTrie(temp,"...--..-",'$');
    insertTrie(temp,".--.-.",'@');
    return temp;
}

TrieNode * createNode()
{
    TrieNode * temp = malloc(sizeof(TrieNode));
    if(temp == NULL)
    {   
        perror("createNode:Couldn't Allocate Memory!\n");
        exit(74);
    }
    

    temp->type = 0;

    return temp;

}

int insertTrie(Trie * trie,char * str, char type)
{
    

    int len = strlen(str);


    for(int i =0 ; i < len ; i ++)
        if(str[i]!='.' && str[i]!='-')
            return 0;
    TrieNode * curr = trie->head;

    for(int i=0; i< len && !sig ; i ++)
    {
        if(curr->nodes[str[i] - '-'] == NULL)
        {
            curr->nodes[str[i]-'-'] = createNode();
        }
        
            curr = curr->nodes[str[i]-'-'];
    }
    if(sig)
        return 0;
    curr->type = type;

    trie->size++;

    return 1;
}
char getType(Trie * trie,char * str)
{
     int len = strlen(str);

    for(int i =0 ; i < len ; i ++)
        if(str[i]!='.' && str[i]!='-')
            return 0;
    

    TrieNode * curr = trie->head;

    for(int i=0; i< len && !sig ; i ++)
    {
        if(curr->nodes[str[i] -'-'] == NULL)
        {
            return '1';
        }
        
            curr = curr->nodes[str[i]-'-'];
    }
    if(sig) return -1; 

    return curr->type;


}

int findTrie(Trie * trie,char * str)
{
     int len = strlen(str);


    for(int i =0 ; i < len ; i ++)
        if(str[i]!='.' || str[i]!='-')
            return 0;

    TrieNode * curr = trie->head;

    for(int i=0; i< len && !sig; i ++)
    {
        if(curr->nodes[str[i] -'-'] == NULL)
        {
            return 0;
        }
        
            curr = curr->nodes[str[i]-'-'];
    }
    if(sig) return 0; 

    if(curr->type != '0')
        return 1;

    return 0;


}
int freeTrie(TrieNode* node)
{
    
    for(int i=0 ; i < 2;i++)
    {
        if(node->nodes[i]!=NULL)
        {
            freeTrie(node->nodes[i]);
        }
    }
    
    free(node);

    return 1;
}
