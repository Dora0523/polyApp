/* create linked list to store polynimial of arbitrary length 
 *
 *************************************************************
 * Xinchen Hou   Stats&CompSci    April 10 2020     Initial Version
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "poly.h"
#include "utils.h"

//create head
 PolyTerm* head = NULL;

//add node function
//   return 0 if success, 1 if failure
 int addPolyTerm (int coef, int exp){
   PolyTerm* temp = NULL;
   PolyTerm* currentNode = NULL;
   PolyTerm* nextNode = NULL;


  // individual node "temp"	 
   temp = (PolyTerm*)malloc(sizeof(PolyTerm));
   if (temp == NULL) return 1;

   temp->coeff = coef;
   temp->expo = exp;
   temp->next = NULL;

  // add to linked list 
   if (head == NULL){ head = temp;} //first node

   else{ //**** save exponents in order******
      currentNode = head;

      if (currentNode->expo > exp){
	      temp->next = currentNode;
	      head = temp;
       }


      else{
      nextNode = currentNode->next;
     // currentNode exp <= input exp < nextNode exp 
     // OR end of the list 
      while (nextNode != NULL){
	   if ((currentNode->expo <= exp) && (nextNode->expo > exp)){
		   break;}
	   currentNode = nextNode;
	   nextNode = nextNode->next;
	   }
      
      // merge term w/ same exp
      if (currentNode->expo == exp){
       currentNode->coeff = (currentNode->coeff)+coef;
      }else{
      // append after currentNode
        currentNode->next = temp;
	temp->next = nextNode;
      }
      }
      
   }      
 return 0;
 }

//displayPolynomial function
//
//
 void displayPolynomial (){
    PolyTerm* t = head;

    int a = 0; // a=0 if first term
    while (t != NULL){

	    if (t->coeff < 0){
	    printf("%dx%d",t->coeff,t->expo);} // negative coef
	    else if (a == 0){
            printf("%dx%d",t->coeff,t->expo);  // first term 
	    a = 1;}
	    else{
	    printf("+%dx%d",t->coeff,t->expo);}

	    t=t->next;

	    }
    printf("\n");

 }

//evalatePolynomial function

 int evaluatePolynomial (int x){
   PolyTerm* t = head;
   int result = 0;
   while (t != NULL){
	   int c = t->coeff;
	   int e = t->expo;
	   int a = powi(x,e);
	   result = result + c*a;

	   t=t->next;}

return result;}
