//---------------------------------------------------------------------------
#include <vcl.h>

#pragma hdrstop

#include "graph.h"
#include "graph_alg_u.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//#define MAX_VERTEX_NUM 8

TForm1 *Form1;

TShape *sp[MAX_VERTEX_NUM];                           //�ڵ�Shap����
TLabel *lb[MAX_VERTEX_NUM];                           //�ڵ�Shap�ϵı�ǩ���飬����->Shap->Label
int graph[MAX_VERTEX_NUM][MAX_VERTEX_NUM] = { 9999 };       //�洢ͼ�ľ���ṹ graph[i][i] = n:�����i���ڵ㵽��j���ڵ�ľ�����n

int direct = 1;                                 //Ĭ��������ͼ

int x[MAX_VERTEX_NUM], y[MAX_VERTEX_NUM];                   //�洢ͼ����Ļ������λ��
int n;                                          //n:��¼�ڵ�����
int start, end;                                 //start:��������ʱ��ʼ�������, end:��������ʱ�����������

int i, j;
bool input_node = false;
int node_R = 20;

MGraph MG;      //����洢
ALGraph ALG;    //�ٽ�����洢


TMemo *memo_local;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent * Owner):TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject * Sender)    //������ʼ����Ϊ�����(��ͨ)
{
    MG.vexnum = 0;
    MG.arcnum = 0;
    for (i = 0; i < MAX_VERTEX_NUM; i++)
        for (j = 0; j < MAX_VERTEX_NUM; j++)
            graph[i][j] = 9999;
            MG.arcs[i][j] = 99999;

}

//---------------------------------------------------------------------------
void __fastcall TForm1::CreateNodeBtClick(TObject * Sender)    //���ɶ��㰴ť�����¼�
{

    pnl->Enabled = true;                            //�������幦��
    if (input_node == false) {
        memo->Lines->Add("�������������ͼ�Ľڵ�");
        CreateNodeBt->Caption = "��������";
        input_node = true;
        img->Canvas->MoveTo(0, 0);
        img->Canvas->LineTo(0, 0);
    } else {
        memo->Lines->Add("�����ڵ�����������������ק����ͼ�ı���");
        CreateNodeBt->Caption = "����ڵ�";
        input_node = false;
        pnl->Cursor = crArrow;
        img->Visible = true;
        CreateNodeBt->Enabled = false;
    }
}


//---------------------------------------------------------------------------
int searchPoint(int X, int Y)                   //�����������������ͼ���ĸ���
{
    for (i = 0; i < n; i++) {
        int d = sqrt((X - x[i]) * (X - x[i]) + (Y - y[i]) * (Y - y[i]));
        if (d <= node_R * 1.3) {
            return i;
        }
    }
    return -1;
}

int overLap(int X, int Y)                       //����������������ĸ����غ�
{
    for (i = 0; i < n; i++) {
        int d = sqrt((X - x[i]) * (X - x[i]) + (Y - y[i]) * (Y - y[i]));
        if (d <= node_R * 3.5) {
            return i;
        }
    }
    return -1;
}

void __fastcall TForm1::imgMouseDown(TObject * Sender, //��갴���¼�,��¼��ʼ���λ��
        TMouseButton Button,
        TShiftState Shift, int X, int Y)
{
    if (CreateNodeBt->Enabled == true && input_node == true) {
        if (n < MAX_VERTEX_NUM) {    //�����������MAX_VERTEX_NUM���ڵ�
            int tmp = overLap(X, Y);
            if (tmp != -1) {
                ShowMessage("��ڵ�:" + IntToStr(tmp) + "����̫��");
                return;
            }
            sp[n] = new TShape(Form1);    //�����½��ؼ�
            sp[n]->Parent = pnl;    //�����½��ؼ�����
            sp[n]->Enabled = false;
            sp[n]->Left = X - node_R;    //Բ�ε�ֱ����15��Բ
            sp[n]->Top = Y - node_R;
            sp[n]->Height = 2 * node_R;
            sp[n]->Width = 2 * node_R;
            TColor color[MAX_VERTEX_NUM] = {
                clWhite, clYellow, clLime, clWebLightgrey, clRed, clAqua,
                clTeal, clWebRoyalBlue
            };
            sp[n]->Brush->Color = color[n];    //���������ɫ
            sp[n]->Shape = stEllipse;    //�ؼ�����������Բ��C++builder ��û��Բֻ����Բ���߶ȿ����ȼ�ΪԲ
            lb[n] = new TLabel(pnl);    //�����½���ǩ
            lb[n]->Parent = pnl;    //�����½��ؼ�����
            lb[n]->Caption = n;    //�ڵ����ʾ���ݼ��ڵ���±�
            lb[n]->Transparent = true;    //��ǩ͸��
            lb[n]->Left = X - 5;    //���ñ�ǩ��λ��
            lb[n]->Top = Y - 5;
            x[n] = X;
            y[n] = Y;        //�洢�¶������꣬Բ������
            n++;
            MGraph_Inc_Node(&MG);
        }
        //�����������1
        return;
    }
    start = searchPoint(X, Y);

    //ShowMessage("������ 0 ~ "+);
}


