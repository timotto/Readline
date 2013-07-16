#include "Readline.h"

char* ReadLine::feed(Stream *stream) {
	while(stream->available()>0) {
		buffer[bpos] = stream->read();
		if (buffer[bpos] == '\r' || buffer[bpos] == '\n' || buffer[bpos] == 0) {
			buffer[bpos] = 0;
			if (bpos > 0) {
				bpos = 0;
				return buffer;
			}
			bpos = 0;
		} else if (++bpos >= READLINE_MAX) {
			// overflow
			bpos = 0;
		}
	}
	return 0;
}

