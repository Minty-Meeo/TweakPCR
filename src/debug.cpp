#include "debug.h"

void outputInternalData( pcr& mainPCR ) {
	
	/* Read colorData */ {
		printf("ColorData\n");
		if ( mainPCR.bool_0 == false ) {
			printf("   falseA: %.5f\n", mainPCR.col.falseA);
			printf("   falseB: %.5f\n", mainPCR.col.falseB);
		}
		for ( uint8_t i = 0; i < mainPCR.col.key.size(); i++ ) {
			printf("   key%u: %.5f     %08X     %08X\n", i, mainPCR.col.key[i], mainPCR.col.valA[i], mainPCR.col.valB[i]);
		}
	}
	
	/* generatorData */ {
		/* Constants */ {
			printf("Generator Constants\n");
			printf("   X Position:  %.5f\n", mainPCR.gen.pos.x);	// X Position
			printf("   Y Position:  %.5f\n", mainPCR.gen.pos.y);	// Y Position
			printf("   Z Position:  %.5f\n", mainPCR.gen.pos.z);	// Z Position
			printf("   X Rotation:  %.5f\n", mainPCR.gen.rot.x);	// X Rotation
			printf("   Y Rotation:  %.5f\n", mainPCR.gen.rot.y);	// Y Rotation
			printf("   Z Rotation:  %.5f\n", mainPCR.gen.rot.z);	// Z Rotation
			printf("   X Unk:       %.5f\n", mainPCR.gen.unk.x);	// X Unk
			printf("   Y Unk:       %.5f\n", mainPCR.gen.unk.y);	// Y Unk
			printf("   Z Unk:       %.5f\n", mainPCR.gen.unk.z);	// Z Unk
			printf("   Spread:      %.5f\n", mainPCR.gen.spread);	// Spread
		}
		
		/* [000000C0] Particle Life */ {
			printf("ParticleLife [000000C0]\n");
			if ( mainPCR.gen.inventory & 0x000000C0 ) {
				for ( uint8_t i = 0; i < mainPCR.gen.x000000C0.key.size(); i++ )
					printf("   key%u: %.5f     %.5f\n", i, mainPCR.gen.x000000C0.key[i], mainPCR.gen.x000000C0.val[i]);
			}
			else {
				printf("   (nokeys) %.5f\n", mainPCR.gen.x000000C0.noKeysValue);
			}
			printf("   unkA:        %.5f\n", mainPCR.gen.x000000C0.flt_00);
			printf("   unkB:        %.5f\n", mainPCR.gen.x000000C0.flt_01);
		}
		
		/* [00000300] */ {
			printf("[00000300]\n");
			if ( mainPCR.gen.inventory & 0x00000300 ) {
				for ( uint8_t i = 0; i < mainPCR.gen.x00000300.key.size(); i++ )
					printf("   key%u: %.5f     %.5f\n", i, mainPCR.gen.x00000300.key[i], mainPCR.gen.x00000300.val[i]);
			}
			else {
				printf("   (nokeys) %.5f\n", mainPCR.gen.x00000300.noKeysValue);
			}
		}
		
		/* [00000C00] */ {
			printf("[00000C00]\n");
			if ( mainPCR.gen.inventory & 0x00000C00 ) {
				for ( uint8_t i = 0; i < mainPCR.gen.x00000C00.key.size(); i++ )
					printf("   key%u: %.5f     %.5f\n", i, mainPCR.gen.x00000C00.key[i], mainPCR.gen.x00000C00.val[i]);
			}
			else {
				printf("   (nokeys) %.5f\n", mainPCR.gen.x00000C00.noKeysValue);
			}
			printf("   velocityMin:   %.5f\n", mainPCR.gen.x00000C00.flt_00);
			printf("   velocityMax:   %.5f\n", mainPCR.gen.x00000C00.flt_01);
			printf("   deceleration:  %.5f\n", mainPCR.gen.x00000C00.flt_02);
			printf("   unkBirthA:     %.5f\n", mainPCR.gen.x00000C00.flt_03);
			printf("   unkBirthB:     %.5f\n", mainPCR.gen.x00000C00.flt_04);
			printf("   scaleBirthMin: %.5f\n", mainPCR.gen.x00000C00.flt_05);
			printf("   scaleBirthMax: %.5f\n", mainPCR.gen.x00000C00.flt_06);
			printf("   unkDeathA:     %.5f\n", mainPCR.gen.x00000C00.flt_07);
			printf("   unkDeathB:     %.5f\n", mainPCR.gen.x00000C00.flt_08);
			printf("   scaleDeathMin: %.5f\n", mainPCR.gen.x00000C00.flt_09);
			printf("   scaleDeathMax: %.5f\n", mainPCR.gen.x00000C00.flt_10);
			printf("   unkA:          %.5f\n", mainPCR.gen.x00000C00.flt_11);
			printf("   unkB:          %.5f\n", mainPCR.gen.x00000C00.flt_12);
			printf("   unkC:          %.5f\n", mainPCR.gen.x00000C00.flt_13);
			printf("   unkD:          %u\n"  , mainPCR.gen.x00000C00.u16_00);
			printf("   unkE:          %u\n"  , mainPCR.gen.x00000C00.u16_01);
			printf("   unkF:          %u\n"  , mainPCR.gen.x00000C00.u16_02);
			printf("   maxLifeFrames: %u\n"  , mainPCR.gen.x00000C00.u16_03);
			printf("   maxPtclCount:  %u\n"  , mainPCR.gen.x00000C00.u16_04);
			printf("   unkG:          %u\n"  , mainPCR.gen.x00000C00.u8_00 );
			printf("   unkH:          %u\n"  , mainPCR.gen.x00000C00.u8_01 );
			printf("   unkI:          %u\n"  , mainPCR.gen.x00000C00.u8_02 );
			printf("   unkJ:          %u\n"  , mainPCR.gen.x00000C00.u8_03 );
			printf("   unkK:          %u\n"  , mainPCR.gen.x00000C00.u8_04 );
		}
		
		/* [00010000] */ {
			if ( mainPCR.gen.inventory & 0x00010000 ) {
				printf("[00010000]\n");
				printf("   unkA: %.5f\n", mainPCR.gen.x00010000.flt_00);
				printf("   unkB: %.5f\n", mainPCR.gen.x00010000.flt_01);
				printf("   unkC: %.5f\n", mainPCR.gen.x00010000.flt_02);
			}
		}
		
		/* [00020000] */ {
			if ( mainPCR.gen.inventory & 0x00020000 ) {
				printf("[00020000]\n");
				printf("   unkA: %.5f\n", mainPCR.gen.x00020000.flt_00);
				printf("   unkB: %.5f\n", mainPCR.gen.x00020000.flt_01);
				printf("   unkC: %.5f\n", mainPCR.gen.x00020000.flt_02);
			}
		}
		
		/* [00040000] */ {
			if ( mainPCR.gen.inventory & 0x00040000 ) {
				printf("[00040000]\n");
				printf("   unkA: %.5f\n", mainPCR.gen.x00040000.flt_00);
				printf("   unkB: %.5f\n", mainPCR.gen.x00040000.flt_01);
				printf("   unkC: %.5f\n", mainPCR.gen.x00040000.flt_02);
				printf("   unkD: %.5f\n", mainPCR.gen.x00040000.flt_03);
				printf("   unkE: %.5f\n", mainPCR.gen.x00040000.flt_04);
				printf("   unkF: %.5f\n", mainPCR.gen.x00040000.flt_05);
				printf("   unkG: %.5f\n", mainPCR.gen.x00040000.flt_06);
			}
		}
		
		/* [00080000] */ {
			if ( mainPCR.gen.inventory & 0x00080000 ) {
				printf("[00080000]\n");
				printf("   unkA: %.5f\n", mainPCR.gen.x00080000.flt_00);
				printf("   unkB: %.5f\n", mainPCR.gen.x00080000.flt_01);
				printf("   unkC: %.5f\n", mainPCR.gen.x00080000.flt_02);
				printf("   unkD: %.5f\n", mainPCR.gen.x00080000.flt_03);
			}
		}
		
		/* [00100000] */ {
			if ( mainPCR.gen.inventory & 0x00100000 ) {
				printf("[00100000]\n");
				printf("   unkA: %.5f\n", mainPCR.gen.x00100000.flt_00);
				printf("   unkB: %.5f\n", mainPCR.gen.x00100000.flt_01);
				printf("   unkC: %.5f\n", mainPCR.gen.x00100000.flt_02);
				printf("   unkD: %.5f\n", mainPCR.gen.x00100000.flt_03);
			}
		}
		
		/* [00200000] */ {
			if ( mainPCR.gen.inventory & 0x00200000 ) {
				printf("[00200000]\n");
				printf("   unkA:       %.5f\n", mainPCR.gen.x00200000.flt_00);
				printf("   unkB:       %.5f\n", mainPCR.gen.x00200000.flt_01);
				printf("   unkC:       %.5f\n", mainPCR.gen.x00200000.flt_02);
				printf("   unkD:       %u\n"  , mainPCR.gen.x00200000.u8_00 );
				printf("   solidTexID: %u\n"  , mainPCR.gen.x00200000.u8_01 );
				printf("   unkE:       %u\n"  , mainPCR.gen.x00200000.u8_02 );
			}
		}
		
		/* [00400000] - Death Scatter */ {
			if ( mainPCR.gen.inventory & 0x00400000 ) {
				printf("Death Scatter [00400000]\n");
				printf("   deathScatter: %.5f\n", mainPCR.gen.x00400000.flt_00);
			}
		}
		
		/* [00800000] */ {
			if ( mainPCR.gen.inventory & 0x00800000 ) {
				printf("[00800000]\n");
				printf("   unkA: %.5f\n", mainPCR.gen.x00800000.flt_00);
				printf("   unkB: %.5f\n", mainPCR.gen.x00800000.flt_01);
				printf("   unkC: %.5f\n", mainPCR.gen.x00800000.flt_02);
				printf("   unkD: %.5f\n", mainPCR.gen.x00800000.flt_03);
				printf("   unkE: %.5f\n", mainPCR.gen.x00800000.flt_04);
			}
		}
		
		/* [00002000] */ {
			if ( mainPCR.gen.inventory & 0x00002000 ) {
				printf("[00002000]\n");
				printf("   unkA: %.5f\n", mainPCR.gen.x00002000.flt_00);
				printf("   unkB: %.5f\n", mainPCR.gen.x00002000.flt_01);
				printf("   unkC: %.5f\n", mainPCR.gen.x00002000.flt_02);
				printf("   unkD: %u\n"  , mainPCR.gen.x00002000.u8_00);
				printf("   unkE: %u\n"  , mainPCR.gen.x00002000.u8_01);
				printf("   unkF: %u\n"  , mainPCR.gen.x00002000.u8_02);
				printf("   unkG: %u\n"  , mainPCR.gen.x00002000.u8_03);
				printf("   unkH: %u\n"  , mainPCR.gen.x00002000.u8_04);
				printf("   unkI: %u\n"  , mainPCR.gen.x00002000.u8_05);
			}
		}
	}


		
		
		

		
}

void outputKeyData( pcr& mainPCR ) {
	printf("%s	%u	%u	%u	%u	%u	%u	%08x\n",
		mainPCR.magic.c_str(),
		static_cast<uint16_t>(mainPCR.genStart),
		mainPCR.bool_0,
		mainPCR.col.TEVColor,
		mainPCR.col.unkA,
		mainPCR.col.isFadeout,
		mainPCR.col.key.size(),
		mainPCR.gen.inventory);
}
