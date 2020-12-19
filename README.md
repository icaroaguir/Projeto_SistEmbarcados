# Projeto de Controle de Fermentação de Cerveja

Projeto desenvolvido para a disciplina de Sistemas Embarcados (SAA0356) pelos alunos do curso de Engenharia Mecatrônica. O projeto visa a construção do conceito de um sistema de controle de fermentação de cerveja em uma caldeira industrial. Será feito a validação do projeto via simulação online na ferramenta TINKERCAD. 

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

### Introdução 

A realização do processo de fermentação de bebidas foi praticada pelos povos primitivos pela primeira vez. E desde então, o processo continuou sendo realizado, até chegar no patamar e no nível de desenvolvimento que temos atualmente, considerando todas as etapas e profissionais que auxiliam e ajudam no processo de fermentação de bebidas.

O processo de fermentação em si, faz com que as leveduras consumam todos os açúcares fermentáveis contidos na planta, gerando pôster e principalmente, o álcool e o CO2. Mas não são somente esses itens que são produzidos na fermentação, os aromas e os sabores por exemplo, que são grandes valores da cerveja são produzidos também, somados com a redução do Ph da cerveja.

![cervejatemp](https://github.com/icaroaguir/Projeto_SistEmbarcados/blob/main/cervejatemp.jpg)

Em praticamente todas as receitas de cerveja é indicado uma temperatura ideal para a fermentação.Isso se deve ao fato de que para a levedura trabalhar e converter todo o açúcar do mosto em álcool são necessárias condições ideais. E a temperatura é uma das principais!
Quando a temperatura se encontra na faixa ideal da levedura, este pode fazer o seu trabalho de modo mais natural e sem estresse.

É fácil de visualizar isso quando pensamos que nós trabalhamos praticamente da mesma forma! Imagine que você está em seu local de trabalho e o ar condicionado quebrou, as janelas não podem ser abertas e praticamente não há ventilação! Realmente não é uma condição ideal de trabalho e a sua produtividade com certeza vai ser comprometida.

Com as leveduras acontece a mesma coisa. Sob estresse elas podem gerar diversos sabores e aromas indesejados na cerveja (off-flavors), tais como aromas frutados demais ou até notas muito alcoólicas. Além disso é capaz que, nestas circunstâncias, ela não termine de fermentar por completo a cerveja (baixa atenuação).

A solução ideal para então controlar melhor a temperatura da fermentação é o uso de um sistema que consiga identificar a temperatura na câmara de fermentação e de maneira inteligente consiga controlá-la.


## Descrição do Projeto:
* Será implementado um controlador para um processo de fermentação de cerveja, com controle de temperatura e nível de CO2 dentro da câmara de fermentação. Conforme visto na figura abaixo:
![Circuito](https://github.com/icaroaguir/Projeto_SistEmbarcados/blob/main/circuito.png)
* No circuito constam os seguites elementos e suas funções:
1. Sensor de temperatura -> Aferir a temperatura da mistura líquida.
2. Potenciômetros -> Promovem a interface para regular a temperatura da mistura líquida, e o nível máximo de CO2 dentro da câmara.
3. Servos motores -> Utilizados para regularem a abertura da válvula de gás para o fogareiro, e a válvula de liberação de CO2 para a atmosfera.
4. Motor DC -> Liga e controla a velocidade do misturador do mosto.
5. Buzzer -> Interface sonora que sinaliza o término do processo de fermentação, ou algum problema que ocorra no sistema.
6. Display LCD -> Interface visual para reportar informações do processo (temperatura, nível de CO2, tempo de fermentação) e alterá-las.
7. Microcontrolador -> Plataforma de desenvolvimento que oferece controle e manipulação a partir da comunicação entre sensores, atuadores e sua programação. 

## Sistema de Fermentação da Cerveja:
 O caldo será mexido e aquecido até a temperatura desejada e durante o tempo que o usuario escolher. Durante a fermentação o caldo libera CO2, e a concentração de gás carbonico também pode ser escolhida pelo operador. O caldo deve ser mexido durante um tempo de X horas e após o motor que mexe o caldo deve ser desligado. Mesmo com o motor desligado o caldo continua fermentando durante o tempo que o usuario setou.

## Subsistemas
* Configurar entradas: Para configurar os valores das entradas de temperatura e CO2, o usuario precisará pressionar o botão de configuração uma vez, o que habilitará que o sistema capture os valores dos potenciômetros, então o usuário irá mexer nos potenciômetros de forma a atingir os valores de temperatura e nivel de co2 que desejar, e irá pressionar o botão de configuração novamente para salvar os valores configurados.

* Temperatura: O subsistema de temperatura conta com um Sensor de Temperatura (TMP36), um Microservo de Posição e um Potenciômetro. Após o operador configurar as entradas, o sensor de temperatura monitora a temperatura do mosto, e enquanto a temperatura medida for menor que a desejada o Microservo mantém a válvula de gás da caldeira com uma abertura grande para grandes diferenças de temperatura, e dimui essa abertura conforme a temperatura se aproxima do valor desejado. Caso a temperatura seja maior que a desejada, o Microservo reduz a abertura da válvula lentamente.

* CO2: O subsistema conta com um Sensor de CO2, um Servomotor, um potênciometro, e um botão. O usurario vai setar o nivel maximo de CO2 na mistura utilizando o potenciometeo e o botão. Caso a concentração de CO2 passe do valor maximo escolhido, o Servomotor vai abrir a valvula rotular de escape de CO2 proporcionalmente ao quanto a concentração está mais alta que o máximo, sendo 100% acima abrindo toda a valvula.

* Motor DC: O Motor DC será responsável por homogeinizar a mistura na câmara de fermentação quando necessário. Dado a natureza de funcionamento do motor será possivel fazer o controle de velocidade através de um potenciômetro, sendo assim, regulando a tensão aplicada.

* Buzzer: O Buzzer será responsável por alertar o usuário do sistema quando a temperatura desejada estiver fora do padrão dado um erro de dois(02) graus célsius acima ou abaixo do desejado. Dessa forma o alerta será dado de forma a previnir algum acidente e que o usuário perca o produto, pois o controle de temperatura é essencial no processo de fermentação.

* Display LCD: O display LCD será responsável por dar visualização do status do sistema de controle de temperaturado sistema, viabilizando o monitoramento em tempo real se o input de temperatura desejada está sendo atingida e mantida.


## Requisitos do Sistema:
* Para esse projeto foi utilizada a plataforma de prototipagem eletrônica, Tinkercad, onde era possível utilizar nosso circuito em conjunto com o microcontrolador e verificar a lógica do código em conjunto com a simulação do nosso circuito virtual e a funcionalidade do mesmo.
* A BB Black conta com um processador AM335x, que integra um ARM Cortex™-A8 com velocidade de 1GHz, 512MB (tipo DDR3) de memória RAM e 4GB de memória flash (8 bits).


## Implementação para um produto real:
Primeiramente, é importante ressaltar que, em uma aplicação presencial em sala de aula, seria usado a plataforma de desenvolvimento BeagleBone Black. Esta plataforma de desenvolvimento de baixo custo, diferente do Arduino Uno Rev3, não possui barreiras de uso exclusivo educacionais e pode ser utilizada comercialmente (simulando um projeto de engenharia embarcada real). Como o presente projeto se encontra em tempos de aulas EAD, simplificamos seu desenvolvimento em uma plataforma virtual de desenvolvimento, que apenas contava com o microcontrolador Arduino Rev3. Portanto, o projeto levará em conta os parametrôs da simulação em Tinkercad.
