/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief This is a C program file which will be used to create Analytics Report on a given set of numbers
 *
 * There are 8 functions that would be employed in the program:
    1. main() - The main entry point of program
    2. print_statistics() - A function that prints the statistics of an array including minimum, maximum, mean, and median.
    3. print_array() -  Given an array of data and a length, prints the array to the screen
    4. find_median() - Given an array of data and a length, returns the median value
    5. find_mean() -  Given an array of data and a length, returns the mean
    6. find_maximum() -  Given an array of data and a length, returns the maximum
    7. find_minimum() -  Given an array of data and a length, returns the minimum
    8. sort_array() - Given an array of data and a length, sorts the array from largest to smallest.  
       (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )
 *
 * @author Nishad T. 
 * @date 21-June-2021 
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)


//unsigned int ChartoInt(unsigned char test[]);

void print_statistics(unsigned int test_int[], unsigned int len); 			//changing to void fucntion because nothing returns
unsigned int find_median(unsigned int test_int[], unsigned int len);			//these are the Declaration of all the Functions
unsigned int find_mean(unsigned int test_int[], unsigned int len) ;				//that are used in this program
unsigned int find_maximum(unsigned int test_int[], unsigned int len) ;			//they are to be preprocessed before the main()
unsigned int find_minimum(unsigned int test_int[], unsigned int len); 
unsigned int sort_array(unsigned int test_int[], unsigned int len);
unsigned int print_array(unsigned int test_int[], unsigned int len);

void main()
{

    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                114, 88,   45,  76, 123,  87,  25,  23,
                                200, 122, 150, 90,   92,  87, 177, 244,
                                201,   6,  12,  60,   8,   2,   5,  67,
                                  7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
    unsigned int len=SIZE;
    unsigned int i=0;
    unsigned int test_int[SIZE];
   
    for(i=0;i<=len-1;i++)
    {
//       test_int[i]=ChartoInt(test[i]);		// this part is used to typecast the unsigned char array (test[]) 
        test_int[i]=(unsigned int)(test[i]);	//	into unsigned int array (test_int[])
    }
 
    sort_array(test_int,SIZE);											//These are the triggers for the various functions
    printf("The Given Array is sorted and Now it will be printed:\n");
    print_array(test_int,SIZE);
    printf("\nNow we shall see the staistics\n");
    print_statistics(test_int, SIZE);			//this Function will itself trigger 4 other Functions as below
}

unsigned int count=0, temp=0, i=0,j=0;

//unsigned int ChartoInt(unsigned char test[])
//{
//    return ((unsigned int)test);
//}


unsigned int sort_array(unsigned int test_int[], unsigned int len)
{
    unsigned int i=0;							
    for(i=0;i<=len-1;i++)
    {
        for(j=0;j<len-1-i;j++)
        {
            if(test_int[j] < test_int[j+1])			//Here we have sorted the test_int[] into descending order
            {
                temp=test_int[j];
                test_int[j]=test_int[j+1];
                test_int[j+1]=temp;
            }
        }   
       // count++;
    //    printf("current value at %d=%d \n count=%d \n",i,test_int[i],count);
    }
    return 0;
}

unsigned int print_array(unsigned int test_int[],unsigned int len)
{
    printf("[");
    for(i=0;i<=len-1;i++)
    {
       if(i==(len-1))
       {
           printf("%d]",test_int[i]);		//Here we are Printing the sorted array in a readable structure
       }
       else
       {
           printf("%d, ",test_int[i]);
       }
    }
    return 0;
}

void print_statistics(unsigned int test_int[], unsigned int len) 

{
    printf(" The Median = %d \n",find_median(test_int, len));
    printf(" The Mean = %d \n",find_mean(test_int, len));			//As we  can see, these are the various statistic fuctions
    printf(" The Maximum = %d \n",find_maximum(test_int, len));		//they willl be triggered after the print statement
    printf(" The Mininmum = %d \n",find_minimum(test_int, len)); 
}

unsigned int find_median(unsigned int test_int[], unsigned int len)
{
    if(len%2==0)
        {
            return((test_int[len/2]+test_int[(len/2)+1])/2);
        }
    else											//we have to check for oodd or even number of elements and 
        {											//calculate the median accordingly
            return(test_int[(len/2)+1]);
        }
}
unsigned int find_mean(unsigned int test_int[], unsigned int len) 
{
    unsigned int sum=0;
    for (i=0;i<len;i++)
    {
        sum+=test_int[i];
    }
    return(sum/len);
}
unsigned int find_maximum(unsigned int test_int[], unsigned int len) 
{
    return(test_int[0]);
}
unsigned int find_minimum(unsigned int test_int[], unsigned int len)
{
    return(test_int[len-1]);
}

/* Add other Implementation File Code Here */
