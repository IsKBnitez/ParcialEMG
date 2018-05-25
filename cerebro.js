var SerialPort = require('serialport');
var port = new SerialPort('COM7', {
  baudRate: 9600
});

const brain = require('brain.js');
var  Neurona = new brain.NeuralNetwork();

   Neurona.train([
  {input:{f:0},output:{Devil:1}},
  {input:{f:0.09},output:{Devil:1}},
  {input:{f:0.19},output:{Medio:1}},
  {input:{f:0.39},output:{Medio:1}},
  {input:{f:0.48},output:{Fuerte:1}},
  {input:{f:1},output:{Fuerte:1}}

  
  
  
  ]);

  //Neurona.train(datos,{log: true});
  

var Sensor1 = 0;
var Sensor1Tmp = 0;
var Estado = 0;
var Sensor2 = 0;
var Sensor2Tmp = 0;

port.on('data', function(data) {
  console.log("Valor: " + Sensor1 );
  for (var i = 0; i < data.length; i++) {
    switch (Estado) {
      case 0:
        if (data[i] == 97) {
          Estado = 1;
          Sensor1Tmp = 0;
        } else if (data[i] == 100) {
          Estado = 2;
          Sensor2Tmp = 0;
        }
        break;
      case 1:
        if (data[i] == 99) {
          Sensor1 = Sensor1Tmp;
          Estado = 0;
          //console.log("El Valor es:" + Sensor1);
        } else {
          Sensor1Tmp = Sensor1Tmp * 10 + data[i];
        }
        break;
      case 2:
        if (data[i] == 101) {
          Sensor2 = Sensor2Tmp;
          Estado = 0;
          //console.log("El Valor es:" + Sensor1);
        } else {
          Sensor2Tmp = Sensor2Tmp * 10 + data[i];
        }
        break;
    }
  }
  var salida = Neurona.run({f:Sensor1/1024});
  //var fuerza = brain.likely(Sensor1/1024,Neurona);
  //console.log("Nivel de fuerza:"+salida.Fuerte);

  if(salida.Devil > 0.5){
    console.log("Fuerza es devil");
  }
  else if(salida.Medio > 0.5){
    console.log("Fuerza Media");
  }
  else if(salida.Fuerte > 0.8){
    console.log("Ferza Fuerte");
  }
  else
  {
    console.log("Enclenque");
  }

  
});







  
