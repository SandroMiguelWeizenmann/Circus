//***************************************//
// Sandro Miguel Weizenmann              //
// EXEMPLO DE UTILIZAÇÃO DA PLATAFORMA   //
// CIRCUS OF THINGS                      //
//***************************************//


#include <CircusESP32Lib.h>

/** Estas são as declarações relacionadas ao CircusESP32Lib**/
char ssid[] = "SEU WIFI";                         // Coloque seu SSID wifi aqui
char password[] =  "SUA SENHA";                   // Coloque sua senha wifi aqui
char token[] = " ";                               // Coloque seu token da conta Circus Of Things.
char server[] = "www.circusofthings.com";
char teste_key[] = " ";                           // Coloque a chave do sinal que você criou no Circus Of Things para contagem de ciclo
char order_key [] = " "  ;                        // Digite a chave do sinal de circo que você deseja que o ESP32 escute.
CircusESP32Lib circusESP32(server,ssid,password); // O objeto que representa um ESP32 para você poder solicitar gravação ou leitura

/**Variáveis adicionais**/
int contador = 0;
float teste;
const int output22 = 2;                           //saída do LED interno da placa ESP32ROOM

void setup() {
    Serial.begin(115200);                         // Lembre-se de combinar esse valor com a taxa de transmissão no console
    circusESP32.begin();                          // Deixe o objeto Circus configurar-se para uma conexão SSL / Secure
    pinMode(output22, OUTPUT);                    // Define o pino 22 como saída. (Led Azul interno)
    digitalWrite(output22, LOW);                  // Defina as saídas para LOW
}

void loop() {                                     // Agora que tudo está configurado, vamos começar com as tarefas
    teste = contador;
    Serial.println(""); Serial.print("Valor do Teste: "); Serial.println(teste);
    circusESP32.write(teste_key,teste,token);      // Informe o valor do teste ao Circus
    double dashboard_order = circusESP32.read(order_key,token);
     if(dashboard_order == 1){
        digitalWrite(output22, LOW);              // botão OFF Circus
        contador = 0;
    } else {
        digitalWrite(output22, HIGH);             // Botão ON Circus
        contador++;
    }
    delay(70);
}
