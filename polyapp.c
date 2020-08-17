/* program to implement a simple application that constructs a polynomial expression
 * and evaluates it for certain predetermined values. 
 EG:
  <data file> 
     3,0
     2,1
     4,2
  <==> 
   3+2x+4x^2
  
 *************************************************************
 * Author          Dept.            Date            Notes
 *************************************************************
 * Xinchen Hou   Stats&CompSci    April 09 2020     Initial version
 * Xinchen Hou   Stats&CompSci    April 10 2020     Added functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "poly.h"
#include "utils.h"

//######################################  MAIN ###########################################

int main(int argc, char* argv[])
{

// check input
	if (argc != 2) { 
	fprintf(stderr,"Error, incorrect usage: ./polyapp <data file> \n"); 
        return 1;}

// else search for input file
   char* dataFile = argv[1];
   FILE* f = fopen ( dataFile ,"rt");

   // if unable to locate input data file, return ErrorCode 100
	if (f == NULL) {
		fprintf(stderr,"Error, unable to locate the data file\n");
		return 100;
	}

//
//read from input data file
//

	
    // read one line at a time from file
	for(;;){        
	      char line[100];
	      fgets(line,99,f);
              if (feof(f)){break;} //break if end of file
	    // pass line into functions
	      int c=0;
	      int e=0;
	      parse(line,&c,&e); // c=coeff, e=exponent in int
	      int returnCode = addPolyTerm(c,e);  // add to linked list
	         /*if (returnCode == 1)
		 { fprintf(stderr,"Error, program run out of memory\n");
			                exit(1);
		 }*/
	}
       
	displayPolynomial();


   // evaluate polynomial at (-2,-1,0,1,2)
      int i;

      for (i=-2;i<=2;i++){
       int r = evaluatePolynomial(i);
       printf("for x=%d, y=%d\n",i,r);
      }



return 1;
}
