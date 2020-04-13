// I pledge my honor that I have abided by the Stevens Honor System. - Aparajita Rana
// a simplified version of the “cat” shell command,
// which reads all contents from the input file and prints the data to the standard output

#include <stdio.h>
#include <stdlib.h>
#include <errno.h> 

//cat shell command -> reads all contents from the input file and prints data to standard output
void cat(char *name){
	FILE *file=fopen(name, "r");

	if(file==NULL){
		printf("failed to open the input file\n");
		exit(1);
	}

	//first, let's determine the size of the file
	//trace to the end of the file
	fseek(file, 0L, SEEK_END); 

	//now that we are at the end, we can determine the size
	long size;
	size=ftell(file);

	//reset
	rewind(file);

	//Next, we are asked to:
	//use dynamically allocated memory as destination/source of stream read/write
	char *vals;
	vals=malloc(size);
	fread(vals, 1, size, file);
	fwrite(vals, size, 1, stdout);

	//we are told to also use free -> frees the memory
	free(vals);

	//we done
	fclose(file);
}

//main method for the application of the cat.c files
int main(int argc, char ** argv)
{
	//the program should only be taking one argument, the path

	//this if statement address the case there are too many/too little arguments
	if(argc != 2) {
        printf("Error regarding arguments");
        exit(1);
    }

    //correct amount of arguments, lets try running cat
    cat(argv[1]);

    return(0);
}
