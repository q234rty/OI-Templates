#include <cctype>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXSIZE=30000020;
int bufpos;
char buf[MAXSIZE];
void init(){
    buf[fread(buf,1,MAXSIZE,stdin)]='\0';
    bufpos=0;
}
int readint(){
    bool isneg;
    int val=0;
    for(;!isdigit(buf[bufpos]) && buf[bufpos]!='-';bufpos++);
    bufpos+=(isneg=(buf[bufpos]=='-'))?1:0;
    for(;isdigit(buf[bufpos]);bufpos++)
        val=val*10+buf[bufpos]-'0';
    return isneg?-val:val;
}
char readchar(){
    for(;isspace(buf[bufpos]);bufpos++);
    return buf[bufpos++];
}
