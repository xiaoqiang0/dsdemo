//---------------------------------------------------------------------------
#include <vcl.h>

#pragma hdrstop

#include "graph.h"
#include "graph_shortest_path.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//#define MAX_VERTEX_NUM 8

TGraphAlgorithmForm *GraphAlgorithmForm;

static TShape *sp[MAX_VERTEX_NUM];                           //�ڵ�Shap����
static TLabel *lb[MAX_VERTEX_NUM];                           //�ڵ�Shap�ϵı�ǩ���飬����->Shap->Label
int graph[MAX_VERTEX_NUM][MAX_VERTEX_NUM] = { 9999 };       //�洢ͼ�ľ���ṹ graph[i][i] = n:�����i���ڵ㵽��j���ڵ�ľ�����n

static int direct = 1;                                 //Ĭ��������ͼ

int x[MAX_VERTEX_NUM], y[MAX_VERTEX_NUM];                   //�洢ͼ����Ļ������λ��
int n;                                          //n:��¼�ڵ�����
static int start, end;                                 //start:��������ʱ��ʼ�������, end:��������ʱ�����������

static int i, j;
static bool input_node = false;
int node_R = 20;

MGraph MG;      //����洢
ALGraph ALG;    //�ٽ�����洢

TMemo *memo_local;

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



void showInMemo(string s)
{
      memo_local->Lines->Append(s.c_str());
}


//---------------------------------------------------------------------------
__fastcall TGraphAlgorithmForm::TGraphAlgorithmForm(TComponent * Owner):TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TGraphAlgorithmForm::FormCreate(TObject * Sender)    //������ʼ����Ϊ�����(��ͨ)
{
    MG.vexnum = 0;
    MG.arcnum = 0;
    memo_local = memo;
    MG.print = showInMemo;
    for (i = 0; i < MAX_VERTEX_NUM; i++)
        for (j = 0; j < MAX_VERTEX_NUM; j++) {
            graph[i][j] = 9999;
            MG.arcs[i][j] = 99999;
        }

}

//---------------------------------------------------------------------------
void __fastcall TGraphAlgorithmForm::CreateNodeBtnClick(TObject * Sender)    //���ɶ��㰴ť�����¼�
{

    pnl->Enabled = true;                            //�������幦��
    if (input_node == false) {
        memo->Lines->Add("�������������ͼ�Ľڵ�");
        CreateNodeBtn->Caption = "��������";
        input_node = true;
        img->Canvas->MoveTo(0, 0);
        img->Canvas->LineTo(0, 0);
    } else {
        memo->Lines->Add("�����ڵ�����������������ק����ͼ�ı���");
        CreateNodeBtn->Caption = "����ڵ�";
        input_node = false;
        pnl->Cursor = crArrow;
        img->Visible = true;
        //CreateNodeBtn->Enabled = false;
    }
}



void __fastcall TGraphAlgorithmForm::imgMouseDown(TObject * Sender, //��갴���¼�,��¼��ʼ���λ��
        TMouseButton Button,
        TShiftState Shift, int X, int Y)
{
    if (CreateNodeBtn->Enabled == true && input_node == true) {
        if (n < MAX_VERTEX_NUM) {    //�����������MAX_VERTEX_NUM���ڵ�
            int tmp = overLap(X, Y);
            char data = 'A' + n;
            if (tmp != -1) {
                ShowMessage("��ڵ�:" + IntToStr(tmp) + "����̫��");
                return;
            }
            sp[n] = new TShape(this);    //�����½��ؼ�
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
            lb[n]->Caption = data;    //�ڵ����ʾ���ݼ��ڵ���±�
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


void __fastcall TGraphAlgorithmForm::imgMouseUp(TObject * Sender,
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
void __fastcall TGraphAlgorithmForm::my_print (String info)
{
     memo->Lines->Add(info);
}

//---------------------------------------------------------------------------
void __fastcall TGraphAlgorithmForm::ShortestPathBtnClick(TObject * Sender)    //���·������¼�
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

    ShortestPathBtn->Enabled = false;
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

    memo->Lines->Add("��ԭ�㵽�� " + IntToStr(target) + " �����·��Ϊ" +
            IntToStr(dte[target]));
}



void __fastcall TGraphAlgorithmForm::BtClearMemoClick(TObject * Sender)
{
    memo->Clear();
}

//---------------------------------------------------------------------------


void __fastcall TGraphAlgorithmForm::DirectBtnClick(TObject * Sender)
{
    direct = 1;
}

//---------------------------------------------------------------------------

void __fastcall TGraphAlgorithmForm::NoDirectBtnClick(TObject * Sender)
{
    direct = 0;
}

//---------------------------------------------------------------------------



void __fastcall TGraphAlgorithmForm::ResetBtnClick(TObject * Sender)
{
    int i;
//    TColor original_color =  img->Canvas->Brush->Color;
//    img->Canvas->Brush->Color = clWhite;
//    img->Canvas->Rectangle(0, 0, img->Width, img->Height);
//    img->Canvas->Brush->Color =  original_color;
//    img->Repaint();
    for (i = 0; i < img->Width; i++)
        for (j = 0; j < img->Height; j++)
            img->Canvas->Pixels[i][j] = clWhite;    //����Χ�ڵĻ�����
    img->Canvas->MoveTo(0,0);
    img->Canvas->LineTo(0,0);

    //�ͷű�ǩ��Բ��
    for (i = 0; i < n; i++) {
        delete sp[i];
        delete lb[i];
    }

    n = 0;
    CreateNodeBtn->Enabled = true;
    CreateNodeBtn->Caption = "����ڵ�";
}

//---------------------------------------------------------------------------
void __fastcall TGraphAlgorithmForm::FloydBtnClick(TObject *Sender)
{

     memo->Lines->Add("=====Floyd ���·�����������=====");
     ShortestPath_FLOYD(&MG);
}
//---------------------------------------------------------------------------

void __fastcall TGraphAlgorithmForm::DijBtnClick(TObject *Sender)
{
   memo->Lines->Add("=====Dijkstra ���·�����������=====");
   for (i = 0; i < MG.vexnum; i++)
       ShortestPath_DIJ(&MG, i);
}
//---------------------------------------------------------------------------


