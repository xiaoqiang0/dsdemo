//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USEFORM("graph_intro_u.cpp", graph_intro_frm);
USEFORM("graph_alg_u.cpp", GraphAlgorithmForm);
USEFORM("MainForm.cpp", dsdemo_MainForm);
USEFORM("DSDemo_sort\ThSort.cpp", ThreadSortForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(Tdsdemo_MainForm), &dsdemo_MainForm);
                 Application->CreateForm(__classid(Tgraph_intro_frm), &graph_intro_frm);
                 Application->CreateForm(__classid(TGraphAlgorithmForm), &GraphAlgorithmForm);
                 Application->CreateForm(__classid(TThreadSortForm), &ThreadSortForm);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
