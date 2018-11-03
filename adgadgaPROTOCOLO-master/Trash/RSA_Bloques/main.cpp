#include "RSA_BLOCKS.h"

int main()
{
    /*cout << "-----------------------------------------------" <<endl;
    cout << "-----------------------------------------------" <<endl;
    cout << "------------------BIENVENIDO-------------------" <<endl;
    cout << "-----------------------------------------------" <<endl;
    cout << "----------------------RSA----------------------" <<endl;
    cout << "-----------------------------------------------" <<endl;
    cout << "----------------------CON----------------------" <<endl;
    cout << "-----------------------------------------------" <<endl;
    cout << "--------------------BLOQUES--------------------" <<endl;
    cout << "-----------------------------------------------" <<endl;
    system("pause");
    system("cls");
    unsigned short int op;
    cout << "Ingrese la opcion que quiera realizar" <<endl;
    cout << "1.- Instanciar y Asignar Claves" <<endl;
    cout << "2.- Cifrado" <<endl;
    cout << "3.- Descifrado" <<endl;
    cout << "4.- Salir" <<endl;
    cout << "Opcion: ";
    cin >> op;
    while(op!=4){
        switch(op)
        {
        case 1:
            ///instanciar xd
        case 2:
            ///cifrado
            break;
        case 3:
            ///Descifrado"
            break;
        default:
            cout << "jajajaja nel prro "<<endl;
            break;
        }
        cout << "Ingrese la opcion otra ves: ";
        cin >> op;
    }
    system("cls");
    cout <<"Eligio la opcion 4"<<endl;
    cout <<"Ta luegorl"<<endl;*/
    ///RSA_BLOCKS cuack(8,ZZ(3),ZZ(1003));
    ///RSA_BLOCKS cuack(8);
    RSA_BLOCKS cuack(ZZ(17),ZZ(23),ZZ(47),ZZ(15),ZZ(47),ZZ(391));
    string chula = cuack.Encriptado("come here");
    cout<<"E: "<<chula<<endl;
    cout<<"D: "<<cuack.Desencriptado(chula)<<endl;
    return 0;
}
