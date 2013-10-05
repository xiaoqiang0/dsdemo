//---------------------------------------------------------------------------

#ifndef cd5_1uH
#define cd5_1uH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TEdit *ein;
        TPanel *pn;
        TButton *end;
        TLabel *Label1;
        TLabel *lout;
        TImage *Image1;
        void __fastcall einKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall endClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
