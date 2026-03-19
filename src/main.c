#include <stdio.h>
#include "trie.h"
#include "prog.h"
#include "word.h"
void printHelp();

void sigint(int signal);

void clearbuf(char * str);

int sig;

int main (int argc , char * argv[])
{

    signal(SIGINT,sigint);
    int val;

    const char * string=NULL;
    const char * modestr=NULL;
    int mode=-1;
    int lower=0,input=0,help=0;
    
    while((val=getopt(argc,argv,"i:lhm:"))!=-1)
    {
        if(val =='i')
        {
            string = optarg;
            input++;
        }
        else if(val=='l')
        {
            lower++;
        }
        else if(val=='h')
        {
            help++;   
        }
        else if(val=='m')
        {
            modestr=optarg;
            if(strcmp(modestr,"morse")==0 || strcmp(modestr,"m")==0)
            {
                mode =1;
            }
            else if(strcmp(modestr,"text") || strcmp(modestr,"t"))
            {
                mode=0;
            }
            else 
            {
                fprintf(stderr,"Mode specifier invalid!\n");
                printHelp();
                exit(1);
            }
        }
    }
    if(lower && mode==0)
    {
        fprintf(stderr,"Warning:\e[1;33m Text mode and lower text parameter doesnt make a difference.Ignoring -l\e[0m\n");
    }
    if(lower && input && help)
    {
        printHelp();
    }
    
    if(!input || mode==-1)
    {
        printHelp();
    }
    Trie * obj = initTrie();
    
    FILE * file = fopen(string,"r");

    if(file==NULL)
    {   
        fprintf(stderr,"Cannot Open File %s!",string);
        return 0;
    }

    if(mode==1)
    {
        handle_morse(file,lower,obj);
    }
    else if(mode==0)
    {
        handle_text(file,obj);
    }
    freeTrie(obj->head);

    free(obj);
    fclose(file);
   return 0;
}   

void sigint(int signal)
{
    if(signal==SIGINT)
    {
        sig=1;
    }

}
