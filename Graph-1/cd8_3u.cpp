//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "cd8_3u.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TShape *sp[8];          //节点Shap数组
TLabel *lb[8];          //节点Shap上的标签数组，画板->Shap->Label
TLabel *lbl;
int graph[8][8]={9999};  //存储图的矩阵结构 graph[i][i] = n:代表第i个节点到第j个节点的距离是n
int x[8],y[8];           //存储图在屏幕的坐标位置
int n,p,f,t,d;           //n:记录节点总数
                         //p:最佳路径求解目的节点索引
                         //f:设置连线时起始点的索引
                         //t:设置连线时结束点的索引
                         //d:f->t的距离
bool vst[8]={false};     //访问辅助数组
int dte[8]={0};          //单源最短路径算法存储最短路径dte[i] = x 代表从节点0到节点i的最短路径是x
bool draw=false;
int i,j;
bool input_node = false;
int node_R = 20;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ctClick(TObject *Sender)  //生成顶点按钮单击事件
{

   pnl->Enabled=true;        //启动画板功能
   if (input_node == false) {
	   ct->Caption = "结束输入";
	   input_node = true;
	   img->Repaint();
	   img->Canvas->LineTo(0,0);
   } else {
		ct->Caption = "输入节点";
		input_node = false;
		pnl->Cursor=crArrow;
		img->Visible=true;
		ct->Enabled=false;
   }


}

//---------------------------------------------------------------------------

int searchPoint(int X, int Y)
{
	for (i = 0; i < n; i++) {
		int d = sqrt((X-x[i])*(X-x[i]) +  (Y-y[i])*(Y-y[i]));
		if (d <= node_R * 1.3) {
			return i;
		}
	}
	return -1;
}

int overLap(int X, int Y)
{
	for (i = 0; i < n; i++) {
		int d = sqrt((X-x[i])*(X-x[i]) +  (Y-y[i])*(Y-y[i]));
		if (d <= node_R * 3.5) {
			return i;
		}
	}
	return -1;
}



void __fastcall TForm1::imgMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	if(ct->Enabled==true && input_node == true)
   {
	  if(n<8)                               //限制最多输入8个节点
	  {  int tmp = overLap(X, Y);

		 if (tmp != -1) {
			 ShowMessage("与节点:" + IntToStr(tmp) + "相邻太近");
			 return ;
		 }

		 sp[n]=new TShape(Form1);         //建立新结点控件
		 sp[n]->Parent=pnl;               //设置新结点控件属性
		 sp[n]->Enabled=false;
		 sp[n]->Left=X - node_R;                  //圆形的直径是15的圆
		 sp[n]->Top=Y - node_R;
		 sp[n]->Height=2 * node_R;
		 sp[n]->Width=2 * node_R;
		 TColor color[8]={clWhite, clYellow, clLime, clWebLightgrey, clRed, clAqua, clTeal, clWebRoyalBlue};
		 sp[n]->Brush->Color=color[n];      //设置填充颜色
		 sp[n]->Shape=stEllipse;            //控件的类型是椭圆，C++builder 中没有圆只有椭圆，高度宽度相等即为圆

		 lb[n]=new TLabel(pnl);             //建立新结点标签
		 lb[n]->Parent=pnl;                 //设置新结点控件属性
		 lb[n]->Caption=n;                  //节点的显示内容即节点的下标
		 lb[n]->Transparent=true;           //标签透明
		 lb[n]->Left=X-5;                   //设置标签的位置
		 lb[n]->Top=Y-5;
		 x[n]=X; y[n]=Y;                	//存储新顶点坐标，圆的中心
		 //if(n>0)
		 //ln->Enabled=true;

	  }
	  n++;                                 //顶点计数器加1
	  return;
   }
   f = searchPoint(X, Y);
	//ShowMessage("请输入 0 ~ "+);
}
//---------------------------------------------------------------------------

int getArrayPoints(TImage *img, float x1, float y1, float x2, float y2)
{
	float dx = abs(x2 - x1);
	float dy = abs(y2 - y1);
	float d, Ox, Oy, O1x, O1y, O2x, O2y;
	float k1, k2;
	d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	//左下角-->右上角方向
	if (x2 - x1 > 0 && y2 - y1 < 0) {
		Ox = x2 - 2 * node_R * dx / d;
		Oy = y2 + 2 * node_R * dy / d;
		O1x= Ox + node_R / 3 * dy / d;
		O1y= Oy + node_R / 3 * dx / d;
		O2x = Ox - node_R / 3 * dy / d;
		O2y = Oy - node_R / 3 * dx / d;
	}
	//右上角-->左下角方向
	if (x2 - x1 < 0 && y2 - y1 > 0) {
		Ox = x2 + 2 * node_R * dx / d;
		Oy = y2 - 2 * node_R * dy / d;
		O1x= Ox - node_R / 3 * dy / d;
		O1y= Oy - node_R / 3 * dx / d;
		O2x = Ox + node_R / 3 * dy / d;
		O2y = Oy + node_R / 3 * dx / d;
	}
	//左上角-->右下角方向
	if (x2 - x1 > 0 && y2 - y1 > 0) {
		Ox = x2 - 2 * node_R * dx / d;
		Oy = y2 - 2 * node_R * dy / d;
		O1x= Ox + node_R / 3 * dy / d;
		O1y= Oy - node_R / 3 * dx / d;
		O2x = Ox - node_R / 3 * dy / d;
		O2y = Oy + node_R / 3 * dx / d;
	}
    //右下角-->左上角方向
	if (x2 - x1 < 0 && y2 - y1 < 0) {
		Ox = x2 + 2 * node_R * dx / d;
		Oy = y2 + 2 * node_R * dy / d;
		O1x= Ox - node_R / 3 * dy / d;
		O1y= Oy + node_R / 3 * dx / d;
		O2x = Ox + node_R / 3 * dy / d;
		O2y = Oy - node_R / 3 * dx / d;
	}

	float dst_x = (Ox + x2) / 2;
	float dst_y = (Oy + y2) / 2;


	img->Canvas->MoveTo(ceil(O1x), ceil(O1y));
	img->Canvas->Pen->Width = 2;
	img->Canvas->Pen->Color = clRed;
	img->Canvas->LineTo(floor(dst_x), floor(dst_y));
	img->Canvas->LineTo(floor(O2x), floor(O2y));


}

