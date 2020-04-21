/* I pledge my honor that I have abided by the Stevens Honor System - Aparajita Rana*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct cs392_struct{
	int course;
	int student;
	char  semester;
	char string[24];
};


void cs392_read_datastructure(struct cs392_struct * cs_ds, char * fpath){
	/* Please write down your code here  */
	FILE *file; 
      
    // open file able to read & write
    file = fopen (fpath, "r+"); 
    if (file == NULL) 
    { 
        printf("Error opening file"); 
        exit(1); 
    } 
    else
    {
    	//temp vals for all of the diff parameters of cs392_struct
    	int c; int s;
	  	char sem;
	  	//we were given wouldnt be more than 24
	  	char str[24];

	  	//get and save each value in the variables
	    fscanf(file, "%d %d %c %s",&c, &s, &sem, str);
	    
	    //bc its a pointer we need -> to save each val
	    cs_ds->course=c;
	    cs_ds->student=s;
	    cs_ds->semester=sem;
	    //cs_ds->string=malloc(strlen(str) + 1);
	    //str needs strcpy to do successfully
	    strcpy(cs_ds->string,str);
    }
    //close the file
    fclose(file);

}


int main(int argc, char ** argv){


	int index = 0; 

	struct cs392_struct test, res; 

	int course[5] = {123, 345, 456, 789, 868};
	int student[5] = {987,675, 234, 432, 656};
	char semester[5] = {'A', 'B', 'C', 'D', 'E'};
	char string[5][24]= {"This", "Is", "The", "Mid", "Term"};


	for(index = 0; index < 5; index++){
		
		FILE * fp = fopen("/tmp/ds", "w");

		fprintf(fp, "%d %d %c %s",  course[index], student[index], semester[index],string[index]);
		
		fclose(fp);

		memset(&test, 0, sizeof(struct cs392_struct));
		memset(&res, 0, sizeof(struct cs392_struct));
		
		res.course = course[index];
		res.student = student[index]; 
		res.semester = semester[index];
		strcpy(res.string, string[index]);
		
		cs392_read_datastructure(&test, "/tmp/ds");		

		printf("	Test case %d:\n", index);

		if ( memcmp(&res, &test, sizeof(struct cs392_struct)) == 0)
			printf("	=== Result: PASSED === \n\n");
		else
			printf("	=== Result: FAILED === \n\n");	
	
	}


	return 0;
}


