#include "coordenadas.h"
#include "asteroide.h"
#include "bala.h"
#include <stdlib.h>
#include <list>

using namespace std;

int main(){

    bool gameOver = false;
    int puntos = 0;
        
    ocultarCursor();
    pintarLimites();

    Nave n(37, 30, 3, 3);

    n.pintar();
    n.pintarCorazones();

    list<Asteroide*> A;
    list<Asteroide*>::iterator itA;
    for(int i = 0; i < 5; i++){ //for para crear los objetos (5 objetos de la clase Asteroide)
        A.push_back(new Asteroide(rand()%75 + 3, rand()%5 + 4));
    }

    list<Bala*> B; //Creación de la lista que posee diferentes objetos de tipo Bala
    list<Bala*>::iterator it; //Iterador de la lista de los objetos de la clase Bala, apuntador

    while(!gameOver){

        gotoxy(4, 2); printf("Puntos: %d", puntos);
        if(kbhit()) {
            char tecla = getch();
            if(tecla == 'a') {
                B.push_back(new Bala(n.getCoorX() + 2, n.getCoorY() - 1)); //Crea el objeto bala cada vez que se oprime 'a'
            }
        }

        for(it = B.begin(); it != B.end(); it++){ //Iterador primer elemento de la lista; iterador diferente del final
            (*it) -> mover();
            if((*it) -> fuera()){
                gotoxy((*it) -> getCoorX(), (*it) -> getCoorY());
                printf(" ");
                delete(*it); //Elimina un elemento de la lista, pero invalida el iterador, quitando los enlaces entre posiciones
                it = B.erase(it); //Vuelve a hacer los enlaces entre las posiciones de la lista
            }
        }

        for(itA = A.begin(); itA != A.end(); itA++) { //Se utiliza el iterador para recorrer la lista y llamar las funciones de la clase
            (*itA) -> mover();
            (*itA) -> choque(n);
        }

        for(itA = A.begin(); itA != A.end(); itA++){
            for(it = B.begin(); it != B.end(); it++) {
                if((*itA)->getCoorX() == (*it)->getCoorX() && ( (*itA)->getCoorY()+1 == (*it)->getCoorY() || (*itA)->getCoorY() == (*it)->getCoorY())) {
                    gotoxy((*it)->getCoorX(), (*it)->getCoorY()); printf(" ");
                    delete(*it); 
                    it = B.erase(it);

                    A.push_back(new Asteroide(rand()%74 + 3, 4));
                    gotoxy((*itA)->getCoorX(), (*itA)->getCoorY()); printf(" ");
                    delete(*itA);
                    itA = A.erase(itA);

                    puntos++;
                }
            }
        }

        if(n.vidas() == 0) {
            gameOver = true;
        }
        n.morir();
        n.mover();
        Sleep(30); //Detiene la ejecución del programa durante 30 ms, da tiempo al procesador

    }

    return 0;
}
