#ifndef POSITION_HPP
#define POSITION_HPP

class Position{

	public:
		Position(); 
		unsigned int getX()const;
		unsigned int getY()const; 
		void setX(unsigned int newX);
		void setY(unsigned int newY);
		bool operator==(const Position& otherPosition); 
		bool operator!=(const Position& otherPosition); 
	protected:
		unsigned int xPosition; 
		unsigned int yPosition; 



}; 
#endif
