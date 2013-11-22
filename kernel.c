

/* Nov 10 Project 7  
   Develop kernel to Print to Screen
                     Read from Keyboard
                     Read sector from Disk
                     Create my Interrupt
                     Provide Services
   Debra Nash CSE 7343
   */



int mod();
int div();
void printString();
void readString();
void readSector();

char myLine[80] = 0;
char abuffer[512] = 0;
int  sector = 30;

int main(){
 
 /*    printString("Hello World \0"); */

/*     printString("Enter a new line \r\n\0");
     readString(myLine);
      
     printString("\n");
     printString(myLine);
*/

     readSector(abuffer, 30);  
     printString(abuffer);
  

 while (1);
      return 0;
}
int div(int a, int b){
  int q = 0;
  while ((q * b) < a){
    q = q + 1;
  }
  return q-1;
}
int mod(int dividend, int divisor){
  while (dividend >= divisor){
    dividend = dividend - divisor;
  }
}
void readSector(char* abuffer, int sector){
  int rs, h, t;
  int idx = 0;
  char mychar;
  
  /* rs = mod(sector,18)+ 1;*/
  rs = 13;
  h = 1;
/*
  h = div(sector,18);h = mod(h,2); */
  t = 0;
/*  t = div(sector, 36); Manually calculated variables for test*/
    interrupt(0x13, 2*256+1, abuffer, t*256+rs, h*256+0);
  

}
void readString(char* myLine) {
 int idx = 0;
 char mychar =  0;
 while (1) {
  if (mychar == 0xD) break;
  mychar = interrupt(0x16, mychar, 0, 0, 0);
  interrupt(0x10, 0xE*256 + mychar, 0, 0, 0);
  myLine[idx]=mychar;
  ++idx;
/* if (mychar == 0x8) {
    if (idx > 0)
       --idx;
    else
     continue;
  } */
 }
 myLine[idx+1] = '\r';
 myLine[idx+2] = '\n';
 myLine[idx+3] = '\0';
}
void printString(char* RandomWord) {

int  idx = 0;
char mychar = RandomWord[idx];

      while (mychar != '\0'){
        interrupt(0x10, 0xE*256 + mychar, 0, 0, 0);
      	mychar = RandomWord[++idx];
      }
 }
