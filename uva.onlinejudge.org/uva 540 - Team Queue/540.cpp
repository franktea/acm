/*
 * 540.cpp
 *
 *  Created on: Jun 24, 2018
 *      Author: frank
 */
#include <iostream>
#include <list>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

// one team, each one queue after the last one
struct TeamQueue
{
	int team_id;
	list<int> line; // the queue
};

class Queue
{
public:
	void AddTeamMate(int team_id, int id)
	{
		team_mates_[id] = team_id;
	}

	void Enqueue(int id)
	{
		int team_id = team_mates_[id];
		auto it = std::find_if(line_.begin(), line_.end(), [&id, this](const TeamQueue& tq) {
			return tq.team_id == team_mates_[id];
		});
		if(it == line_.end())
		{
			//cout<<"==>"<<id<<" not found.\n";
			line_.push_back(TeamQueue{team_id, {id}});
		}
		else
		{
			it->line.push_back(id);
		}
	}

	void ShowData()
	{
		for(auto i: line_)
		{
			cout<<"{("<<i.team_id<<":";
			for(auto x: i.line)
			{
				cout<<x<<", ";
			}
			cout<<")}\n";
		}
	}

	void Dequeue()
	{
		if(line_.empty())
		{
			return;
		}

		//ShowData();

		cout<<line_.front().line.front()<<"\n";
		line_.front().line.pop_front();
		if(line_.front().line.empty())
		{
			line_.pop_front();
		}
	}

	void ShowPersons()
	{
		for(auto it: team_mates_)
		{
			cout<<"("<<it.first<<","<<it.second<<")";
		}
		cout<<"\n";
	}
private:
	list<TeamQueue> line_;
	map<int, int> team_mates_; // person id, team id
};

int main()
{
	int case_count = 0;
	int team_count;
	cin>>team_count;
	while(team_count)
	{
		cout<<"Scenario #"<<++case_count<<"\n";

		Queue q;
		while(team_count--)
		{
			int person_count;
			cin>>person_count;
			while(person_count--)
			{
				int person_id;
				cin>>person_id;
				q.AddTeamMate(team_count, person_id);
			}
		}

		//q.ShowPersons();

		string cmd;
		cin>>cmd;
		while(cmd != "STOP")
		{
			if(cmd == "ENQUEUE")
			{
				int person_id;
				cin>>person_id;
				q.Enqueue(person_id);
			}
			else if(cmd == "DEQUEUE")
			{
				q.Dequeue();
			}
			cin>>cmd;
		}

		cout<<"\n";
		cin>>team_count;
	}
	return 0;
}



