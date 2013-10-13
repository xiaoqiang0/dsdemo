//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "graph_intro.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGraphIntroduceForm *GraphIntroduceForm;
TRichEditOleCallback roc;
//---------------------------------------------------------------------------
__fastcall TGraphIntroduceForm::TGraphIntroduceForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TGraphIntroduceForm::FormActivate(TObject *Sender)
{
     //RichEdit1->Perform(EM_SETOLECALLBACK,0,LPARAM(&roc));
     //RichEdit2->Perform(EM_SETOLECALLBACK,0,LPARAM(&roc));
     //RichEdit3->Perform(EM_SETOLECALLBACK,0,LPARAM(&roc));
     //RichEdit4->Perform(EM_SETOLECALLBACK,0,LPARAM(&roc));
}
//---------------------------------------------------------------------------

void __fastcall TGraphIntroduceForm::Button1Click(TObject *Sender)
{
     AnsiString AppPath;

     AppPath = ExtractFileDir (Application->ExeName);


     RichEdit1->Lines->LoadFromFile(AppPath + "\\data\\Graph_Introduction.rtf");
     RichEdit2->Lines->LoadFromFile(AppPath + "\\data\\Graph_Traverse.rtf");
     RichEdit4->Lines->LoadFromFile(AppPath + "\\data\\Graph_MinSpanTree.rtf");
     RichEdit3->Lines->LoadFromFile(AppPath + "\\data\\Graph_ShortestPath.rtf");
}
//---------------------------------------------------------------------------

void __fastcall TGraphIntroduceForm::FormClose(TObject *Sender, TCloseAction &Action)

{
RichEdit1->Clear();RichEdit2->Clear();RichEdit3->Clear();RichEdit4->Clear();
}
//---------------------------------------------------------------------------

