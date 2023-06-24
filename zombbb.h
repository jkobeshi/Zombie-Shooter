// Project identifier: 9504853406CBAC39EE89AA3AD238AA12CA198043

#ifndef ZOMBBB_H
#define ZOMBBB_H
#include <iostream>
#include <queue>
#include <string>
#include <getopt.h>
#include <vector>
#include <algorithm>
using namespace std;

struct zombie {
	string name;
	uint32_t round, hlth, spd, dist;
};
class zombieComp {
public:
	bool operator()(const zombie* a, const zombie* b) const {
		if ((a->dist / a->spd) != (b->dist / b->spd)) {
			return (a->dist / a->spd) > (b->dist / b->spd);
		}
		else if (a->hlth != b->hlth) {
			return a->hlth > b->hlth;
		}
		else {
			return a->name > b->name;
		}
	}
};
class roundComp {
public:
	bool operator()(const zombie* a, const zombie* b) const {
		if (a->round != b->round) {
			return a->round < b->round;
		}
		else {
			return a->name > b->name;
		}
	}
}; 

class roundComp2 {
public:
	bool operator()(const zombie* a, const zombie* b) const {
		if (a->round != b->round) {
			return a->round > b->round;
		}
		else {
			return a->name > b->name;
		}
	}
};

class Game {
public:
	void run();
	void get_options(int argc, char** argv);
private:
	//zombie data
	uint32_t max_rand_dis, max_rand_spd, max_rand_hlth;
	priority_queue<zombie*, vector<zombie*>, zombieComp> que;
	deque<zombie> mZomb;
	vector<zombie*> graveyard;
	//player data
	uint32_t quiv_cap, seed;
	bool life = 1;
	//flags
	bool stat = 0, med = 0, verb = 0;
	uint32_t entries = 0;
};

#endif