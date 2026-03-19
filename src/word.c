#include "word.h"

int istext(char c)
{
    return isalpha(c) || issymbol(c) || isnum(c);
    
}

int issymbol(char c)
{
    return c=='.' || c==','||c=='?'||c=='\''||c=='/'||c=='('||c==')'||c=='&'||c==':'||c==';'||c=='"'||c=='='||c=='+'||c=='-'||c=='_'||c=='$'||c=='@';
    
}

int isnum(char c)
{
    return c -'0' >=0 && c-'0' <=9;

}
