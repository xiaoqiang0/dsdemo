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
#include "tree.h"
#include <Vcl.ComCtrls.hpp>

//---------------------------------------------------------------------------
class TBiTreeForm : public TForm
{
__published:    // IDE-managed Components
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
        TButton *Button1;
        TStatusBar *StatusBar1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);

    private:    // User declarations
        int max_depth;
        int height, width;
        BiTree T;
        int get_pos_x (BiTree T);
        int get_pos_y (BiTree T);
        void  PaintTree(BiTree T);
        void RepaintTree();

    public:        // User declarations
        __fastcall TBiTreeForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBiTreeForm *BiTreeForm;
//---------------------------------------------------------------------------
#endif
