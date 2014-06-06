/*	Parser library designed for Arduino commands.	*/
class Parser
{
private:
	char* request;
	Command result;
	void BuildInterface();
	void BuildPin();
	void BuildCharge();
	int ConvertToInt(char c);

public:
	Parser();
	~Parser();
	Command BuildCommand(char input[7]);
};

Parser::Parser()
{

}

Parser::~Parser()
{

}

Command Parser::BuildCommand(char input[7])
{
	request = input;
	BuildInterface();
	BuildPin();
	BuildCharge();
	return result;
}

void Parser::BuildInterface()
{
	if (request[0] == 'A' && request[1] == 'I')
	{
		result.Interface = ANALOG_INPUT;
	}
	else if (request[0] == 'A' && request[1] == 'O')
	{
		result.Interface = ANALOG_OUTPUT;
	}
	else if (request[0] == 'D' && request[1] == 'I')
	{
		result.Interface = DIGITAL_INPUT;
	}
	else if (request[0] == 'D' && request[1] == 'O')
	{
		result.Interface = DIGITAL_OUTPUT;
	}
}

void Parser::BuildPin()
{
	result.Pin = ConvertToInt(request[3]) + ConvertToInt(request[2]) * 10;
}

void Parser::BuildCharge()
{
	if (result.Interface == DIGITAL_INPUT || result.Interface == DIGITAL_OUTPUT)
	{
		result.Charge = ConvertToInt(request[7]);
	}
	else
	{
		result.Charge = (ConvertToInt(request[4]) * 100) + (ConvertToInt(request[5]) * 10) + ConvertToInt(request[6]);
	}
}

int Parser::ConvertToInt(char x)
{
	return (x - 48);
}