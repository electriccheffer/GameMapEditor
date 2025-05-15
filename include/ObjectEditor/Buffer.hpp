#include <vector>
#ifndef BUFFER_HPP
#define BUFFER_HPP
class InputBuffer{

	public:
		InputBuffer();
	        InputBuffer(std::vector<int>& rawBuffer); 
		std::vector<int>& getBuffer(); 

	protected: 
		std::vector<int> rawBuffer; 

};
#endif
