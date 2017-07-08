//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "main.h"
#include "class.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TfmMain *fmMain;
//---------------------------------------------------------------------------
__fastcall TfmMain::TfmMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::Button1Click(TObject *Sender)
{
	TmyClass * a = new TmyClass("heaven", 48, "02/16");

	Label1->Text = a->getname();
	Label2->Text = a->getage();

}
//---------------------------------------------------------------------------
