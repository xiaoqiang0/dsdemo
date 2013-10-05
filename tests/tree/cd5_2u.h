//---------------------------------------------------------------------------

#ifndef cd5_2uH
#define cd5_2uH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TEdit *ein;
        TButton *show;
        TStringGrid *sg;
        TPanel *pn;
        TImage *Image1;
        TButton *end;
        TLabel *lout;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall einKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall showClick(TObject *Sender);
        void __fastcall endClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
