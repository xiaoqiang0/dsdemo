//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "cd8_3u.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TShape *sp[8];          //�ڵ�Shap����
TLabel *lb[8];          //�ڵ�Shap�ϵı�ǩ���飬����->Shap->Label
TLabel *lbl;
int graph[8][8]={9999};  //�洢ͼ�ľ���ṹ graph[i][i] = n:�����i���ڵ㵽��j���ڵ�ľ�����n
int x[8],y[8];           //�洢ͼ����Ļ������λ��
int n,p,f,t,d;           //n:��¼�ڵ�����
                         //p:���·�����Ŀ�Ľڵ�����
                         //f:��������ʱ��ʼ�������
                         //t:��������ʱ�����������
                         //d:f->t�ľ���
bool vst[8]={false};     //���ʸ�������
int dte[8]={0};          //��Դ���·���㷨�洢���·��dte[i] = x ����ӽڵ�0���ڵ�i�����·����x
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

void __fastcall TForm1::ctClick(TObject *Sender)  //���ɶ��㰴ť�����¼�
{

   pnl->Enabled=true;        //�������幦��
   if (input_node == false) {
	   ct->Caption = "��������";
	   input_node = true;
	   img->Repaint();
	   img->Canvas->LineTo(0,0);
   } else {
		ct->Caption = "����ڵ�";
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
	  if(n<8)                               //�����������8���ڵ�
	  {  int tmp = overLap(X, Y);

		 if (tmp != -1) {
			 ShowMessage("��ڵ�:" + IntToStr(tmp) + "����̫��");
			 return ;
		 }

		 sp[n]=new TShape(Form1);         //�����½��ؼ�
		 sp[n]->Parent=pnl;               //�����½��ؼ�����
		 sp[n]->Enabled=false;
		 sp[n]->Left=X - node_R;                  //Բ�ε�ֱ����15��Բ
		 sp[n]->Top=Y - node_R;
		 sp[n]->Height=2 * node_R;
		 sp[n]->Width=2 * node_R;
		 TColor color[8]={clWhite, clYellow, clLime, clWebLightgrey, clRed, clAqua, clTeal, clWebRoyalBlue};
		 sp[n]->Brush->Color=color[n];      //���������ɫ
		 sp[n]->Shape=stEllipse;            //�ؼ�����������Բ��C++builder ��û��Բֻ����Բ���߶ȿ����ȼ�ΪԲ

		 lb[n]=new TLabel(pnl);             //�����½���ǩ
		 lb[n]->Parent=pnl;                 //�����½��ؼ�����
		 lb[n]->Caption=n;                  //�ڵ����ʾ���ݼ��ڵ���±�
		 lb[n]->Transparent=true;           //��ǩ͸��
		 lb[n]->Left=X-5;                   //���ñ�ǩ��λ��
		 lb[n]->Top=Y-5;
		 x[n]=X; y[n]=Y;                	//�洢�¶������꣬Բ������
		 //if(n>0)
		 //ln->Enabled=true;

	  }
	  n++;                                 //�����������1
	  return;
   }
   f = searchPoint(X, Y);
	//ShowMessage("������ 0 ~ "+);
}
//---------------------------------------------------------------------------

int getArrayPoints(TImage *img, float x1, float y1, float x2, float y2)
{
	float dx = abs(x2 - x1);
	float dy = abs(y2 - y1);
	float d, Ox, Oy, O1x, O1y, O2x, O2y;
	float k1, k2;
	d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	//���½�-->���ϽǷ���
	if (x2 - x1 > 0 && y2 - y1 < 0) {
		Ox = x2 - 2 * node_R * dx / d;
		Oy = y2 + 2 * node_R * dy / d;
		O1x= Ox + node_R / 3 * dy / d;
		O1y= Oy + node_R / 3 * dx / d;
		O2x = Ox - node_R / 3 * dy / d;
		O2y = Oy - node_R / 3 * dx / d;
	}
	//���Ͻ�-->���½Ƿ���
	if (x2 - x1 < 0 && y2 - y1 > 0) {
		Ox = x2 + 2 * node_R * dx / d;
		Oy = y2 - 2 * node_R * dy / d;
		O1x= Ox - node_R / 3 * dy / d;
		O1y= Oy - node_R / 3 * dx / d;
		O2x = Ox + node_R / 3 * dy / d;
		O2y = Oy + node_R / 3 * dx / d;
	}
	//���Ͻ�-->���½Ƿ���
	if (x2 - x1 > 0 && y2 - y1 > 0) {
		Ox = x2 - 2 * node_R * dx / d;
		Oy = y2 - 2 * node_R * dy / d;
		O1x= Ox + node_R / 3 * dy / d;
		O1y= Oy - node_R / 3 * dx / d;
		O2x = Ox - node_R / 3 * dy / d;
		O2y = Oy + node_R / 3 * dx / d;
	}
    //���½�-->���ϽǷ���
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
		  d = StrToInt(InputBox("�ڵ����",	 "������ڵ����: ","5"));  //Ĭ��ֵ5
		  img->Canvas->MoveTo(x[f],y[f]);
		  img->Canvas->LineTo(x[t],y[t]);

		  lbl=new TLabel(Form1);            //����·��������ʾ��ǩ
		  lbl->Parent=pnl;                  //���ñ�ǩ
		  lbl->Caption=d;
		  lbl->Left=(x[f]+x[t])/2;         //��ʾ��ǩλ��
		  lbl->Top=(y[f]+y[t])/2;
		  getArrayPoints(img,x[f],y[f],x[t],y[t]);
		  graph[f][t]=d;                  //����ͼ

	  }

	  f = -1; t = -1 ; 		//reset

}

