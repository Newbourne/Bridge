#include <QCoreApplication>
#include "extensions/motordriver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const string com = "COM3";
    MotorDriver driver(com);

    string input = "";

    while(input != "exit")
    {
        cout << "Enter Arduino Command:" << endl;
        cout << ">>";
        cin >> input;
        cout << "Command: " << input << endl;
        driver.Send(input);
    }

    return a.exit();
}
