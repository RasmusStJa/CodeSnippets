#include <stdio.h>

//Get the length of any integer.
//NOTE: use math.h
unsigned int int_length(const int number){
  return floor(log10(abs(number))) + 1;
}

//Fastest way to calculate the nth fibonacci number
unsigned int fib(unsigned int n) {
  if (n == 0){ return 0; }
  unsigned int x = 0, y = 1, z = 0;
  for (unsigned int i = 1; i < n; i++) {
    z = x + y;
    x = y;
    y = z;
  }
  return z;
}

//Fast sqrt approximation
//AKA: The Newton-Raphson Method
static unsigned int usqrt4(int number) {
    unsigned int a, b;

    if (val < 2) { return number }; /* avoid div/0 */
    a = 1255;       /* starting point is relatively unimportant */

    //NOTE: This uses 5 for 32bit, but add an extra one for 64bit
    b = number / a; a = (a + b) / 2;
    b = number / a; a = (a + b) / 2;
    b = number / a; a = (a + b) / 2;
    b = number / a; a = (a + b) / 2;
    //b = number / a; a = (a + b) / 2;
  
    return a;
}

//Fast inverse sqrt
//idfk just look here: https://en.wikipedia.org/wiki/Fast_inverse_square_root
//NOTE: comments not by me
float inv_sqrt(float number)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;						// evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
  //y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return y;
}

//How to pass a function as a parameter
void func(void (*f)(int)) {
  (*f)(i);
}

//Print any matrix containing ints
void printMatrix(const int matrix[ROWS][COLUMNS]) {
    unsigned int rows = sizeof(matrix) / sizeof(matrix[0]);
    unsigned int columns = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    unsigned int length = rows * columns;
    
    //print every node in the same line
    printf("     "); //formatting
    for (unsigned int i = 0; i < columns; i++) {
        printf("%d     ", i);
        //if less than 2 characters, add a space
        if (i < 10) { printf(" "); }
    }
    printf("\n");
    for (unsigned int y = 0; y < rows; y++) { //column
        for (unsigned int x = 0; x < columns; x++) { //row
            //at start of each line print index
            if (x == 0) {
                //compensate for the extra space
                if (y < 10) { printf(" "); }
                printf("%d  ", y);
            }
            if (matrix[y][x] < 10) { printf(" "); }
            printf("%.2f  ", matrix[x][y]);
        }
        printf("\n");
    }
}

int main(){
  //Inverse for loop
  //NOTE: prints 99 - 0
  for (int i = 100; i-- > 0;) {
    printf("%d", i);
  };
  
  return 0;
}
