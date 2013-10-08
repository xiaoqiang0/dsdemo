//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

USEFORM("DSDemo_search\binary_search.cpp", BinarySearchForm);
USEFORM("DSDemo_search\search_string.cpp", search_stringForm);
USEFORM("MainForm.cpp", dsdemo_MainForm);
USEFORM("DSDemo_sort\ThSort.cpp", ThreadSortForm);
USEFORM("DSDemo_graph\graph_traverse.cpp", GraphTraverseForm);
USEFORM("DSDemo_graph\graph_shortest_path.cpp", GraphAlgorithmForm);
USEFORM("DSDemo_graph\graph_intro.cpp", GraphIntroduceForm);
USEFORM("DSDemo_graph\graph_MST.cpp", GraphMSTForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(Tdsdemo_MainForm), &dsdemo_MainForm);
         Application->CreateForm(__classid(TGraphIntroduceForm), &GraphIntroduceForm);
         Application->CreateForm(__classid(TGraphAlgorithmForm), &GraphAlgorithmForm);
         Application->CreateForm(__classid(TThreadSortForm), &ThreadSortForm);
         Application->CreateForm(__classid(Tsearch_stringForm), &search_stringForm);
         Application->CreateForm(__classid(TGraphTraverseForm), &GraphTraverseForm);
         Application->CreateForm(__classid(TBinarySearchForm), &BinarySearchForm);
         Application->CreateForm(__classid(TGraphMSTForm), &GraphMSTForm);
         Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------