#include <bits/stdc++.h>
using namespace std;

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

    size_t access = posicaoInicial;
    int ptr = 0;
    int deslocamento = 0;
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


int main(){
    //Teste
    vector<int> values = {30, 70, 54, 59, 29, 64, 87, 38, 05, 40};
    int inicial = 88;

    // vector<int> values = geraValores();
    // int inicial = 1 + rand() % 99;
    cout << "===== Gerenciador de escalonamento de acesso a disco =====" << endl << endl;

    // fcfs(values, inicial);
    sstf(values, inicial);
    
    return 1;
}