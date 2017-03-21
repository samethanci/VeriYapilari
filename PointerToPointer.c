#include <stdio.h>
#include <stdlib.h>

int main( void ){
 int firstIntegerVariable = 10;
 int *firstIntegerPointer = NULL;

 int **firstIntegerPointerToPointer = NULL;

 printf( "firstIntegerVariable:%d\n", firstIntegerVariable );
 printf( "firstIntegerPointer:%p\n", firstIntegerPointer );
 printf( "firstIntegerPointerToPointer:%p\n", firstIntegerPointerToPointer );

 firstIntegerPointer = &firstIntegerVariable;
 firstIntegerPointerToPointer = &firstIntegerPointer;

 printf( "After assignments ...\n" );
 printf( "firstIntegerPointer:%p\n", firstIntegerPointer );
 printf( "firstIntegerPointerToPointer:%p\n", firstIntegerPointerToPointer );

 printf( "Dereferencing firstIntegerPointer:%d\n", *firstIntegerPointer );
 printf( "Dereferencing firstIntegerPointerToPointer:%p\n", *firstIntegerPointerToPointer );
 printf( "Two level dereferencing firstIntegerPointerToPointer:%d\n", *( *firstIntegerPointerToPointer ) );

 return 0;
}
