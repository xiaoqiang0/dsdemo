//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "graph_intro_u.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tgraph_intro_frm *graph_intro_frm;
//---------------------------------------------------------------------------
__fastcall Tgraph_intro_frm::Tgraph_intro_frm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tgraph_intro_frm::introBtnClick(TObject *Sender)
{
     AnsiString AppPath;

     AppPath = ExtractFileDir (Application->ExeName);

     RichEdit1->Lines->LoadFromFile(AppPath + "\\data\\graph_intr.rtf");

}
//---------------------------------------------------------------------------
void __fastcall Tgraph_intro_frm::Button1Click(TObject *Sender)
{
       AnsiString AppPath;

     AppPath = ExtractFileDir (Application->ExeName);

     RichEdit1->Lines->LoadFromFile(AppPath + "\\data\\test.rtf");

}
//---------------------------------------------------------------------------
