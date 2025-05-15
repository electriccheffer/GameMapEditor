#include <vector>
#ifndef BUFFER_HPP
#define BUFFER_HPP
class InputBuffer{

	public:
		InputBuffer();
	        InputBuffer(std::vector<int>& rawBuffer); 
		std::vector<int>& getBuffer(); 
		void setBuffer(std::vector<int>& newBuffer); 

	protected: 
		std::vector<int> rawBuffer; 

};
#endif
