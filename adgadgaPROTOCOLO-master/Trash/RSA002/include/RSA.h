#ifndef RSA_H
#define RSA_H
#include "Func.h"

class RSA
{
    public:
        RSA(int);
        RSA(int,ZZ,ZZ);
        vector<ZZ> Encriptado(string);
        string Desencriptado(vector<ZZ>);
        void ingresar_clave_pub(ZZ,ZZ);
    private:
        string alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ._-0123456789";
        ZZ p;
        ZZ q;
        ZZ n;
        ZZ phi;
        ZZ e;
        ZZ d;

        void generar_claves(int);
        int tam;
};

#endif // RSA_H
