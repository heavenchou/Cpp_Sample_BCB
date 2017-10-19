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

	String bigString = L"寫一些中文來試英文試";
	String littlestring = "(.)(文)";

	TRegEx * regex;
	TMatchCollection mycoll;
	TGroupCollection mygrps;

	regex = new TRegEx();
	mycoll = regex->Matches(bigString, littlestring);
	Edit1->Text = "Count: " + IntToStr(mycoll.Count);	// 找到二組 , 中文 和 英文
	Memo1->Lines->Add("First Collection: ");
	for (int i=0; i < mycoll.Count; i++)
	{
		Memo1->Lines->Add("Match #" + IntToStr(i) + ": " + mycoll.Item[i].Value);	// mycoll.Item[i].Value 分別是是中文和英文
		Memo1->Lines->Add("Group: " + IntToStr(i));
		mygrps = mycoll.Item[i].Groups;
		for (int j=0; j < mygrps.Count; j++)
			Memo1->Lines->Add("Value: " + mygrps.Item[j].Value);	// mygrps.Item[j].Value 有三個, 分別是 "中文", "中" , "文"
	};

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	String s = u"床前明月光 , 疑是地上霜, 舉頭望明月 ,低頭思故鄉";

	TStringDynArray r = TRegEx::Split(s, u"\\s*,\\s*");

	for(auto i=0; i<r.get_length(); i++)
	{
		ShowMessage(r[i]);
	}
}
//---------------------------------------------------------------------------
