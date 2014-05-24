#ifndef SERIALBASE_H
#define SERIALBASE_H

#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>
#include <boost/system/error_code.hpp>
#include <boost/system/system_error.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <string>

using namespace std;

class SerialBase
{
private:
    static const int baud_rate = 9600;
    string port;
    boost::asio::io_service io;
    boost::asio::serial_port serial;
public:
    SerialBase::SerialBase(const string port) : io(), serial(io, port)
    {
        serial.set_option(boost::asio::serial_port_base::baud_rate(baud_rate));
        boost::thread t(boost::bind(&boost::asio::io_service::run, &io));
    }

    SerialBase::~SerialBase()
    {

    }

    void SerialBase::Send(string sendText)
    {
        boost::asio::write(serial, boost::asio::buffer(sendText.c_str(), sendText.size()));
    }

    void SerialBase::Read()
    {

    }
};

#endif SERIALBASE_H
