import processing.serial.*;


int[] values;

int threshhold = 25;

Serial arduinoPort;
void setup(){
  values = new int[5];
  String portName = Serial.list()[0]; //change the 0 to a 1 or 2 etc. to match your port
  arduinoPort = new Serial(this, portName, 9600);
  //arduinoPort.bufferUntil('\n');
  textSize(72);
  
}

boolean newInput = false;

void draw(){
  background(0);
  fill(255);
  if (arduinoPort.available() != 0){
    /*int temp = arduinoPort.read();  
    if (temp == (int)('\n')){
      newInput = true;
    }*/
    
    /*
    String data = arduinoPort.readStringUntil('\n');
     println(data);
    if (data.equals("A\n")){
      values[0] = Integer.parseInt(arduinoPort.readStringUntil('\n'));
    }else if (data == "B"){
      values[1] = Integer.parseInt(arduinoPort.readStringUntil('\n'));
    }else if (data == "C"){
      values[2] = Integer.parseInt(arduinoPort.readStringUntil('\n'));
    }else if (data == "D"){
      values[3] = Integer.parseInt(arduinoPort.readStringUntil('\n'));
    }else if (data == "E"){
      values[4] = Integer.parseInt(arduinoPort.readStringUntil('\n'));
    }*/
    int error = 0;
    int temp = 0;
    println("===================================");
    switch(arduinoPort.read()){
      case 1:
        temp = arduinoPort.read();
        temp =  temp <= threshhold ? 0: temp;
        values[0] = temp;
        break;
      case 2:
        temp = arduinoPort.read();
        temp = temp <= threshhold ? 0: temp;
        values[1] = temp;
        break;
      case 3:
        temp = arduinoPort.read();
        temp =  temp <= threshhold ? 0: temp;
        values[2] = temp;
        break;
      case 4:
        temp = arduinoPort.read();
        temp = temp <= threshhold ? 0: temp;
        values[3] = temp;
        break;
      case 5:
        temp = arduinoPort.read();
        temp = temp <= threshhold ? 0: temp;
        values[4] = temp;
        break;
       default:
         error = temp;
         
    }
    println("ERROR: "+error);
    for (int i =0; i < 5; i++){
       println(i+": "+values[i]); 
    }
   // int data = arduinoPort.read();  
    //text(data+"", width/2, height/2);
    
  }
  
}