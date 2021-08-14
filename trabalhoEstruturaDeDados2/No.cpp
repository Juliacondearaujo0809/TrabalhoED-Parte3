#include "No.h"

No::No(){
    chave = "";
    valor = "";
    texto = "";
}

No::No(string chave, string valor, string texto) {
    this->chave = chave;
    this->valor = valor;
    this->texto = texto;
}

string No::getChave() {
    return this->chave;
}

string No::getValor() {
    return this->valor;
}

string No::getTexto() {
    return this->texto;
}