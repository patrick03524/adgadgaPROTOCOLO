#include "RSA.h"

int main()
{
    string mensaje_desencriptado;
    vector<ZZ> mensaje_encriptado;
    /*ZZ a,b;
    int bits;
    cout<<"Ingresar la Clave publica del men"<<endl;
    cout<<"E: ";
    cin >> a;
    cout<<"N: ";
    cin >> b;
    cout<<"ingrese la cantidad de Bits: ";
    cin >> bits;
    RSA rsa_obj(bits);
    rsa_obj.ingresar_clave_pub(a,b);*/
    vector<ZZ> Cuack;
    Cuack.push_back(ZZ(19482189496109057303985582078648010096331803643799865803581415829880012753943));
    Cuack.push_back(ZZ(24219353979707605113143789310595875317988737812849469055551333382050716725827));
    Cuack.push_back(ZZ(33127392394185482737058117233058561568834402201877705703217166533578693574581));
    Cuack.push_back(ZZ(23891200046163048306344748807198468995717036285120181457583174429919311988400));
    ZZ p;
    ZZ q;
    ZZ e;
    ZZ n;
    ///ZZ d;
    p=ZZ(227);
    q=ZZ(157);
    ///e=ZZ(587);
    ///e=ZZ(35021);
    ///n=ZZ(1941459763);
    ///n=ZZ(2809);

    e=ZZ(241);
    n=ZZ(36863);
    cout<<e<<endl;
    cout<<n<<endl;
    ///d=ZZ(1047);
    ///e=ZZ(33414925680778783171056778613498035868462232437091767291503441134496372382173);
    ///n=ZZ(53245705508869250225098266227224809693639750996586928917220382238522074264031);
    ///RSA rsa_obj(8);
    RSA rsa_obj(8,p,q);
    rsa_obj.ingresar_clave_pub(e,n);
    /*ZZ e1 =ZZ(13447546860115965247895795093708710719451505650555947930527677407323708756173);
    ZZ n1= ZZ(29865848305831217172201942987644608583833987696880075293370050079687694529847);
    RSA test(e1,n1);*/
    ///mensaje_encriptado=rsa_obj.Encriptado("Love");
    ///rsa_obj.ingresar_clave_pub(e,n);
    ///cout<<"E: "<<mensaje_encriptado<<endl;
    ///mensaje_desencriptado=rsa_obj.Desencriptado(mensaje_encriptado);
    ///mensaje_desencriptado=rsa_obj.Desencriptado(Cuack);
    ///cout <<"D: "<<mensaje_desencriptado<<endl;

    return 0;
}
