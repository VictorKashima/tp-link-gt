<!-- README CARRO CONTROLADO POR CONTROLE REMOTO COM ARDUINO>
<!-- README IR CAR WITH ARDUINO -->

<h1 align="center"> CARRINHO DE CONTROLE REMOTO COM ARDUINO </h1>

<div align="center">
<img src = "https://media.giphy.com/media/DADPAT9e6NCLlsTBeK/giphy.gif">
</div>
<pre>
<h3 align="center">O carrinho funciona através do arduino com 4 modos.</h3>
<p align="left">
Modo 1 / Stand by = carrinho fica parado com todas funções desligadas para poupar energia.
Modo 2 / Automático = funciona de modo automático seguindo a linha feita com fita isolante.
Modo 3 / Infra Vermelho = funciona manualmente de acordo com os sinais do controle remoto.
Modo 4 / Bluetooth = funciona manualmente de acordo com os sinais enviados pelo bluetooth.
</p>
    </pre>

<pre>
<h2 align="center">Modo 1 / Stand By</h2>
<p align="left">

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
