#include "BrowserHistory.h"
#include <list>
#include <iterator>
BrowserHistory::BrowserHistory() {
	list<Webpage> navHistory(string url = "", int size = 0);
	list<Webpage> allHistory(string url = "", int size = 0);
	navSize = 0;
}

BrowserHistory::~BrowserHistory() {
	navHistory.clear();
	allHistory.clear();
}

void BrowserHistory::visitSite(Webpage newSite) {
	if (navSize > 1)
	{
		while (it != --navHistory.end())
		{
			navHistory.pop_back();
			navSize--;
		}
	}
	navHistory.push_back(newSite);
	allHistory.push_back(newSite);
	it = --navHistory.end();
	navSize++;
}

string BrowserHistory::getURL() {
	return it->getURL();
}

size_t BrowserHistory::getNavSize() {
	return navSize;
}

string BrowserHistory::back() {
	it--;
	return it->getURL();
}

string BrowserHistory::forward() {
	it++;
	return it->getURL();
}

void BrowserHistory::readHistory(string fileName) {
	ifstream myfile(fileName);
	
	if (myfile.is_open())
	{
		time_t time;
		string word;
		Webpage newWebSite;
		cout << "Successfully opened file " << fileName << endl;

		while (myfile >> word)
		{
			if (word == "new")
			{
				myfile >> URL >> time;
				newWebSite.URL = URL;
				newWebSite.time = time;
				visitSite(newWebSite);
			}
			else if (word == "back")
			{
				it--;
			}
			else if (word == "forward")
			{
				it++;
			}
		}
	}
	else cout << "failed to open" << endl;
}

void BrowserHistory::printBackSites() {
	list<Webpage>::iterator i;
	for (i = navHistory.begin(); i != it; i++)
	{
		cout << i->URL /*<< " " << i->time*/ << endl;
	}
}

void BrowserHistory::printForwardSites() {
	list<Webpage>::iterator i;
	for (i = it++; i != navHistory.end(); i++)
	{
		cout << i->URL /*<< " " << i->time*/ << endl;
	}
}

void BrowserHistory::printFullHistory() {
	list<Webpage>::iterator i;
	for (i = allHistory.begin(); i != allHistory.end(); i++)
	{
		cout << i->URL /*<< " " << i->time*/ << endl;
	}
}
