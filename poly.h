typedef struct PolyTerm {
          int coeff;
          int expo;
          struct PolyTerm *next;
  }PolyTerm;

extern struct PolyTerm *head;


int addPolyTerm(int coef,int exp);
void displayPolynomial();
int evaluatePolynomial(int x);
