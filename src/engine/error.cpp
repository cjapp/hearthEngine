/**
 * @file error.cpp
 * @brief Contains the error printing 
 *        and handling function definitions
 * @author Colby Japp
 * @version 1.0.0
 * @date 2017-09-06
 * @edited 2017-09-06
 */

#include "error.hpp"
#include "application.hpp"

#include<iostream>
#include<stdlib.h>

namespace Hearth
{

  void Error::initLog()
  {
    //TODO: This will be the function that initializes a log file for
    //      printing errors too( if the file exists for this particular
    //      create a new one
  }


  void Error::fatalError(const std::string msg)
  {

    std::cout << msg << std::endl;

    //Get a confirmation from user before quiting
    std::cout << "Enter a key to quit...";
    int input;
    std::cin >> input;

    Application::unInitialize();

    exit(3);

  }

  void Error::printMessage(const std::string msg)
  {
    std::cout << msg << std::endl;
  }

}//end Hearth
