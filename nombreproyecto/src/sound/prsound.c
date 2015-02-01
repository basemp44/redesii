#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <redes2/sound.h>

int main()
{
	char buf[256];
	register int i;
	FILE *f;

	record_format(PA_SAMPLE_S16BE,2); 
	play_format(PA_SAMPLE_S16BE,2); 

	if(open_record()) puts("error");
	f=fopen("pruebasonido","w+b");
	puts("Grabando");
	for(i=0; i < 10000; ++i)
	{
		record_sound(buf,160);
		fwrite(buf,1,160,f);
	}
	fclose(f);
	close_record();

	if(open_play()) puts("error");
	f=fopen("pruebasonido","rb");
	puts("Reproduciendo");
	for(i=0; i < 10000; ++i)
	{
		fread(buf,1,160,f);
		play_sound(buf,160);
	}
	fclose(f);
	close_play();
	return 0;
}

