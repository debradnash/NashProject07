/* Nov 10 Project 7  
   Develop kernel to Print to Screen
                     Read from Keyboard
                     Read sector from Disk
                     Create my Interrupt
                     Provide Services
   Debra Nash CSE 7343
   */
#include <stdio.h>

void printString();
void readString();
void readSector();

char myLine[80] = 0;
int main()
{
	// Step 1 Print to screen using Interrupt 0x10
    printString("This is Debras World - Hello \r\n\0");

    printString("Huh? \r\n\0");
    readString(myLine);
    printString(myLine);
	while (1) ;
		/* to do */
	
	return 0;
}
void readString(char* mystr) {
 int idx = 0;
 char mychar =  0;
 while (1) {
  if (mychar == 0xD) break;
  mychar = interrupt(0x16, 0, 0, 0, 0);
  interrupt(0x10, 0xE*256 + mychar, 0, 0, 0);
  mystr[idx]=mychar;
  ++idx;

 }
 mystr[idx+1] = '\r';
 mystr[idx+2] = '\n';
 mystr[idx+3] = '\0';
}
void printString(char* RandomWord) {

int  idx = 0;
char mychar = RandomWord[idx];

      while (mychar != '\0'){
        interrupt(0x10, 0xE*256 + mychar, 0, 0, 0);
      	mychar = RandomWord[++idx];
      }
 }
