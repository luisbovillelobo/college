alert ('Ejemplo programa js');

document.getElementById('parrafo'); document.getElementsByTagName('form'); document.getElementsByTagName('input');

mivar = 8; //sin declarar la variable, la inicializamos dandole valor
alert(mivar);

var mivardeclarada; //declarando la variable mivardeclarada
mivardeclarada = "declarada"; //inicializando la variable dandole valor
alert(mivardeclarada);

if (5 == '5') alert('Si');

entrada = prompt('Introduce algo:');

alert(entrada);

function lol(){
	console.log('Hola soy console.log');
}

lol();

function creaParrafos(){
	var para = document.createElement('P');
	var t = document.createTextNode('Esto es un parrafo');
	para.appendChild(t);
	document.getElementById('miDiv').appendChild(para);
}

function creaDiv(){
	var btn = document.createElement('DIV');
	document.body.appendChild(btn);
}