//---------------------------------------------------------------------------
int paintArrow(TImage * img, float x1, float y1, float x2, float y2)
{
    float dx = abs(x2 - x1);
    float dy = abs(y2 - y1);
    float d, Ox, Oy, O1x, O1y, O2x, O2y;
    float k1, k2;
    d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    //�����ң������ҵ���
    if (dy == 0) {
        int flag = (x2 - x1) > 0 ? 1 : -1;
        Ox = x2 - 2 * node_R * flag;
        Oy = y2;
        O1x = Ox;
        O1y = y2 + node_R / 3;
        O2x = Ox;
        O2y = y2 - node_R / 3;
    }
    //���¶��ϻ����϶���
    if (dx == 0) {
        int flag = (y2 - y1) > 0 ? 1 : -1;
        Ox = x2;
        Oy = y2 - 2 * node_R * flag;
        O1x = Ox + node_R / 3;
        O1y = Oy;
        O2x = Ox - node_R / 3;
        O2y = Oy;
    }
    //���½�-->���ϽǷ���
    if (x2 - x1 > 0 && y2 - y1 < 0) {
        Ox = x2 - 2 * node_R * dx / d;
        Oy = y2 + 2 * node_R * dy / d;
        O1x = Ox + node_R / 3 * dy / d;
        O1y = Oy + node_R / 3 * dx / d;
        O2x = Ox - node_R / 3 * dy / d;
        O2y = Oy - node_R / 3 * dx / d;
    }
    //���Ͻ�-->���½Ƿ���
    if (x2 - x1 < 0 && y2 - y1 > 0) {
        Ox = x2 + 2 * node_R * dx / d;
        Oy = y2 - 2 * node_R * dy / d;
        O1x = Ox - node_R / 3 * dy / d;
        O1y = Oy - node_R / 3 * dx / d;
        O2x = Ox + node_R / 3 * dy / d;
        O2y = Oy + node_R / 3 * dx / d;
    }
    //���Ͻ�-->���½Ƿ���
    if (x2 - x1 > 0 && y2 - y1 > 0) {
        Ox = x2 - 2 * node_R * dx / d;
        Oy = y2 - 2 * node_R * dy / d;
        O1x = Ox + node_R / 3 * dy / d;
        O1y = Oy - node_R / 3 * dx / d;
        O2x = Ox - node_R / 3 * dy / d;
        O2y = Oy + node_R / 3 * dx / d;
    }
    //���½�-->���ϽǷ���
    if (x2 - x1 < 0 && y2 - y1 < 0) {
        Ox = x2 + 2 * node_R * dx / d;
        Oy = y2 + 2 * node_R * dy / d;
        O1x = Ox - node_R / 3 * dy / d;
        O1y = Oy + node_R / 3 * dx / d;
        O2x = Ox + node_R / 3 * dy / d;
        O2y = Oy - node_R / 3 * dx / d;
    }

    float dst_x = (Ox + x2) / 2;
    float dst_y = (Oy + y2) / 2;

    img->Canvas->MoveTo(ceil(O1x), ceil(O1y));
    img->Canvas->LineTo(floor(dst_x), floor(dst_y));
    img->Canvas->LineTo(floor(O2x), floor(O2y));
}


