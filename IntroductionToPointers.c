#include <stdio.h>
#include <stdlib.h>

int main( void ){
 char firstCharVariable = 'A';
 int firstIntegerVariable = 10;
 float firstFloatVariable = 10.0f;
 double firstDoubleVariable = 10.f;

 char *firstCharPointer = NULL;
 int *firstIntegerPointer = NULL;
 float *firstFloatPointer = NULL;
 double *firstDoublePointer = NULL;
 
 printf( "Before assignment...\n" );
 printf( "firstCharPointer:%p\n", firstCharPointer );
 printf( "firstIntegerPointer:%p\n", firstIntegerPointer );
 printf( "firstFloatPointer:%p\n", firstFloatPointer );
 printf( "firstDoublePointer:%p\n", firstDoublePointer );

 printf( "After assignment operations...\n\n");

 firstCharPointer = &firstCharVariable;
 firstIntegerPointer = &firstIntegerVariable;
 firstFloatPointer = &firstFloatVariable;
 firstDoublePointer = &firstDoubleVariable;

 printf( "firstCharPointer:%p\n", firstCharPointer );
 printf( "firstIntegerPointer:%p\n", firstIntegerPointer );
 printf( "firstFloatPointer:%p\n", firstFloatPointer );
 printf( "firstDoublePointer:%p\n", firstDoublePointer );

 printf( "Dereferencing firstCharPointer:%c\n", *firstCharPointer );
 printf( "Dereferencing firstIntegerPointer:%d\n", *firstIntegerPointer );
 printf( "Dereferencing firstFloatPointer:%f\n", *firstFloatPointer ); 
 printf( "Dereferencing firstDoublePointer:%f\n", *firstDoublePointer );

 return 0;
}






















