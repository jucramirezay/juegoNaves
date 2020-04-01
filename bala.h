class Bala{
    public:

    Bala(int coordenadaX, int coordenadaY);
    void mover();
    bool fuera();
    int getCoorX() const;
    int getCoorY() const;

    private:

    int coorX;
    int coorY;

};