//---------------------------------------------------------------------------

void __fastcall TForm1::phClick(TObject *Sender)     //���·������¼�
{
   do{
      p=StrToInt(InputBox("���·���趨��",
                 "������Ŀ�Ķ��� 0 ~"+IntToStr(n-1),""));
   }while(p>=n||p<0);                          //�������뷶Χ

   ph->Enabled=false;
   int edg=1,min=9999,vtx;    //��edg��min��vtx�ֱ��ʾʼ��,��С��,����
   vst[0]=true;              //�Ӷ���0��ԭ�㣩��ʼ����·��
   for(i=1;i<n;i++)          //��¼����ԭ���·��ֵ
      dte[i]=graph[0][i];

   while(edg<n-1)                 //���·���������
   {
      edg++;                      //���߼�������1
      min=9999;                   //�趨�Ƚϻ�ֵ
      for(i=1;i<n;i++)
      {
         if(vst[i]==false && min>dte[i])    //û�з��ʹ������ڽӶ���
         {
            vtx=i;                      //�����ʵĶ���
            min=dte[i];                 //���·��ֵ�Ѿ��ı�
         }
	  }
      vst[vtx]=true;                    //��������
      for(i=1;i<n;i++)
      {
         if(vst[i]==false && dte[vtx]+graph[vtx][i]<dte[i])   //��·���ܳ����С��Ŀǰ���·��
            dte[i]=dte[vtx]+graph[vtx][i];                           //���µ�ǰ���·����¼
      }
   }
   ShowMessage("��ԭ�㵽�� "+IntToStr(p)+" �����·��Ϊ"+IntToStr(dte[p]));
   gb->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender) //������ʼ����Ϊ�����(��ͨ)
{
   for(i=0;i<8;i++)
      for(j=0;j<8;j++)
         graph[i][j]=9999;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cleClick(TObject *Sender)   //������
{
   for(i=0;i<img1->Width;i++)
      for(j=0;j<img1->Height;j++)
         img1->Canvas->Pixels[i][j]=clWhite;       //����Χ�ڵĻ�����
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pctClick(TObject *Sender) //��ͼ��ť����¼�
{
   img1->Canvas->Pen->Color=clBlue;              //��������ɫ��Ϊ��ɫ
   img1->Canvas->Pen->Width=1;                   //�趨���ʿ��Ϊ1

}
//---------------------------------------------------------------------------

void __fastcall TForm1::delClick(TObject *Sender)  //��Ƥ��
{
   img1->Canvas->Pen->Color=clWhite;      //��������ɫ��Ϊ��ɫ
   img1->Canvas->Pen->Width=8;            //���û��ʿ��Ϊ8
}
//---------------------------------------------------------------------------

void __fastcall TForm1::img1MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)      //�ֻ滭�����������¼�
{
   draw=true;
   img1->Canvas->MoveTo(X,Y);               //�������
}
//---------------------------------------------------------------------------

void __fastcall TForm1::img1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)                        //�ֻ滭��������ƶ��¼�
{
   if(draw)                               //����������
      img1->Canvas->LineTo(X,Y);          //���������յ�
}
//---------------------------------------------------------------------------

void __fastcall TForm1::img1MouseUp(TObject *Sender, TMouseButton Button,
	  TShiftState Shift, int X, int Y)      //�ֻ滭������굯���¼�
{
   draw=false;                              //�жϻ�ͼ
   img1->Canvas->MoveTo(X,Y);
}



//---------------------------------------------------------------------------

