class Executor
{
public:
	Executor();
	~Executor();
	void Execute(Command command);
};

Executor::Executor()
{

}

Executor::~Executor()
{

}

void Executor::Execute(Command command)
{
	int result = 0;
	switch (command.Interface)
	{
		case ANALOG_OUTPUT:
			analogWrite(command.Pin, command.Charge);
			break;
		case ANALOG_INPUT:
			result = analogRead(command.Pin);
			break;
		case DIGITAL_OUTPUT:
			if (command.Charge == 0)
				digitalWrite(command.Pin, LOW);
			else
				digitalWrite(command.Pin, HIGH);
			break;
		case DIGITAL_INPUT:
			result = digitalRead(command.Pin);
			break;
		default:
			break;
	}

	// How to send the input values back to serial.
}