//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int test() {
    char str[] = "26-dac_write-1F-18-7-32-21";
	int init_size = strlen(str);
	char delim[] = "-";

	char *ptr = strtok(str, delim);

    char* arr[6];
    int i = 0;

	while(ptr != NULL)
	{
		printf("'%s'\n", ptr);
		ptr = strtok(NULL, delim);
        arr[i] = ptr;
        i++;

	}

    char number1 = *arr[5];
    int num = atoi(arr[5]);
    int num2 = num+1;

    int arr2[5];
    for (int i = 0; i < 6; i++){
        char *kar = arr[i];
        arr2[i] = atoi(kar);
    }
    

    printf("'%s'\n", arr[0]);
    printf("'%s'\n", arr[5]);
    printf("%d\n", num);
    printf("%d\n", num2);
    printf("%d\n", arr2[0]);
    printf("%d\n", arr2[5]);
    
	

	return 0;
}

//------------------------------------------------------------------------------
