#ifndef CAMPO_H_INCLUDED
#define CAMPO_H_INCLUDED

#include "quadrado.h"
#include <vector>

class campo
{
    public:
        //construtor
        campo(int alt, int larg, int quantMinas); //sem a coordenada inicial
        campo(int alt, int larg, int quantMinas, int linha, int coluna); //para construir em cima da coordennada inicial

        int getAlt();
        int getLarg();
        int getNum();
        //o setNum conta quantas bombas tem em volta
        void setNum(int lin, int col);

        std::vector<std::vector<quadrado>> tabuleiro;
    protected:

    private:
        int alt;
        int larg;
        int quantMinas;
};

#endif // CAMPO_H_INCLUDED
