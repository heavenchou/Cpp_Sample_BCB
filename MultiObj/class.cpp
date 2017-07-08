//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "class.h"
//---------------------------------------------------------------------------
//#pragma package(smart_init)
//#pragma resource "*.fmx"
//TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TmyClass::TmyClass(String sName, int iAge, String sBirthday)		// «Øºc¦¡
{
	Name = sName;
	Age = iAge;
    Birthday = sBirthday;
}
//---------------------------------------------------------------------------
__fastcall TmyClass::~TmyClass(void)	//
{

}
//---------------------------------------------------------------------------
String __fastcall TmyClass::getname(void)
{
	return Name;
}
//---------------------------------------------------------------------------
int __fastcall TmyClass::getage(void)
{
	return Age;
}
//---------------------------------------------------------------------------
