//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#include "System.RegularExpressions.hpp"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

	String bigString = L"�g�@�Ǥ���Ӹխ^���";
	String littlestring = "(.)(��)";

	TRegEx * regex;
	TMatchCollection mycoll;
	TGroupCollection mygrps;

	regex = new TRegEx();
	mycoll = regex->Matches(bigString, littlestring);
	Edit1->Text = "Count: " + IntToStr(mycoll.Count);	// ���G�� , ���� �M �^��
	Memo1->Lines->Add("First Collection: ");
	for (int i=0; i < mycoll.Count; i++)
	{
		Memo1->Lines->Add("Match #" + IntToStr(i) + ": " + mycoll.Item[i].Value);	// mycoll.Item[i].Value ���O�O�O����M�^��
		Memo1->Lines->Add("Group: " + IntToStr(i));
		mygrps = mycoll.Item[i].Groups;
		for (int j=0; j < mygrps.Count; j++)
			Memo1->Lines->Add("Value: " + mygrps.Item[j].Value);	// mygrps.Item[j].Value ���T��, ���O�O "����", "��" , "��"
	};

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	String s = u"�ɫe����� , �ìO�a�W��, �|�Y����� ,�C�Y��G�m";

	TStringDynArray r = TRegEx::Split(s, u"\\s*,\\s*");

	for(auto i=0; i<r.get_length(); i++)
	{
		ShowMessage(r[i]);
	}
}
//---------------------------------------------------------------------------
