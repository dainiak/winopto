#ifndef __COPTLIST_H__
#define __COPTLIST_H__

#include "coptobject.h"

//////////////////////////////////////////////////////////////////////////////
//COptList class definition:
//////////////////////////////////////////////////////////////////////////////
struct SOptListElement
{
  SOptListElement* PrevPointer; //Pointer to the previous element in the list
  SOptListElement* NextPointer; //Pointer to the next element in the list
  COptObject* Data;            //Data field
};
//////////////////////////////////////////////////////////////////////////////
class COptList
{
private:
  SOptListElement* CurrentElement; //Index of the current element
  SOptListElement* FirstElement;   //Index of the first element
  int NumOfElements;              //Total number of elements in the list

  //Public functions definitions:
public:
  void Next( void ); //Go to the next element of the list
  void Prev( void ); //Go to the previous element of the list
  void GoToStart( void ); //Go to the first element of the list
  void GoToEnd( void );   //Go to the last element of the list
  void FreeAccess( int );
  COptObject* GetElement( void ); //Get current element
  void SetElement( COptObject* );
  int GetNumOfElements( void );   //Get number of elements in the list
  void AddElement( void );        //Add new element to the list
  void RemoveCurrentElement( void ); //Remove current element from the list
  void Clear( void );             //Remove all elements from the list

  COptList( void );  //Constructor and
  ~COptList( void ); //destructor of the class
};

#endif