//---------------------------------------------------------------------------

#ifndef ClassH
#define ClassH
//---------------------------------------------------------------------------
//#include <System.Classes.hpp>
//#include <FMX.Controls.hpp>
//#include <FMX.Forms.hpp>
//---------------------------------------------------------------------------
class TmyClass
{
//__published:	// IDE-managed Components
private:	// User declarations
	String Name;
	int Age;
	String Birthday;
public:		// User declarations

	String __fastcall getname();
	int _fastcall getage();
	__fastcall TmyClass(String sName, int iAge, String sBirthday);
    __fastcall ~TmyClass();
};
//---------------------------------------------------------------------------
//extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

