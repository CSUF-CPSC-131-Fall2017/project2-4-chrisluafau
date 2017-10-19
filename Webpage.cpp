#include "Webpage.h"

Webpage::Webpage() {
	URL = "";
	time = 0;
}

Webpage::Webpage(const string& webpageURL, const time_t& timeVisited) {
	URL = webpageURL;
	time = timeVisited;
}

string Webpage::getURL() {
	return URL;
}

time_t Webpage::getTime() {
	return time;
}
