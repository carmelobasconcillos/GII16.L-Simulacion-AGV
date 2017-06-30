#ifndef COMANDOS_H_
#define COMANDOS_H_
#include <stdio.h>
#include "std_msgs/String.h"
#include "mirobot.h"
std::vector<std::string> split(const std::string &c, char d);
namespace gazebo {

	class Comandos {
		public:
			static bool procesar(std::string &comando, MiRobot *);
	};

}

#endif