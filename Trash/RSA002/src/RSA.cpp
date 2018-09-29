#include "RSA.h"

RSA::RSA(int bits)
{
   generar_claves(bits);
   cout<<"Se generaron las claves"<<endl;
}
/*
RSA::RSA(int bits,ZZ p,ZZ q)
{
    p=a;
    q=b;
    n=p*q;
    phi=phi_euler(p,q);
    e=generar_Aleatorio_Max(bits,phi);
    while(euclides(e,phi)!=1){
        e=generar_Aleatorio_Max(bits,phi);
    }
    tam=alfabeto.length();
}*/

RSA::RSA(int bits,ZZ clave_p,ZZ clave_q)
{
    p=clave_p;
    q=clave_q;
    n=p*q;
    cout<<"N: "<<n<<endl;
    phi=phi_euler(p,q);
    cout<<"PHI: "<<phi<<endl;
    e=generar_Aleatorio_Max(phi);
    while(euclides(e,phi)!=1){
        e=generar_Aleatorio_Max(phi);
    }
    cout <<"E:"<<e<<endl;
    tam=alfabeto.length();
    cout<<"TAM: "<<tam<<endl;
    d=inversa(e,phi);
}
vector<ZZ> RSA::Encriptado(string mensaje_original)
{
    cout<<"Entrando al Encriptado.."<<endl;
    vector<ZZ> mensaje_encriptado;
    int allahu_akbar;
    for(unsigned int i=0;i<mensaje_original.length();i++){
        allahu_akbar=alfabeto.find(mensaje_original[i]);
        ZZ cuack = exponenciacion_modular(ZZ(allahu_akbar),e,n);
        mensaje_encriptado.push_back(cuack);
        cout<<cuack<<endl;
    }
    return mensaje_encriptado;

}
string RSA::Desencriptado(vector<ZZ> mensaje_encriptado)
{
    cout<<"Entrando al Desencriptado.."<<endl;
    string mensaje_desencriptado;
    int allahu_akbar;
    for(unsigned int i=0;i<mensaje_encriptado.size();i++){
        ZZ cuack = exponenciacion_modular(mensaje_encriptado[i],d,n);
        allahu_akbar=ZZ_to_int(cuack);
        mensaje_desencriptado+=alfabeto[allahu_akbar];
    }
    return mensaje_desencriptado;
}
void RSA::ingresar_clave_pub(ZZ clave_e,ZZ clave_n)
{
    e=clave_e;
    cout <<"E:"<<e<<endl;
    n=clave_n;
    cout<<"N: "<<n<<endl;
    d=inversa(e,phi);
}
void RSA::generar_claves(int bits)
{
    p=generar_Aleatorio(bits);
    while(!ProbPrime(p)){
        p=generar_Aleatorio(bits);
        ///cout<<"NEL"<<endl;
    }
    cout<<"P:"<<p<<endl;
    q=generar_Aleatorio(bits);
     while(!ProbPrime(q)){
        q=generar_Aleatorio(bits);
        ///cout<<"NEL"<<endl;
    }
    cout<<"Q:"<<q<<endl;
    n=p*q;
    cout<<"N: "<<n<<endl;
    phi=phi_euler(p,q);
    cout<<"PHI: "<<phi<<endl;
    e=generar_Aleatorio_Max(phi);
    while(euclides(e,phi)!=1){
        e=generar_Aleatorio_Max(phi);
    }
    cout <<"E:"<<e<<endl;
    tam=alfabeto.length();
    cout<<"TAM: "<<tam<<endl;
    d=inversa(e,phi);
    cout <<"D:"<<d<<endl;
}
