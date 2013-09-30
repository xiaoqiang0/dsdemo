//---------------------------------------------------------------------------

#ifndef graph_intro_uH
#define graph_intro_uH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class Tgraph_intro_frm : public TForm
{
__published:	// IDE-managed Components
    TRichEdit *RichEdit1;
    TButton *introBtn;
    TButton *Button1;
    void __fastcall introBtnClick(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall Tgraph_intro_frm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tgraph_intro_frm *graph_intro_frm;
//---------------------------------------------------------------------------
#endif
