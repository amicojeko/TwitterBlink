// Copyright (c) 2015 Stefano Guglielmetti - jeko@jeko.net
// https://github.com/amicojeko
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.


#include <Bridge.h>
#include <Process.h>

// LED pin. Either keep this or replace it with
// your actual hardware configuration (i.e. servo)
const int  led = 13;

// configure this with your command path
// the go.py file must be in the same directory
// of the streaming.py file
const String SCRIPT_DIR = "/root/python/TwitterBlink/";

const String python_command = "/usr/bin/python " + SCRIPT_DIR + "streaming.py";
const String kill_command = SCRIPT_DIR + "kill_processes.sh";

Process p;

char go_buffer[2];
// still not sure if I should have used a bool instead
// btw with int I can handle more states
int  go = 0;

void setup() {
  // hardware initialization: Either keep this or replace it with
  // your actual hardware configuration (i.e. servo)

  pinMode(led, OUTPUT);

  // Initialize the Bridge Library
  Bridge.begin();

  // Kill all running python scripts if any
  p.runShellCommand(kill_command);

  // Start the python script
  p.runShellCommandAsynchronously(python_command);
}

void loop() {
  // read the "go" Bridge var and copies it into the go_buffer variable
  Bridge.get("go", go_buffer, 2);

  // convert the bugger into an int variable (should I have used bool instead?)
  go = atoi(go_buffer);

  if (go == 1){
    doSomething();
  } else {
    delay(50);
  }

}

void doSomething(){
  // replace this code with the code that does your stuff
  // i.e. move a servo or set your neighbor's garden on fire

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
