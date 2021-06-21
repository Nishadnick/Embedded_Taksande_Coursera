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
 * @file stats.h
 * @brief This header file contains the Declaration and a bit of description 
 *			of all the functions that are being used in this program
 *
 * These are the following functions:
 * main() - The main entry point for your program
 * print_statistics() - A function that prints the statistics of an array including minimum, maximum, mean, and median.
 * print_array() -  Given an array of data and a length, prints the array to the screen
 * find_median() - Given an array of data and a length, returns the median value
 * find_mean() -  Given an array of data and a length, returns the mean
 * find_maximum() -  Given an array of data and a length, returns the maximum
 * find_minimum() -  Given an array of data and a length, returns the minimum
 * sort_array()
 *
 * @author <Nishad T.>
 * @date <21-june-2021>
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

unsigned int print_statistics(unsigned int test_int[], unsigned int len); 		

//@param   unsigned int test_int[]	Array of Unsigned Integers
//@param   unsigned int len 			Length of given Array

//@return : This function returns output from 4 functions
// Mean, Median, Maximum and Minimum
//****************************************************************************

unsigned int find_median(unsigned int test_int[], unsigned int len);	
//@param   unsigned int test_int[]	Array of Unsigned Integers
//@param   unsigned int len 			Length of given Array

//@return : This function returns the median  of test_int[] array
//****************************************************************************

unsigned int find_mean(unsigned int test_int[], unsigned int len) ;	

//@param   unsigned int test_int[]	Array of Unsigned Integers
//@param   unsigned int len 			Length of given Array

//@return : This function returns the mean  of test_int[] array
//****************************************************************************

unsigned int find_maximum(unsigned int test_int[], unsigned int len) ;

//@param   unsigned int test_int[]	Array of Unsigned Integers
//@param   unsigned int len 			Length of given Array

//@return : This function returns the Maximum  of test_int[] array
//****************************************************************************
unsigned int find_minimum(unsigned int test_int[], unsigned int len); 

//@param   unsigned int test_int[]	Array of Unsigned Integers
//@param   unsigned int len 			Length of given Array

//@return : This function returns the Minimum of test_int[] array
//****************************************************************************
unsigned int sort_array(unsigned int test_int[], unsigned int len);

//@param   unsigned int test_int[]	Array of Unsigned Integers
//@param   unsigned int len 			Length of given Array

//@return : This function sorts the test_int[] array into Descending order
//****************************************************************************
unsigned int print_array(unsigned int test_int[], unsigned int len);

//@param   unsigned int test_int[]	Array of Unsigned Integers
//@param   unsigned int len 			Length of given Array

//@return : This function prints the test_int[] array
//****************************************************************************


#endif /* __STATS_H__ */
