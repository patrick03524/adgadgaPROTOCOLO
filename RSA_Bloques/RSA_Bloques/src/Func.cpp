#include "Func.h"

ZZ modulo(ZZ a,ZZ b)
{
    ZZ q=a/b;
    ZZ r=a-q*b;
    if(r<0)
        r+=b;
    return r;
}
ZZ euclides(ZZ a, ZZ b)
{
    ZZ res=modulo(a,b);
    while(res!=0)
    {
        ///cout<< a << "=" << a/b << "(" << b << ")" << "+" << res << endl;
        a=b;
        b=res;
        res=modulo(a,b);
    }
    ///cout<< a << "=" << a/b << "(" << b << ")" << "+" << res << endl;
    return b;
}
vector<ZZ> euclides_extendido(ZZ a, ZZ b)
{
    vector<ZZ> result;
    ZZ r1 = a, r2 = b;
    ZZ x1 = to_ZZ(1), x2 = to_ZZ(0);
    ZZ y1 = to_ZZ(0), y2 = to_ZZ(1);

    ZZ q , r , x , y;

    while(r2>0){
        q = r1/r2;

        r = r1 - q*r2;
        r1 = r2;
        r2 = r;

        x = x1 - q*x2;
        x1 = x2;
        x2 = x;
    }
    result.push_back(x1);
    result.push_back(x2);
    result.push_back(euclides(a,b));
    return result;
}
ZZ inversa(ZZ a,ZZ b)
{
    vector<ZZ> temp;
    temp=euclides_extendido(a,b);
    if(temp[0]<0){
        return temp[0]+b;
    }
    else{
        return temp[0];
    }
}
ZZ multiplicacion_modular(ZZ a, ZZ b,ZZ mod)
{
    return modulo((modulo(a, mod) * modulo(b,mod)), mod);
}
ZZ exponenciacion_modular(ZZ a,ZZ b,ZZ mod)
{
    ZZ resultado = ZZ(1);
    while(b>0){
        if((b&1)==1){
            resultado = multiplicacion_modular(resultado,a,mod);
        }
        a=multiplicacion_modular(a,a,mod);
        b=b/2;
    }
    return resultado;
}
ZZ phi_euler(ZZ p,ZZ q)
{
    return (p-1)*(q-1);
}
/*
string leer_txt_p()
{
    string mensaje;
    ifstream Fichero_Entrada1;
    Fichero_Entrada1.open("p.txt");
    getline(Fichero_Entrada1,mensaje);
    cout <<mensaje<<endl;
    Fichero_Entrada1.close();
    return mensaje;
}
string leer_txt_q()
{
    string mensaje;
    ifstream Fichero_Entrada2;
    Fichero_Entrada2.open("q.txt");
    getline(Fichero_Entrada2,mensaje);
    cout <<mensaje<<endl;
    Fichero_Entrada2.close();
    return mensaje;
}*/
string zz_To_String(ZZ z) {
    stringstream a;
    a << z;
    return a.str();
}

ZZ string_To_ZZ(string str){
    ZZ number(INIT_VAL, str.c_str());
    return number;
}
int ZZ_to_int(ZZ number)
{
    int n;
    conv(n,number);
    return n;
}
string int_to_string(int a)
{
    stringstream bleach;
    bleach << a;
    string aux=bleach.str();
    return aux;
}
int string_to_int(string a)
{
    stringstream bleach(a);
    int aux = 0;
    bleach >> aux;
    return aux;
}
ZZ generar_Aleatorio(int bits)
{
     ZZ a;
     a=RandomLen_ZZ(bits);
     return a;
}
ZZ generar_Aleatorio_Prime(int bits)
{
     ZZ a;
     GenPrime(a,bits);
     return a;
}
ZZ generar_Aleatorio_Max(ZZ max)
{
    ZZ a;
    a=RandomBnd(max); ///default 512?
    return a;
}
ZZ generar_Aleatorio_bits(int bits)
{
    ZZ a;
    a = RandomBits_ZZ(bits);
    return a;
}

