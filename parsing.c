#include <stdio.h>
#include <string.h>

int ParseForHello(char c);
void NextState(char c);
int Output ();

int state=0;
char name[]="hello";

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

int ParseForHello(char c)
{
	NextState(c);
	return Output();
}

void NextState(char c){
	if(c==name[0] && !(c==name[state]))
	{
		state=1;
	}
	else if (state==6) 
	{
		state=0;
	}
	else if(c==name[state])
	{
		state++;
	}
	else state=0;
}

int Output () 
{
	return (state==strlen(name));
}