void __fastcall TForm1::imgMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	  t = searchPoint(X, Y);

	  if (f != -1 && t != -1 && f != t) {
		  d = StrToInt(InputBox("节点距离",	 "请输入节点距离: ","5"));  //默认值5
		  img->Canvas->MoveTo(x[f],y[f]);
		  img->Canvas->LineTo(x[t],y[t]);

		  lbl=new TLabel(Form1);            //建立路径长度显示标签
		  lbl->Parent=pnl;                  //设置标签
		  lbl->Caption=d;
		  lbl->Left=(x[f]+x[t])/2;         //显示标签位置
		  lbl->Top=(y[f]+y[t])/2;
		  getArrayPoints(img,x[f],y[f],x[t],y[t]);
		  graph[f][t]=d;                  //有向图

	  }

	  f = -1; t = -1 ; 		//reset

}

//---------------------------------------------------------------------------

void __fastcall TForm1::phClick(TObject *Sender)     //最短路径求解事件
{
   do{
      p=StrToInt(InputBox("最佳路径设定框",
                 "请输入目的顶点 0 ~"+IntToStr(n-1),""));
   }while(p>=n||p<0);                          //控制输入范围

   ph->Enabled=false;
   int edg=1,min=9999,vtx;    //edg、min、vtx分别表示始边,最小边,顶点
   vst[0]=true;              //从顶点0（原点）开始计算路径
   for(i=1;i<n;i++)          //记录相邻原点的路经值
      dte[i]=graph[0][i];

   while(edg<n-1)                 //最短路径解决方法
   {
      edg++;                      //边线计数器加1
      min=9999;                   //设定比较基值
      for(i=1;i<n;i++)
      {
         if(vst[i]==false && min>dte[i])    //没有访问过的相邻接定点
         {
            vtx=i;                      //将访问的对象
            min=dte[i];                 //最短路径值已经改变
         }
	  }
      vst[vtx]=true;                    //访问设置
      for(i=1;i<n;i++)
      {
         if(vst[i]==false && dte[vtx]+graph[vtx][i]<dte[i])   //新路径总长如果小于目前最短路径
            dte[i]=dte[vtx]+graph[vtx][i];                           //更新当前最短路径记录
      }
   }
   ShowMessage("从原点到第 "+IntToStr(p)+" 点最佳路径为"+IntToStr(dte[p]));
   gb->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender) //顶点间初始设置为无穷大(不通)
{
   for(i=0;i<8;i++)
      for(j=0;j<8;j++)
         graph[i][j]=9999;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cleClick(TObject *Sender)   //清理画板
{
   for(i=0;i<img1->Width;i++)
      for(j=0;j<img1->Height;j++)
         img1->Canvas->Pixels[i][j]=clWhite;       //将范围内的画板变白
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pctClick(TObject *Sender) //绘图按钮点击事件
{
   img1->Canvas->Pen->Color=clBlue;              //将画笔颜色设为蓝色
   img1->Canvas->Pen->Width=1;                   //设定画笔宽度为1

}
//---------------------------------------------------------------------------

void __fastcall TForm1::delClick(TObject *Sender)  //橡皮擦
{
   img1->Canvas->Pen->Color=clWhite;      //将画笔颜色设为白色
   img1->Canvas->Pen->Width=8;            //设置画笔宽度为8
}
//---------------------------------------------------------------------------

void __fastcall TForm1::img1MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)      //手绘画板上鼠标点下事件
{
   draw=true;
   img1->Canvas->MoveTo(X,Y);               //设置起点
}
//---------------------------------------------------------------------------

void __fastcall TForm1::img1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)                        //手绘画板上鼠标移动事件
{
   if(draw)                               //鼠标左键按下
      img1->Canvas->LineTo(X,Y);          //绘制连续终点
}
//---------------------------------------------------------------------------

void __fastcall TForm1::img1MouseUp(TObject *Sender, TMouseButton Button,
	  TShiftState Shift, int X, int Y)      //手绘画板上鼠标弹起事件
{
   draw=false;                              //中断绘图
   img1->Canvas->MoveTo(X,Y);
}



//---------------------------------------------------------------------------

