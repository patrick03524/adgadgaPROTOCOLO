#include "Protocolo.h"

int main()
{
    srand(time(NULL));
    cout << "Protoculo!" << endl;
    Protocolo culo("243","PMC","MAR","CH");
    string mensaje = "TEESTOYBUSCANDOPARAEXPLOTARCONTIGOPARAEXPLOTARCONTIGOPARAEXPLOTARNOSTEESTOYLLAMANDOPARAVOLARCONTIGOZ";
    string encriptado = culo.Encriptado(mensaje);
    cout <<encriptado<<endl;
    string desencriptado = culo.Desencriptado();
    cout <<desencriptado<<endl;
    /*culo.leer_txt();
    culo.escribir_txt("TE ESTOY LLAMANDO PARA EXPLOTAR CONTIGO");
    culo.leer_txt();*/
    /*Enigma e("ABC",1,2,3,"RFW","GH");
    string wea = e.Desencriptado("RXATTSFKVJANRFYNUEIFNOBFYSPVAQACJSF");
    cout <<wea<<endl;*/




    return 0;
}
