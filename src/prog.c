#include "prog.h"
#include "trie.h"
#include "word.h"

char * tokens[128] = { 0 };

int
handle_morse(FILE * f,int lower,Trie * obj)
{
        int i=0;

        char buf[33] = { 0 };
        char c=0;
    init_tokens();

    while((c=fgetc(f))!=EOF)
    {
        if(i>32)
        {
            i=0;
            clearbuf(buf);
        }

        if(c==' ') 
        {
            buf[i]='\0';
            printf("%c",lower?tolower(getType(obj,buf)):getType(obj,buf));
            clearbuf(buf);
            i=0;
        }
        else if(c=='/')
        {
            buf[i]='\0';
            printf("%c ",lower?tolower(getType(obj,buf)):getType(obj,buf));
            clearbuf(buf);
            i=0;
        }
        else if(c=='\n')
        {
            buf[i]='\0';
            printf("%c\n",lower?tolower(getType(obj,buf)):getType(obj,buf));
            clearbuf(buf);
            i=0;
        }
        else
            buf[i++]=c;

    }

    return 0;
}

int 
handle_text(FILE * f, Trie * obj)
{
     
    int i=0;

    char c=0;
    
    init_tokens();
    while( (c=fgetc(f))!=EOF)
    {
        if(istext(c))
        {
            printf("%s ",tokens[toupper(c)]);
        }
        else if(c==' ')
            printf("/");
        else if(c=='\n')
            printf("\n");
        else 
        {
            fprintf(stderr,"\e[1;33m character %d|->%c not found in libary for text to morse code!Ignoring...\e[0m\n",i,c);

        }


    }

    for(int i=0; i< 128;i++)
    {
        free(tokens[i]);
    }

    return 1;
}

int init_tokens()
{
    
    tokens['E'] = strdup(".");
    tokens['I']=strdup(".."); 
    tokens['S']=strdup("...");
    tokens['H']=strdup("....");
    tokens['A']=strdup(".-");
    tokens['R']=strdup(".-.");
    tokens['W']=strdup(".--");
    tokens['U']=strdup("..-");
    tokens['B']=strdup("-...-");
    tokens['C']=strdup("-.-.");
    tokens['D']=strdup("-..");
    tokens['F']=strdup("..-.");
    tokens['G']=strdup("--.");
    tokens['J']=strdup(".---");
    tokens['K']=strdup("-.-");
    tokens['L']=strdup(".-..");
    tokens['M']=strdup("--");
    tokens['N']=strdup("-.");
    tokens['O']=strdup("---");
    tokens['P']=strdup(".--.");
    tokens['Q']=strdup("--.-");
    tokens['T']=strdup("-");
    tokens['V']=strdup("...-");
    tokens['X']=strdup("-..-");
    tokens['Y']=strdup("-.--");
    tokens['Z']=strdup("--..");

    tokens['1']=strdup(".----");
    tokens['2']=strdup("..---");
    tokens['3']=strdup("...--");
    tokens['4']=strdup("....-");
    tokens['5']=strdup(".....");
    tokens['6']=strdup("-....");
    tokens['7']=strdup("--...");
    tokens['8']=strdup("---..");
    tokens['9']=strdup("----.");
    tokens['0']=strdup("-----");

    tokens['.']=strdup(".-.-.-");
    tokens[',']=strdup("--..--");
    tokens['?']=strdup("..--..");
    tokens['\'']=strdup(".----");
    tokens['/']=strdup("-..-.");
    tokens['(']=strdup("-.--.");
    tokens[')']=strdup("-.--.-");
    tokens['&']=strdup(".-...");
    tokens[':']=strdup("---...");
    tokens[';']=strdup("-.-.-.");
    tokens['=']=strdup("-...-");
    tokens['+']=strdup(".-.-.");
    tokens['-']=strdup("-....-");
    tokens['_']=strdup("..--.-");
    tokens['"']=strdup(".-..-.");
    tokens['$']=strdup("...--..-");
    tokens['@']=strdup(".--.-.");


    return 0;

}


void clearbuf(char * str)
{
    while(str[0]!='\0') { str[0]=0;str++;}
}

void printHelp()
{
    printf("Morse Code Translator\n\nUsage:./mct -i [input file] -m [mode] [options]\n\n");  
    printf("Options:\n\n-i [input file]: specifies the input file.Format : '.' or '-' for the actual code and ' ' for new word, '/' for new word.\n\n");
    printf("-m [mode] : text or t for text -> morse translation. morse or m for morse -> text translation.\n\n");
    printf("-l : print all in lowercase.If not , print all in uppercase.\n\n");
    printf("-h : this help message\n");
    exit(0);
}


