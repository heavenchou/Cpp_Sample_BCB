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
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.omnixmldom.hpp>
#include <Xml.adomxmldom.hpp>
#include <Xml.Win.msxmldom.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.TreeView.hpp>
//---------------------------------------------------------------------------
class TfmMain : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TXMLDocument *XMLDocument1;
	TTreeView *TreeView1;
	TTreeViewItem *TreeViewItem1;
	TTreeViewItem *TreeViewItem2;
	TTreeViewItem *TreeViewItem3;
	TTreeViewItem *TreeViewItem4;
	TTreeViewItem *TreeViewItem5;
	TTreeViewItem *TreeViewItem6;
	TPanel *Panel1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations

	WideString __fastcall ParseChild(_di_IXMLNode node);
	WideString __fastcall ParseNode(_di_IXMLNode node);
	WideString __fastcall tag_Default(_di_IXMLNode node);

	__fastcall TfmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmMain *fmMain;
//---------------------------------------------------------------------------
#endif
