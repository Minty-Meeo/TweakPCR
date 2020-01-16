#include "ansi_include.h"


//		BYTE SWAPPING FUNCTIONS / DEFINES

#define _BSWAP_16(v) (((v & 0xff00) >> 8) | \
                      ((v & 0x00ff) << 8))

#define _BSWAP_32(v) (((v & 0xff000000) >> 24) | \
                      ((v & 0x00ff0000) >>  8) | \
                      ((v & 0x0000ff00) <<  8) | \
                      ((v & 0x000000ff) << 24) )

unsigned int swap32(unsigned int value) {
    return _BSWAP_32( value );
}
unsigned short swap16(unsigned short value) {
    return _BSWAP_16( value );
}


//	FILE READING FUNCTIONS
char* read_CStr( ifstream& inFile, unsigned int length ) {
	char temp[length+1] ;
	inFile.read( temp, length );
	return temp;
}

uint32_t read_u32( ifstream& inFile ) {
	uint32_t value;
	
	inFile.read( reinterpret_cast<char*>(&value), 4 );
	return swap32( value );
}
uint16_t read_u16( ifstream& inFile ) {
	uint16_t value;
	
	inFile.read( reinterpret_cast<char*>(&value), 2 );
	return swap16( value );
}
uint8_t read_u8( ifstream& inFile ) {
	uint8_t value;
	
	inFile.read( reinterpret_cast<char*>(&value), 1 );
	return value;
}
float read_float(ifstream& inFile ) {
	unsigned int value;
	
	inFile.read( reinterpret_cast<char*>(&value), 4 );
	value = swap32( value );
	return reinterpret_cast<float&>(value);
}

void write_u32( ofstream& outFile, uint32_t value ) {
	value = swap32( value );
	outFile.write( reinterpret_cast<char*>(&value), 4 );
}
void write_u16( ofstream& outFile, uint16_t value ) {
	value = swap16( value );
	outFile.write( reinterpret_cast<char*>(&value), 2 );
}
void write_u8( ofstream& outFile, uint8_t value ) {
	outFile.write( reinterpret_cast<char*>(&value), 1 );
}

void write_float(ofstream& outFile, float value ) {
	unsigned int value2 = reinterpret_cast<unsigned int&>(value);
	value2 = swap32( value2 );
	outFile.write( reinterpret_cast<char*>(&value2), 4 );
}


void skip( ifstream& inFile, std::streampos offset ) {
	inFile.seekg( offset, std::ios_base::cur );
}
void skip( ofstream& outFile, std::streampos offset ) {
	outFile.seekp( offset, std::ios_base::cur );
}
void align( ifstream& inFile, std::streampos value ) {
	std::streampos offset = value - ( inFile.tellg() % value );
	
	if ( offset == value ) return;
	
	inFile.seekg( offset, std::ios_base::cur );
}
void align( ofstream& outFile, std::streampos value ) {
	std::streampos offset = value - ( outFile.tellp() % value );
	
	if ( offset == value ) return;
	
	outFile.seekp( offset, std::ios_base::cur );
}

string getUserInput( string prompt ) {
	std::cout << prompt;
	string temp;
	std::cin >> temp;
	return temp;
}
