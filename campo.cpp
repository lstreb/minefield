#include <ctime>
#include <cstdlib>
#include "campo.h"

//sem a coordenada inicial
campo::campo(int alt, int larg, int quantMinas)
{
    this->alt = alt;
    this->larg = larg;
    this->quantMinas = quantMinas;

    // referencia: https://stackoverflow.com/questions/23852358/construct-object-where-one-of-its-properties-depends-on-another-in-c
    // define a quantidade de linhas igual a altura
    tabuleiro.resize(alt);
    // semelhante a: quadrado tabuleiro[alt][];

    for(int linha=0; linha<alt; linha++){
        // define a quantidade de colunas igual a largura
        tabuleiro[linha].resize(larg);
    }
    // matriz agora eh: quadrado tabuleiro[alt][larg]

    srand((unsigned)time(NULL));
    for(int i=0; i<quantMinas; i++){
        quadrado *coordenada;

        do{
            int lin = (rand()%alt);
            int col = (rand()%larg);

            coordenada = &tabuleiro[lin][col];
        }while(coordenada->getMina()==true);

        coordenada->setMina(true);
    }
}

//com a coordenada inicial
campo::campo(int alt, int larg, int quantMinas, int linha, int coluna)
{
    this->alt = alt;
    this->larg = larg;
    this->quantMinas = quantMinas;

    // referencia: https://stackoverflow.com/questions/23852358/construct-object-where-one-of-its-properties-depends-on-another-in-c
    // define a quantidade de linhas igual a altura
    tabuleiro.resize(alt);
    // semelhante a: quadrado tabuleiro[alt][];

    for(int linha=0; linha<alt; linha++){
        // define a quantidade de colunas igual a largura
        tabuleiro[linha].resize(larg);
    }
    // matriz agora eh: quadrado tabuleiro[alt][larg]

    srand((unsigned)time(NULL));
    for(int i=0; i<quantMinas; i++){
        int lin=0, col=0;

        do{
            lin = (rand()%alt);
            col = (rand()%larg);
        }while(tabuleiro[lin][col].getMina()==true ||
                (lin==linha-1 && (col==coluna-1 || col==coluna || col==coluna+1)) ||
                (lin==linha && (col==coluna-1 || col==coluna || col==coluna+1)) ||
                (lin==linha+1 && (col==coluna-1 || col==coluna || col==coluna+1))
               );
        //assim o jogo sempre vai abrir porque tem que começar em uma coordenada que nao tem minas em volta

        tabuleiro[lin][col].setMina(true);
    }
}

/*

    lin-1 col-1    lin-1 col    lin-1 col+1
    lin col-1       lin col      lin col+1
    lin+1 col-1    lin+1 col    lin+1 col+1



*/

int campo::getLarg()
{
    return larg;
}

int campo::getAlt()
{
    return alt;
}

void campo::setNum(int lin, int col)
{
    if(lin<0 || col<0) return;
    if(lin>alt || col>larg) return;

    int minasEmVolta=0;

    //pra mostrar onde tem bomba para o teste
    if(tabuleiro[lin][col].getMina()) {
        tabuleiro[lin][col].setNum(9); //9 eh onde tem bomba
        return;
    }

    if(lin-1 >= 0){
        if(col-1 >= 0){
            if(tabuleiro[lin-1][col-1].getMina()) minasEmVolta++;
        }

        if(col+1 < larg){
            if(tabuleiro[lin-1][col+1].getMina()) minasEmVolta++;
        }

        if(tabuleiro[lin-1][col].getMina()) minasEmVolta++;
    }

    if(lin+1 < alt){
        if(col-1 >= 0){
            if(tabuleiro[lin+1][col-1].getMina()) minasEmVolta++;
        }

        if(col+1 < larg){
            if(tabuleiro[lin+1][col+1].getMina()) minasEmVolta++;
        }

        if(tabuleiro[lin+1][col].getMina()) minasEmVolta++;
    }

    if(col+1 < larg){
        if(tabuleiro[lin][col+1].getMina()) minasEmVolta++;
    }

    if(col-1 >= 0){
        if(tabuleiro[lin][col-1].getMina()) minasEmVolta++;
    }

    tabuleiro[lin][col].setNum(minasEmVolta);
}
