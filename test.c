#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

//#include "lena_hex.h"

#define _MAX_SIZE_ 640*480*4
uint32_t matrix [_MAX_SIZE_];

void crtaj_liniju (int x1, int x2, int y1, int y2){
	int i=0;
	for (i=y1; i<y2; i++)
		*(matrix+640*x1 +i)= 0xFFFF;
}

int main(void) {
	int i = 0;
	int cnt=0;
	for (i=0; i < 640*480; i++) {
		matrix[i] = 0x0;
	}// obojili
	int j=0;
	int k=0;


	int x, y;
	int y_off=100;
	int x_off=200;
	int size=100;
	//for (i=0; i<640*400;i++)
	//	matrix[i]=0xFFFF;
	//crtaj_liniju(100,100,100,200);
//	for (j=(640-1)*y_off+x_off;j<(640-1)*y_off+x_off+size;j++)		matrix[i]=0xFFFF;
//		matrix[i]=0xFFFF;

	for(x=100; x<200; x++){
		matrix[x+(100*640)] = 0xFFFF;
	}
	

	int* pointer;
	int file;

	file = open("/dev/vga_dma", O_RDWR | O_NDELAY);

	pointer = (int*)mmap(0,_MAX_SIZE_ , PROT_READ|PROT_WRITE, MAP_SHARED, file, 0);
	memcpy(pointer, matrix, _MAX_SIZE_);
	close(file);

}

