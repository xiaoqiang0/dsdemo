//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main_u.h"
#include "graph_alg_u.h"
#include "ds_flash.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ShockwaveFlashObjects_OCX"
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
    __fastcall TForm1::TForm1(TComponent* Owner)
: TForm(Owner)
{
}
//-------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Form2 = new TForm2(this);
    Form2->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
//    ShowFlashDemo(this, "\\data\\disarrayinsert.swf");
    ShowFlashDemo(this, "数组插入操作", "\\data\\好.swf");
}
//---------------------------------------------------------------------------
