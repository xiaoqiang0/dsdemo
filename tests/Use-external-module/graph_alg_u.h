//---------------------------------------------------------------------------
#ifndef cd8_3uH
#define cd8_3uH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Grids.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
    __published:	// IDE-managed Components
        TPanel *pnl; //面板空间
        TImage *img; //图像
        TGroupBox *GroupBox1;
        TButton *CreateNodeBt;
        TButton *ShortestPathBt;
        TButton *BtClearMemo;
        TRadioGroup *GraphType;
        TRadioButton *RadioButtonDirect;
        TRadioButton *RadioButtonNoDirect;
        TMemo *memo;
        TPageControl *PageControl;
        TTabSheet *TabSheetDirect;
        TTabSheet *TabSheetNoDirect;
        TButton *ResetBt;
        TGroupBox *GroupBox2;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        TButton *Button7;
        void __fastcall CreateNodeBtClick(TObject *Sender);   //生成顶点按钮点击函数
        void __fastcall ShortestPathBtClick(TObject *Sender);   //最短路径按钮点击函数
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall imgMouseDown(TObject *Sender, TMouseButton Button,
                TShiftState Shift, int X, int Y);    //鼠标按下函数
        void __fastcall imgMouseUp(TObject *Sender, TMouseButton Button,
                TShiftState Shift, int X, int Y);
        void __fastcall BtClearMemoClick(TObject *Sender);
        void __fastcall RadioButtonNoDirectClick(TObject *Sender);
        void __fastcall RadioButtonDirectClick(TObject *Sender);
        void __fastcall ResetBtClick(TObject *Sender);



    private:	        // User declarations
    public:		// User declarations
		__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
