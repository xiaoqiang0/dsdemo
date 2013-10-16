//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ds_flash.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ShockwaveFlashObjects_OCX"
#pragma resource "*.dfm"
TFlashForm *FlashForm;

void ShowFlashDemo(TComponent*parent, AnsiString title, AnsiString flash_file)
{
    AnsiString AppPath;
    AppPath = ExtractFileDir (Application->ExeName);
    TFlashForm *my_flash;
    TForm *p = (TForm *) parent;

    //Check if flash installed
    Activex::TCLSID ClassID;
    if(CLSIDFromProgID(PWideChar("ShockwaveFlash.ShockwaveFlash"), &ClassID) == S_OK){
        Application->MessageBox(PWideChar(WideString("ShockwaveFlash 控件没有安装")), p->Caption.c_str(), MB_ICONINFORMATION | MB_OK);
        return;
    }

    try {
        my_flash = new TFlashForm(p);
    } catch(const Exception &E) {
        Application->MessageBox(E.Message.c_str(),
                p->Caption.c_str(),
                MB_ICONINFORMATION | MB_OK);
    }

    if (my_flash != NULL) {
       my_flash->Caption = title;
        my_flash->flash->Movie = AppPath + flash_file;
        my_flash->ShowModal();
    }
}

//---------------------------------------------------------------------------
__fastcall TFlashForm::TFlashForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFlashForm::BitBtn3Click(TObject *Sender)
{
     Close();
}
//---------------------------------------------------------------------------

void __fastcall TFlashForm::BitBtn2Click(TObject *Sender)
{
     flash->Stop();

}
//---------------------------------------------------------------------------
void __fastcall TFlashForm::BitBtn1Click(TObject *Sender)
{
flash->Play();
}
//---------------------------------------------------------------------------
void __fastcall TFlashForm::FormResize(TObject *Sender)
{
    ActiveControl=NULL;
    ActiveControl=flash;
}
//---------------------------------------------------------------------------
void __fastcall TFlashForm::Timer1Timer(TObject *Sender)
{    int n =  flash->CurrentFrame();
     Edit1->Text = IntToStr(n);
}
//---------------------------------------------------------------------------

