#include <stdint.h>

#include "BasicRenderer.hpp"
#include "cstr.h"
#include "efiMemory.h"
#include "memory.h"

struct BootInfo {
	Framebuffer* framebuffer;
	PSF1_FONT* psf1_Font;
	EFI_MEMORY_DESCRIPTOR* mMap;
	uint64_t mMapSize;
	uint64_t mMapDescSize;
} ;

unsigned int colors[] = {
    0xff0000,
    0xffa500,
    0xffff00,
    0x00ff00,
    0x0000ff,
    0x52307c
};

extern "C" void _start(BootInfo* bootInfo){
    
    BasicRenderer renderer = BasicRenderer(bootInfo->framebuffer, bootInfo->psf1_Font); 
    
    //uint64_t mMapEntries = bootInfo->mMapSize / bootInfo->mMapDescSize;
    
    //renderer.Print(to_string(GetMemorySize(bootInfo->mMap, mMapEntries, bootInfo->mMapDescSize)));

    renderer.Color = 0x000000;

    for(unsigned long x = 0L; x < (renderer.TargetFramebuffer->Width/10); x++){
        for(unsigned long i = 0L; i < 10; i++) {
            renderer.Rect(((x*10L)+i), 0, 1, renderer.TargetFramebuffer->Height);
        }
        renderer.Color = colors[x%6];
    }

    while(true) {}
    
    return;
}