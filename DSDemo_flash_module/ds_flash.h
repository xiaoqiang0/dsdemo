//---------------------------------------------------------------------------

#ifndef ds_flashH
#define ds_flashH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "ShockwaveFlashObjects_OCX.h"
#include <Vcl.OleCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TFlashForm : public TForm
{
__published:	// IDE-managed Components
    TShockwaveFlash *flash;
    TPanel *Panel1;
    TBitBtn *BitBtn1;
    TBitBtn *BitBtn2;
    TBitBtn *BitBtn3;
    TEdit *Edit1;
    TTimer *Timer1;
    void __fastcall BitBtn3Click(TObject *Sender);
    void __fastcall BitBtn2Click(TObject *Sender);
    void __fastcall BitBtn1Click(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFlashForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFlashForm *FlashForm;
extern void ShowFlashDemo(TComponent*parent, AnsiString title, AnsiString flash_file);
//---------------------------------------------------------------------------
#endif
