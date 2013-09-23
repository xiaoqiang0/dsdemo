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
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TPanel *pnl; //面板空间
    TImage *img; //图像
    TGroupBox *GroupBox1;
    TGroupBox *gb;//距离输入文本框
	TButton *ct;//生成顶点按钮
	TButton *ph;//最短路径按钮
    TBitBtn *pct;
    TBitBtn *del;
    TBitBtn *cle;
    TBevel *Bevel1;
    TImage *img1;
	void __fastcall ctClick(TObject *Sender);   //生成顶点按钮点击函数
	void __fastcall phClick(TObject *Sender);   //最短路径按钮点击函数
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall imgMouseDown(TObject *Sender, TMouseButton Button,
			TShiftState Shift, int X, int Y);    //鼠标按下函数
	void __fastcall imgMouseUp(TObject *Sender, TMouseButton Button,
			TShiftState Shift, int X, int Y);    //鼠标弹起函数

	//以下函数式画板功能按钮的三个点击事件函数
    void __fastcall cleClick(TObject *Sender);
    void __fastcall pctClick(TObject *Sender);
    void __fastcall delClick(TObject *Sender);
    void __fastcall img1MouseDown(TObject *Sender, TMouseButton Button,
            TShiftState Shift, int X, int Y);
    void __fastcall img1MouseMove(TObject *Sender, TShiftState Shift,
            int X, int Y);
    void __fastcall img1MouseUp(TObject *Sender, TMouseButton Button,
            TShiftState Shift, int X, int Y);


    private:	        // User declarations
    public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
