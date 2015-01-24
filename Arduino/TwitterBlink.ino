/* Stefano Guglielmetti 2015 - jeko@jeko.net */


#include <Bridge.h>
#include <Process.h>

char go_buffer[2];
int  led = 13;
int  go = 0;

// configure this with your command path
// the go.py file must be in the same directory
// of the streaming.py file
String command = "/usr/bin/python /root/python/TwitterBlink/streaming.py";

Process p;

void setup() {
  pinMode(led, OUTPUT);
  Bridge.begin();
  p.runShellCommandAsynchronously(command);
}

void loop() {
  Bridge.get("go", go_buffer, 2);
  go = atoi(go_buffer);
  
  if (go == 1){
    doSomething();
  } else {
    delay(50);
  }
      
}

void doSomething(){
  // replace this code with the code that moves the servo
  
  // blinks the led a dozen times
  for (int i=0; i<12; i++){
    digitalWrite(led, 1);
    delay(100);
    digitalWrite(led, 0);
    delay(100);
  }
  
  // and resets the go variable to 0
  // you want to keep this line
  Bridge.put("go", String(0));
}
