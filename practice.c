/*
I pledge my honor that I have abided by the Stevens Honor System - Aparajita Rana

[1] Create an integer variable 
[2] Assign a constant value to that variable (whatever value you want)
[3] Create an integer pointer
[4] Make that pointer point to the integer variable 
[5] Change that integer variable to another constant value by dereferencing the pointer created in [3] (instead of directly changing that integer variable)
[6] Print the integer variable again. 
[7] Please upload your .c file.
*/

#include <stdio.h>

int main()
{
	int x = 10; // steps 1 & 2
    int *pointy = &x; // steps 3 & 4

    printf("x = %d\n",x); // print the og variable to compare change
    (*pointy)+=2; //step 5
    printf("x = %d\n",x); // step 6

    return 0;
}