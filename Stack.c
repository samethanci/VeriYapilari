#include <stdio.h>
#include <stdlib.h>

#define NUMBEROFSTUDENTS 5

struct student{
 int studentNumber;
 char *studentLastName;
 char *studentFirstName;
 struct student *nextStudent;
};

typedef struct student Student;
typedef struct student *StudentPointer;

void printStudentStack( StudentPointer *studentStack );
void popStudent( StudentPointer *studentStack, StudentPointer *poppedStudent );
void pushStudent( StudentPointer *studentStack, int studentNumber, char *studentLastName, char *studentFirstName );

int studentNumbers [ NUMBEROFSTUDENTS ] = { 3493, 3462, 15, 6236, 199 };
char *studentLastNames [ NUMBEROFSTUDENTS ] = { "Sahin", "Aslan", "Ozkan", "Karabina", "Ozer" };
char *studentFirstNames [ NUMBEROFSTUDENTS ] = { "Varol", "Selcuk", "Ahmet", "Armagan", "Gulcan" };

int main( void ){
 StudentPointer studentStack = NULL;
 printStudentStack( &studentStack );

 //Adding students to the stack
 for( int studentIndex = 0; studentIndex < NUMBEROFSTUDENTS; studentIndex ++ ){
  pushStudent( &studentStack, studentNumbers[ studentIndex ], studentLastNames[ studentIndex ], studentFirstNames[ studentIndex ] );
 }
 printf( "\nAfter adding students to the stack...\n" );
 printStudentStack( &studentStack );
 //Adding students to the stack

 //Adding a new student to the stack
 int studentNumber = 1;
 char studentLastName [ 6 ] = { 'A', 'r', 't', 'a', 'n', '\0'};
 char studentFirstName [ 8 ] = { 'B', 'a', 't', 'u', 'h', 'a', 'n', '\0'};
 pushStudent( &studentStack, studentNumber, studentLastName, studentFirstName );
 printf( "\nAfter adding a new student to the stack...\n" );
 printStudentStack( &studentStack ); 
 //Adding a new student to the stack

 //Popping a student from the stack
 StudentPointer poppedStudent = ( StudentPointer )malloc( sizeof( Student ) );
 popStudent( &studentStack, &poppedStudent );
 printf( "\nAfter popping a student from the stack...\n" );
 printf( "Number:%-10dName:%-10sLastName:%-10s\n\n", poppedStudent->studentNumber, poppedStudent->studentFirstName, ( *poppedStudent ).studentLastName );
 printStudentStack( &studentStack );
 //Popping a student from the stack

 //Popping a student from the stack
 popStudent( &studentStack, &poppedStudent );
 printf( "\nAfter popping a student from the stack...\n" );
 printStudentStack( &studentStack );
 //Popping a student from the stack

 //Adding student to the stack
 pushStudent( &studentStack, poppedStudent->studentNumber, poppedStudent->studentLastName, poppedStudent->studentFirstName );
 printf( "\nAfter adding a new student to the stack...\n" );
 printStudentStack( &studentStack );
 //Adding student to the stack

 return 0;
}

void printStudentStack( StudentPointer *studentStack ){
 if( *studentStack != NULL ){
  StudentPointer currentStudent = *studentStack;
  while( currentStudent != NULL ){
   printf( "Number:%-10dFirstName:%-10sLastName:%-10s\n", currentStudent->studentNumber, currentStudent->studentFirstName, currentStudent->studentLastName );
   currentStudent = currentStudent->nextStudent;
  }
 }
 else{
  printf( "printStudentStack: There is no student in the stack...\n" );
 }
}
void popStudent( StudentPointer *studentStack, StudentPointer *poppedStudent ){
 if( *studentStack != NULL ){
  StudentPointer currentStudent = *studentStack;
  ( *poppedStudent )->studentNumber = currentStudent->studentNumber;
  ( *poppedStudent )->studentLastName = currentStudent->studentLastName;
  ( *poppedStudent )->studentFirstName = currentStudent->studentFirstName;
  *studentStack = currentStudent->nextStudent;
  free( currentStudent );
 }
 else{
  printf( "popStudent: There is no student in the stack...\n" );
 }
}
void pushStudent( StudentPointer *studentStack, int studentNumber, char *studentLastName, char *studentFirstName ){
 StudentPointer newStudent = ( StudentPointer )malloc( sizeof( Student ) );
 if( newStudent != NULL ){
  newStudent->studentNumber = studentNumber;
  newStudent->studentLastName = studentLastName;
  newStudent->studentFirstName = studentFirstName;
  //Adding student to the head of the stack
  newStudent->nextStudent = *studentStack;
  *studentStack = newStudent;
  //Adding student to the head of the stack
 }
 else{
  printf( "pushStudent: There is no memory space for adding a new student...\n" );
 }
}
