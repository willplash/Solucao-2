#include <iostream>
#include <string>
using namespace std;

/* Backus Naur:

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
*/

class Binario {

public:
	Binario() {}
	char d0000() { return '0'; }
	char d0001() { return '1'; }
	char d0010() { return '2'; }
	char d0011() { return '3'; }
	char d0100() { return '4'; }
	char d0101() { return '5'; }
	char d0110() { return '6'; }
	char d0111() { return '7'; }
	char d1000() { return '8'; }
	char d1001() { return '9'; }
	char d1010() { return 'a'; }
	char d1011() { return 'b'; }
	char d1100() { return 'c'; }
	char d1101() { return 'd'; }
	char d1110() { return 'e'; }
	char d1111() { return 'f'; }

	friend class Expression;
};

class Context {

public:
	char* entrada;
	string saida;

	Context(string entrada) {
		if (entrada.size() == 0 || entrada.size() > 6) {
			this->entrada = NULL;
		}
		else {
			bool validade = true;
			char temp[7];
			temp[6] = '\0';
			strcpy(temp, entrada.c_str());
			for (int i = 0; i < entrada.size(); i++) {
				if (temp[i] == 'A') temp[i] = 'a';
				if (temp[i] == 'B') temp[i] = 'b';
				if (temp[i] == 'C') temp[i] = 'c';
				if (temp[i] == 'D') temp[i] = 'd';
				if (temp[i] == 'E') temp[i] = 'e';
				if (temp[i] == 'F') temp[i] = 'f';
			}
			for (int i = 0; i < entrada.size(); i++) {
				if (temp[i] != '0' && temp[i] != '1' && temp[i] != '2' && temp[i] != '3' && temp[i] != '4'
					&& temp[i] != '5' && temp[i] != '6' && temp[i] != '7' && temp[i] != '8' && temp[i] != '9'
					&& temp[i] != 'a' && temp[i] != 'b' && temp[i] != 'c' && temp[i] != 'd' && temp[i] != 'e' && temp[i] != 'f') {
					validade = false;
				}
			}
			if (validade == false) this->entrada = NULL;
			if (validade == true) {
				char aux[7];
				aux[6] = '\0';
				for (int i = 0; i < 6; i++) aux[i] = '0';
				int j = entrada.size() - 1;
				int k = 5;
				while (j >= 0 && k >= 0) {
					aux[k] = temp[j];
					j--;
					k--;
				}
				this->entrada = new char[7];
				for (int i = 0; i < 7; i++) this->entrada[i] = aux[i];
			}
		}
	}

	friend class Expression;
};

class Expression {

public:

	Binario binario;

	Expression() {
	}

	void interpretar(Context &contexto) {
		if (contexto.entrada == NULL) contexto.saida = "O codigo informado nao e um Hexadecimal.";
		else {
			string temp[6];
			for (int indice = 0; indice < 6; indice++) {
				if (contexto.entrada[indice] == binario.d0000()) temp[indice] = "0000";
				if (contexto.entrada[indice] == binario.d0001()) temp[indice] = "0001";
				if (contexto.entrada[indice] == binario.d0010()) temp[indice] = "0010";
				if (contexto.entrada[indice] == binario.d0011()) temp[indice] = "0011";
				if (contexto.entrada[indice] == binario.d0100()) temp[indice] = "0100";
				if (contexto.entrada[indice] == binario.d0101()) temp[indice] = "0101";
				if (contexto.entrada[indice] == binario.d0110()) temp[indice] = "0110";
				if (contexto.entrada[indice] == binario.d0111()) temp[indice] = "0111";
				if (contexto.entrada[indice] == binario.d1000()) temp[indice] = "1000";
				if (contexto.entrada[indice] == binario.d1001()) temp[indice] = "1001";
				if (contexto.entrada[indice] == binario.d1010()) temp[indice] = "1010";
				if (contexto.entrada[indice] == binario.d1011()) temp[indice] = "1011";
				if (contexto.entrada[indice] == binario.d1100()) temp[indice] = "1100";
				if (contexto.entrada[indice] == binario.d1101()) temp[indice] = "1101";
				if (contexto.entrada[indice] == binario.d1110()) temp[indice] = "1110";
				if (contexto.entrada[indice] == binario.d1111()) temp[indice] = "1111";
			}
			contexto.saida = temp[0] + " " + temp[1] + " " + temp[2] + " " + temp[3] + " " + temp[4] + " " + temp[5];
		}
	}
};

int main() {

	Expression Interpretador;

	cout << "\nConversao de hexadecimais para binarios.\n\n";

	string entrada;
	do {
		cout << "\nInsira o codigo Hexadecimal ou sair para finalizar: #";
		cin >> entrada;
		if (entrada != "sair") {
			Context contexto(entrada);
			Interpretador.interpretar(contexto);
			cout << "\nInterpretacao: " << contexto.saida << "\n";
		}
	} while (entrada != "sair");

	cout << "\n";
}
