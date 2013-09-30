//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USEFORM("graph_alg_u.cpp", FormGraphAlgorithm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TFormGraphAlgorithm), &FormGraphAlgorithm);
         Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
