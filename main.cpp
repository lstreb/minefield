/********************************************************************
* @brief   programa com objetivo de construir um campo minado funcional
* @file    main.cpp
* @author  Laura Streb de Avila
* @date    novembro/2022
* @version 1
*********************************************************************/

#include <iostream>
#include <iomanip> // para formatar o cout
#include "campo.h"
#include "quadrado.h"

using namespace std;

//declarando funções
void exibeNaoIniciado(int largura, int altura);
void exibe(int altura, int largura, campo jogo);
void pedeCoordenadas(int *l, int *c, campo jogo);
void testes(int largura, int altura, int bombas);

int main()
{
    int altura, largura, bombas;
    int nivel;

    do{
        cout << "LAURA STREB E SAMARA ROSSONI" << endl;
        cout << endl;

        cout << "qual nivel deseja jogar?" << endl;
        cout << "1- facil" << endl;
        cout << "2- medio" << endl;
        cout << "3- dificil" << endl;

        cout << "digite o numero: ";
        cin >> nivel;
        cout << endl;

        switch(nivel){
            case 1:
                altura = 8;
                largura = 10;
                bombas = 10;
                break;

            case 2:
                altura = 18;
                largura = 15;
                bombas = 40;
                break;

            case 3:
                altura = 20;
                largura = 24;
                bombas = 99;
                break;

            default:
                cout << "numero invalido" << endl << endl;
                system("pause");
                system("cls"); // limpa a tela
        }
    }while(nivel<1 || nivel>3);

    //testes(largura, altura, bombas);

    cout << "A PARTIR DE AGORA O JOGO IRA COMECAR" << endl;

    system("pause");
    system("cls"); // limpa a tela

    cout << "Para jogar sera necessario digitar a coordenada de onde deseja 'apertar' " << endl;
    cout << "Exemplo de como sao as coordenadas:" << endl;

    exibeNaoIniciado(5,5);

    cout << "Na primeira coluna, onde estao os numeros, temos o numero da linha" << endl;
    cout << "Na primeira linha, onde estao os numeros, temos o numero da coluna" << endl << endl;

    cout << "Agora digite a coordenada inicial do seu jogo:" << endl << endl;

    exibeNaoIniciado(altura, largura);

    int l=0, c=0;
    campo exemplo(altura, largura, bombas);
    pedeCoordenadas(&l, &c, exemplo);

    campo jogo(altura, largura, bombas, l-1, c-1);
    jogo.tabuleiro[l-1][c-1].setCoordenadaClicada(true);

    system("cls"); // limpa a tela

    char tipoDeClique;
    bool gameover = false;
    while(!gameover){

        system("cls"); // limpa a tela

        exibe(altura, largura, jogo);

        cout << "\nDeseja clicar no quadrado ou adicionar uma bandeira" << endl;
        cout << "Para adicionar uma bandeira digite B e para clicar digite C" << endl;
        cout << "Insira a letra aqui: ";
        cin >> tipoDeClique;

        switch(tipoDeClique){
        case 'c':
        case 'C':
            pedeCoordenadas(&l, &c, jogo);

            if(jogo.tabuleiro[l-1][c-1].getMina()){
                gameover = true;
                cout << "VOCE PERDEU!" << endl;
            }
            jogo.tabuleiro[l-1][c-1].setCoordenadaClicada(true);
            break;

        case 'b':
        case 'B':
            pedeCoordenadas(&l, &c, jogo);
            jogo.tabuleiro[l-1][c-1].setFlag(true);
            break;
            // vai ter q por pra printar algo pra ser a bandeira pensei em * ou #
            //nao tem como perder aqui, so printar mesmo

        default:
            cout << "\ncaractere invalido, tente novamente..." << endl;
            system("pause");
            system("cls"); // limpa a tela
        }
    }
    return 0;
}

/*************************************************
* @brief exibe o campo quando o jogo ainda nao foi iniciado
* @param largura: largura do campo
* @param altura: altura do campo
*************************************************/
void exibeNaoIniciado(int altura, int largura){

    int n = 0;
    for(int col=0; col <= largura; col++){
        cout << setfill('0') << setw(2) << col << " ";
    }

    cout << endl;

    for(int lin=0; lin < altura; lin++){
        n++;
        cout << setfill('0') << setw(2) << n << " ";
        for(int col=0; col < largura; col++){
            cout << "X  ";
        }
        cout << endl;
    }
}

/*************************************************
* @brief exibe o campo quando o jogo ja foi iniciado
* @param largura: largura do campo
* @param altura: altura do campo
* @param jogo:
*************************************************/
void exibe(int altura, int largura, campo jogo){

    int n = 0;
    for(int col=0; col <= largura; col++){
        cout << setfill('0') << setw(2) << col << " ";
    }

    cout << endl;

    for(int lin=0; lin < altura; lin++){
        n++;
        cout << setfill('0') << setw(2) << n << " ";
        for(int col=0; col < largura; col++){
            jogo.setNum(lin, col);
            if(jogo.tabuleiro[lin][col].getFlag())
                cout << "#  ";

            else if(jogo.tabuleiro[lin][col].getCoordenadaClicada())
                cout << jogo.tabuleiro[lin][col].getNum() << "  ";

            else
                cout << "X  ";
        }
        cout << endl;
    }
}

/*************************************************
* @brief funçao para pedir as coordenadas para o usuario e
*        testar se sao validas
* @param
* @param
* @param altura: altura do campo
* @param largura: largura do campo
*************************************************/
void pedeCoordenadas(int *l, int *c, campo jogo)
{
    bool coordenadasOk = false;

    while(!coordenadasOk){

        coordenadasOk = true;

        cout << "\nNumero da linha: ";
        cin >> *l;

        cout << "Numero da coluna: ";
        cin >> *c;
        cout << endl;

        if(*l>jogo.getAlt() || *c>jogo.getLarg() || *l<1 || *c<1){
            cout << "coordenada invalidas, tente novamente..." << endl;
            coordenadasOk = false;
        }
        else if(jogo.tabuleiro[*l-1][*c-1].getCoordenadaClicada()) {
            cout << "coordenada ja clicada, tente novamente..." << endl;
            coordenadasOk = false;
        }
    }
}

/*************************************************
* @brief essa função pode ser chamada para testar se o
*        programa esta construindo o campo corretamente
* @param largura: largura do campo
* @param altura: altura do campo
* @param bombas: numero de bombas no campo
*************************************************/
void testes(int largura, int altura, int bombas){

    campo jogo(altura, largura, bombas);

    cout << "Altura: " << jogo.getAlt() << endl;
    cout << "Largura: " << jogo.getLarg() << endl << endl;

    int cnt = 0;

    //vendo se as bombas estao em jogo
    for(int lin=0; lin < altura; lin++){
        for(int col=0; col < largura; col++){
            if (jogo.tabuleiro[lin][col].getMina() == true){
                cout << "X "; //x tem bomba
                cnt++;
            }
            else{
                cout << "O "; //nao tem bomba
            }
        }
        cout << endl;
    }

    cout << "Bombas em jogo: " << cnt << endl << endl << endl;

    //testando a contagem de bombas em volta
    for(int lin=0; lin < altura; lin++){
        for(int col=0; col < largura; col++){
            jogo.setNum(lin, col);
            cout << jogo.tabuleiro[lin][col].getNum() << " ";
        }
        cout << endl;
    }
}
