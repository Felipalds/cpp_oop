# Orientação a objetos
## Origem
- anos 60 e 70
- hardware se desenvolvendo muito rápido -
  - reutilização
  - padronização
- software precisava acompanhar
  - nasce CC
  - toda empresa precisava criar tudo do zero
  - criação de bibliotecas

## Programação estruturada
- série de ações realizadas sobre um conjunto de dados
- sequência, decisão, repetição -> funções!!
- Divide and Conquer (divisão em procedimentos mais simples)
- sem "Go To", código espaghetti

## Programação Orientada a Objetos
- não é centrada no processo, mas sim nos dados
- modela objetos reais em software
- tipos abstratos de dados
  - não são apenas dados, mas sim funções e procedimentos são incluidos na definição do tipo, protegendo os dados contra acessos indevidos
  - a definição de tipos abstratos é **classe**

# Classe - abstrato
- struct que pode conter procedimentos
- **atributos** := variáveis definidas na classe
- **métodos** := procedimentos definidas na classe
- molde para objetos

# Objetos - concreto
- **instância** de uma classe

## Mensagem
- solicitações enviadas à um objeto, para que este execute um de seus métodos
- ao receber uma mensagem, o objeto assume o controle do programa

## Protocolo
- conjunto de mensagens de um objeto (o que você pode ou não pedir)

## Herança
- capacidade de se definir novas classes com base em classes já existentes
1. simples - única classe
2. múltipla - múltiplas classes

## Polimorfismo
- alterar métodos herdados da classe-mãe
- funciona só na sub-classe, outras classes herdadas da classe-mãe não sofrerão alterações
- usa o mesmo nome, mas métodos são diferentes

## Encapsulamento
- confinar em um objeto todos os dados e funções que são necessários para seu funionamento, reduzindo ao máximo (de preferência tudo), as interferências externas.