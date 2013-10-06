//---------------------------------------------------------------------------

#ifndef cd5_3uH
#define cd5_3uH
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
        TGroupBox *GroupBox1;
        TEdit *ein;
        TButton *Button2;
        TButton *Button5;
        TPanel *pn;
        TImage *img;
        TTimer *Timer1;
        TButton *Button3;
    TPanel *Panel1;
    TPanel *Panel2;
    TMemo *Memo1;
    TLabel *Label1;
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
    void __fastcall einKeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
