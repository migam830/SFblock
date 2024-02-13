#pragma once

class Shuffler
{
public:
	// Abstract class so pure specifier used
	virtual char getNextPiece() = 0;
	// Initialises shufflers where applicable
	virtual void init() {}
};