/**
 * @file error.hpp
 * @brief Contains the error printing 
 *        and handling functions declarations
 * @author Colby Japp
 * @version 1.0.0
 * @date 2017-09-06
 * @edited 2017-09-06
 */

#ifndef ERROR_HPP
#define ERROR_HPP 

#include "render.hpp"
#include "window.hpp"

#include<string>
namespace Hearth
{
  namespace Error
  {
    void initLog();
    void fatalError(const std::string msg);
    void printMessage(const std::string msg);
  };
}
#endif /* ERROR_HPP */
