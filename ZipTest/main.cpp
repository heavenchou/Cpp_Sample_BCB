//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "main.h"
#include <System.ZLib.hpp>
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
void __fastcall TfmMain::btZipUnzipStrClick(TObject *Sender)
{
	// 字串壓縮再解壓
	String str1 = Edit1->Text;

	TMemoryStream * ms = new TMemoryStream();
	TZCompressionStream * zip = new TZCompressionStream(ms);

	// 寫入 zip
	zip->Write(str1.w_str(), str1.Length()*2);
	// 壓縮到 ms
	zip->Free();

	ms->Position = 0;
	// 由 ms 解到 unzip
	TZDecompressionStream *unzip = new TZDecompressionStream(ms);

	Memo1->Lines->LoadFromStream(unzip,TEncoding::Unicode);
	ms->Free();
}
//---------------------------------------------------------------------------
// 1. 標準的檔案壓縮
void __fastcall TfmMain::btFile2FileZipClick(TObject *Sender)
{
	TFileStream * in = new TFileStream("c:/temp/ziptest/zsource.txt", fmOpenRead);
	TFileStream * out = new TFileStream("c:/temp/ziptest/zzip.txt", fmCreate);

	TZCompressionStream * zip = new TZCompressionStream(out);

	zip->CopyFrom(in,0);

	zip->Free();
	out->Free();
	in->Free();
}
//---------------------------------------------------------------------------
// 2. 標準的檔案解壓縮
void __fastcall TfmMain::btFile2FileUnzipClick(TObject *Sender)
{
	TFileStream * in = new TFileStream("c:/temp/ziptest/zzip.txt", fmOpenRead);
	TFileStream * out = new TFileStream("c:/temp/ziptest/zunzip.txt", fmCreate);

	TZDecompressionStream *unzip = new TZDecompressionStream(in);

	out->CopyFrom(unzip,0);

	ShowString((TStream *)out);

	unzip->Free();
	out->Free();
	in->Free();

}

//---------------------------------------------------------------------------
void __fastcall TfmMain::btString2FileZipClick(TObject *Sender)
{
// 3. 字串壓縮到 UTF8 檔案

	// 來源是 unicode
	String us = u"試看有漢字的能不能順利壓縮，還有𠄣這種字及鉢。";
	int us_len = us.Length();
	char * c = new char[us_len * 6];
	// 轉成 utf8
	int c_len = UnicodeToUtf8(c,us.w_str(),us_len*6);


	TFileStream * out = new TFileStream("c:/temp/ziptest/zzip2.txt", fmCreate);
	TMemoryStream * ms = new TMemoryStream();

	TZCompressionStream * zip = new TZCompressionStream(ms);

	zip->Write(c,c_len-1);
	zip->Free();  // 要先 Free , ms 才有正確的內容

	char * cz = new char[ms->Size];
	ms->Position = 0;
	ms->Read(cz,ms->Size);

	out->Write(cz,ms->Size);
	out->Free();

	ms->Free();
}
//---------------------------------------------------------------------------
// 把字串秀出來
void __fastcall TfmMain::ShowString(TStream * ms)
{
	ms->Position = 0;
	Memo1->Lines->LoadFromStream(ms,TEncoding::UTF8);
}
//---------------------------------------------------------------------------

