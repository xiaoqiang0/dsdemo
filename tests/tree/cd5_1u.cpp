//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>                      //使用math函数
#include "cd5_1u.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int tree[32]={0};                  //简单的数组数据类型,经过设计后可变成树状结构
int a=1,i,l;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void create(int lv,int d,int i)          //可视化新结点的构建函数；运行时调用
{
   static int p[16];            //静态数组整数变量p是用来记录与应用线段的端点

   TShape *sp;                  //产生新的Spape控件sp及设定其属性值
   TColor color[5]={clWhite,clYellow,clLime,clBlue,clRed};      //设置结点层次颜色
   sp=new TShape(Form1);
   sp->Parent=Form1->pn;     //设置新控件出现在画板上
   sp->Height=30;
   sp->Width=30;
   sp->Shape=stCircle;
   sp->Brush->Color=color[d];

   TLabel *lb;                 //声明产生新的Label控件lb并设置其属性值
   lb=new TLabel(Form1);
   lb->Parent=Form1->pn;
   lb->Height=20;
   lb->Width=30;
   lb->Transparent=true;         //设置Label为透明，在画面上只出现字
   lb->Caption=IntToStr(i);

   sp->Top=20+d*50;             //设定控件出现的顶端值
   lb->Top=28+d*50;

   if(d==0)                    //设置控件出现的左端值，注意d为新控件深度
   {
      sp->Left=245;          //这是根结点座标
      lb->Left=255;
   }
   else
   {
      sp->Left=245-d*50+(d*100/(pow(2,d)-1)*(lv-(pow(2,d))));     //用pow()求次方
      lb->Left=255-d*50+(d*100/(pow(2,d)-1)*(lv-(pow(2,d))));      //lv为结点位置

      Form1->Image1->Canvas->MoveTo(p[lv/2],35+(d-1)*50);         //线段起点设置
      Form1->Image1->Canvas->LineTo((sp->Left)+15,(sp->Top)+15);  //线段终点设置
   }

   Form1->lout->Caption="第 "+IntToStr(a)+" 个输入值("+IntToStr(tree[lv])+"),"+
                         "位于第 "+IntToStr(d+1)+" 层";         //在这里深度加1为层数

   if(lv<16)
      p[lv]=(sp->Left)+15;             //将结点中心位置记录于p数组
}
//---------------------------------------------------------------------------
void __fastcall TForm1::einKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   int d=0;                              //深度初始值设为0
   if(Key==13)
   {
      i=StrToInt(ein->Text);
      l=1;                               //根结点位置为1(便于运算)
      if(a>1)
      {
         while(tree[l]!=0)              //有根结点后才可安排子结点位址
         {
            if(i<tree[l])               //新的输入值比较小
            {
               l=l*2;                   //位置在其两倍处
               d++;                     //深度加1
            }
            else                        //新的输入值比较大
            {
               l=l*2+1;                 //位置在其两倍加1处
               d++;
            }
         }
      }
      tree[l]=i;                       //将数值设置于特定数组位置中
      if(d>=5)
         lout->Caption="请输入的值落在第五层之外";
      else
         create(l,d,i);    //调用构建窗体显示控件的函数并传入位置,深度及内容
      ein->Text="";
      a++;                 //结点计数器加1
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::endClick(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

