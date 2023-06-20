#include <iostream>
#include "Drone.h"
#include "Bateria.h"

using namespace std;

class Outdoor : public Drone {
    private:
    float cargaMapear;

    public:
    Outdoor(float CMap, float ef, Bateria b){
    cargaMapear = CMap;
    eficiencia = ef;
    bateria = b;    
    }

    void setCargaMapear(float CMap){
        cargaMapear = CMap;
    }

    float getCargaMapear(){
        return cargaMapear;
    }

    bool Mapear(){
        if(bateria->getCargaAtual() > cargaMapear && decolado==true){
        cout << "Mapeamento concluído!" << endl;       
        //gastar carga de bateria
        return true;
    }
    cout << "Impossível completar o mapeamento." << endl;
    return false;
    }


}