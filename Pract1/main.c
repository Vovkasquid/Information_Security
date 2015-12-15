#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
// TODO: записать оба бита, а получается что по одному
int main() {
	
	unsigned short magicalPoly = 0x8E47;
	unsigned short src = 0x0000;
	char buf[2];
	int nread = 0;
	int in = open("prob.txt", O_RDONLY);
	int firstEntryFlag = 1;
	int digitForIteration = pow(2,15);
	printf("before nread\n");
	while (nread = read(in, buf, 1) > 0) {
		printf("cycle\n");
		int i;
		if (nread == 2) {
			
		} else {
			if (firstEntryFlag) {
				src = (unsigned short) buf;
				firstEntryFlag--;
			}
		}
		for (i = 0; i < 8; ++i) {
			if (src & digitForIteration) {//Если старший бит = 1, то смещаем и умножаем, иначе просто смещаем
				src = src << 1;
				src = src ^ magicalPoly;
				if (buf & 128) { //смещение и перенос бита
					src++;
					buf = buf << 1;
				}
			} else {
				src = src << 1;
				if (buf & 128) { //смещение и перенос бита
					src++;
					buf = buf << 1;
				}
			}
		}
	}

	int iter; //досмещение оставшегося
	for (iter = 0; iter < 16; ++iter) {
		int i;
		for (i = 0; i < 8; ++i) {
			if (src & digitForIteration) {
				src = src << 1;
				src = src ^ magicalPoly;				
			} else {
				src = src << 1;	
			}
		}
	}
	
	printf("src: %#04x\n", src);
	close(in);
	return 0;
}
