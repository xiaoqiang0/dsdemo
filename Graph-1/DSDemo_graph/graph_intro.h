//---------------------------------------------------------------------------

#ifndef graph_introH
#define graph_introH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TGraphIntroduceForm : public TForm
{
__published:	// IDE-managed Components
    TRichEdit *RichEdit1;
    TPageControl *PageControl2;
    TTabSheet *TabSheet1;
    TTabSheet *TabSheet2;
    TTabSheet *TabSheet3;
    TRichEdit *RichEdit2;
    TRichEdit *RichEdit3;
    void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TGraphIntroduceForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGraphIntroduceForm *GraphIntroduceForm;
//---------------------------------------------------------------------------
#endif
