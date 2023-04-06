#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include "lost.h"
using namespace std;

int main()
{
    int pos = 1,bot;
    while(true)
    {
        do
        {
            pula(0,0); // pula(0,0) ao inves de system cls, para o texto se sobreescrever ao inves de apagar tudo e começar denovo
            if(pos == 1)colorizar(F_VERDE_C);cout << " ITEM 1 \n";
            colorizar(VERDE_C);
            if(pos == 2)colorizar(F_VERDE_C);cout << " ITEM 2 \n";
            colorizar(VERDE_C);
            if(pos == 3)colorizar(F_VERDE_C);cout << " ITEM 3 \n";
            colorizar(VERDE_C);    
            if(pos == 4)colorizar(F_VERDE_C);cout << " ITEM 4 \n";
            colorizar(VERDE_C);    
            if(pos == 5)colorizar(F_VERDE_C);cout << " ITEM 5 \n";
            colorizar(VERDE_C);    
            
            bot = getch();
            
            if(bot == 72) pos--; //se apertar SETA_CIMA sobe
            if(bot == 80) pos++;//se apertar SETA_BAIXO desce
            if(pos < 1)pos = 5;
            if(pos > 5)pos = 1;
            
            if(bot == 13) break;//se apertar ENTER aceitar;
            if(bot == 27) exit(0);
            
        }while(true);
        cout << "\n\nEntrando na opcao ";colorizar(VERDE_C); cout << " " << pos << " ";colorizar(VERDE_C); cout << ".\a";
        getch();
    }
}
