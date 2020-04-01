class Nave{
    public:

        Nave(int coordenadaX, int coordenadaY, int corazones, int vida); //Método constructor
        void pintar(); //Dibuja la nave
        void borrar(); //Borra la nave para que no quede el rastro
        void mover(); //Mueve la nave por el tablero
        void pintarCorazones(); //Pinta la cantidad de corazones de la nave
        void morir(); 
        int getCoorX() const;
        int getCoorY() const;
        void decrecerCorazones();
        int vidas() const;

    private:
        int coorX;
        int coorY;
        int corazones;
        int vida;
};