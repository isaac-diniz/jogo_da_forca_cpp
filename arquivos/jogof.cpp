/*
Exercício adicional, Jogo da forca!
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stdlib.h>

using namespace std;
int main(){
    vector<string> bancopalavras={"bahia", "computador", "macaco", "pindamonhangaba", "gato", "programa"};
    srand(static_cast<unsigned int>(time(0)));
    int tipo=0;
    string palavra;
    cout<<"Você deseja inserir uma palavra ou usar uma do banco de palavras pronto?\n";
    cout<<"[1] para inserir uma palavra / [0] para sortear uma do banco de palavras\n";
    cin>>tipo;
    if(tipo){
        cout<<"Insira a palavra enquanto o 2 jogador fecha os olhos: ";
        cin>>palavra;
    }else{
        palavra = bancopalavras[rand()%bancopalavras.size()];
    }
    string palavraOc(palavra.length(), '-');
    int maxerro=6, erro=0;
    while(erro<6){
        system("cls");
        cout<<"A palavra sorteada e: "<<palavraOc<<endl;
        cout<<"A quantidas de chances que lhe sobram e: "<<maxerro-erro;
        char letra;
        cout<<"\n\nInsira uma letra: ";
        cin>>letra;
        if(!isalpha(letra)){
            cout<<"Letra invalida!\n";
            continue;
        }
        bool existente=false;
        for(size_t i=0; i<palavra.length(); i++){
            if(letra==palavra[i]){
                palavraOc[i]=letra;
                existente=true;
            }
        }
        if(!existente){
            erro++;
        }
        if(palavraOc==palavra){
            cout<<"Parabens!! Voce ganhou e achou a palavra "<<palavra<<endl;
            break;
        }
        if(erro==maxerro){
            cout<<"Infelizmente voce perdeu :( A palavra era: "<<palavra<<endl;
        }
    }

    return 0;
}