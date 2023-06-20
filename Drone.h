#include <iostream>
#include "Bateria.h"
#include <cmath.h>
using namespace std;

class Drone{

protected:
    float eficiencia;
    bool decolado;
    int posicao[2]={0,0};
public:

Drone(){
//construtor
}

Bateria bateria(100);

void setEficiencia(float ef){
    eficiencia = ef;
}

void setDecolado(bool d){
    decolado = d;
}

void setPosicao(int x,int y){
    posicao[0] = x;
    posicao[1] = y;
}

float getEficiencia(){
    return eficiencia;
}

bool getDecolado(){
    return decolado;
}

int getPosicaoX(){
    return posicao[0];
}

int getPosicaoY(){
    return posicao[1];
}

bool Takeoff(){          //chamar porcentagem da bateria
    if (decolado == false && bateria->Porcentagem()>0)
    {
        decolado = true; //decolar o drone (?)
        return true;
    }
    return false;
}

bool Pousar(){
    if (decolado == true){
        posicao[0] = 0;         //pousar o drone (?)
        posicao[1] = 0;
        decolado = false;
    return true;
    }
return false;
}

bool Voar(int x, int y){

float distancia = sqrt((x-posicao[0])^2 + (y-posicao[1])^2);

float cargaNecessária = eficiencia*distancia;

float cargaA = bateria->getCargaAtual();

if(cargaNecessária < cargaA){
    posicao[0] = x;
    posicao[1] = y;
    bateria->setCargaAtual(cargaA - cargaNecessária);
    return true;
}
return false;
}

}