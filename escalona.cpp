// 

#include <bits/stdc++.h>
using namespace std;

int deslocamentos;
bool done;
vector<int> requisitions;
int lastPoint;
bool nn, zero;


vector<int> geraValores() {
    srand(static_cast<unsigned>(time(nullptr)));
    vector<int> valores;
    set<int> valoresExistentes;

    while (valores.size() < 10) {
        int valor = 1 + rand() % 99;
        if (valoresExistentes.find(valor) == valoresExistentes.end()) {
            valores.push_back(valor);
            valoresExistentes.insert(valor);
        }
    }
    return valores;
}

void print(vector<int> values, int access, int deslocamentos){
    cout << "Acessou " << access << "[";
    for (size_t i = 0; i < values.size(); i++){
        cout << values[i];
        if (i!= values.size()-1) cout << " - ";
    }
    cout << "] Ja deslocou "<< deslocamentos<< endl;
}

// First in First Out 
void fcfs(vector<int> values, int posicaoInicial) {
    //Init
    cout << "Posicao inicial da cabeca de leitura e gravacao "<< posicaoInicial << endl;
    cout << "Original [";
    for (size_t i = 0; i < values.size(); i++) { 
        cout << values[i];
        if (i != values.size() - 1)
            cout << " - ";
    }
    cout << "]" << endl << endl;
    cout << "========== Algoritmo FCFS! ==========" << endl;

    //Variables
    size_t l = 0;
    size_t r;
    size_t voltas = values.size();
    int deslocamento = 0;

    //Algorithm
    while (l < voltas) {
        cout << "Acessou " << values[l] << "[";
        if (l == 0) deslocamento = abs(posicaoInicial - values[l]);
        else deslocamento += abs(values[l-1] - values[l]);
        r = l + 1;
        while (r < voltas) {
            cout << values[r];
            if (r != voltas - 1)
                cout << " - ";
            r++;
        }
        cout << "] Ja deslocou " << deslocamento << " vezes" << endl;
        l++;
    }
    cout << "FCFS - Quantidade total de deslocamentos: " << deslocamento << endl << endl;
}

// Shortest Seek Time First - Menor deslocamento
void sstf(vector<int> values, int posicaoInicial){
    //Init
    cout << "Posicao inicial da cabeca de leitura e gravacao "<< posicaoInicial << endl;
    cout << "Original [";
    for (size_t i = 0; i < values.size(); i++) { 
        cout << values[i];
        if (i != values.size() - 1)
            cout << " - ";
    }    
    cout << "]" << endl << endl;
    cout << "========== Algoritmo FCFS! ==========" << endl;

    //Variables
    size_t access = posicaoInicial;
    int ptr = 0;
    int deslocamento = 0;

    //Algorithm
    for (int j = 0; j < 10; j++){
        ptr=0;
        int minDesloc = 100;
        for (size_t i = 0; i < values.size(); i++){
            int tempDesloc = abs(values[i] - (int)access);
            if(tempDesloc < minDesloc){
                minDesloc = tempDesloc;
                ptr = i;
            }
        }
        deslocamento += minDesloc;
        access = values[ptr];
        values.erase(values.begin() + ptr);
        print(values, access, deslocamento);
    }
    cout << "SSTF - Quantidade total de deslocamentos: " << deslocamento << endl << endl;

}

//Go Up
void goDown(int posicaoInicial, bool first){
    int access  = posicaoInicial;
    if(!first && !done){
        if (!nn){
            deslocamentos += (int)lastPoint;
            lastPoint = 99;
            print(requisitions, 99, deslocamentos);
            nn=true;
        }
        access = 99;
    }else{
        lastPoint = posicaoInicial;
    }

    while(access >= 0){
            int ptr;
            for (size_t i = 0; i < requisitions.size(); i++){
                if (requisitions[i] == access){
                    if(access == 0) zero=false;

                    deslocamentos += abs(access - (int)lastPoint);
                    lastPoint = access;
                    ptr = i;
                    requisitions.erase(requisitions.begin() + ptr);
                    print(requisitions, access, deslocamentos);
                    break;
                }
            }
            access--;
        }
    if(requisitions.size() == (size_t) 0) done = true;

    if(!zero && first && !done){
        deslocamentos += lastPoint;
        lastPoint = 0;
        print(requisitions, 0, deslocamentos);
        zero = true;
    }

}

