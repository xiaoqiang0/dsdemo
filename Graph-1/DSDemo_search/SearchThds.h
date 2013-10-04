//---------------------------------------------------------------------------
#ifndef SearchThdsH
#define SearchThdsH
//---------------------------------------------------------------------------

#include <Classes.hpp>
#include <Graphics.hpp>
#include <ExtCtrls.hpp>

#define ARRAY_SIZE 10000
typedef int TSearchArrary[ARRAY_SIZE];

//---------------------------------------------------------------------------

class TSearchThread: public TThread
{
__published:	// IDE-managed Components
    private: // User declarations
    protected:  // User declarations
        TSearchArrary FSearchArray;
        void __fastcall Execute();
        virtual void __fastcall Search(TSearchArrary &A);
    public:  // User declarations
        int count;int FSize;
        AnsiString SearchName;
        __fastcall TSearchThread(TSearchArrary &SearchArray, AnsiString SearchType);
};

class TSequentialSearchThread: public TSearchThread
{
__published:    // IDE-managed Components
    private:
    protected:  // User declarations
        void __fastcall Search(TSearchArrary &A);
    public:
        __fastcall TSequentialSearchThread(TSearchArrary &SearchArray, AnsiString SearchType);
};

//---------------------------------------------------------------------------
class TBinarySearchThread: public TSearchThread
{
__published:    // IDE-managed Components
    private:
    protected:  // User declarations
        void __fastcall swap(int i, int j);
        void __fastcall qsort(int l, int u);
        void __fastcall Search(TSearchArrary &A);
    public:
           int sort_count;
        __fastcall TBinarySearchThread(TSearchArrary &SearchArray, AnsiString SearchType);
};

class TBinarySearchThread_opt: public TBinarySearchThread
{
__published:    // IDE-managed Components
    private:
    protected:  // User declarations
        void __fastcall Search(TSearchArrary &A);
    public:
           int sort_count;
        __fastcall TBinarySearchThread_opt(TSearchArrary &SearchArray, AnsiString SearchType);
};



extern int array_size;

#endif
