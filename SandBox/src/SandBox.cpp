
#include <windows.h>

namespace Nina {

__declspec(dllimport) void Print();

}


int main(int argc, char* argv[])
{
    Nina::Print();
    return 0;
}
