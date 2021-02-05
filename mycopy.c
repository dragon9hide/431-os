#include <stdio.h>
 
int main (int argc, char *argv[])
{
    // open the file
    FILE *doner = fopen(argv[1],"r");
	FILE *reciever = fopen(argv[2], "w");
 
    // Return if could not open file
    if (doner == NULL)
      return 0;
 
    do
    {
        // Taking input single character at a time
        char c = fgetc(doner);
 
        // Checking for end of file
        if (feof(doner))
            break ;
		fputc(c, reciever);
        
    }  while(1);
 
    fclose(doner);
	fclose(reciever);
    return(0);
} 