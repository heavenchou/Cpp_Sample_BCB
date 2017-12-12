//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
//---------------------------------------------------------------------------
class TfmMain : public TForm
{
__published:	// IDE-managed Components
	TButton *btZipUnzipStr;
	TEdit *Edit1;
	TButton *btFile2FileUnzip;
	TButton *btFile2FileZip;
	TButton *btString2FileZip;
	TMemo *Memo1;
	void __fastcall btZipUnzipStrClick(TObject *Sender);
	void __fastcall btFile2FileUnzipClick(TObject *Sender);
	void __fastcall btFile2FileZipClick(TObject *Sender);
	void __fastcall btString2FileZipClick(TObject *Sender);
private:	// User declarations
public:		// User declarations

	void __fastcall ShowString(TStream * ms);   // §â¦r¦ê¨q¥X¨Ó
	__fastcall TfmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmMain *fmMain;
//---------------------------------------------------------------------------
#endif
