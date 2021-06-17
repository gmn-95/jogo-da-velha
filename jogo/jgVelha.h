#ifndef JGVELHA_H_INCLUDED
#define JGVELHA_H_INCLUDED

#include "iostream"
#include "string"
#include "iomanip"
#include "math.h"
#include "cstdlib"

using namespace std;

class jgVelha
{
    private:
        char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        char p1 = 'X', p2 = 'O', escoPlayer;
        int pontosX, pontosO;

        char escolhaXO(); //escolhas dos players X ou O
        void Board(); //tabuleiro do jogo da velha -> #
        char jogada(char turno); //jogadas dos players
        bool verificador(); //verificar se houve um vencedor ou empate
        bool resultado(char turno, bool verificador);//mostrar na tela se foi empate, ou se houve um vencedor
        void zerarJogo(); //reseta o tabuleiro, e a variavel vencedor
        void construirJogo();

    public:
        void game();//método utilizado para chamar o game no arquivo main

};

char jgVelha::escolhaXO()
{
    char turno;

    cout << "Escolha X ou O --> ";
    cin >> escoPlayer;

    if(escoPlayer == 'X' || escoPlayer == 'x'){
        turno = p1;
        cout << "\nO Jogador X começa.";
    }
    else if(escoPlayer == 'O' || escoPlayer == 'o'){
        turno = p2;
        cout << "\nO Jogador O começa.";
    }

    return turno; 
}

void jgVelha::Board()
{
    cout << "\n" << board[0] << " | " << board[1] << " | "<< board[2] << "\n";
    cout << "----------\n";
    cout << board[3] << " | " << board[4] << " | "<< board[5] << "\n";
    cout << "----------\n";
    cout << board[6] << " | " << board[7] << " | "<< board[8] << "\n\n";
}

char jgVelha::jogada(char turn)
{
    int escolha, i;
    movimento:
    if(turn == p1){
        cout << "X --> ";
        cin >> escolha;
    }

    else if(turn == p2){
        cout << "O --> ";
        cin >> escolha;
    }

    switch(escolha){
        case 1: i = 0; break; case 2: i = 1; break; case 3: i = 2; break;
        case 4: i = 3; break; case 5: i = 4; break; case 6: i = 5; break;
        case 7: i = 6; break; case 8: i = 7; break; case 9: i = 8; break;
        default: cout << "Jogada inválida - tente novamente!\n"; goto movimento;
    }

    if (turn == p1 && board[i] != 'X' && board[i] != 'O'){
        board[i] = 'X';
        turn = p2;
    }

    else if (turn == p2 && board[i] != 'X' && board[i] != 'O'){
        board[i] = 'O';
        turn = p1;
    }

    else{
        cout << "Jogada inválida - tente novamente!\n";
        goto movimento;
    }

    system("clear");
    Board();

    return turn;
}

bool jgVelha::verificador()
{
    bool result = false;

        if ((board[0] == board[1] && board[1] == board[2] ) || (board[3] == board[4] && board[4] == board[5] ) ||
            (board[6] == board[7] && board[7] == board[8] ) || (board[0] == board[3] && board[3] == board[6] ) ||
            (board[1] == board[4] && board[4] == board[7] ) || (board[2] == board[5] && board[5] == board[8] ) ||
            (board[0] == board[4] && board[4] == board[8] ) || (board[2] == board[4] && board[4] == board[6] )){

                result = true;
        }
    return result;
}

bool jgVelha::resultado(char turn_, bool verificador)
{
    
    if(turn_ == p2 && verificador == true){
        cout << "Jogador X venceu!\n";
    }

    else if(turn_ == p1 && verificador == true){
        cout << "Jogador O venceu!\n";
    }
    else {
          cout << "Empate!\n\n";
        }
    return true;
}

void jgVelha::zerarJogo()
{

    board[0] = '1'; board[1] = '2'; board[2] = '3';
    board[3] = '4'; board[4] = '5'; board[5] = '6';
    board[6] = '7'; board[7] = '8'; board[8] = '9';

}

void jgVelha::construirJogo()
{
    bool win = false;
    char turnIni;

    system("clear");
    cout << "\n";

    turnIni = escolhaXO();
    Board();
    int n = 0;
    while(win == false || n > 9){
        n++;
        turnIni = jogada(turnIni);
        win = verificador();
        if (n >= 9){
            break;
        }
    }
    resultado(turnIni, win);
}

void jgVelha::game()
{
    char r;
    reinicio:

    zerarJogo();
    construirJogo();

    cout << "\nAguarde...\n\n";
    system("sleep 2");

    cout << "\nDeseja jogar novamente? [S/N] --> ";
    cin.ignore();
    cin >> r;

    if(r == 's' || r == 'S'){
        zerarJogo();
        goto reinicio;
    }
    else if(r == 'n' || r == 'N'){
        exit(0);
    }
}

#endif // !JGVELHA_H_INCLUDED
