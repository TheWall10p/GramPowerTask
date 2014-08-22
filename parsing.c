/**
 * @file doxygen_c.h
 * @author Vivek Varier
 * @date 22 Aug 2014
 * @C code for embedded system for parsing strings
 *
 * Including relevant header for I/O and string operations
 */

#include <stdio.h>
#include <string.h>

/** Prototyping the functions used*/

int ParseForHello(char c);
void NextState(char c);
int Output ();

/** Initialising Global Variables*/

int state=0;                  /** Tracks the stages of the state machine*/
char name[]="hello";          /** The string to be parsed and searched for*/

/** Main function which calls subsequent functions,*/

int main()
{ 
	 	 while(1) 
	 { 
		 char c = getchar();                           /** Seeking User Input*/                            
		 int helloFound = ParseForHello(c);            /** Calling ParseForHello function*/ 
		 if(helloFound) 
		 { 
			break;
		 }                                             /** Function loops out when "hello" is found in the input string*/
	 } 
	 return 0;
}

/** ParseForHello Function - controls flow of the state machine and the corresponding outputs at eacg stage*/

int ParseForHello(char c)
{
	NextState(c);                                      /** Function to determine the next state of teh FSM*/
	return Output();                                   /** Function to assign Output for transited stages*/
}

/** Function NextState- takes in the read character as input and outputs the next state of the FSM*/

void NextState(char c){
	if(c==name[0] && !(c==name[state])) 
	{
		state=1;                                       /**Next state is the state 1 when the character read is same as the first character of the required string, thereby allowing for overlapping situations*/ 
	}
	else if (state==strlen(name)) 
	{
		state=0;                                       /** Next state is 0 if the sequence is not followed after the last stage , pertaining to the last character check of the string to be compared with */
	}
	else if(c==name[state])
	{
		state++;                                       /** Increment the state to the next if the sequence is correctly followed*/
	}
	else state=0;                                      /** Next state is state 0 if the correct sequence is not followed at any stage*/
}

/** Function Output- Outputs the value for helloFound for each stage of the FSM*/

int Output () 
{
	return (state==strlen(name));                     /** helloFound made 1 only when complete sequence is detected(when the FSM reaches the last state!)*/
}
