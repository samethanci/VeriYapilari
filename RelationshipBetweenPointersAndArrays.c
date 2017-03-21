#include <stdio.h>
#include <stdlib.h>

#define NUMBEROFELEMENTS 10

int main( void ){
 char firstCharacterArray [ 10 ] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
 char *firstCharacterPointer = firstCharacterArray;

 for( int firstIntegerCounter = 0; firstIntegerCounter < NUMBEROFELEMENTS; firstIntegerCounter ++ ){
  printf( "Value of the %d element in array: %c\n", firstIntegerCounter, *( firstCharacterPointer + firstIntegerCounter ) );
 }
 return 0;
}
