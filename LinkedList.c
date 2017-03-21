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
typedef struct student* StudentPointer;

void printStudentList( StudentPointer *studentList );
void deleteStudent( StudentPointer *studentList, int studentNumber );
void searchStudent( StudentPointer *studentList, int studentNumber, StudentPointer *searchedStudent );
void insertStudent( StudentPointer *studentList, int studentNumber, char *studentLastName, char* studentFirstName );

int studentNumbers [ NUMBEROFSTUDENTS ] = { 1023, 102, 100, 9999, 23523 };
char *studentLastNames [ NUMBEROFSTUDENTS ] = { "Aslan", "Sahin", "Ozkan", "Sahin", "Senturk" };
char *studentFirstNames [ NUMBEROFSTUDENTS ] = { "Ahmet", "Varol", "Sedat", "Omer", "Selcuk" };

int main( void ){

 //Define a pointer for head of the linked list
 StudentPointer studentList = NULL;
 //Define a pointer for head of the linked list

 //Invoking printStudentList method
 printf( "After invoking printStudentList method...\n" );
 printStudentList( &studentList );
 //Invoking printStudentList method

 //Adding students to the linked list
 for( int studentIndex = 0; studentIndex < NUMBEROFSTUDENTS; studentIndex ++ ){
  insertStudent( &studentList, studentNumbers[ studentIndex ], studentLastNames[ studentIndex ], studentFirstNames[ studentIndex ] );
 }
 printf( "\nAfter adding students to the linked list...\n" );
 printStudentList( &studentList );

 //Adding a new student to the linked list
 int studentNumber = 40000 ;
 char studentLastName [ 7 ] = { 'C', 'a', 'k', 'm', 'a', 'k', '\0' };
 char studentFirstName [ 8 ] = { 'N', 'a', 'g', 'i', 'h', 'a', 'n', '\0' };
 insertStudent( &studentList, studentNumber, studentLastName, studentFirstName );
 printf( "\nAfter adding a new student with the number :%d to the linked list...\n",  studentNumber );
 printStudentList( &studentList );
 //Adding a new student to the linked list

 //Searching a student 
 int searchedStudentNumber = 102; 
 StudentPointer searchedStudent = NULL;
 searchStudent( &studentList, searchedStudentNumber, &searchedStudent );
 printf( "\nAfter searching the student with the number :%d\n", searchedStudentNumber );
 if( searchedStudent != NULL ){
  printf( "Number:%-10dFirstName:%-10sLastName:%-10s\n", searchedStudent->studentNumber, searchedStudent->studentFirstName, searchedStudent->studentLastName );
 }
 else{
  printf( "\nThere is no student with the number :%d in the linked list...\n", searchedStudentNumber );
 }
 //Searching a student

 //Deleting a student from linked list
 int deletedStudentNumber = 1023;
 deleteStudent( &studentList, deletedStudentNumber );
 printf( "After invoking deleteStudent method...\n" );
 printStudentList( &studentList );
 //Deleting a student from linked list

 //Deleting a student from linked list
 deletedStudentNumber = 40000;
 printf( "\nAfter invoking deleteStudent method...\n" );
 deleteStudent( &studentList, deletedStudentNumber );
 printStudentList( &studentList );
 //Deleting a student from linked list

 return 0;
}

void printStudentList( StudentPointer *studentList ){
 if( *studentList != NULL ){
  StudentPointer currentStudent = *studentList;
  while( currentStudent != NULL ){
   printf( "Number:%-10dFirstName:%-10sLastName:%-10s\n", currentStudent->studentNumber, currentStudent->studentFirstName, currentStudent->studentLastName );
   currentStudent = currentStudent->nextStudent;
  }
 }
 else{
  printf( "printStudentList: There is no student in the linked list...\n" );
 }
}
void deleteStudent( StudentPointer *studentList, int studentNumber ){
 if( *studentList != NULL ){
  StudentPointer previousStudent = NULL;
  StudentPointer currentStudent = *studentList;
  //Determining the location of the deleted student
  while( currentStudent != NULL && currentStudent->studentNumber != studentNumber ){
   previousStudent = currentStudent;
   currentStudent = currentStudent->nextStudent;
  }
  if( currentStudent != NULL ){
   if( previousStudent != NULL ){
    previousStudent->nextStudent = currentStudent->nextStudent;
   }
   else{
    *studentList = currentStudent->nextStudent;
   }
   free( currentStudent );
  }
  else{
   printf( "deleteStudent: The student with the number %d was not included by the list...\n", studentNumber );
  }
  //Determining the location of the deleted student
 }
 else{
  printf( "deleteStudent: There is no student in the linked list...\n" );
 }
}
void searchStudent( StudentPointer *studentList, int studentNumber, StudentPointer *searchedStudent ){
 if( *studentList != NULL ){
  StudentPointer currentStudent = *studentList;
  while( currentStudent != NULL && currentStudent->studentNumber != studentNumber ){
   currentStudent = currentStudent->nextStudent;
  }
  if( currentStudent != NULL ){
   *searchedStudent = currentStudent;
  }
 }
 else{
  printf( "searchStudent:There is no student in the linked list...\n" );
 }
}
void insertStudent( StudentPointer *studentList, int studentNumber, char *studentLastName, char *studentFirstName ){
 StudentPointer newStudent = ( StudentPointer )malloc( sizeof( Student ) );
 if( newStudent != NULL ){
  newStudent->studentNumber = studentNumber;
  newStudent->studentLastName = studentLastName;
  newStudent->studentFirstName = studentFirstName;

  //Determining the correct position of the new student
  StudentPointer previousStudent = NULL;
  StudentPointer currentStudent = *studentList;
  while( currentStudent != NULL && currentStudent->studentNumber < studentNumber ){
   previousStudent = currentStudent;
   currentStudent = currentStudent->nextStudent;
  }
  //Determining the correct postion of the new student
  
  //Adding the new student to the list
  if( previousStudent != NULL ){
   previousStudent->nextStudent = newStudent;
   newStudent->nextStudent = currentStudent;
  }
  else{
   newStudent->nextStudent = *studentList;
   *studentList = newStudent;
  }
 //Adding the new student to the list
 }
 else{
  printf( "insertStudent:There is no space in the memory for new student...\n" );
 }
}
