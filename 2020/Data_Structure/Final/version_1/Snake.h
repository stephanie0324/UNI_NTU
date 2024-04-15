#include <iostream>
#include <queue>
#include <tuple>
#include <iomanip>
#include <cmath>

using namespace std;

class Snake
{
private:
	queue<tuple<int, int>> position;
	tuple<int, int> target;
    queue <tuple<int, int>> path;

public:
	Snake(queue<tuple<int, int>> start_position);
	queue<tuple<int, int>> nextPosition(vector<vector<int>> map);
	tuple<int, int> getTarget(vector<vector<int>> map , int head_x , int head_y);
	bool collide(queue<tuple<int, int>> pos_body, tuple<int, int> pos_head, vector<vector<int>> map);
    bool beenThere(queue<tuple<int, int>> pos_body, tuple<int, int> pos_head);
    void clearPath(queue <tuple<int, int>> path);
    bool eaten = false;
};
