#include <vector>
#include <iostream>
#include <list>

#pragma once
using namespace std;

static int _numOfUsers;
static list<int> _onlineUsers;

class Member{

    int _userId;
    vector<int> _followers; //i follow
    vector<int> _followMe; 

public:

    static int count();
    void follow(Member& m);
    void unfollow(Member& m);
    int numFollowers();
    int numFollowing();

    Member();
    ~Member();
};