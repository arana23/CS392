/* I pledge my honor that I have abided by the Stevens Honor System - Aparajita Rana*/
#include<stdio.h>
#include<string.h>

void cs392_reversestr(char * str){

	/*Please write down your code here*/

	//get the end value for our loop using length - thats our max iteration
	int length = strlen(str);

	//temp values for store different individual characters these are
	//where we store and swap with
    int temp;
    int temp2;
    int temp3;

    //for loop breakdown:
    //start at the first character, temp3 is the last, check if first is less than last
    //if so flip
    for (temp2 = 0, temp3 = length - 1; temp2 < temp3; temp2++, temp3--)
    {
    	//essentially a swap method except we are flipping specific characters
        temp = str[temp2];
        str[temp2] = str[temp3];
        str[temp3] = temp;
    }
}


int main(int argc, char ** argv){

	int index; 
	char src[128];
	char dst[128];

	printf("CS_392 midterm task 1: \n");

	index = 1; 

	while(index <= 5){

		printf("	Test case %d:\n", index);

		memset(src, 0, 128);
		memset(dst, 0, 128);

		strcpy(src, argv[index]);
		strcpy(dst, argv[index+5]);

		cs392_reversestr(src);
		
		printf("	Original string: \"%s\"; Reversed string: \"%s\"; \n", argv[index], src);	

		if(strcmp(src, dst) == 0 )	
			printf("	=== Result: PASSED === \n\n");
		else
			printf("	=== Result: FAILED === \n\n");	

		index += 1;
	}

	return 0;
}


