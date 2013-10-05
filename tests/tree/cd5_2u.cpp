//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include "cd5_2u.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
struct tree                          //构建一结构类型,名称就叫tree
{
   int data;                         //存放结点内容
   int left;                         //储存左子树位置
   int right;                        //储存右子树位置
};
typedef struct tree node;            //声明新的树结构
node t[31];                          //定义结构数组t
int i,idx,p,d,lv=1;
int dat=0,ts=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)     //程序开始时运行的事件
{
   for(i=0;i<31;i++)                                        //设置结构树结点的初始值
   {
      t[i].data=0;                                            //数据初始值设为0
      t[i].left=-1;                                           //左子树初始值设为-1
      t[i].right=-1;                                          //右子树初始值设为-1
   }
   sg->Cells[0][0]=" 节点数";
   sg->Cells[1][0]=" 左子值";
   sg->Cells[2][0]=" 内容值";
   sg->Cells[3][0]=" 右子值";
}
//---------------------------------------------------------------------------
void create(int lv,int d,int da)            //二叉树控件构建窗体
{
   static int p[16];                   //结点座标数组
   TShape *sp;                         //声明继承类别
   TColor color[5]={clTeal,clPurple,clLime,clBlue,clBackground};
   sp=new TShape(Form1);                //产生新控件
   sp->Parent=Form1->pn;                 //设置控件出现的面板
   sp->Height=30;
   sp->Width=30;
   sp->Hint="索引值为"+IntToStr(ts);    //数组索引值开始值为0,ts为窗体变量
   sp->ShowHint=true;

   TLabel *lb;
   lb=new TLabel(Form1);
   lb->Parent=Form1->pn;
   lb->Height=20;
   lb->Width=30;
   lb->Transparent=true;                //标签背景色设为透明
   lb->Caption=IntToStr(da);

   sp->Top=20+d*50;                     //设置结点顶点座标
   lb->Top=28+d*50;

   if(d==0)                             //取得结点左端座标值
   {
      sp->Left=210;
      lb->Left=220;
   }
   else
   {
      sp->Left=210-d*50+(d*100/(pow(2,d)-1)*(lv-(pow(2,d))));
      lb->Left=220-d*50+(d*100/(pow(2,d)-1)*(lv-(pow(2,d))));

      Form1->Image1->Canvas->MoveTo(p[lv/2],35+(d-1)*50);
      Form1->Image1->Canvas->LineTo((sp->Left)+15,(sp->Top)+15);
   }

   Form1->lout->Caption="第 "+IntToStr(ts+1)+" 个输入值( "+IntToStr(da)+" ) ,"+
                         "位于第 "+IntToStr(d+1)+" 层";

   sp->Shape=stCircle;
   sp->Brush->Color=color[d];

   if(lv<16)
      p[lv]=(sp->Left)+15;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::einKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)                       //加入事件
{
   if(Key==13)
   {
      dat=StrToInt(ein->Text);
      p=0;
      if(ts==0)
         t[0].data=dat;                  //根结点
      else
      {
         idx=0;
         d=0;
         lv=1;
         t[ts].data=dat;                 //储存结点内容
         while(p==0)                     //当指向判断值p为0时执行
         {
            if(dat < t[idx].data)        //如果新值小于索引数组内容执行
            {
               if(t[idx].left!=-1)       //如果左子树有索引结点
                  idx=t[idx].left;       //将索引值移至左子树,继续循环
               else                      //左子树无索引结点
                  p=-1;                  //将索引值移至右子树,继续循环

               lv*=2;                    //左子结点位置
            }
            else
            {
               if(t[idx].right != -1)    //如果右子树有索引结点
                  idx=t[idx].right;      //将索引质疑至右子树,继续循环
               else
                  p=1;

               lv=lv*2+1;             //右子结点位置
            }
            d++;                      //深度加1
         }

         if(p==1)                     //储存子树结点于索引位置
            t[idx].right=ts;
         else
            t[idx].left=ts;
      }
      if(d>=5)
         lout->Caption="新节点位于第五层之外";
      else
         create(lv,d,dat);       //调用窗体控件构建函数

      ein->Text="";
      ts++;                      //输入结点次数累加
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::showClick(TObject *Sender)  //结点显示的运行事件
{
   for(i=0;i<ts;i++)
   {
      sg->Cells[0][i+1]="索引值"+IntToStr(i);
      sg->Cells[1][i+1]=t[i].left;
      sg->Cells[2][i+1]=t[i].data;
      sg->Cells[3][i+1]=t[i].right;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::endClick(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

