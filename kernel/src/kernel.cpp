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

extern "C" void _start(BootInfo* bootInfo){
    
    BasicRenderer renderer = BasicRenderer(bootInfo->framebuffer, bootInfo->psf1_Font); 
    
    //uint64_t mMapEntries = bootInfo->mMapSize / bootInfo->mMapDescSize;
    
    //renderer.Print(to_string(GetMemorySize(bootInfo->mMap, mMapEntries, bootInfo->mMapDescSize)));

    renderer.Color = 0xff0000;

    renderer.Rect(10, 10, 10, 10);

    while(true) {}
    
    return;
}