void __fastcall TForm1::imgMouseUp(TObject * Sender,
        TMouseButton Button,
        TShiftState Shift, int X, int Y)
{
    int dist = 0;

    end = searchPoint(X, Y);
    if (start != -1 && end != -1 && start != end) {
        dist = StrToInt(InputBox("�ڵ����", "������ڵ����: ", "5"));    //Ĭ��ֵ5
        img->Canvas->MoveTo(x[start], y[start]);
        img->Canvas->LineTo(x[end], y[end]);
	    img->Canvas->TextOut((x[start] + x[end]) / 2, (y[start] + y[end]) / 2, dist);

        //���������ͼ����ͷ
        if (direct == 1) {
            paintArrow(img, x[start], y[start], x[end], y[end]);
            graph[start][end] = dist;    //����ͼ
            MGraph_Add_Arc(&MG, start, end, dist);
        } else {
            //����ͼ�ǶԳƾ���
            graph[start][end] = graph[end][start] = dist;
            MGraph_Add_Arc(&MG, start, end, dist);
            MGraph_Add_Arc(&MG, end, start, dist);
        }
    }

    start = -1;
    end = -1;            //reset
}
void __fastcall TForm1::my_print (String info)
{
     memo->Lines->Add(info);
}

//---------------------------------------------------------------------------
void __fastcall TForm1::ShortestPathBtClick(TObject * Sender)    //���·������¼�
{
    bool vst[MAX_VERTEX_NUM] = { false };     //���ʸ�������
    int dte[MAX_VERTEX_NUM] = { 0 };          //��Դ���·���㷨�洢���·��dte[i] = x ����ӽڵ�0���ڵ�i�����·����x
    int target = -1;

    if (n == 0) {
        ShowMessage("ͼ��δ����,�봴����ͼ���ٽ��в���");
        return;
    }

    do {
        target = StrToInt(InputBox("���·���趨��", 
                          "������Ŀ�Ķ��� 0 ~" + IntToStr(n - 1), ""));
    } while (target >= n || target < 0);           //�������뷶Χ

    ShortestPathBt->Enabled = false;
    int edg = 1, min = 9999, vtx;                  //��edg��min��vtx�ֱ��ʾʼ��,��С��,����
    vst[0] = true;                                 //�Ӷ���0��ԭ�㣩��ʼ����·��

    for (i = 1; i < n; i++)                        //��¼����ԭ���·��ֵ
        dte[i] = graph[0][i];

    while (edg < n - 1)                            //���·���������
    {
        edg++;                                     //���߼�������1
        min = 9999;                                //�趨�Ƚϻ�ֵ
        for (i = 1; i < n; i++) {
            if (vst[i] == false && min > dte[i])   //û�з��ʹ������ڽӶ���
            {
                vtx = i;                           //�����ʵĶ���
                min = dte[i];                      //���·��ֵ�Ѿ��ı�
            }
        }
        vst[vtx] = true;                           //��������
        for (i = 1; i < n; i++) {
            if (vst[i] == false && dte[vtx] + graph[vtx][i] < dte[i])    //��·���ܳ����С��Ŀǰ���·��
                dte[i] = dte[vtx] + graph[vtx][i];    //���µ�ǰ���·����¼
        }
    }

    ShowMessage("��ԭ�㵽�� " + IntToStr(target) + " �����·��Ϊ" +
            IntToStr(dte[target]));
}



void __fastcall TForm1::BtClearMemoClick(TObject * Sender)
{
    memo->Clear();
}

//---------------------------------------------------------------------------


void __fastcall TForm1::DirectBtClick(TObject * Sender)
{
    direct = 1;
    PageControl->TabIndex = 0;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::NoDirectBtClick(TObject * Sender)
{
    direct = 0;
    PageControl->TabIndex = 1;
}

//---------------------------------------------------------------------------



void __fastcall TForm1::ResetBtClick(TObject * Sender)
{
    int i;

    for (i = 0; i < img->Width; i++)
        for (j = 0; j < img->Height; j++)
            img->Canvas->Pixels[i][j] = clWhite;    //����Χ�ڵĻ�����

    for (i = 0; i < n; i++) {
        delete sp[i];
        delete lb[i];
    }

    n = 0;
    CreateNodeBt->Enabled = true;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::PageControlChange(TObject *Sender)
{
     if (PageControl->TabIndex == 0)
        DirectBt->Checked = true;
     else
         NoDirectBt->Checked = true;
}
//---------------------------------------------------------------------------

void p(String s)
{
      memo_local->Lines->Add(s);
}
void __fastcall TForm1::Button6Click(TObject *Sender)
{
     memo_local = memo;
     ShortestPath_FLOYD(&MG, &p);
}
//---------------------------------------------------------------------------

