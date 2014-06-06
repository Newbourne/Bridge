enum INTERFACE { ANALOG_OUTPUT, ANALOG_INPUT, DIGITAL_OUTPUT, DIGITAL_INPUT };

class Command
{
public:
	INTERFACE Interface;
	int Pin;
	int Charge;

	Command()
	{
		Pin = 0;
		Charge = 0;
	}

	Command(INTERFACE _interface, int _pin)
	{
		Interface = _interface;
		Pin = _pin;
	}

	~Command()
	{

	}

	void Print()
	{
		Serial.print("Interface: ");
		switch (Interface)
		{
		case 0:
			Serial.print("ANALOG OUTPUT");
			break;
		case 1:
			Serial.print("ANALOG INPUT");
			break;
		case 2:
			Serial.print("DIGITAL OUTPUT");
			break;
		case 3:
			Serial.print("DIGITAL INPUT");
			break;
		}
		Serial.println("");

		Serial.print("Pin: ");
		Serial.print(Pin);
		Serial.println("");

		Serial.print("Charge: ");
		Serial.print(Charge);
		Serial.println("");
	}
};