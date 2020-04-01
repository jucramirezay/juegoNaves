#include "coordenadas.h"
#include "bala.h"

Bala::Bala(int coordenadaX, int coordenadaY)
:   coorX(coordenadaX),
    coorY(coordenadaY)
{ }

void Bala::mover(){
    gotoxy(coorX, coorY); printf(" ");
    coorY--;    
    gotoxy(coorX, coorY); printf("*");
}

bool Bala::fuera(){
    if(coorY == 4) {
        return true;
    } else {
        return false;
    }
}

int Bala::getCoorX() const {
    return coorX;
}

int Bala::getCoorY() const {
    return coorY;
}