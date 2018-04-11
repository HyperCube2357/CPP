#include "Member.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("follow twice after same member :"){
    Member bar, shahar;
    shahar.follow(bar);
    CHECK(bar.numFollowers() == 1);
    shahar.follow(bar);
    CHECK(bar.numFollowers() == 1);
}

TEST_CASE("check follow :"){
    Member avi,noa,dani,beni, bar,shahar;
    avi.follow(noa);
    noa.follow(dani);
    dani.follow(avi);
    beni.follow(shahar);
    bar.follow(shahar);
    beni.follow(bar);
    CHECK(avi.numFollowing() == 1);
    CHECK(noa.numFollowing() == 1);
    CHECK(beni.numFollowing() == 2);
    CHECK(bar.numFollowing() == 1);
}

TEST_CASE("check unfollow :"){
    Member bar,shahar,dana;
    bar.follow(shahar);
    dana.follow(shahar);
    CHECK(shahar.numFollowers() == 2);
    CHECK(dana.numFollowers() == 0);
    CHECK(dana.numFollowing()==1);
    dana.unfollow(shahar);
    CHECK(shahar.numFollowers() == 1);
    CHECK(dana.numFollowing() == 0);
}

void test(Member& m){
    Member bar;
    bar.follow(m);
}

TEST_CASE("Destructor :"){
    Member avi, beni;
    beni.follow(avi);
    CHECK(avi.numFollowers()==1);
    test(avi);
    CHECK(avi.numFollowers()==1);
}

TEST_CASE("follow myself :"){
    Member avi;
    avi.follow(avi);
    CHECK(avi.numFollowing() == 0);
}
