//----------------------------------------------------------------------------
//C++Builder
// Copyright (c) 1995-2010 Embarcadero Technologies, Inc.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef search_stringH
#define search_stringH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class Tsearch_stringForm : public TForm
{
__published:	// IDE-managed Components
	TRichEdit *RichEdit1;
	TFindDialog *FindDialog1;
	TReplaceDialog *ReplaceDialog1;
    TPanel *Panel1;
    TButton *searchBtn;
    TButton *replaceBtn;
    TButton *Button3;
	void __fastcall Find1Click(TObject *Sender);
    void __fastcall Replace1Click(TObject *Sender);
    void __fastcall Find(TObject *Sender);
    void __fastcall Replace(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall searchBtnClick(TObject *Sender);
    void __fastcall replaceBtnClick(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	virtual __fastcall Tsearch_stringForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern Tsearch_stringForm *search_stringForm;
//---------------------------------------------------------------------------
#endif
