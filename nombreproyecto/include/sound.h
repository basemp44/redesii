#ifndef _SOUND_H
#define _SOUND_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <pulse/simple.h>
#include <pulse/error.h>

#define NO_ERROR				0
#define NO_CONGRUENT_NUMBER_OF_CHANNELS		-1
#define NO_CORRECT_FORMAT			-2
#define UNKNOWN_ERROR				-3

int record_format	(enum pa_sample_format format, int channels);
int play_format		(enum pa_sample_format format, int channels);
int open_record		(void);
int open_play		(void);
int record_sound	(char * buf, int size);
int play_sound		(char * buf, int size);
void close_record	(void);
void close_play		(void);

#endif
