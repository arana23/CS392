// I pledge my honor that I have abided by the Stevens Honor System. - Aparajita Rana
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h> 

//comparator method needed for qsort
int comparator(const void *x, const void *y)  
{ 
    int l = *((int*) x); 
    int r = *((int*) y);  
    if (l==r)
        return 0;
    else if (l<r)
        return -1;
    else
        return 1;
} 

void mysort(char *inputfile, char *outputfile)
{
FILE *file;
FILE *file2;

file=fopen(inputfile,"r");

if(file==NULL)
{
    printf("Cannot open file");
    exit(1);
}

//in order to store integers in int array, we need the size
//each line is new number, so # of lines=int array size
char val;
int size=0;

for (val=getc(file); val!=EOF; val=getc(file))
{
    if (val=='\n')
    {
        size++; 
    }
}

rewind(file);

//here we create and start storing the vals
int *numbers;

//finally, we have the correct (hopefully) amt of memory
numbers=(int *) malloc(sizeof(int)*size);

//store each val into numbers
int loc=0;
//int val_temp;
while(!feof(file))
{
    fscanf(file, "%d",&numbers[loc]);
    //numbers[loc]=val_temp;
    loc++;
}

//utilize quicksort algorithm & comparator
qsort(numbers, size, sizeof(int), comparator);
fclose(file);

file2 = fopen(outputfile, "w"); //open writefile

if(file2==NULL) 
{
    printf("Cannot open file");
    exit(1);
}

//write the numbers to the file
int x;
char temp[size];

//convert int array to char array
for(x = 0; x < size; x++)
{
    snprintf(&temp[x], sizeof(temp), "%d",numbers[x]);
}

for(x = 0; x < size; x++)
{
    fprintf(file2, "%d", numbers[x]);
    fputc('\n', file2);
}

fclose(file2);

//we are told to also use free -> frees the memory
free(numbers);

}


int main(int argc, char **argv) 
{
    //report an error if fewer than or more than two arguments are provided
    if(argc!=3) 
    {
        printf("Error in number of arguments");
        exit(1);
    }
    mysort(argv[1], argv[2]);
    return(0);
}