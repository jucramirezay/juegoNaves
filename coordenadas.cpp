#include "coordenadas.h"

void ocultarCursor(){
    
    HANDLE hCon; 
    hCon = GetStdHandle(STD_OUTPUT_HANDLE); 
    CONSOLE_CURSOR_INFO cci; //Objeto creado de la estrcutura que permite manipular la apariencia del cursor en pantalla
    cci.dwSize = 2; //Tamaño del cursor en pantalla, admite valores entre 1 y 100
    cci.bVisible = false; //Indica si el cursor puede ser visible o no (True o False)   

    SetConsoleCursorInfo(hCon, &cci); //La estructura se debe pasar por referencia, para que se puedan modificar sus atributos
}


void gotoxy(int x, int y){
    
    HANDLE hCon; //Se le da un nombre a la ventana de ejecución, es decir la consola
    hCon = GetStdHandle(STD_OUTPUT_HANDLE); //Recupera el identificador de la consola, toma control de salida de la consola
    COORD dwPos; //Estructura (objeto) de tipo COORD para manipular las coordenadas de la consola
    dwPos.X = x; //Atributos para el objeto en x
    dwPos.Y = y; //Atributo para el objeto en y

    SetConsoleCursorPosition(hCon, dwPos); //Consola primer parámetro, segundo parámetro coordenadas de ubicación
}

void pintarLimites(){
    for(int i = 2; i < 78; i++){
        gotoxy(i, 3); printf("%c", 205);
        gotoxy(i, 33); printf("%c", 205);
    }

    for(int i = 4; i < 33; i++){
        gotoxy(2, i); printf("%c", 186);
        gotoxy(77, i); printf("%c", 186);
    }

    gotoxy(2, 3); printf("%c", 201);
    gotoxy(2, 33); printf("%c", 200);
    gotoxy(77, 3); printf("%c", 187);
    gotoxy(77, 33); printf("%c", 188);
}