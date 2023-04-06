#ifndef HACKTHREAT_H
#define HACKTHREAT_H

#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <iostream>
using namespace std;

char loststrbuffer[500];
char loststrbuffer2[500];
#define testador(x...) sprintf(loststrbuffer,x);MessageBox(0,loststrbuffer,"Mensagem de Teste",MB_OK);
#define MB_Instantaneo(y,x...) sprintf(loststrbuffer2,x);MessageBox(0,loststrbuffer2,y,MB_OK);

//<----DEFINI��ES DE CORES------------------
#define COR_ORIGINAL      1|2|4

//Cores do texto:
#define AZUL_E            1
#define VERDE_E           2
#define VERMELHO_E        4
#define VIOLETA           4|1
#define MARROM            4|2
#define VERDE_AGUA        2|1
#define CINZA_C           4|2|1
#define VERMELHO_C        4|8
#define VERDE_C           2|8
#define AZUL_C            1|8
#define ROSA              4|1|8
#define AMARELO           4|2|8
#define CIANO             2|1|8
#define BRANCO            4|2|1|8

//Cores do fundo:
#define F_AZUL_E          16
#define F_VERDE_E         32
#define F_VERMELHO_E      64
#define F_VIOLETA         64|16
#define F_MARROM          64|32
#define F_VERDE_AGUA      32|16
#define F_CINZA_C         64|32|16
#define F_VERMELHO_C      64|128
#define F_VERDE_C         32|128
#define F_AZUL_C          16|128
#define F_ROSA            64|16|128
#define F_AMARELO         64|32|128
#define F_CIANO           32|16|128
#define F_BRANCO          64|32|16|128

//Ex:   Texto rosa com fundo branco seria "colorizar(ROSA | F_BRANCO);".
//OBS:  Ao omitir a cor de fundo � usada a cor padr�o (preto).
//----DEFINI��ES DE CORES------------------>


//LEIASTR(TEXTO,TAMANHO) - L� O INPUT DO TECLADO, REMOVE OS LINE FEEDS E FAZ UM FLUSH NO BUFFER.
void leiastr(char *texto ,int tamanho){
     fgets(texto, tamanho, stdin);
     char *newline = strchr(texto, '\n');
     if(newline != NULL) *newline = '\0';
     fflush(stdin);
}

//COLORIZAR(CODIGO DA COR) - DEFINE A COR DO FUNDO E TEXTO PARA OS PR�XIMOS OUTPUTS.
void colorizar(WORD cor){
     HANDLE SaidaSTD = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(SaidaSTD, cor);
}

//REMOVEACC(TEXTO) - REMOVE OS ACENTOS DO VETOR DE CHAR ESPECIFICADO.
void removeacc(char *texto){
    char converter[256]={'\x0','\x1','\x2','\x3','\x4','\x5','\x6','\x7','\x8','\x9','\xa','\xb','\xc','\xd','\xe','\xf','\x10','\x11','\x12','\x13','\x14','\x15','\x16','\x17','\x18','\x19','\x1a','\x1b','\x1c','\x1d','\x1e','\x1f','\x20','\x21','\x22','\x23','\x24','\x25','\x26','\x27','\x28','\x29','\x2a','\x2b','\x2c','\x2d','\x2e','\x2f','\x30','\x31','\x32','\x33','\x34','\x35','\x36','\x37','\x38','\x39','\x3a','\x3b','\x3c','\x3d','\x3e','\x3f','\x40','\x41','\x42','\x43','\x44','\x45','\x46','\x47','\x48','\x49','\x4a','\x4b','\x4c','\x4d','\x4e','\x4f','\x50','\x51','\x52','\x53','\x54','\x55','\x56','\x57','\x58','\x59','\x5a','\x5b','\x5c','\x5d','\x5e','\x5f','\x60','\x61','\x62','\x63','\x64','\x65','\x66','\x67','\x68','\x69','\x6a','\x6b','\x6c','\x6d','\x6e','\x6f','\x70','\x71','\x72','\x73','\x74','\x75','\x76','\x77','\x78','\x79','\x7a','\x7b','\x7c','\x7d','\x7e','\x7f','C','u','e','a','a','a','a','c','e','e','e','i','i','i','A','A','E','\x91','\x92','o','o','o','u','u','y','O','U','\x9b','\x9c','\x9d','\x9e','\x9f','a','i','o','u','n','N','\xa6','\xa7','\xa8','\xa9','\xaa','\xab','\xac','\xad','\xae','\xaf','\xb0','\xb1','\xb2','\xb3','\xb4','A','A','A','\xb8','\xb9','\xba','\xbb','\xbc','\xbd','\xbe','\xbf','\xc0','\xc1','\xc2','\xc3','\xc4','\xc5','a','A','\xc8','\xc9','\xca','\xcb','\xcc','\xcd','\xce','\xcf','\xd0','\xd1','E','E','E','\xd5','I','I','I','\xd9','\xda','\xdb','\xdc','\xdd','I','\xdf','O','\xe1','O','O','o','O','\xe6','\xe7','\xe8','U','U','U','y','Y','\xee','\xef','\xf0','\xf1','\xf2','\xf3','\xf4','\xf5','\xf6','\xf7','\xf8','\xf9','\xfa','\xfb','\xfc','\xfd','\xfe','\xff'};
    int id,x;
    for(x = 0; x < strlen(texto); x++){
        id = (int) texto[x];
        if(id < 0) id += 256;
        texto[x] = converter[id];
    }
}

