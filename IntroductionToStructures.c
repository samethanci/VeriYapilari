#include <stdio.h>
#include <stdlib.h>

#define NUMBEROFSTUDENTS 4

struct student{
 int finalGrade;
 int midtermGrade;
 char *studentNumber;
 char *studentLastName;
 char *studentFirstName;
};

void printStudentInformation( struct student *studentPointer );

int main( void ){
 char *studentFirstNames [ 4 ] = { "Serhat", "Alihan","Ilgın", "Varol" };
 char *studentLastNames [ 4 ] = { "Karabina", "Ozer", "Aslan", "Pehlivan" };
 char *studentNumbers [ 4 ] = { "102350", "235232", "235235", "230231" };
 int finalGrades [ 4 ] = { 100, 100, 100, 100 };
 int midtermGrades [ 4 ] = { 100, 100, 100, 100 };
  
 struct student students [ 4 ];  

 for( int studentIndex = 0; studentIndex < NUMBEROFSTUDENTS; studentIndex ++ ){
  students[ studentIndex ].finalGrade = finalGrades[ studentIndex ];
  students[ studentIndex ].midtermGrade = midtermGrades[ studentIndex ];
  students[ studentIndex ].studentFirstName = studentFirstNames[ studentIndex ];
  students[ studentIndex ].studentLastName = studentLastNames[ studentIndex ];
  students[ studentIndex ].studentNumber = studentNumbers[ studentIndex ];
 }

 for( int studentIndex = 0; studentIndex < NUMBEROFSTUDENTS; studentIndex ++ ){
  printStudentInformation( &students[ studentIndex ] );
 }
 
 return 0;
}

void  printStudentInformation( struct student *studentPointer ){
 printf( "%s\t%s\t%s\t%d\t%d\n", studentPointer->studentFirstName, studentPointer->studentLastName, studentPointer->studentNumber, studentPointer->finalGrade, studentPointer->midtermGrade );
}

