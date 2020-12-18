# Projeto de Controle de uma Fermentação de Cerveja

Projeto desenvolvido para a disciplina de Sistemas Embarcados (SAA0356) pelos alunos do curso de Engenharia Mecatrônica. A intenção do projeto é implementar um sistema de controle de fermentação de cerveja em uma caldeira industrial. 

### Alunos:

* Edson Jose Brumatti Junior - 9880169
* Gabriel Guarino - 9866419
* Ícaro Almeida Aguiar - 9805042
* Jorge Luis Faneco Paschoa - 9805824
* Matheus Borghi Ricardo de Oliveira - 8910517

### Instituição:
* Escola de Engenharia de São Carlos - USP

### Docente Responsável:
* Glauco Caurin

## Descrição do Projeto:
* Será implementado o código de um sistema controlador do processo de fermentação de cerveja. Conforme visto na figura abaixo:
![Circuito](https://github.com/icaroaguir/Projeto_SistEmbarcados/blob/main/circuito.png)
* O circuito consta dos seguites elementos:
1. Sensor de temperatura;
2. Potenciometro para controle da temperatura;
3. Servo motor, representando as pás giratórias;
4. Motor, representando a inclinação da tampa da caldeira;
5. Buzzer para sinalizar quando o processo acabar;
6. Display para repassar informações do processo;
7. Microcontrolador.


## Requisitos do Sistema:
* Para esse projeto foi utilizada a plataforma de prototipagem eletrônica, Tinkercad, onde era possível utilizar nosso circuito em conjunto com o microcontrolador e verificar a lógica do código em conjunto com a funcionalidade do mesmo.
* A BB Black conta com um processador AM335x, que integra um ARM Cortex™-A8 com velocidade de 1GHz, 512MB (tipo DDR3) de memória RAM e 4GB de memória flash (8 bits).


## Implementação para um produto real:
Primeiramente, é importante ressaltar que em uma aplicação presencial em sala de aula, seria usado a plataforma de desenvolvimento BeagleBone Black. Esta plataforma de desenvolvimento de baixo custo, diferente do Arduino Uno Rev3, não possui barreiras de uso exclusivo educacionais e pode ser utilizada comercialmente (simulando um projeto de engenharia embarcada real). Como o presente projeto se encontra em tempos de aulas EAD, simplificamos seu desenvolvimento em uma plataforma virtual de desenvolvimento, que apenas contava com o microcontrolador Arduino Rev3. Portanto, o projeto levará em conta os parametrôs da simulação em Tinkercad.
