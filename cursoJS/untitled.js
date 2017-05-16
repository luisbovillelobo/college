var showMeTheText = function (text) {

  var textoModificado = "---" + text + "----";

  function modificaTexto() {
      return "<" + textoModificado + ">";
  }

  return modificaTexto;
}

showMeTheText("Esto es un texto de prueba");