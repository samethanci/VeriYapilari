#include <stdio.h>
#include <stdlib.h>

#define NUMBEROFSTUDENTS 5

void printStudentNames( char* studentNames [] );

int main( void ){
 char *studentNames [ 5 ] ={ "Damla", "Serhat", "Ilgın", "Sedat", "Alihan" };
 printStudentNames( studentNames );

 return 0;
}

void printStudentNames( char* studentNames[] ){
 for( int firstIntegerCounter = 0; firstIntegerCounter < NUMBEROFSTUDENTS; firstIntegerCounter ++ ){
  printf( "StudentID:%d\tStudentName:%s\n", firstIntegerCounter + 1, *( studentNames + firstIntegerCounter ) );
 }
}
