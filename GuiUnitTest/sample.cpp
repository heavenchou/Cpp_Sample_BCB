//---------------------------------------------------------------------------

//#include <fmx.h>
#pragma hdrstop

#include "sample.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall CSample::CSample(TStringList * slTitle, TStringList * slResult)
{
	Titles = slTitle;
	Results = slResult;
}
//---------------------------------------------------------------------------
// �����������
void __fastcall CSample::RunAllTest()
{
	LogTest(u"���դ@", Test1());
	LogTest(u"���դG", Test2());
}
//---------------------------------------------------------------------------
// �x�s���յ��G
void __fastcall CSample::LogTest(String sTitle, bool bResult)
{
	String s = "0";
	if(bResult) s = "1";
	Titles->Add(sTitle);
	Results->Add(s);
}
//---------------------------------------------------------------------------
// �C�@�Ӵ��ն���
//---------------------------------------------------------------------------
bool __fastcall CSample::Test1()
{
	return true;
}
//---------------------------------------------------------------------------
bool __fastcall CSample::Test2()
{
	return false;
}
//---------------------------------------------------------------------------
