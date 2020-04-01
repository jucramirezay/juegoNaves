#include "nave.h"
#include "coordenadas.h"

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80


Nave::Nave(int coordenadaX, int coordenadaY, int corazones, int vida)
:   coorX(coordenadaX),
    coorY(coordenadaY),
    corazones(corazones),
    vida(vida)
{
}

void Nave::pintar(){
    gotoxy(coorX, coorY);     printf("  %c", 94);
    gotoxy(coorX, coorY + 1); printf(" %c%c%c", 40,157,41);
    gotoxy(coorX, coorY + 2); printf("%c%c %c%c", 94,157,157,94);
}

void Nave::borrar(){
    gotoxy(coorX, coorY);   printf("        ");
    gotoxy(coorX, coorY+1); printf("        ");
    gotoxy(coorX, coorY+2); printf("        ");
}

void Nave::mover(){
    if(kbhit()){ //Funcion que detecta si se presiono una tecla
        char tecla = getch(); //Funcion que guarda la tecla que se presiona
        borrar();
        if(tecla == IZQUIERDA && coorX > 3){
            coorX--;
        } else if(tecla == DERECHA && coorX+5 < 77){
            coorX++;
        } else if(tecla == ARRIBA && coorY > 4) {
            coorY--;
        } else if(tecla == ABAJO && coorY+3 < 33) {
            coorY++;
        } else if(tecla == 'e') {
            corazones--;
        }
        pintar();
        pintarCorazones();
    }
}

void Nave::pintarCorazones(){

    gotoxy(50, 2); printf("VIDAS %d", vida);
    gotoxy(64, 2); printf("SALUD: ");
    gotoxy(70, 2); printf("       ");

    for(int i = 0; i < corazones; i++){
        gotoxy(70+i, 2); printf("%c", 254);
    }
}

void Nave::morir(){
    if(corazones == 0){
        borrar();
        gotoxy(coorX, coorY);   printf("   **   ");
        gotoxy(coorX, coorY+1); printf("  ****  ");
        gotoxy(coorX, coorY+2); printf("   **   ");
        Sleep(200);

        borrar();
        gotoxy(coorX, coorY);   printf(" * ** *");
        gotoxy(coorX, coorY+1); printf("  **** ");
        gotoxy(coorX, coorY+2); printf(" * ** *");
        Sleep(200);
        borrar();
        
        vida--;
        corazones = 3;
        pintarCorazones();
        pintar();
    }
}

int Nave::getCoorX() const{
    return coorX;
}

int Nave::getCoorY() const{
    return coorY;
}

void Nave::decrecerCorazones(){
    corazones--;
}

int Nave::vidas() const {
    return vida;
}