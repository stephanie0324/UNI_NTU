#include <iostream>
#include <queue>
#include <tuple>
#include <iomanip>

using namespace std;

class Snake
{
private:
	queue<tuple<int, int>> position;
	tuple<int, int> target;

public:
	
	Snake(queue<tuple<int, int>> start_position);
	queue<tuple<int, int>> nextPosition(vector<vector<int>> map);
	tuple<int, int> getTarget(vector<vector<int>> map);
	bool collide(queue<tuple<int, int>> pos_body, tuple<int, int> pos_head, vector<vector<int>> map);
	
};
