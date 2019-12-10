#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include "funcoes/funcao.h"
#include "funcoes/interface.h"


int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    menu();
    SetConsoleOutputCP(CPAGE_DEFAULT);
}