//PULA(X,Y) - MOVE O CURSOR PARA O PONTO ESCOLHIDO
void pula(int x, int y){
	HANDLE SaidaSTD = GetStdHandle(STD_OUTPUT_HANDLE); //Define o HANDLE de saida
	COORD coord; //Define uma struct do tipo COORD que vai receber as coordenadas
    coord.X = x; //Salva o argumento 'x' na propriedade X da estrutura 'coord'
    coord.Y = y; //Salva o argumento 'y' na propriedade Y da estrutura 'coord'
    SetConsoleCursorPosition(SaidaSTD, coord); //Pula para a linha especificada
}

//PRINT_ANIMADO(TEXTO [,VELOCIDADE]) - ESCREVE LETRA POR LETRA O TEXTO ESPECIFICADO.
void print_animado(char str[], int vel=100){ //vel (velocidade) � opcional, caso n�o especificado � 100
     for(int x=0;x<strlen(str);x++){ //x varia de 0 at� o tamanho de str[] -1 (< menor que)
             std::cout << str[x]; //Imprime letra por letra
             _sleep(vel); //D� uma pausa de 'vel' segundos entre cada cout. Padr�o de vel = 100.
     }
}

int sal=9247; //usado para randomizar o seed da fun��o LSTaleatorio
//LSTaleatorio(MINIMO, MAXIMO) - RETORNA UM NUMERO ALEATORIO ENTRE 'MINIMO' E 'MAXIMO'
int LSTaleatorio(int minimo, int maximo)
{
    time_t segundos;
    time(&segundos); //segundos recebe o tempo atual em segundos
    srand((unsigned int)(segundos + (sal++ - (rand() % 10000 )))); //gera um seed aleatorio   
    return rand() % maximo + minimo; //retorna o valor entre minimo e maximo
}

//TECLAS GETCH()
#ifdef __HOTKEYS__
#define BOTAO_ESC           27
#define BOTAO_F1            59
#define BOTAO_F2            60
#define BOTAO_F3            61
#define BOTAO_F4            62
#define BOTAO_F5            63
#define BOTAO_F6            64
#define BOTAO_F7            65
#define BOTAO_F8            66
#define BOTAO_F9            67
#define BOTAO_F10           68
#define BOTAO_F11           133
#define BOTAO_F12           134
#define BOTAO_ASP           39
#define BOTAO_1             49
#define BOTAO_2             50
#define BOTAO_3             51
#define BOTAO_4             52
#define BOTAO_5             53
#define BOTAO_6             54
#define BOTAO_7             55
#define BOTAO_8             56
#define BOTAO_9             57
#define BOTAO_0             48
#define BOTAO_TRACO         45
#define BOTAO_IGUAL         61
#define BOTAO_BACKSPACE     8
#define BOTAO_Q             113
#define BOTAO_W             119
#define BOTAO_E             101
#define BOTAO_R             114
#define BOTAO_T             116
#define BOTAO_Y             121
#define BOTAO_U             117
#define BOTAO_I             105
#define BOTAO_O             111
#define BOTAO_P             112
#define BOTAO_AGUDO         39
#define BOTAO_COLCHETEA     91
#define BOTAO_A             97
#define BOTAO_S             115
#define BOTAO_D             100
#define BOTAO_F             102
#define BOTAO_G             103
#define BOTAO_H             104
#define BOTAO_J             106
#define BOTAO_K             107
#define BOTAO_L             108
#define BOTAO_CEDILHA       135
#define BOTAO_TIL           126
#define BOTAO_COLCHETEF     93
#define BOTAO_ENTER         13
#define BOTAO_CBARRA        92
#define BOTAO_Z             122
#define BOTAO_X             120
#define BOTAO_C             99
#define BOTAO_V             118
#define BOTAO_B             98
#define BOTAO_N             110
#define BOTAO_M             109
#define BOTAO_VIRG          44
#define BOTAO_PONT          46
#define BOTAO_PONTVIRG      59
#define BOTAO_CIMA          72
#define BOTAO_BAIXO         80
#define BOTAO_ESQUERDA      75
#define BOTAO_DIREITA       77
#define BOTAO_TAB           9
#define BOTAO_DEL           83
#define BOTAO_HOME          71
#define BOTAO_PGUP          73
#define BOTAO_PGDN          81
#define BOTAO_END           79
#endif
//TECLAS GETCH() FIM

#endif

