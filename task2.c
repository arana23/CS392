/* I pledge my honor that I have abided by the Stevens Honor System - Aparajita Rana*/
#include<stdio.h>
#include<string.h>
/*int sort_helper(char* a){
	char * i;
    int ascii;
    int sum;
	for (i=a; *i; i++) 
	{
		//sprintf(ascii, " %d",i);
		ascii = (int) i;
		sum+=ascii;
	}
	return sum;
}*/

//my strcomp method -> takes in two val returns 0 if equal like basic strcmps
int my_strcmp(char *val1, char *val2){
	int val=0;
	//if this specific character is equal to incremented val2
	while (*val1 == *val2++)
	{
		//if incremened val1 is zero
		if (*val1++ == 0)
		{
			return 0;
		}
	}
	//otherwise, the two string are not equal
	//return pointers ascii val
	val=*val1 - *--val2;
	return val;

}


void cs392_str_sort(char ** strlist, int number){
	//IGNORE - Old Code
	//strl=strlist;
	//int n=number;
	/* Please write down your code here 
	int c; int d; 
	char* swap;
	for (c = 0 ; c < n - 1; c++)
  	{
    for (d = 0 ; d < n - c - 1; d++)
    {
      if(my_strcmp(strlist[c],strlist[d])==1)
      {
        swap = strlist[c];
        strlist[c] = strlist[d];
        strlist[d] = swap;
      }
    }
  }*/

	int loc;
	//checker tells us when to excit
	int checker=1;
	//reduces list and keeps track of sorted vals
	int val=number-1;
    char* temp;

    //bubble sort using while loop
    while(checker)
    {
        checker = 0;
        //iterate through all of the strings
        for (loc = 0; loc < val; loc++) 
        {
        	//utilize my compare method, this means strlist[loc+1] was bigger
            if (my_strcmp(strlist[loc], strlist[loc+1]) > 0) 
            {
            	//this is my swap -> could be another function but left here
            	//switch str[loc] and str[loc+1]
                temp=strlist[loc];
                strlist[loc]=strlist[loc+1];
                strlist[loc+1]=temp;
                checker=1;
            }
        }
        val--;
    }

}


int main(int argc, char ** argv){

	printf("CS_392 midterm task 2: \n");

	printf("        Test case 1:\n");

	char *strlist[5] = {"String1", "STring1", "String1extended", "String", "StRING1"};
	
	cs392_str_sort(strlist, 5);

	printf("	Correct results are: STring1, StRING1, String, String1, String1extended\n");
	printf("	Your results are: %s, %s, %s, %s, %s\n", strlist[0], strlist[1], strlist[2], strlist[3], strlist[4]);

	if(strcmp(strlist[0], "STring1") == 0 && strcmp(strlist[1], "StRING1") == 0 && strcmp(strlist[2], "String") == 0 && strcmp(strlist[3], "String1") == 0 && strcmp(strlist[4], "String1extended") == 0)
			printf("	=== Result: PASSED === \n\n");
		else
			printf("	=== Result: FAILED === \n\n");	

	char *strlist1[5] = {"string2", "s@ing2", "stringA", "sTRING2", "@tring2"};
	
	cs392_str_sort(strlist1, 5);

	printf("	Correct results are: @tring2, s@ing2, sTRING2, string2, stringA\n");
	printf("	Your results are: %s, %s, %s, %s, %s\n", strlist1[0], strlist1[1], strlist1[2], strlist1[3], strlist1[4]);

	if(strcmp(strlist1[0], "@tring2") == 0 && strcmp(strlist1[1], "s@ing2") == 0 && strcmp(strlist1[2], "sTRING2") == 0 && strcmp(strlist1[3], "string2") == 0 && strcmp(strlist1[4], "stringA") == 0)
			printf("	=== Result: PASSED === \n\n");
		else
			printf("	=== Result: FAILED === \n\n");	

	return 0;
}


