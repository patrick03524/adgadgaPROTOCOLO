#include "RSA_BLOCKS.h"

RSA_BLOCKS::RSA_BLOCKS(int bits)
{
    ///menu();
    ///numeros de (2^bits)/2 a (2^bits)-1
    generar_claves(bits);
    e_pub=e;
    n_pub=n;
}
RSA_BLOCKS::RSA_BLOCKS(int bits, ZZ e2, ZZ n2)
{
    generar_claves(bits);
    e_pub=e2;
    n_pub=n2;
}
RSA_BLOCKS::RSA_BLOCKS(ZZ p_1,ZZ q_1,ZZ e_1,ZZ d_1,ZZ e_2,ZZ n_2)
{
    p = p_1;
    q = q_1;
    e = e_1;
    d = d_1;
    n = p * q;
    phi = (p-1)*(q-1);
    e_pub = e_2;
    n_pub = n_2;
}
void RSA_BLOCKS::generar_claves(int bits)
{
    ZZ min;
    min = (2^bits)/2;
    p=generar_Aleatorio_bits(bits);
    while(!ProbPrime(p) || p<min){
        p=generar_Aleatorio(bits);
        ///cout<<"NEL"<<endl;
    }
    cout<<"P:"<<p<<endl;
    q=generar_Aleatorio_bits(bits);
     while(!ProbPrime(q) || q<min){
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
ZZ RSA_BLOCKS::Resto_Chino(ZZ num){     ///algoritmo exponenciación rápida binaria – Teorema Chino del Resto
    ZZ dp = modulo(d,p-1);
    ZZ dq = modulo(d,q-1);
    ZZ D1 = exponenciacion_modular(num,dp,p);
    ZZ D2 = exponenciacion_modular(num,dq,q);
    ZZ P = p*q;
    ZZ P1 = P/p;        ///ZZ P1 = q;
    ZZ P2 = P/q;        ///ZZ P2 = p;
    ZZ Q1 = inversa(P1,p);
    ZZ Q2 = inversa(P2,q);
    ZZ resultado = modulo(D1 * P1 * Q1,P);
    resultado += modulo(D2 * P2 * Q2,P);
    resultado = modulo(resultado,P);
    return resultado;
}
string RSA_BLOCKS::rellenado_0(int a)
{
    string llenar = int_to_string(a);
    string treat_fill = int_to_string(alfabeto.size());
    while(llenar.size()<treat_fill.size()){
        llenar = '0' + llenar;       ///llenado al principio
    }
    return llenar;
}
string  RSA_BLOCKS::rellenado_aux(ZZ a, ZZ n_1)
{
    string llenar = zz_To_String(a);
    string treat_fill = zz_To_String(n_1);
    while(llenar.size()<treat_fill.size()){
        llenar = '0' + llenar;       ///llenado al principio
    }
    return llenar;
}
string RSA_BLOCKS::rellenado_aux_esp(ZZ a,ZZ n_1)
{
    string llenar = zz_To_String(a);
    string treat_fill = zz_To_String(n_1);
    while(llenar.size()<treat_fill.size()-1){
        llenar = '0' + llenar;       ///llenado al principio
    }
    return llenar;
}
string RSA_BLOCKS::Encriptado(string mensaje_original)
{
    string mensaje_encriptado;
    string mensaje_1_paso,mensaje_2_paso,mensaje_3_paso;
    vector<string> bloques;
    string bleach1 = zz_To_String(n);
    string bleach2 = zz_To_String(n_pub);
    int bloques1 = bleach1.size();
    int bloques2 = bleach2.size();

    string temp1,temp2,temp3,temp4;
    int treat_num = zz_To_String(n).size()-1;
    for(unsigned int i=0; i<mensaje_original.size();i++){
        temp1+=rellenado_0(alfabeto.find(mensaje_original[i]));
    }
    cout <<temp1<<endl;
    while(modulo(ZZ(temp1.size()),ZZ(bleach1.size()-1))!=0){
        temp1+=zz_To_String(ZZ(alfabeto.find('W')));
    }
    cout <<temp1<<endl;
    for(unsigned int i = 0; i<temp1.size();i++){
        temp2+=temp1[i];
        if(temp2.size()==bloques1){
            bloques.push_back(temp2);
            cout<<"B"<<i/5+1<<": "<<temp2<<endl;
            temp2 = "";
        }
    }
    cout<<temp1<<endl;
    for(unsigned int i = 0; i<bloques.size();i++){
        ZZ pos = exponenciacion_modular(string_To_ZZ(bloques[i]),e_pub,n_pub);
        mensaje_1_paso+= rellenado_aux(pos,n_pub);
    }
    cout<<mensaje_1_paso<<endl;
    ///RÚBRICA
    for(unsigned int i = 0; i<mensaje_1_paso.size(); i++){
        temp3+=mensaje_1_paso[i];
        if(temp3.size()==bloques1){
            ZZ pos = exponenciacion_modular(string_To_ZZ(temp3),d,n);
            mensaje_2_paso+=rellenado_aux(pos,n);
        }
        if(i==mensaje_1_paso.size()-1){
            ZZ pos = exponenciacion_modular(string_To_ZZ(temp3),d,n);
            mensaje_2_paso+=rellenado_aux(pos,n);
        }
    }
    cout<<temp3<<endl;
    ///FIRMA DIGITAL

    for(unsigned int i = 0; i<mensaje_2_paso.size();i++){
        temp4+=mensaje_2_paso[i];
        if(temp4.size()==bloques2){
            ZZ pos = exponenciacion_modular(string_To_ZZ(temp4),e_pub,n_pub);
            mensaje_3_paso+=rellenado_aux(pos,n_pub);
        }
        if(i==mensaje_2_paso.size()-1){
            ZZ pos = exponenciacion_modular(string_To_ZZ(temp4),e_pub,n_pub);
            mensaje_3_paso+=rellenado_aux(pos,n_pub);
        }
    }
    mensaje_encriptado = mensaje_3_paso;
    return mensaje_encriptado;
}
string RSA_BLOCKS::Desencriptado(string mensaje_encriptado)
{
    string mensaje_desencriptado;
    string mensaje_1_paso;
    vector<string> bloques;
    string bleach1 = zz_To_String(n);
    string bleach2 = zz_To_String(n_pub);
    int bloques1 = bleach1.size();
    int bloques2 = bleach2.size();

    string temp1,temp2,temp3,temp4,temp5,temp6;
    int treat_num = zz_To_String(n).size()-1;
    for(unsigned int i=0; i<mensaje_encriptado.size();i++){
        temp1+=mensaje_encriptado[i];
        if(temp1.size()==bloques1){
            bloques.push_back(temp1);
            cout<<"B"<<i/5+1<<": "<<temp1<<endl;
            temp1 = "";
        }
    }
    cout <<temp1<<endl;
    for(unsigned int i=0; i<bloques.size(); i++){
        ZZ pos = Resto_Chino(string_To_ZZ(bloques[i]));
        temp2 += rellenado_aux_esp(pos,n);
    }
    ///FIRMA
    for(unsigned int i=0; i<temp2.size();i++){
        temp3+=temp2[i];
        if(temp3.size()==bloques2){
            ZZ pos = exponenciacion_modular(string_To_ZZ(temp3),e_pub,n_pub);
            temp4+=rellenado_aux(pos,n_pub);
        }
        if(i==temp2.size()-1){
            ZZ pos = exponenciacion_modular(string_To_ZZ(temp3),e_pub,n_pub);
            temp4+=rellenado_aux(pos,n_pub);
        }
    }
    ///RÚBRICA
    for(unsigned int i=0; i<temp4.size();i++){
        temp5+=temp4[i];
        if(temp5.size()==bloques2){
            ZZ pos = exponenciacion_modular(string_To_ZZ(temp5),d,n);
            temp6+=rellenado_aux(pos,n);
        }
        if(i==temp4.size()-1){
            ZZ pos = exponenciacion_modular(string_To_ZZ(temp3),d,n);
            temp6+=rellenado_aux(pos,n);
        }
    }
    for(unsigned int i=0;i<temp6.size();i++){
        mensaje_1_paso+=temp6[i];
        string lim = int_to_string(alfabeto.size());
        if(mensaje_1_paso.size()==lim.size()){
            mensaje_desencriptado+=alfabeto[string_to_int(mensaje_1_paso)];
            mensaje_1_paso="";
        }
    }
    return mensaje_desencriptado;
}
