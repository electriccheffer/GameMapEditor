#ifndef POSITION_HPP
#define POSITION_HPP

class Position{

	public:
		Position(); 
		unsigned int getX();
		unsigned int getY(); 
		void setX(unsigned int newX);
		void setY(unsigned int newY); 
	protected:
		unsigned int xPosition; 
		unsigned int yPosition; 



}; 
#endif
