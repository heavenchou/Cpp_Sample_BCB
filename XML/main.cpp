//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "main.h"
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
	/*

	XML �B�z��k

	WideString wsResult = parseChild(Root);

	WideString parseChild(node)
	{
		Result = "";
		if(node->hasChild())
		{
			for(i=0;i<=node->childCount;i++)
			{
				Result += parseNode(node->child[i]);
			}
		}
		return Result;
	}

	WideString ParseNode (node)
	{
		if(node.type == "node")
		{
			tag = node.tag;

			if(tag == "Name") return tag_Name(node);
			if(tag == "Tel") return tag_Tel(node);
		}

		if(node.type == "Text")
		{
			return node.getText();
		}
	}

	WideString tag_Name(node)
	{
		Result = "";
		att = node.getAtt;
		Result += parseChild(node);
		Result += "end Name";
		return Result;
	}


	*/

	_di_IXMLNodeList NodeList;
	_di_IXMLNode node;

	XMLDocument1->Active = true;

	NodeList = XMLDocument1->ChildNodes;

	for (int i=0; i < NodeList->Count; i++)
	{
		node = NodeList->Get(i);
		WideString Result = ParseChild(node);   // ���R�D�n���`�I
		ShowMessage(Result);                    // �q�X���G
	}

}
//---------------------------------------------------------------------------
// ���R�l�`�I
WideString __fastcall TfmMain::ParseChild(_di_IXMLNode node)
{
	WideString Result = "";

	_di_IXMLNodeList NodeList = node->GetChildNodes();  // ���o�����l�`�I

	// �v�@�B�z�l�`�I
	for(int i = 0; i < NodeList->Count; i++)
	{
		_di_IXMLNode node = NodeList->Get(i);
		Result += ParseNode(node);		// ���R��@�`�I
	}

	return Result;
}
//---------------------------------------------------------------------------
// ���R��@�`�I
WideString __fastcall TfmMain::ParseNode(_di_IXMLNode node)
{
	WideString Result = "";

	// �B�z�аO
	if(node->GetNodeType() == 1) // ELEMENT_NODE = 1
	{
		UnicodeString TagName = node->NodeName;

		// �B�z���w�аO

		//if(TagName == "Tag1") return tag_Tag1(node);
		//else if(TagName == "Tag2") return tag_Tag2(node);
		//else
		{
			Result = tag_Default(node);
        }
	}

	// �B�z��r
	if(node->GetNodeType() == 3) // TEXT_NODE = 3
	{
		Result = node->GetText();
	}

	return Result;
}
//---------------------------------------------------------------------------
// �B�z���w�аO
WideString __fastcall TfmMain::tag_Default(_di_IXMLNode node)
{
	WideString Result = "";

	// ���o�аO�W��
	Result += node->NodeName;
	Result += ":";

	// �B�z�ݩ�

	// �B�z�����ݩ�
	_di_IXMLNodeList Atts = node->GetAttributeNodes();

	// �v�@�B�z�ݩ�
	for(int i = 0; i < Atts->Count; i++)
	{
		_di_IXMLNode Att = Atts->Get(i);
		UnicodeString AttName = Att->NodeName;
		UnicodeString AttVal = Att->GetChildValue(0);   // �Ĥ@���ݩʪk , �`�N : DOM Vendor �ϥ� Omni XML �� ADOM XML V4 ��, ���榳��
		UnicodeString AttVal2 = Att->GetNodeValue();    // �ĤG���ݩʪk
		Result += " [" + AttName + ":" + AttVal2 + ":" + AttVal2 + "] ";
	}

	// �B�z���w�ݩ�, ��k�@ : node->GetAttribute("tag")

	System::OleVariant AttVal3 = node->GetAttribute("id2");
	if (!AttVal3.IsNull())
	{
		UnicodeString AttVal4 = AttVal3;
		Result += " [ id2=" + AttVal4 + "] ";
	}

	// �B�z���w�ݩ�, ��k�G: Atts->FindNode("tag")->GetNodeValue()

	_di_IXMLNode node2 = Atts->FindNode("id3");
	if(node2)
	{
		UnicodeString AttVal5 = node2->GetNodeValue();
		Result += " [ id3=" + AttVal5 + "] ";
	}


	// �B�z�l�`�I
	Result += ParseChild(node);


	// �B�z����
	Result += ":end\n";

	return Result;

}
//---------------------------------------------------------------------------