#include <stdafx.h>
#include "coptlist.h"

//////////////////////////////////////////////////////////////////////////////
//COptList class member functions:
//////////////////////////////////////////////////////////////////////////////
COptList::COptList( void )
{
  NumOfElements = 0;
  CurrentElement = NULL;
}
//////////////////////////////////////////////////////////////////////////////
COptList::~COptList( void )
{
  Clear();
}
//////////////////////////////////////////////////////////////////////////////
void COptList::Next( void )
{
  if( NumOfElements && CurrentElement->NextPointer )
    CurrentElement = CurrentElement->NextPointer;
}
//////////////////////////////////////////////////////////////////////////////
void COptList::Prev( void )
{
  if( NumOfElements && CurrentElement->PrevPointer )
    CurrentElement = CurrentElement->PrevPointer;
}
//////////////////////////////////////////////////////////////////////////////
void COptList::GoToStart( void )
{
  if( NumOfElements )
    CurrentElement = FirstElement;
}
//////////////////////////////////////////////////////////////////////////////
void COptList::GoToEnd( void )
{
  if( NumOfElements )
    while( CurrentElement->NextPointer )
      Next();
}
//////////////////////////////////////////////////////////////////////////////
void COptList::FreeAccess( int Number )
{
  if( NumOfElements && Number < NumOfElements )
  {
    GoToStart();

    for( int i = 0; i < Number; i++ )
      Next();
  }
}
//////////////////////////////////////////////////////////////////////////////
COptObject* COptList::GetElement( void )
{
  if( !NumOfElements )
    AfxMessageBox("Internal Error: GETELEMENT", 1, 0 );

  return CurrentElement->Data;
}
//////////////////////////////////////////////////////////////////////////////
void COptList::SetElement( COptObject* NewObject )
{
  CurrentElement->Data = NewObject;
}
//////////////////////////////////////////////////////////////////////////////
int COptList::GetNumOfElements( void )
{
  return NumOfElements;
}
//////////////////////////////////////////////////////////////////////////////
void COptList::AddElement( void )
{
  SOptListElement* NewElement;

  NewElement = new SOptListElement;

  if( !NewElement )
    AfxMessageBox("Internal Error: ADDELEMENT", 1, 0 );

  if( NumOfElements )
  {
    NewElement->NextPointer = CurrentElement->NextPointer;
    CurrentElement->NextPointer = NewElement;
    NewElement->PrevPointer = CurrentElement;
    if( NewElement->NextPointer ) NewElement->NextPointer->PrevPointer = NewElement;
  }
  else
  {
    NewElement->NextPointer = NULL;
    NewElement->PrevPointer = NULL;
    FirstElement = NewElement;
  }

  CurrentElement = NewElement;
  NumOfElements++;
}//AddElement
//////////////////////////////////////////////////////////////////////////////
void COptList::RemoveCurrentElement( void )
{
  if( !NumOfElements )
    exit( 2 );

  if( CurrentElement == FirstElement )
  {
    CurrentElement = FirstElement->NextPointer;
    delete FirstElement;
    FirstElement = CurrentElement;
  }
  else
  {
    SOptListElement* TempElement;

    TempElement = CurrentElement->PrevPointer;
    CurrentElement->PrevPointer->NextPointer = CurrentElement->NextPointer;

    if( CurrentElement->NextPointer ) 
      CurrentElement->NextPointer->PrevPointer = CurrentElement->PrevPointer;
    delete CurrentElement;

    CurrentElement = TempElement;
  }
  NumOfElements--;
}//RemoveCurrentElement
//////////////////////////////////////////////////////////////////////////////
void COptList::Clear( void )
{
  SOptListElement* TempElement;
  GoToStart();

  for( int i = 0; i < NumOfElements; i++ )
  {
    TempElement = CurrentElement->NextPointer;
    delete CurrentElement;
    CurrentElement = TempElement;
  }

  NumOfElements = 0;
  CurrentElement = NULL;
  FirstElement = NULL;
}//Clear