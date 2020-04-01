#include "nave.h"

class Asteroide {
    public:

        Asteroide(int coordenadaX, int coordenadaY);
        void pintar();
        void mover();
        void choque(Nave &n);
        int getCoorX() const;
        int getCoorY() const;

    private:
        
        int coorX;
        int coorY;
};