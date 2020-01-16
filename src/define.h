#ifndef DEFINE_H
#define DEFINE_H

#include "ansi_include.h"

struct rgba {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};

struct xyz {
	float x;
	float y;
	float z;
};

struct pcr {
	string magic;
	std::streampos genStart;
	bool bool_0;
	
	struct {
		uint8_t TEVColor;
		uint8_t unkA;
		bool isFadeout;
		uint8_t keyCount;
		
		float falseA;
		float falseB;
		
		vector<float> key;
		vector<uint32_t> valA;
		vector<uint32_t> valB;
	} col;
	
	
	struct {
		uint32_t inventory;
		xyz pos;
		xyz rot;
		xyz unk;
		float spread;
		
		struct {	// Particle Life
			float noKeysValue;
			vector<float> key;
			vector<float> val;
			float flt_00;	//unkA;
			float flt_01;	//unkB;
		} x000000C0;
		
		struct {	// [00000300]
			float noKeysValue;
			vector<float> key;
			vector<float> val;
		} x00000300;
		
		struct {	// [00000C00]
			float noKeysValue;
			vector<float> key;
			vector<float> val;
			float flt_00;	//velocityMin;
			float flt_01;	//velocityMax;
			float flt_02;	//deceleration;
			float flt_03;	//unkBirthA;
			float flt_04;	//unkBirthB;
			float flt_05;	//scaleBirthMin;
			float flt_06;	//scaleBirthMax;
			float flt_07;	//unkDeathA;
			float flt_08;	//unkDeathB;
			float flt_09;	//scaleDeathMin;
			float flt_10;	//scaleDeathMax;
			float flt_11;	//unkA;
			float flt_12;	//unkB;
			float flt_13;	//unkC;
			uint16_t u16_00;	//unkD;
			uint16_t u16_01;	//unkE;
			uint16_t u16_02;	//unkF;
			uint16_t u16_03;	//maxLifeFrames;
			uint16_t u16_04;	//maxPtclCount;
			uint8_t u8_00;	//unkG;
			uint8_t u8_01;	//unkH;
			uint8_t u8_02;	//unkI;
			uint8_t u8_03;	//unkJ;
			uint8_t u8_04;	//unkK;
		} x00000C00;
		
		struct {	// [00010000]
			float flt_00;	//unkA;
			float flt_01;	//unkB;
			float flt_02;	//unkC;
		} x00010000;
		
		struct {	// [00020000]
			float flt_00;	//unkA;
			float flt_01;	//unkB;
			float flt_02;	//unkC;
		} x00020000;
		
		struct {	// [00040000]
			float flt_00;	//unkA;
			float flt_01;	//unkB;
			float flt_02;	//unkC;
			float flt_03;	//unkD;
			float flt_04;	//unkE;
			float flt_05;	//unkF;
			float flt_06;	//unkG;
		} x00040000;
		
		struct {	// [00080000]
			float flt_00;	//unkA;
			float flt_01;	//unkB;
			float flt_02;	//unkC;
			float flt_03;	//unkD;
		} x00080000;
		
		struct {	// [00100000]
			float flt_00;	//unkA;
			float flt_01;	//unkB;
			float flt_02;	//unkC;
			float flt_03;	//unkD;
		} x00100000;
		
		struct {	// [00200000]
			float flt_00;	//unkA;
			float flt_01;	//unkB;
			float flt_02;	//unkC;
			uint8_t u8_00;	//unkD;
			uint8_t u8_01;	//solidTexID;
			uint8_t u8_02;	//unkE;
		} x00200000;
		
		struct {	// [00400000]
			float flt_00;	//deathScatter;
		} x00400000;
		
		struct {	// [00800000]
			float flt_00;	//unkA;
			float flt_01;	//unkB;
			float flt_02;	//unkC;
			float flt_03;	//unkD;
			float flt_04;	//unkE;
		} x00800000;
		
		struct {	// [00002000]
			float flt_00;	//unkA;
			float flt_01;	//unkB;
			float flt_02;	//unkC;
			uint8_t u8_00;	//unkD;
			uint8_t u8_01;	//unkE;
			uint8_t u8_02;	//unkF;
			uint8_t u8_03;	//unkG;
			uint8_t u8_04;	//unkH;
			uint8_t u8_05;	//unkI;
		} x00002000;
		
	} gen;
};


#endif	//DEFINE_H
