#include "coordenadas.h"
#include "asteroide.h"

Asteroide::Asteroide(int coordenadaX, int coordenadaY)
:   coorX(coordenadaX),
    coorY(coordenadaY)
{

}

void Asteroide::pintar(){
    gotoxy(coorX, coorY); printf("%c", 79);
}

void Asteroide::mover(){
    gotoxy(coorX, coorY); printf(" ");
    coorY++;
    if(coorY > 32){
        coorX = 4+rand()%71;
        coorY = 4;
    }
    pintar();
}

void Asteroide::choque(Nave &n){
    if(coorX >= n.getCoorX() && coorX < n.getCoorX()+6 && coorY >= n.getCoorY() && coorY < n.getCoorY()+2){
        n.decrecerCorazones();
        n.borrar();
        n.pintar();
        n.pintarCorazones();
        coorX = 4+rand()%71;
        coorY = 4;  
    }
}

int Asteroide::getCoorX() const{
    return coorX;
}

int Asteroide::getCoorY() const{
    return coorY;
}
