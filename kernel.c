/* Nov 10 Project 7  
   Develop kernel to Print to Screen
                     Read from Keyboard
                     Read sector from Disk
                     Create my Interrupt
                     Provide Services
   Debra Nash CSE 7343
   */

void printString();
void readString();
void readSector();

int main()
{
	// Step 1 Print to screen using Interrupt 0x10
    printString("This is Debras World - Hello\r\n\0");
	while (1) ;
		/* to do */
	
	return 0;
}
void printString(char* RandomWord){

int  idx = 0;
char mychar = RandomWord[idx];

      while (mychar != '\0'){
        interrupt(0x10, 0xE*256 + mychar, 0, 0, 0);
      	mychar = RandomWord[++idx];
      }
 }
