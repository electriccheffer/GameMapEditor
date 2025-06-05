#include <stdexcept>
#include <string>

class InputBufferException : public std::runtime_error{

	public: 
		explicit InputBufferException(const std::string& message)
					:std::runtime_error(message){}

}; 

class PaletteListError : public std::runtime_error{

	public: 
		explicit PaletteListError(const std::string& message)
					:std::runtime_error(message){}
}; 
