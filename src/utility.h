#ifndef UTILITY_H
#define UTILITY_H

#include "ANSI_include.h"


uint32_t swap32(unsigned int value);
uint16_t swap16(unsigned short value);

char* read_CStr( ifstream& inFile, unsigned int length );
uint32_t read_u32( ifstream& inFile );
uint16_t read_u16( ifstream& inFile );
uint8_t read_u8( ifstream& inFile );
float read_float(ifstream& inFile );

void write_u32( ofstream& outFile, uint32_t value );
void write_u16( ofstream& outFile, uint16_t value );
void write_u8( ofstream& outFile, uint8_t value );
void write_float(ofstream& outFile, float value );

void skip( ifstream& inFile, std::streampos offset );
void skip( ofstream& outFile, std::streampos offset );
void align( ifstream& inFile, std::streampos value );
void align( ofstream& outFile, std::streampos value );

string getUserInput( string prompt );



#endif	// UTILITY_H
