#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include <stdexcept>

using namespace ariel;


TEST_CASE("Create Player")
{
    Player p("Simcha");
    CHECK(p.stacksize() == 0);
    CHECK(p.cardesTaken() == 0);
}


TEST_CASE("Create Game")
{
    Player p1("Simcha");
    Player p2("Shalom");
    Game g(p1, p2);
    CHECK(p1.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.stacksize() == 26);
    CHECK(p2.cardesTaken() == 0);
}

