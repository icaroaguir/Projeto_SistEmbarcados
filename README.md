# Projeto de Controle de Fermentação de Cerveja

Projeto desenvolvido para a disciplina de Sistemas Embarcados (SAA0356) pelos alunos do curso de Engenharia Mecatrônica. A intenção do projeto é implementar um sistema de controle de fermentação de cerveja em uma caldeira industrial. 

### Alunos:

* Edson Jose Brumatti Junior - 9880169 - https://github.com/EdsonBrumatti
* Gabriel Guarino - 9866419 - https://github.com/gabrielguarino97
* Ícaro Almeida Aguiar - 9805042 - https://github.com/icaroaguir
* Jorge Luis Faneco Paschoa - 9805824 - https://github.com/jorgelfp123
* Matheus Borghi Ricardo de Oliveira - 8910517 - https://github.com/mtsborghi

### Instituição:
* Escola de Engenharia de São Carlos - USP

### Docente Responsável:
* Glauco Augusto de Paula Caurin

## Descrição do Projeto:
* Será implementado um controlador para um processo de fermentação de cerveja, com controle de temperatura e nível de CO2 dentro da câmara de fermentação. Conforme visto na figura abaixo:
![Circuito](https://github.com/icaroaguir/Projeto_SistEmbarcados/blob/main/circuito.png)
* No circuito constam os seguites elementos e suas funções:
1. Sensor de temperatura -> Aferir a temperatura da mistura líquida.
2. Potenciometros -> Promovem a interface para regular a temperatura da mistura líquida, e o nível máximo de CO2 dentro da câmara.
3. Servos motores -> Utilizados para regularem a abertura da válvula de gás para o fogareiro, e a válvula de liberação de CO2 para a atmosfera.
4. Motor DC -> Liga e controla a velocidade do misturador do mosto.
5. Buzzer -> Interface sonora que sinaliza o término do processo de fermentação, ou algum problema que ocorra no sistema.
6. Display LCD -> Interface visual para reportar informações do processo (temperatura, nível de CO2, tempo de fermentação) e alterá-las.
7. Microcontrolador -> Plataforma de desenvolvimento que oferece controle e manipulação a partir da comunicação entre sensores, atuadores e sua programação. 

## Subsistemas
* Configurar entradas: 

* Temperatura: O subsistema de temperatura conta com um botão, um Sensor de Temperatura (TMP), um Microservo de Posição e um Potenciometro. O operador aperta o botão que lhe permite escolher a temperatura girando o potenciometro. O sensor de temperatura monitora a temperatura e enquanto a temperatura medida for menor que a desejada o Microservo mantem a valvula de gás da caldeira aberta. Caso a temperatura seja maior ou igual a temperatura desejada, o Microserve fecha a valvula

* CO2: O subsistema conta com um Sensor de CO2, um Servomotor, um potênciometro, e um botão. O usurario vai setar o nivel maximo de CO2 na mistura utilizando o potenciometeo e o botão. Caso a concentração de CO2 passe do valor maximo escolhido, o Servomotor vai abrir a valvula rotular de escape de CO2 proporcionalmente ao quanto a concentração está mais alta que o máximo, sendo 100% acima abrindo toda a valvula.

* Buzzer:

* Display LCD: O display LCD será responsável por dar visualização do status do sistema de controle de temperaturado sistema, viabilizando o monitoramento em tempo real se o input de temperatura desejada está sendo atingida e mantida.


## Requisitos do Sistema:
* Para esse projeto foi utilizada a plataforma de prototipagem eletrônica, Tinkercad, onde era possível utilizar nosso circuito em conjunto com o microcontrolador e verificar a lógica do código em conjunto com a simulação do nosso circuito virtual e a funcionalidade do mesmo.
* A BB Black conta com um processador AM335x, que integra um ARM Cortex™-A8 com velocidade de 1GHz, 512MB (tipo DDR3) de memória RAM e 4GB de memória flash (8 bits).


## Implementação para um produto real:
Primeiramente, é importante ressaltar que, em uma aplicação presencial em sala de aula, seria usado a plataforma de desenvolvimento BeagleBone Black. Esta plataforma de desenvolvimento de baixo custo, diferente do Arduino Uno Rev3, não possui barreiras de uso exclusivo educacionais e pode ser utilizada comercialmente (simulando um projeto de engenharia embarcada real). Como o presente projeto se encontra em tempos de aulas EAD, simplificamos seu desenvolvimento em uma plataforma virtual de desenvolvimento, que apenas contava com o microcontrolador Arduino Rev3. Portanto, o projeto levará em conta os parametrôs da simulação em Tinkercad.
