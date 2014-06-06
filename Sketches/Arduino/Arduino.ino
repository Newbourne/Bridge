#include "Config.h"
#include "Parser.h"
#include "Executor.h"

char input[7];
int input_counter;
Config* configuration;
Parser* parser;
Executor* executor;

Command command;

void setup()
{
  configuration = new Config();
  parser = new Parser();
  executor = new Executor();
  Serial.begin(9600);
  input_counter = 0;
}

void loop()
{
  while(Serial.available())
  {
      char c = Serial.read();
      input[input_counter++] = c;
  }
  
  if(input_counter > 0 && input_counter % 7 == 0)
  {
    command = parser->BuildCommand(input);
    command.Print();
    
    executor->Execute(command);
    input_counter = 0;
  }
}
