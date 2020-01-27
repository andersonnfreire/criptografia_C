# Sistema de Criptografia em C

As mensagens enviadas são sempre em formato de string, ou seja, consistem num
vetor de caracteres. Para simplificação serão usados apenas caracteres em minúsculo,
dígitos e os símbolos ‘,’ (vírgula) e ‘.’ (ponto).

A lei de formação para a criptografia das mensagens é a seguinte:
Pré processamento:
Eliminando a corrupção: toda vez que for encontrada a substring “corrupção” ela
será substituída por “”, ou seja, a “corrupção” é eliminada da string original. Essa
técnica deve ser aplicada a cada uma das substrings da string geral, se a substring
for diferente de “corrupção” ela é apenas copiada.

Ex: “nunca antes na história desse país tanto se combateu a corrupção, mas também
nunca foram encontrados tantos casos de corrupção” => “nunca antes na história desse país tanto se combateu a , mas também nunca foram encontrados tantos casos de ”.

# Parametros

- Implementar as seguintes funções:
  1) lerString que aloca dinamicamente uma string de 5000 caracteres (use uma constante #define TAMANHO 5000) e promove a leitura da mesma pelo teclado, retornando a string informada.
  2) eliminarCorrupcao que recebe a string informada e retorna uma nova string pré-processada.
  3) criptografaDados que recebe a string informada e retorna uma nova string com os dados criptografados.
  4) descriptografaDados que recebe uma string criptografada e recria a mensagem original retornando-a.
  5) recriarCorrupcao que recebe a string pré-processada e recoloca a “corrupção” nos locais originais.

# Built With

Linguagem C.

# Authors

Anderson N. Freire - @andersonnfreire

# License

This project is licensed under the MIT License - see the LICENSE.md file for details.