//go Up
void goUp(int posicaoInicial, bool first){
    int access = posicaoInicial;

    if(!first && !done){
        if(!zero){
            deslocamentos += (int)lastPoint;
            lastPoint = 0;
            print(requisitions, 0, deslocamentos);
            zero = true;
        }
        access = 0;
    }else{
        lastPoint = posicaoInicial;
    }
    while(access < 100){
        int ptr;
        for (size_t i = 0; i < requisitions.size(); i++){
            if (requisitions[i] == access){
                if(access == 99)nn=false;
                
                deslocamentos += abs(access - (int)lastPoint);
                lastPoint = access;
                ptr = i;
                requisitions.erase(requisitions.begin() + ptr);
                print(requisitions, access, deslocamentos);
                break;
            }   
        }
        access++;            
    }
    if(requisitions.size() == (size_t) 0) done = true;
    if(!nn && first && !done){
        deslocamentos += abs(99 - (int)lastPoint);
        lastPoint = 99;
        print(requisitions, 99, deslocamentos);
        nn=true;
    }
}

// Algorithm Scan
void scan(int posicaoInicial){
    //Init
    cout << "Posicao inicial da cabeca de leitura e gravacao "<< posicaoInicial << endl;
    cout << "Original [";
    for (size_t i = 0; i < requisitions.size(); i++) { 
        cout << requisitions[i];
        if (i != requisitions.size() - 1)
            cout << " - ";
    }
    cout << "]" << endl << endl;
    cout << "===== Algoritmo Scan (elevador) =====" << endl;


    // Variables
    bool scanUp;
    done = false;

    // Algorithm
    if (posicaoInicial < 50)
        scanUp = true;

    if (!scanUp){
        goDown(posicaoInicial, true);
        goUp(posicaoInicial, false);
    }else{
        goUp(posicaoInicial, true);
        goDown(posicaoInicial, false);
    }
    cout << "SCAN - Quantidade total de deslocamentos: " << deslocamentos << endl << endl;

}

void circular(int posicaoInicial){
    //Init
    cout << "Posicao inicial da cabeca de leitura e gravacao "<< posicaoInicial << endl;
    cout << "Original [";
    for (size_t i = 0; i < requisitions.size(); i++) { 
        cout << requisitions[i];
        if (i != requisitions.size() - 1)
            cout << " - ";
    }
    cout << "]" << endl << endl;
    cout << "====== Algoritmo Circular SCAN ======" << endl;


    // Variables
    bool scanUp;
    done = false;

    // Algorithm
    if (posicaoInicial > 50)
        scanUp = true;


    if(scanUp){
        goUp(posicaoInicial, true);
        goUp(posicaoInicial, false);
    }else{
        goDown(posicaoInicial, true);
        goDown(posicaoInicial, false);
    }

    cout << "Circular Scan - Quantidade total de deslocamentos: " << deslocamentos << endl << endl;

}

void resetValues(vector<int> values){
    nn = false;
    zero =false;
    deslocamentos = 0; 
    done = false;
    requisitions = values;
}

//C-LOOK
void clook(int posicaoInicial){
    //Init
    cout << "Posicao inicial da cabeca de leitura e gravacao "<< posicaoInicial << endl;
    cout << "Original [";
    for (size_t i = 0; i < requisitions.size(); i++) { 
        cout << requisitions[i];
        if (i != requisitions.size() - 1)
            cout << " - ";
    }
    cout << "]" << endl << endl;
    cout << "========= Algoritmo C-look ==========" << endl;

    // Variables
    bool scanUp;
    done = false;

    // Algorithm
    if (posicaoInicial > 50)
        scanUp = true;

    if (!scanUp){
        goDown(posicaoInicial, true);
        goUp(posicaoInicial, false);
    }else{
        goUp(posicaoInicial, true);
        goDown(posicaoInicial, false);
    }
    cout << "C-look - Quantidade total de deslocamentos: " << deslocamentos << endl << endl;



}


int main(){
    //Teste
    vector<int> values = {30, 70, 54, 59, 29, 64, 87, 38, 05, 40};
    int inicial = 88;

    // vector<int> values = geraValores();
    // int inicial = 1 + rand() % 99;
    cout << "===== Gerenciador de escalonamento de acesso a disco =====" << endl << endl;
    // fcfs(values, inicial);
    // sstf(values, inicial);

    resetValues(values);
    scan(inicial);
    
    // resetValues(values);
    // circular(inicial);

    // resetValues(values);
    // clook(inicial);

    return 1;
}