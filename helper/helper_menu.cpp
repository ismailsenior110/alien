#include <cstdlib>
#include <iostream>
using namespace std;



class Helper_Menu{
public:
	int ClearScreen();
	int Pause();
};
int Helper_Menu :: ClearScreen()
    {
        #if defined(_WIN32)
            return std::system("cls");
        #elif defined(__linux__) || defined(__APPLE__)
            return std::system("clear");
        #endif
    }
 int Helper_Menu :: Pause()
    {
        #if defined(_WIN32)
            return std::system("pause");
        #elif defined(__linux__) || defined(__APPLE__)
            return std::system(R"(read -p "Press any key to continue . . . " dummy)");
        #endif
    }
