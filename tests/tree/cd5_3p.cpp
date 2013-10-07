//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USEFORM("cd5_3u.cpp", BiTreeForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TBiTreeForm), &BiTreeForm);
         Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
