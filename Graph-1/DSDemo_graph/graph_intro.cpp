//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "graph_intro.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGraphIntroduceForm *GraphIntroduceForm;
//---------------------------------------------------------------------------
__fastcall TGraphIntroduceForm::TGraphIntroduceForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TGraphIntroduceForm::FormCreate(TObject *Sender)
{
     AnsiString AppPath;

     AppPath = ExtractFileDir (Application->ExeName);

     RichEdit1->Lines->LoadFromFile(AppPath + "\\data\\graph_intr.rtf");
     RichEdit2->Lines->LoadFromFile(AppPath + "\\data\\test.rtf");
}
//---------------------------------------------------------------------------

