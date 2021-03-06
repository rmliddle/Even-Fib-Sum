#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PHI (1+sqrt(5))/2
#define PHIC (1-sqrt(5))/2
#define MU (2+sqrt(5))
#define MUC (2-sqrt(5))


double round(double d)
{
  if (d - floor(d) > 0.5) return ceil(d);
  return (double) (unsigned int) floor(d);
}

/* Sum even Fibonacci numbers below a threshold
 * 
 *
 *@t threshold
 *@a first sequence element
 *@b second sequence element
 * 
 *return s_{t,a,b}
 */

unsigned long sef(unsigned long t, unsigned long a, unsigned long b);
 

int main (int argc, char *argv[]){
  unsigned long t = atoi(argv[1]);
  unsigned long a = atoi(argv[2]);
  unsigned long b = atoi(argv[3]);
  printf( "%lu\n" , sef(t,a,b));
  return 0;
}

unsigned long sef(unsigned long t, unsigned long a, unsigned long b){

  //CASE 1: Boundary conditions a,b are both even
  if (a%2 == 0 && b%2 == 0) {


    /* General recurrence relation for fib numbers is given by fn = fn-1 + fn-2
     * This leads to a generalised closed form equation of the form:
     * f(n) = t1*PHI^n + t2*PHIC^n
     *
     *
     * t1, t2 can be solved by setting the boundary conditions a,b.
     * Reduction gives the generalised solutions:
     * t1 = (b-a*PHIC)/(PHI-PHIC)
     * t2 = (b-a*PHI)/(PHIC - PHI)
     */

    //THESE VARIABLES ARE NOT DECLARED/ASSIGNED IN THE PROGRAM REFINEMENT
    //THEY APPEAR HERE ONLY FOR HUMAN READABILITY
    //AS SUCH THEY CANNOT BE ALTERED
    const long double t1 = (b-a*PHIC)/(PHI-PHIC);
    const long double t2 = (b-a*PHI)/(PHIC - PHI);

    /* 
     * From here we wish to solve the equation for n, and take
     * N = floor(n):  t =  t1*PHI^n + t2*PHIC^n
     * to determine the number of terms in the sequence less than threshold t
     * to do so requires recognition of several cases:
     *
     *   f(n) = t1*PHI^n + t2*PHIC^n = t1*PHI^n + t2*(1/(-PHI)^n) = t
     */

    //ONE SUCH ROOT
    const long double n = log((t+sqrt(pow(t,2) + fabsl(4*t1*t2) ))/(2*t1))/log(PHI); //(8)


    long double N;
    if (n == floor(n)) N = n-1; //(11)
    else N = floor(n); //(12)
     

    /*Now we simply calculate the sum of elements up to and including element
     *at index N
     * This is given by the closed form equation:
     * 
     * s = t1*(1-pow(PHI,N+1))/(1-PHI) + t2*((1-pow(PHIC, N+1))/(1-PHIC);
     *
     * Obtained by taking the geometric series of the closed form above
     */
    return round( t1*(1-pow(PHI,N+1))/(1-PHI) + t2*((1-pow(PHIC, N+1))/(1-PHIC))); //(13)
    
  } else {

      long double A, B;
      /* In the case where out element a, b are not both even, we wish to produce 
       * a sequence of only the even elements for the given Fibonacci sequence.
       * To do so we require the first even elements of the Fibonacci sequence.
       */
      //CASE 2.1: Bound condition a is odd and b is even
      if (a%2 == 0 && b%2 == 1) {
	A = a; B = a + 2*b; //(18)      
      } else {
	//CASE 2.2: Boundary condition a is even and b is odd
	if (a%2 == 1 && b%2 == 0) {
	  A = b; B = 2*a + 3*b;//(21) 
       //CASE 2.3: Both boundary conditions are odd
	} else A = a + b; B = 3*a + 5*b; //(22)
	
      }

      /* From this point the algorithm follows much the same methodology as CASE 1
       * *expect* the recurrence sequence generated by the even numbers is not 
       * a Fibonacci sequence so the formulae are slightly altered 
       *
       *  Even numbers of a Fibonacci sequence are given by the recurrence relation
       *  tn = 4tn-1 + tn-2
       *
       *  Which has the closed form equation:
       *
       *  t(n) = s1*MU^n + s2*MUC^n 
       *  s1, s2 are given by a elimination:
       * 
       * s1 = (b-a*MUC)/(MU-MUC)
       * s2 = (b-a*MU)/(MUC - MU)
       */
     

      
      //AGAIN, AS WITH t1,t2 ; s1,s2 ARE ONLY DECLARED IN CODE
      //FOR CODE CLARITY
      const long double s1 = (B-A*MUC)/(MU-MUC);
      const long double s2 = (B-A*MU)/(MUC-MU);


      //ONE SUCH ROOT
      const long double n = log((t+sqrt(pow(t,2) + fabsl(4*s1*s2)))/(2*s1))/log(MU);

      long double N;
      if (n == floor(n)) N = n-1; //(30)
      else N = floor(n); //(31)

      
      return round(s1*((1-pow(MU,N+1))/(1-MU)) + s2*((1-pow(MUC, N+1))/(1-MUC)));//(32)

    }
}
