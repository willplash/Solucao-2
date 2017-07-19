# Solucao-2
Proposta de implementação do padrão Interpreter (2).

Para a implementação deste padrão de design, foi escolhido o problema de processar um código hexadecimal em seu valor binário equivalente. 
Um problema relativamente simples, e adequado para a implementação deste padrão de orientação objeto (interpreter), visto que os códigos hexadecimais seguem um padrão de uma linguagem específica, cenário ideal para o Interpreter.

Descrição do problema:

Um código hexadecimal é constituído por seis dígitos, onde cada dígito representa um binário de 4 bits.
Cada binário de 4 bits pode ser um dos valores no intervalo de {0000, ..., 1111}.
Cada binário neste intervalo é representado por um caractere (char) em Hexadecimal.

Através das setenças acima, foi possível fazer o formalismo de Backus Naur presente no código, que descreve o problema e as regras para a formação de um hexadecimal ou um binário. Desta forma, o algoritmo foi desmembrado em 3 classes:

Class Binario, que assume o papel de cada dígito e seus respectivos valores para a classe interpretadora.
Class Context, que recebe e trata o input, contextualizando em seguida a classe interpretadora.
Class Expression, responsável pela interpretação do problema no contexto (input).

O algoritmo foi desenvolvido na linguagem C++, para o console Win32, na IDE Visual Studio 2017.
