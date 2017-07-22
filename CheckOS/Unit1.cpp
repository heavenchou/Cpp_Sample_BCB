//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CornerButton1Click(TObject *Sender)
{
	ShowMessage("Start");

#ifdef WINDOWS
	ShowMessage("WINDOWS");
#endif
#ifdef _WINDOWS
	ShowMessage("_WINDOWS");
#endif
#ifdef _WINDOWS_
	ShowMessage("_WINDOWS_");
#endif
#ifdef __WINDOWS__
	ShowMessage("__WINDOWS__");
#endif

#ifdef Windows
	ShowMessage("Windows");
#endif
#ifdef _Windows
	ShowMessage("_Windows");
#endif
#ifdef _Windows_
	ShowMessage("_Windows_");
#endif
#ifdef __Windows__
	ShowMessage("__Windows__");
#endif


#ifdef WIN
	ShowMessage("WIN");
#endif
#ifdef _WIN
	ShowMessage("_WIN");
#endif
#ifdef _WIN_
	ShowMessage("_WIN_");
#endif
#ifdef __WIN__
	ShowMessage("__WIN__");
#endif

#ifdef Win
	ShowMessage("Win");
#endif
#ifdef _Win
	ShowMessage("_Win");
#endif
#ifdef _Win_
	ShowMessage("_Win_");
#endif
#ifdef __Win__
	ShowMessage("__Win__");
#endif

#ifdef WIN32
	ShowMessage("WIN32");
#endif
#ifdef _WIN32
	ShowMessage("_WIN32");
#endif
#ifdef _WIN32_
	ShowMessage("_WIN32_");
#endif
#ifdef __WIN32__
	ShowMessage("__WIN32__");
#endif

#ifdef Win32
	ShowMessage("Win32");
#endif
#ifdef _Win32
	ShowMessage("_Win32");
#endif
#ifdef _Win32_
	ShowMessage("_Win32_");
#endif
#ifdef __Win32__
	ShowMessage("__Win32__");
#endif

#ifdef WIN64
	ShowMessage("WIN64");
#endif
#ifdef _WIN64
	ShowMessage("_WIN64");
#endif
#ifdef _WIN64_
	ShowMessage("_WIN64_");
#endif
#ifdef __WIN64__
	ShowMessage("__WIN64__");
#endif

#ifdef Win64
	ShowMessage("Win64");
#endif
#ifdef _Win64
	ShowMessage("_Win64");
#endif
#ifdef _Win64_
	ShowMessage("_Win64_");
#endif
#ifdef __Win64__
	ShowMessage("__Win64__");
#endif

#ifdef __ANDROID__
	ShowMessage("__ANDROID__");
#endif
#ifdef __APPLE__
	ShowMessage("__APPLE__");
#endif
#ifdef __arm__
	ShowMessage("__arm__");
#endif
#ifdef __arm64__
	ShowMessage("__arm64__");
#endif

}
//---------------------------------------------------------------------------
