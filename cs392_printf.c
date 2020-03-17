//I pledge my honor that I have abided by the Stevens Honor System - Aparajita Rana

#include <stdio.h>
#include <stdarg.h>
#include <string.h>


int getSize (char * s) {
    char * t;    
    for (t = s; *t != '\0'; t++)
        ;
    return t - s;
}

char* reverse(int temp, char* temp2){
	//OK IDEA IS MOD EACH VAL
	//char* flipped;
	int temp3=0;
	int count=0;
	//int length=getSize(val);
	do{
			temp3=temp%10;
			temp2[count]=temp3+48;
			//counter++;
			temp=temp/10;
			count++;
		}while(temp!=0);

	return temp2;
}

int cs392_printf(const char * format, ...){

va_list args;
va_start(args, format);
int counter=0;

//iterative over “format” and find specifiers
while (*format != '\0') {

	// get the first argument with va_arg
	// the following is an example of handling integer format “%d”
	if(*format == '%'){

		format ++;
		if(*format == 0)
			break;
				
		if(*format == 'd'){
		int arg_int = va_arg(args, int); 
		// this helps you get the argument corresponding to “%d”

		int temp=arg_int;
		int get_nums=arg_int;
		char* temp2;
		char* copy;
		int temp3=0;
		int count=0;

		//convert int to char*, and then mod 10 -> count bytes (amt chars)
		do{
			temp3=temp%10;
			temp2[count]=temp3+48;
			counter++;
			temp=temp/10;
			count++;
		}while(temp!=0);
		

		count=0;
		temp=arg_int;
		do{
			temp3=temp%10;
			temp2[count]=temp3+48;
			//counter++;
			temp=temp/10;
			count++;
		}while(temp!=0);

		//null case (ends line)
		temp2[count]='\0';
		//actual printing

		//in order that it is all on one line
		int index=count;
		while(index>-1){
			putc(temp2[index], stdout);
			index--;
		}
		//puts(temp2);
		}


		if (*format == 's') {
	    char *arg_str = va_arg(args, char*);

	    int size=strlen(arg_str);
	    fputs(arg_str, stdout);
	    //strlen
	    counter+=size;
		}

		if (*format == 'c') {
	    char arg_char = va_arg(args, int);
	    fputc(arg_char,stdout);
		}
	}

	//prints regular string
	else {
		char arg_char = *format; 
		putc(arg_char, stdout);
		counter++;
	}

	++format;
    }

    va_end(args);
    putc('\n',stdout);
    return counter;

}
