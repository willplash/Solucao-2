# Solucao-2
Proposta de implementação do padrão Interpreter (2).

Para a implementação deste padrão de design, foi escolhido o problema de processar um código hexadecimal em seu valor binário equivalente. Um problema relativamente simples, e adequado para a implementação deste padrão de orientação objeto (interpreter), visto que os códigos hexadecimais seguem um padrão de uma linguagem específica, cenário ideal para o Interpreter.

Descrição do problema:

Um código hexadecimal é constituído por seis dígitos, onde cada dígito representa um binário de 4 bits.
Cada binário de 4 bits pode ser um dos valores no intervalo de {0000, ..., 1111}.
Cada binário neste intervalo é representado por um caractere (char) em Hexadecimal.

Backus Naur:

<hexadecimal> ::= {binario}{binario}{binario}{binario}{binario}{binario}
<binario> ::= 0000 | 0001 | 0010 | 0011 | 0100 | 0101 | 0110 | 0111 | 1000 | 1001 | 1010 | 1011 | 1100 | 1101 | 1110 | 1111
<0000> ::= '0'
<0001> ::= '1' 
<0010> ::= '2'
<0011> ::= '3' 
<0100> ::= '4' 
<0101> ::= '5' 
<0110> ::= '6' 
<0111> ::= '7' 
<1000> ::= '8' 
<1001> ::= '9' 
<1010> ::= 'a' (Se A, tratado como a)
<1011> ::= 'b' (Se B, tratado como b)
<1100> ::= 'c' (Se C, tratado como c)
<1101> ::= 'd' (Se D, tratado como d)
<1110> ::= 'e' (Se E, tratado como e)
<1111> ::= 'f' (Se F, tratado como f)

Através da escrita acima, é possível formar um hexadecimal ou um binário. Desta forma, o algoritmo foi dividido em 3 classes:

Class Binario, que assume o papel de cada dígito e seus respectivos valores para a classe interpretadora.
Class Context, que recebe e trata o input, contextualizando em seguida a classe interpretadora.
Class Expression, responsável pela interpretação do problema no contexto (input).

O algoritmo foi desenvolvido na linguagem C++, para o console Win32, na IDE Visual Studio 2017.
