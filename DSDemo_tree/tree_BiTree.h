//---------------------------------------------------------------------------

#ifndef tree_BiTreeH
#define tree_BiTreeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include "tree.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Buttons.hpp>

//---------------------------------------------------------------------------
class TBiTreeForm : public TForm
{
__published:    // IDE-managed Components
    TGroupBox *GroupBox1;
    TButton *Button2;
    TPanel *pn;
    TImage *img;
    TTimer *Timer1;
    TButton *Button3;
    TPanel *Panel1;
    TPanel *Panel2;
    TMemo *Memo1;
    TLabel *Label1;
    TButton *Button1;
    TButton *Button4;
    TButton *Button6;
    TEdit *PreOrderEdit;
    TEdit *InOrderEdit;
    TEdit *TableEdit;
    TEdit *TreeArrayEdit;
    TPanel *Panel3;
    TPageControl *PageControl1;
    TTabSheet *TabSheet1;
    TTabSheet *树的广义表;
    TTabSheet *数组线性序列;
    TBitBtn *BitBtn1;
    TPanel *Panel4;
    TButton *Button5;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall BitBtn1Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button5Click(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall Button6Click(TObject *Sender);

    private:    // User declarations
        BiTree T;
        int max_depth;
        int height, width;

        int get_pos_x (BiTree T);
        int get_pos_y (BiTree T);
        // void traverse_visit(void * data);

        void PaintTree(BiTree T);
        void RepaintTree();
        //reset img canvas
        void ClearImage();

    public:        // User declarations
        __fastcall TBiTreeForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBiTreeForm *BiTreeForm;
//---------------------------------------------------------------------------
#endif
