#include "Arduino.h"
#include "Parts.h"
using namespace std;

class Config
{
private:
	Command *commands[21];
	void CommandAssignments();
	void SetupPinModes();

public:
	Config();
	~Config();
};

Config::Config()
{
	CommandAssignments();
	SetupPinModes();
}

Config::~Config()
{

}

void Config::CommandAssignments()
{
	// Used for assignments
	commands[0] = new Command(ANALOG_INPUT, 0);
	commands[1] = new Command(ANALOG_INPUT, 1);
	commands[2] = new Command(ANALOG_INPUT, 2);
	commands[3] = new Command(ANALOG_INPUT, 3);
	commands[4] = new Command(ANALOG_INPUT, 4);
	commands[5] = new Command(ANALOG_INPUT, 5);

	commands[6] = new Command(ANALOG_OUTPUT, 3);
	commands[7] = new Command(ANALOG_OUTPUT, 5);
	commands[8] = new Command(ANALOG_OUTPUT, 6);
	commands[9] = new Command(ANALOG_OUTPUT, 9);
	commands[10] = new Command(ANALOG_OUTPUT, 10);
	commands[11] = new Command(ANALOG_OUTPUT, 11);

	commands[12] = new Command(DIGITAL_INPUT, 1);
	commands[13] = new Command(DIGITAL_INPUT, 2);
	commands[14] = new Command(DIGITAL_INPUT, 4);
	commands[15] = new Command(DIGITAL_INPUT, 7);
	commands[16] = new Command(DIGITAL_INPUT, 8);
	commands[17] = new Command(DIGITAL_OUTPUT, 12);
	commands[18] = new Command(DIGITAL_OUTPUT, 13);
	commands[19] = new Command(DIGITAL_OUTPUT, 14);
	commands[20] = new Command(DIGITAL_OUTPUT, 15);
}

void Config::SetupPinModes()
{
	for (int i = 0; i < 21; i++)
	{
		Command *command = commands[i];

		switch (command->Interface)
		{
		case ANALOG_OUTPUT:
			pinMode(command->Pin, OUTPUT);
			break;
		case ANALOG_INPUT:
			pinMode(command->Pin, INPUT);
			break;
		case DIGITAL_OUTPUT:
			pinMode(command->Pin, OUTPUT);
			break;
		case DIGITAL_INPUT:
			pinMode(command->Pin, INPUT);
			break;
		default:
			break;
		}
	}
}