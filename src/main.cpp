#include "ANSI_include.h"
#include "utility.h"
#include "debug.h"
#include "define.h"

int main( unsigned int argc, char* argv[] ) {
	pcr mainPCR;
	
	ifstream inFile;
	inFile.open( argv[1], std::ios::binary );
	if (!inFile.is_open()) {
		printf("File not found!\n");
		return 0;
	}
	
	/* Read Header */ {
		char temp[5] = {0};
		inFile.read( temp, 4 );
		
		mainPCR.magic		= temp;
		mainPCR.genStart	= read_u16( inFile );
		mainPCR.bool_0		= read_u8( inFile );
	}
	
	/* Read colorData */ {
		
		inFile.seekg( 8 );
		
		if ( mainPCR.bool_0 == false ) {
			mainPCR.col.falseA	= read_float( inFile );
			mainPCR.col.falseB	= read_float( inFile );
		}
		
		mainPCR.col.TEVColor	= read_u8( inFile );		// TEVColor
		mainPCR.col.unkA		= read_u8( inFile );		// unk
		mainPCR.col.isFadeout	= read_u8( inFile );		// isFadeout
		uint8_t keyCount = read_u8( inFile );				// Read Key Count
		
		for ( uint32_t i = 0; i < keyCount; i++ )
			mainPCR.col.key.push_back( read_float( inFile ) );	// Read key
		for ( uint32_t i = 0; i < keyCount; i++ )
			mainPCR.col.valA.push_back( read_u32( inFile ) );	// Read value A
		for ( uint32_t i = 0; i < keyCount; i++ )
			mainPCR.col.valB.push_back( read_u32( inFile ) );	// Read value A
		
	}
	
	/* Read generatorData */ {
		inFile.seekg( mainPCR.genStart );
		mainPCR.gen.inventory = read_u32( inFile );
		
		/* Constants */ {
			mainPCR.gen.pos.x		= read_float( inFile );		// X Position
			mainPCR.gen.pos.y		= read_float( inFile );		// Y Position
			mainPCR.gen.pos.z		= read_float( inFile );		// Z Position
			mainPCR.gen.rot.x		= read_float( inFile );		// X Rotation
			mainPCR.gen.rot.y		= read_float( inFile );		// Y Rotation
			mainPCR.gen.rot.z		= read_float( inFile );		// Z Rotation
			mainPCR.gen.unk.x		= read_float( inFile );		// X Unk
			mainPCR.gen.unk.y		= read_float( inFile );		// Y Unk
			mainPCR.gen.unk.z		= read_float( inFile );		// Z Unk
			mainPCR.gen.spread		= read_float( inFile );		// Spread
		}
		
		/* [000000C0] - Particle Life */ {
			if ( mainPCR.gen.inventory & 0x000000C0 ) {
				uint8_t keyCount = read_u8( inFile );	align( inFile, 4 );			// Read keyCount	
					
				for ( uint8_t i = 0; i < keyCount; i++ )
					mainPCR.gen.x000000C0.key.push_back( read_float( inFile ) );	// Read keys
				for ( uint8_t i = 0; i < keyCount; i++ )
					mainPCR.gen.x000000C0.val.push_back( read_float( inFile ) );	// Read values
			}
			else {
				mainPCR.gen.x000000C0.noKeysValue = read_float( inFile );			// No keys value
			}
			mainPCR.gen.x000000C0.flt_00 = read_float( inFile );	//unkA
			mainPCR.gen.x000000C0.flt_01 = read_float( inFile );	//unkB
		}
		
		/* [00000300] */ {
			if ( mainPCR.gen.inventory & 0x00000300 ) {
				uint8_t keyCount = read_u8( inFile );	align( inFile, 4 );			// Read keyCount	
					
				for ( uint8_t i = 0; i < keyCount; i++ )
					mainPCR.gen.x00000300.key.push_back( read_float( inFile ) );	// Read keys
				for ( uint8_t i = 0; i < keyCount; i++ )
					mainPCR.gen.x00000300.val.push_back( read_float( inFile ) );	// Read values
			}
			else {
				mainPCR.gen.x00000300.noKeysValue = read_float( inFile );			// No keys value
			}
			align( inFile, 4 );
		}
		
		/* [00000C00] */ {
			if ( mainPCR.gen.inventory & 0x00000C00 ) {
				uint8_t keyCount = read_u8( inFile );	align( inFile, 4 );			// Read keyCount	
					
				for ( uint8_t i = 0; i < keyCount; i++ )
					mainPCR.gen.x00000C00.key.push_back( read_float( inFile ) );	// Read keys
				for ( uint8_t i = 0; i < keyCount; i++ )
					mainPCR.gen.x00000C00.val.push_back( read_float( inFile ) );	// Read values
			}
			else {
				mainPCR.gen.x00000C00.noKeysValue = read_float( inFile );			// No keys value
			}
			mainPCR.gen.x00000C00.flt_00 = read_float( inFile );	//velocityMin
			mainPCR.gen.x00000C00.flt_01 = read_float( inFile );	//velocityMax
			mainPCR.gen.x00000C00.flt_02 = read_float( inFile );	//deceleration
			mainPCR.gen.x00000C00.flt_03 = read_float( inFile );	//unkBirthA
			mainPCR.gen.x00000C00.flt_04 = read_float( inFile );	//unkBirthB
			mainPCR.gen.x00000C00.flt_05 = read_float( inFile );	//scaleBirthMin
			mainPCR.gen.x00000C00.flt_06 = read_float( inFile );	//scaleBirthMax
			mainPCR.gen.x00000C00.flt_07 = read_float( inFile );	//unkDeathA
			mainPCR.gen.x00000C00.flt_08 = read_float( inFile );	//unkDeathB
			mainPCR.gen.x00000C00.flt_09 = read_float( inFile );	//scaleDeathMin
			mainPCR.gen.x00000C00.flt_10 = read_float( inFile );	//scaleDeathMax
			mainPCR.gen.x00000C00.flt_11 = read_float( inFile );	//
			mainPCR.gen.x00000C00.flt_12 = read_float( inFile );	//
			mainPCR.gen.x00000C00.flt_13 = read_float( inFile );	//
			mainPCR.gen.x00000C00.u16_00 = read_u16( inFile )  ;	//
			mainPCR.gen.x00000C00.u16_01 = read_u16( inFile )  ;	//
			mainPCR.gen.x00000C00.u16_02 = read_u16( inFile )  ;	//
			mainPCR.gen.x00000C00.u16_03 = read_u16( inFile )  ;	//maxLifeFrames
			mainPCR.gen.x00000C00.u16_04 = read_u16( inFile )  ;	//maxPtclCount
			mainPCR.gen.x00000C00.u8_00  = read_u8( inFile )   ;	//
			mainPCR.gen.x00000C00.u8_01  = read_u8( inFile )   ;	//
			mainPCR.gen.x00000C00.u8_02  = read_u8( inFile )   ;	//
			mainPCR.gen.x00000C00.u8_03  = read_u8( inFile )   ;	//
			mainPCR.gen.x00000C00.u8_04  = read_u8( inFile )   ;	//
			align( inFile, 4 );
		}
		
		/* [00010000] */ {
			if ( mainPCR.gen.inventory & 0x00010000 ) {
				mainPCR.gen.x00010000.flt_00 = read_float( inFile );	//
				mainPCR.gen.x00010000.flt_01 = read_float( inFile );	//
				mainPCR.gen.x00010000.flt_02 = read_float( inFile );	//
			}
			align( inFile, 4 );
		}
		
		/* [00020000] */ {
			if ( mainPCR.gen.inventory & 0x00020000 ) {
				mainPCR.gen.x00020000.flt_00 = read_float( inFile );	//
				mainPCR.gen.x00020000.flt_01 = read_float( inFile );	//
				mainPCR.gen.x00020000.flt_02 = read_float( inFile );	//
			}
			align( inFile, 4 );
		}
		
		/* [00040000] */ {
			if ( mainPCR.gen.inventory & 0x00040000 ) {
				mainPCR.gen.x00040000.flt_00 = read_float( inFile );	//
				mainPCR.gen.x00040000.flt_01 = read_float( inFile );	//
				mainPCR.gen.x00040000.flt_02 = read_float( inFile );	//
				mainPCR.gen.x00040000.flt_03 = read_float( inFile );	//
				mainPCR.gen.x00040000.flt_04 = read_float( inFile );	//
				mainPCR.gen.x00040000.flt_05 = read_float( inFile );	//
				mainPCR.gen.x00040000.flt_06 = read_float( inFile );	//
			}
			align( inFile, 4 );
		}
		
		/* [00080000] */ {
			if ( mainPCR.gen.inventory & 0x00080000 ) {
				mainPCR.gen.x00080000.flt_00 = read_float( inFile );	//
				mainPCR.gen.x00080000.flt_01 = read_float( inFile );	//
				mainPCR.gen.x00080000.flt_02 = read_float( inFile );	//
				mainPCR.gen.x00080000.flt_03 = read_float( inFile );	//
			}
			align( inFile, 4 );
		}
		
		/* [00100000] */ {
			if ( mainPCR.gen.inventory & 0x00100000 ) {
				mainPCR.gen.x00100000.flt_00 = read_float( inFile );	//
				mainPCR.gen.x00100000.flt_01 = read_float( inFile );	//
				mainPCR.gen.x00100000.flt_02 = read_float( inFile );	//
				mainPCR.gen.x00100000.flt_03 = read_float( inFile );	//
			}
			align( inFile, 4 );
		}
		
		/* [00200000] */ {
			if ( mainPCR.gen.inventory & 0x00200000 ) {
				mainPCR.gen.x00200000.flt_00 = read_float( inFile );	//
				mainPCR.gen.x00200000.flt_01 = read_float( inFile );	//
				mainPCR.gen.x00200000.flt_02 = read_float( inFile );	//
				mainPCR.gen.x00200000.u8_00  = read_u8( inFile )   ;	//
				mainPCR.gen.x00200000.u8_01  = read_u8( inFile )   ;	//SolidTexID
				mainPCR.gen.x00200000.u8_02  = read_u8( inFile )   ;	//
			}
			align( inFile, 4 );
		}
		
		/* [00400000] - Death Scatter */ {
			if ( mainPCR.gen.inventory & 0x00400000 ) {
				mainPCR.gen.x00400000.flt_00 = read_float( inFile );	//deathScatter
			}
			align( inFile, 4 );
		}
		
		/* [00800000] */ {
			if ( mainPCR.gen.inventory & 0x00800000 ) {
				mainPCR.gen.x00800000.flt_00 = read_float( inFile );	//
				mainPCR.gen.x00800000.flt_01 = read_float( inFile );	//
				mainPCR.gen.x00800000.flt_02 = read_float( inFile );	//
				mainPCR.gen.x00800000.flt_03 = read_float( inFile );	//
				mainPCR.gen.x00800000.flt_04 = read_float( inFile );	//
			}
			align( inFile, 4 );
		}
		
		/* [00002000] */ {
			if ( mainPCR.gen.inventory & 0x00002000 ) {
				mainPCR.gen.x00002000.flt_00 = read_float( inFile );	//
				mainPCR.gen.x00002000.flt_01 = read_float( inFile );	//
				mainPCR.gen.x00002000.flt_02 = read_float( inFile );	//
				mainPCR.gen.x00002000.u8_00  = read_u8( inFile )   ;	//
				mainPCR.gen.x00002000.u8_01  = read_u8( inFile )   ;	//
				mainPCR.gen.x00002000.u8_02  = read_u8( inFile )   ;	//
				mainPCR.gen.x00002000.u8_03  = read_u8( inFile )   ;	//
				mainPCR.gen.x00002000.u8_04  = read_u8( inFile )   ;	//
				mainPCR.gen.x00002000.u8_05  = read_u8( inFile )   ;	//
			}
			align( inFile, 4 );
		}
		
	}
	
	outputInternalData( mainPCR );
	//outputKeyData( mainPCR );
}
