#include <stdio.h>
#include <stdlib.h>

void printArray( int firstIntegerArray [], int numberOfElements );

int main( void ){
 int firstIntegerArray [ 10 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
 int *firstIntegerPointer = &firstIntegerArray[ 0 ];

 printArray( firstIntegerArray, 10 );

 for( int firstIntegerCounter = 0; firstIntegerCounter < 10; firstIntegerCounter ++ ){
  printf( "Address of %d element:%p\n", firstIntegerCounter, ( firstIntegerPointer + firstIntegerCounter ) );
 }
 
 for( int firstIntegerCounter = 0; firstIntegerCounter < 10; firstIntegerCounter ++ ){
  printf( "Value of the %d element in array:%d\n", firstIntegerCounter, *( firstIntegerPointer + firstIntegerCounter ) );
 }

 for( int firstIntegerCounter = 1; firstIntegerCounter < 10 ; firstIntegerCounter = firstIntegerCounter + 2 ){
  printf( "Value of the %d element in array:%d\n", firstIntegerCounter, *( firstIntegerPointer + firstIntegerCounter ) );
 }
 return 0;
}

void printArray( int firstIntegerArray [], int numberOfElements ){
 for( int firstIntegerCounter = 0; firstIntegerCounter < numberOfElements; firstIntegerCounter ++ ){
  printf( "Element:%d\n", firstIntegerArray[ firstIntegerCounter ] );
 }
}
