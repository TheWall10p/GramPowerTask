#include <stdio.h>

int state=0;
char name[]="demmda";

int main()
{ 
	int flag=0;
 while(1) 
 { 
 char c = getchar(); 
 int helloFound = ParseForHello(c); 
 if(helloFound) 
 { 
	break;
 } 
 } 
 return 0;
}

int ParseForHello(c){
state = NextState(c,state);
int Out=Output(state);
return Out;
}

int NextState(c,state){
if(c==name[0] && !(c==name[state])) {
state=1;
}
else if (state==6) {
state=0;
}
else if(c==name[state]){
state++;
}
else state=0;
return state;
}

int Output (state) {
int Out;
if(state==6) Out=1;
else Out=0;
return Out;
}
