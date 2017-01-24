# Scanner construction

Modifiquen el programa del escáner visto en clase, de tal manera que sea capaz de reconocer comas (,) como separadores e identificadores de variables.

Los identificadores de variables empiezan con una letra minúscula o un guion bajo, seguido por cero o más letras minúsculas, guiones bajos y/o dígitos.
Ejemplos: 

``` hola, x, _, _y3, tasa_interes, a3_b45 ```

###¿Cómo?

- Reconstruyan el autómata finito descrito por la matriz de transiciones del escáner.
- Agréguenle los estados y transiciones necesarios para reconocer los nuevos elementos léxicos.
- Modifique la matriz de transiciones para manejar los nuevos estados (renglones de la matriz) y las nuevas transiciones (columnas de la matriz).
- Modifiquen la función de filtro para que reconozca los nuevos tipos de caracteres.
- Modifiquen el programa principal para que maneje el caso de los nuevos elementos.
- Verifiquen que el programa trabaje correctamente.
- Suban el autómata modificado y el programa a Blackboard (uno solo de los integrantes).
