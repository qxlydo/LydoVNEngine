#include <iostream>
#include <vector>
#include <string>

class Logger{
public:
	Logger();
	template<typename T>
	Logger(T& arg, std::string path);
	Logger(int currentState);
			
};
template<typename T>
Logger::Logger(T& arg, std::string path){
	std::cout<< arg <<" "<< path <<std::endl;	
}
 Logger::Logger(int currentState){
 	std::cout<< currentState<< std::endl;	
 }
 
 

int main(int argc, char *argv[])
{
	int val = 45;
	Logger(val, "value");
	Logger(52);
}