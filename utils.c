 /*Function parse and powi
  * *************************************************************
 * Author          Dept.            Date            Notes
 *************************************************************
 * Xinchen Hou   Stats&CompSci    April 10 2020     Initial version
 */



/* 
 * FUNCTION PARSE
 *
 *INPUT: 
         String
	 int pointer
	 int pointer
 *
 *OUTPUT:
         coef -> int pointer
	 exponent -> int pointer

 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
   void parse (char inputS[], int* c, int* e ){
   	   
   //printf("%s",inputS);  //=> "coef exp"
   char a[10];
   char b[10];
   sscanf(inputS,"%s %s",a,b); // a,b = coef and exp in array form
   int coe = (atoi(a));  // change into int
   int exp = (atoi(b));
   *c = coe;
   *e = exp;

   }



/* FUNCTION POWI
 *
 * INPUT: 
 *      int x
 *      int exponent
 * OUTPUT:
 *      int x^exponent
 */
  int powi ( int base, int power ){
   int result = 1;
   
   if (power == 0){return result;}
   else
   while (power != 0) {
	   result = result * base;
	   power --;
   }
	    

return result;
  }
