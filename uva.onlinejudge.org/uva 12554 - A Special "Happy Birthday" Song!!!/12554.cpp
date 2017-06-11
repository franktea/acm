/*
 * 12554.cpp
 *
 *  Created on: Jun 11, 2017
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> songs = {"Happy", "birthday", "to", "you",
		"Happy", "birthday", "to", "you",
		"Happy", "birthday", "to", "Rujia",
		"Happy", "birthday", "to", "you"};

int main()
{
	vector<string> persons;
	int count;
	cin>>count;
	persons.reserve(count);
	for(int i = 0; i < count; ++i)
	{
		string person;
		cin>>person;
		persons.push_back(person);
	}

	size_t song_times = persons.size() / songs.size();
	if(persons.size() % songs.size() != 0)
	{
		++song_times;
	}

	for(size_t song_index = 0; song_index < song_times*songs.size(); ++song_index)
	{
		cout<<persons[song_index % persons.size()]<<": "<<songs[song_index % songs.size()]<<"\n";
	}

	return 0;
}



