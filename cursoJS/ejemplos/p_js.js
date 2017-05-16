alert ("Ejemplo programa js");
//declaracion de variables locales
var radio1 = 5.5, radio2 = 3.5, pi = 3.14, superficie1, superficie2, diferencia;
//calculos

superficie1 = pi * radio1 * radio1;
superficie2 = pi * radio2 * radio2;
diferencia = superficie1 - superficie2;

//mostrar resultados

document.write("superficie1: " + superficie1 );
document.write("superficie2: " + superficie2 );
alert("diferencia: " + diferencia);