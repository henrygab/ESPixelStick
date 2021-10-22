#pragma once
#ifdef SPI_OUTPUT
/*
* OutputWS2801Spi.h - WS2801 driver code for ESPixelStick Spi Channel
*
* Project: ESPixelStick - An ESP8266 / ESP32 and E1.31 based pixel driver
* Copyright (c) 2015 Shelby Merrick
* http://www.forkineye.com
*
*  This program is provided free for you to use in any way that you wish,
*  subject to the laws and regulations where you are using it.  Due diligence
*  is strongly suggested before using this code.  Please give credit where due.
*
*  The Author makes no warranty of any kind, express or implied, with regard
*  to this program or the documentation contained in this document.  The
*  Author shall not be liable in any event for incidental or consequential
*  damages in connection with, or arising out of, the furnishing, performance
*  or use of these programs.
*
*   This is a derived class that converts data in the output buffer into
*   pixel intensities and then transmits them through the configured serial
*   interface.
*
*/

#include "OutputWS2801.hpp"
#include "OutputSpi.hpp"

class c_OutputWS2801Spi : public c_OutputWS2801
{
public:
    // These functions are inherited from c_OutputCommon
    c_OutputWS2801Spi (c_OutputMgr::e_OutputChannelIds OutputChannelId,
                      gpio_num_t outputGpio,
                      uart_port_t uart,
                      c_OutputMgr::e_OutputType outputType);
    virtual ~c_OutputWS2801Spi ();

    // functions to be provided by the derived class
    void    Begin ();
    void    GetConfig (ArduinoJson::JsonObject& jsonConfig);
    bool    SetConfig (ArduinoJson::JsonObject& jsonConfig);  ///< Set a new config in the driver
    void    Render ();                                        ///< Call from loop(),  renders output data
    void    PauseOutput () {};

private:

    c_OutputSpi Spi;

}; // c_OutputWS2801Spi

#endif // def SPI_OUTPUT
