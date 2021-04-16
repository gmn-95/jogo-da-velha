#include <iostream>
#include <cstdlib>
#include <math.h>
#include <iomanip>

using namespace std;

string status;
char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char p1 = 'X', p2 = 'O', turn, escolhaPlayer;
int i = 0, j = 0, escolha = 0;
bool vencedor, fim = false;

void XO();//escolhas dos players X ou O
void Board();//tabuleiro do jogo da velha -> #
void jogada();//jogadas dos players
bool resultado();//resultado: verificar se houve um vencedor ou empate
bool Final(bool result);//mostrar na tela se foi empate, ou se houve um vencedor
void jogo();//reuni todas as sub-rotinas nesta
bool zerar();//reseta o tabuleiro, e a variavel vencedor

int main(){
    char r;
    reinicio:

    zerar();
    jogo();
    cout << "\nAguarde...\n\n";
    system("sleep 2");
    cout << "\nDeseja jogar novamente? [S/N] --> ";
    cin.ignore();
    cin >> r;

    if(r == 's' || r == 'S'){
        zerar();
        goto reinicio;
    }
    else if(r == 'n' || r == 'N'){
        exit(0);
    }

    return 0;
}

//escolhas dos players X ou O
void XO(){

    cout << "Digite X se desejar ser o X ou Digite O se quiser O --> ";
    cin >> escolhaPlayer;

    if(escolhaPlayer == 'X' || escolhaPlayer == 'x'){
        turn = p1;
        cout << "\nO Jogador X começa.";
    }
    else if(escolhaPlayer == 'O' || escolhaPlayer == 'o'){
        turn = p2;
        cout << "\nO Jogador O começa.";
    }
}

//tabuleiro do jogo da velha -> #
void Board(){

    cout << "\n" << board[0] << " | " << board[1] << " | "<< board[2] << "\n";
    cout << "----------\n";
    cout << board[3] << " | " << board[4] << " | "<< board[5] << "\n";
    cout << "----------\n";
    cout << board[6] << " | " << board[7] << " | "<< board[8] << "\n\n";
}

//jogadas dos players
void jogada(){
    movimento:
    if(turn == p1){
        cout << "X --> ";
        cin >> escolha;
    }

    if(turn == p2){
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
}

//resultado: verificar se houve um vencedor ou empate
bool resultado(){
    bool result = false;

        if ((board[0] == board[1] && board[1] == board[2] ) || (board[3] == board[4] && board[4] == board[5] ) ||
            (board[6] == board[7] && board[7] == board[8] ) || (board[0] == board[3] && board[3] == board[6] ) ||
            (board[1] == board[4] && board[4] == board[7] ) || (board[2] == board[5] && board[5] == board[8] ) ||
            (board[0] == board[4] && board[4] == board[8] ) || (board[2] == board[4] && board[4] == board[6] )){

                result = true;
        }
    return result;
}

//mostrar na tela se foi empate, ou se houve um vencedor
bool Final(bool result){
    if(turn == p2 && result == true){
        cout << "Jogador X venceu!\n";
    }

    else if(turn == p1 && result == true){
        cout << "Jogador O venceu!\n";
    }
    else {
          cout << "Empate!\n\n";
        }
    return true;
}

//reuni todas as sub-rotinas nesta
void jogo(){
    system("clear");
    cout << "\n";
    bool win = false;
    resultado();

    XO();
    Board();
    int n = 0;
    while(win == false || n > 9){
        n++;
        jogada();
        win = resultado();
        if (n >= 9){
            break;
        }
    }
    Final(win);
}

//reseta o tabuleiro, e a variavel vencedor
bool zerar(){

    board[0] = '1'; board[1] = '2'; board[2] = '3';
    board[3] = '4'; board[4] = '5'; board[5] = '6';
    board[6] = '7'; board[7] = '8'; board[8] = '9';

    vencedor = false;

    return vencedor;
}
