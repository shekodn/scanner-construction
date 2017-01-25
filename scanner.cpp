/* Este programa es un ejemplo de como se puede implementar un analizador de
   lexico. El lenguaje que se reconoce, tiene como elementos a las constantes
   numericas (enteras y reales), los operadores aritmeticos y los parentesis.
   El programa lee de teclado, caracter por caracter, y al momento de reconocer un
   elemento, lo identifica con un letrero en pantalla. La ejecucion termina cuando
   el usuario teclea el simbolo '$'.
   Autor: Dr. Santiago Conant, Agosto 2012
*/

// #include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

// Matriz de transiciones
//               dig   op   (    )  raro  esp   .    $    ,    _  letras
int MT[7][11] = {{  1, 102, 105, 106,   4,   0,   4, 107, 108, 5 ,     5 },   // edo 0 - edo inicial
								{  1, 100, 100, 100, 100, 100,   2, 100, 100, 100,    100  },   // edo 1 - digitos enteros
								{  3, 200, 200, 200,   4, 200,   4, 200, 200, 100,    100  },   // edo 2 - primer decimal flotante
                {  3, 101, 101, 101, 101, 101,   4, 101, 101, 100,    100 },   // edo 3 - decimales restantes flotante
								{200, 200, 200, 200,   4, 200,   4, 200, 200, 200,    200 }, // edo 4 - edo de error
								{  5, 200, 200, 200, 200, 109, 200, 200, 101, 5,      5 },   // edo 5 - letras, digitos, _
								{  5, 200, 200, 200, 101, 200, 200, 107, 200, 5,      5  }};   // edo 6 - decimales restantes flotante

int filtro (char c)
{
	switch (c)
	{
	case 'a':
	case 'b':
	case 'c':
	case 'd': return 10;
	case '_': return 9;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9': return 0; // decimales
	case '+':
	case '-':
	case '*':
	case '/': return 1; // operadores
	case '(': return 2; // delimitador (
	case ')': return 3; // delimitador )
	case ',': return 8; // delimitador ,
	case ' ':
	case  10:
	case  13: return 5; // blancos
	case '.': return 6; // punto
	case '$': return 7; // fin de entrada
	default:  return 4; // caracter raro (ilegal)
	}
}

int main(void)
{
	char c;
	string lexema = "";
	int edo = 0;
	while (true)
	{
		do {
			c = getchar();
			edo = MT[edo][filtro(c)];
			if (edo < 100 && edo != 0) lexema += c;
		} while (edo < 100);

		switch (edo) // token reconocido, error o fin de entrada
		{
		case 100: cout << "Entero " << lexema << endl;
			ungetc(c, stdin); // regresa el delimitador
			break;
		case 109: cout << "Variable " << lexema << endl;
			break;
		case 101: cout << "Flotante " << lexema << endl;
			ungetc(c, stdin); // regresa el delimitador
			break;
		case 102: cout << "Operador " << c << endl;
			break;
		case 105: cout << "Delimitador (\n";
			break;
		case 106: cout << "Delimitador )\n";
			break;
		case 107: return 0; // termina ejecuci�n

		case 108: cout << "Delimitador ,\n";
			break;
		case 200: cout << "ERROR! palabra ilegal " << lexema << endl;
			ungetc(c, stdin); // regresa caracter v�lido
			break;
		}

        lexema = "";
		edo = 0; // regresa al inicio
	}
}
