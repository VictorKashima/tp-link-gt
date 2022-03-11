//TCC NERVOSO

//Incluir a biblioteca do infravermelho.
#include <IRremote.h>
//Entrada para receber os sinais do controle iR.
int RECV_PIN = 2;

//Saída para acionar buzina.
int Buzina = 9;

//Saída para acionar os motores das rodas.
int Motor1F = 5;
int Motor1B = 3;
int Motor2F = 6;
int Motor2B = 4;

//Entradas para receber sinal dos sensores IR.
int Sensor1 = 7;
int Sensor2 = 8;

//Saídas para ligar os leds indicadores de modo.
int LED1 = 10;
int LED2 = 11;
int LED3 = 12;
int LED4 = 13;

//Saídas para acionar faróis.
int FarolF = 16;
int FarolB = 17;
int SetaR = 18;
int SetaL = 19;

//Iniciar com valores "padrão".
int PWM = 60;
int Modo = 1;
int valorAnterior, EstadoSensor1, EstadoSensor2, modoF, modoB, modoD, modoE, PiscaD, PiscaE = 0;

char r;

int ledState = LOW;
long pMillis = 0;
long interval = 300;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(Buzina, OUTPUT);
  pinMode(Motor1F, OUTPUT);
  pinMode(Motor1B, OUTPUT);
  pinMode(Motor2F, OUTPUT);
  pinMode(Motor2B, OUTPUT);

  pinMode(Sensor1, INPUT);
  pinMode(Sensor2, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  
  pinMode(FarolF, OUTPUT);
  pinMode(FarolB, OUTPUT);
  pinMode(SetaR, OUTPUT);
  pinMode(SetaL, OUTPUT);
    
}

void loop()
{
  unsigned long cMillis = millis();
  valorAnterior = results.value;
  results.value = 0;
  
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    irrecv.resume();
    delay(180);
  }
  
//Stand by
  if(results.value == 0xC1AA7986){
    Modo = 1 ;
  }

//Automático
  if(results.value == 0xC1AA51AE){
    Modo = 2;
  }

//Infra Vermelho
  if(results.value == 0xC1AAF10E){
    Modo = 3;
  }

//Bluetooth
  if(results.value == 0xC1AAD52A){
    Modo = 4; 
  }


  if(Modo == 1){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    
    void parado();

    modoF = 0;
    modoB = 0;
    modoD = 0;
    modoE = 0;
  }

  
  if(Modo == 2){
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);

  EstadoSensor1 = digitalRead(Sensor1);
  EstadoSensor2 = digitalRead(Sensor2);
  
  if ((EstadoSensor1 == 1)&&(EstadoSensor2 == 1)){
    frente();
  }

  if ((EstadoSensor1 == 0)&&(EstadoSensor2 == 1)){
    esquerda();
  }

  if ((EstadoSensor1 == 1)&&(EstadoSensor2 == 0)){
    direita();
  }

  if ((EstadoSensor1 == 0)&&(EstadoSensor2 == 0)){
    parado();
  }
}


  if(Modo == 3){  
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, LOW);

    //Sistema Farol
    //Frente
      if((results.value == 0xC1AA21DE) && (valorAnterior == 0)){
        if(modoF < 1){
          modoF = modoF + 1;
        }
        else{
          modoF = 0;
        }
      } 
     //Traseiro
      if((results.value == 0xC1AAF906) && (valorAnterior == 0)){
        if(modoB < 1){
          modoB = modoB + 1;
        }
        else{
          modoB = 0;
        }
      }
     //Direita
      if((results.value == 0xC1AAD926) && (valorAnterior == 0)){
        modoE = 0;
        if(modoD < 1){
          modoD = modoD + 1;
        }
        else{
          modoD = 0;
        }
      }
     //Esquerda
      if((results.value == 0xC1AA59A6) && (valorAnterior == 0)){
        modoD = 0;
        if(modoE < 1){
          modoE = modoE + 1;
        }
        else{
          modoE = 0;
        }
      }

      //Reset
    if(results.value == 0){
      parado();
    }
  
    //Frente
    if(results.value == 0xC1AA8D72){
      frente();
    }
    
    //Esquerda
    if(results.value == 0xC1AA0DF2){
      esquerda();
    }

    //Direita
    if(results.value == 0xC1AA4DB2){
      direita();
    }
    
    //Atras
    if(results.value == 0xC1AACD32){
      tras();
    }

    //Buzina
    if(results.value == 0xC1AAA15E){
      digitalWrite(Buzina, HIGH);
    }
  }

  
  if(Modo == 4){
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, HIGH);
  /* Apaguei o restante do modo 4 porque 
    ele não funcionava junto com o sistema infravermelho.
  */
}

    //Velocidade
    if(results.value == 0xC1AA19E6){
      PWM = 255;
    }
    if(results.value == 0xC1AA11EE){
      PWM = 220;
    }
    if(results.value == 0xC1AA619E){
      PWM = 190;
    }
    if(results.value == 0xC1AA9966){
      PWM = 100;
    }
    if(results.value == 0xC1AA916E){
      PWM = 95;
    }
    if(results.value == 0xC1AAE11E){
      PWM = 90;
    }
    if(results.value == 0xC1AA49B6){
      PWM = 80;
    }
    if(results.value == 0xC1AA41BE){
      PWM = 70;
    }
    if(results.value == 0xC1AAC936){
      PWM = 60;
    }


//Sistema Farol dianteiro
  if(modoF == 1){
    digitalWrite(FarolF, HIGH);
  }
  if(modoF == 0){
    digitalWrite(FarolF, LOW);
  }

//Sistema Farol traseiro
  if(modoB == 1){
    digitalWrite(FarolB, HIGH);
  }
  if(modoB == 0){
    digitalWrite(FarolB, LOW);
  }

//Sistema pisca esquerdo
if(modoE == 1){
  if(cMillis - pMillis > interval) {
    pMillis = cMillis;   
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
    digitalWrite(SetaL, ledState);
  }
}
 if(modoE == 0){
    digitalWrite(SetaL, LOW);
  }

//Sistema pisca direito
  if(modoD == 1){
  if(cMillis - pMillis > interval) {
    pMillis = cMillis;   
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
    digitalWrite(SetaR, ledState);
  }
}
  if(modoD == 0){
    digitalWrite(SetaR, LOW);
  }
  
}

//Faz o carrinho ir para frente
void frente(){
    analogWrite(Motor1F, PWM);
    analogWrite(Motor2F, PWM);
    digitalWrite(Motor1B, LOW);
    digitalWrite(Motor2B, LOW);
}

//Faz o carrinho ir para trás.
void tras(){
    analogWrite(Motor1F, PWM);
    analogWrite(Motor2F, PWM);
    digitalWrite(Motor1B, HIGH);
    digitalWrite(Motor2B, HIGH);
}

//Faz o carrinho virar para esquerda.
void esquerda(){
    digitalWrite(Motor1F, LOW);
    analogWrite(Motor2F, PWM);
    digitalWrite(Motor1B, LOW);
    digitalWrite(Motor2B, LOW);
}

//Faz o carrinho virar para direita.
void direita(){
    analogWrite(Motor1F, PWM);
    digitalWrite(Motor2F, LOW);
    digitalWrite(Motor1B, LOW);
    digitalWrite(Motor2B, LOW);
}

//Desliga tudo.
void parado(){
    digitalWrite(Motor1F, LOW);
    digitalWrite(Motor2F, LOW);
    digitalWrite(Motor1B, LOW);
    digitalWrite(Motor2B, LOW);
    digitalWrite(Buzina, LOW);
}