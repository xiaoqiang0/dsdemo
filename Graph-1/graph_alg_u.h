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
class TFormGraphAlgorithm : public TForm
{
    __published:	// IDE-managed Components
        TPanel *pnl; //面板空间
        TImage *img; //图像
        TGroupBox *GroupBox1;
    TButton *CreateNodeBtn;
    TButton *ShortestPathBtn;
        TRadioGroup *GraphType;
    TRadioButton *DirectBtn;
    TRadioButton *NoDirectBtn;
        TMemo *memo;
        TPageControl *PageControl;
        TTabSheet *TabSheetDirect;
        TTabSheet *TabSheetNoDirect;
    TButton *ResetBtn;
        TGroupBox *GroupBox2;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
    TButton *FloydBtn;
        TButton *Button7;
    TButton *DijBtn;
        void __fastcall my_print (String info);
        void __fastcall CreateNodeBtnClick(TObject *Sender);   //生成顶点按钮点击函数

        void __fastcall ShortestPathBtnClick(TObject *Sender);   //最短路径按钮点击函数
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall imgMouseDown(TObject *Sender, TMouseButton Button,
                TShiftState Shift, int X, int Y);    //鼠标按下函数
        void __fastcall imgMouseUp(TObject *Sender, TMouseButton Button,
                TShiftState Shift, int X, int Y);
        void __fastcall BtClearMemoClick(TObject *Sender);
        void __fastcall NoDirectBtnClick(TObject *Sender);
        void __fastcall DirectBtnClick(TObject *Sender);
        void __fastcall ResetBtnClick(TObject *Sender);
    void __fastcall PageControlChange(TObject *Sender);
    void __fastcall FloydBtnClick(TObject *Sender);
    void __fastcall DijBtnClick(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);



    private:	        // User declarations
    public:		// User declarations
        __fastcall TFormGraphAlgorithm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGraphAlgorithm *FormGraphAlgorithm;
//---------------------------------------------------------------------------
#endif
