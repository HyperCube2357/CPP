#include "Member.h"
#include <algorithm>
#include <iostream>

using namespace std;

Member::Member(){
    _userId = ++_numOfUsers;
    _onlineUsers.push_back(_numOfUsers);
}

Member::~Member(){
    --_numOfUsers;
    _onlineUsers.remove(_userId);
}

void Member::follow(Member& m){
    if(m._userId != _userId){
     if(find(_followers.begin(),_followers.end(), m._userId) == _followers.end() ){
        _followers.push_back(m._userId);
        m._followMe.push_back(_userId);
        }
    }
}

void Member::unfollow(Member& m){
    for(int i=0; i<_followers.size();i++){
        if(m._userId == _followers[i]){
            _followers.erase(_followers.begin()+i);
        }
    }
    for(int i=0;i<m._followMe.size(); i++){
        if(_userId==m._followMe[i]){
            m._followMe.erase(m._followMe.begin()+i);
        }
    }
}

int Member::numFollowers(){

    for(int i=0;i<_followMe.size();i++){
        list<int>::iterator it;
        it= find(_onlineUsers.begin(), _onlineUsers.end(), _followMe[i]);
        if(it == _onlineUsers.end()){
            _followMe.erase(_followMe.begin()+i);
        }
    }

    return _followMe.size();
}

int Member::numFollowing(){

    for(int i=0;i<_followers.size();i++){
        list<int>::iterator it;
        it= find(_onlineUsers.begin(), _onlineUsers.end(), _followers[i]);
        if(it == _onlineUsers.end()){
            _followers.erase(_followers.begin()+i);
        }
    }
    return _followers.size();
}

int Member::count(){
    return _numOfUsers;
}