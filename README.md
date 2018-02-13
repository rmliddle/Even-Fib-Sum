# Even Fibonacci Sum
This project is concerned with producing the sum of even numbers in a *generalised* Fibonacci sequence. A generalised Fibonacci sequence is a sequence with
the normal fibonacci property:
``` F(n) = F(n-1) + F(n-1) ```
however the choice of F(1) and F(2) are arbitrary.

even_fib_sum.pdf deals with a semi-rigerous derivation using a set theory loosely addopted from Carol Morgan's  "Programming from Specification".

The sef.c program itself is to serve as a template for a solution rather than a solution itself, as it solves the problem *only* under the correct parameters. For greater correctness, consider using arbitrary precision and/or languages that have floating point semantics that are reconcilable with the included document.  
Beyond this, improving the performance of this program beyond the standard exponentation is somewhat a point of conjecture (at least to the 
authour at the time of this writing).
