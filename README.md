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
* Glauco Caurin

## Descrição do Projeto:
* Será implementado o código de um sistema controlador do processo de fermentação de cerveja. Conforme visto na figura abaixo:
![Circuito](https://github.com/icaroaguir/Projeto_SistEmbarcados/blob/main/circuito.png)
* No circuito constam os seguites elementos e suas funções:
1. Sensor de temperatura -> Aferir a temperatura da mistura líquida.
2. Potenciometro -> Promove a interface para regular a temperatura da mistura líquida.
3. Servo motor -> Representa as pás giratórias, que misturam os ingredientes para posterior fermentação.
4. Motor DC -> Utilizado para regular a inclinação da tampa da caldeira.
5. Buzzer -> Interface sonora que sinaliza o término do processo de fermentação.
6. Display LCD -> Interface visual para reportar informações do processo (temperatura, tempo de fermentação) e alterá-las.
7. Microcontrolador -> Plataforma de desenvolvimento que oferece controle e manipulação a partir da comunicação entre sensores, atuadores e sua programação. 

## Subsistemas
Temperatura: O subsistema de temperatura conta com um Sensor de Temperatura (TMP), um Microservo de Posição e um Potenciometro. 


## Requisitos do Sistema:
* Para esse projeto foi utilizada a plataforma de prototipagem eletrônica, Tinkercad, onde era possível utilizar nosso circuito em conjunto com o microcontrolador e verificar a lógica do código em conjunto com a simulação do nosso circuito virtual e a funcionalidade do mesmo.
* A BB Black conta com um processador AM335x, que integra um ARM Cortex™-A8 com velocidade de 1GHz, 512MB (tipo DDR3) de memória RAM e 4GB de memória flash (8 bits).


## Implementação para um produto real:
Primeiramente, é importante ressaltar que, em uma aplicação presencial em sala de aula, seria usado a plataforma de desenvolvimento BeagleBone Black. Esta plataforma de desenvolvimento de baixo custo, diferente do Arduino Uno Rev3, não possui barreiras de uso exclusivo educacionais e pode ser utilizada comercialmente (simulando um projeto de engenharia embarcada real). Como o presente projeto se encontra em tempos de aulas EAD, simplificamos seu desenvolvimento em uma plataforma virtual de desenvolvimento, que apenas contava com o microcontrolador Arduino Rev3. Portanto, o projeto levará em conta os parametrôs da simulação em Tinkercad.
