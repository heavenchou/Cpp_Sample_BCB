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

	XML 處理方法

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
		WideString Result = ParseChild(node);   // 分析主要的節點
		ShowMessage(Result);                    // 秀出成果
	}

}
//---------------------------------------------------------------------------
// 分析子節點
WideString __fastcall TfmMain::ParseChild(_di_IXMLNode node)
{
	WideString Result = "";

	_di_IXMLNodeList NodeList = node->GetChildNodes();  // 取得全部子節點

	// 逐一處理子節點
	for(int i = 0; i < NodeList->Count; i++)
	{
		_di_IXMLNode node = NodeList->Get(i);
		Result += ParseNode(node);		// 分析單一節點
	}

	return Result;
}
//---------------------------------------------------------------------------
// 分析單一節點
WideString __fastcall TfmMain::ParseNode(_di_IXMLNode node)
{
	WideString Result = "";

	// 處理標記
	if(node->GetNodeType() == 1) // ELEMENT_NODE = 1
	{
		UnicodeString TagName = node->NodeName;

		// 處理指定標記

		//if(TagName == "Tag1") return tag_Tag1(node);
		//else if(TagName == "Tag2") return tag_Tag2(node);
		//else
		{
			Result = tag_Default(node);
        }
	}

	// 處理文字
	if(node->GetNodeType() == 3) // TEXT_NODE = 3
	{
		Result = node->GetText();
	}

	return Result;
}
//---------------------------------------------------------------------------
// 處理指定標記
WideString __fastcall TfmMain::tag_Default(_di_IXMLNode node)
{
	WideString Result = "";

	// 取得標記名稱
	Result += node->NodeName;
	Result += ":";

	// 處理屬性

	// 處理全部屬性
	_di_IXMLNodeList Atts = node->GetAttributeNodes();

	// 逐一處理屬性
	for(int i = 0; i < Atts->Count; i++)
	{
		_di_IXMLNode Att = Atts->Get(i);
		UnicodeString AttName = Att->NodeName;
		UnicodeString AttVal = Att->GetChildValue(0);   // 第一種屬性法 , 注意 : DOM Vendor 使用 Omni XML 或 ADOM XML V4 時, 此行有錯
		UnicodeString AttVal2 = Att->GetNodeValue();    // 第二種屬性法
		Result += " [" + AttName + ":" + AttVal2 + ":" + AttVal2 + "] ";
	}

	// 處理指定屬性, 方法一 : node->GetAttribute("tag")

	System::OleVariant AttVal3 = node->GetAttribute("id2");
	if (!AttVal3.IsNull())
	{
		UnicodeString AttVal4 = AttVal3;
		Result += " [ id2=" + AttVal4 + "] ";
	}

	// 處理指定屬性, 方法二: Atts->FindNode("tag")->GetNodeValue()

	_di_IXMLNode node2 = Atts->FindNode("id3");
	if(node2)
	{
		UnicodeString AttVal5 = node2->GetNodeValue();
		Result += " [ id3=" + AttVal5 + "] ";
	}


	// 處理子節點
	Result += ParseChild(node);


	// 處理結尾
	Result += ":end\n";

	return Result;

}
//---------------------------------------------------------------------------