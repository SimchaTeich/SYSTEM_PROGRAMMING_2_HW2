#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include <stdexcept>

using namespace ariel;


TEST_CASE("Create Player")
{
    // init player.
    Player p("Alice");
    CHECK(p.stacksize() == 0);
    CHECK(p.cardesTaken() == 0);

    // try to create 'Anonymous' player.
    CHECK_THROWS(Player(""));
}


TEST_CASE("Create Game")
{
    // init Game.
    Player alice("Alice");
    Player bob("Bob");
    Player eve("Eve");
    Game g(alice, bob);
    CHECK(alice.stacksize() == 26);
    CHECK(alice.cardesTaken() == 0);
    CHECK(bob.stacksize() == 26);
    CHECK(bob.cardesTaken() == 0);

    // try to create game using the same player.
    Player eve("Eve");
    CHECK_THROWS(Game(eve, eve));

    // try to create came with player
    // that is play right now. (Alice..)
    CHECK_THROWS(Game(alice, eve));
}


TEST_CASE("Play one turn")
{
    // init the game
    Player p1("Alice");
    Player p2("Bob");
    Game g(p1, p2);
    
    // play the turn
    g.playTurn();

    // check how many cards left.
    CHECK(p1.stacksize() <= 25);
    CHECK(p2.stacksize() <= 25);

    // check the score right now.
    CHECK((p1.cardesTaken() >= 1 && p2.cardesTaken() == 0 ||
    p1.cardesTaken() == 0 && p2.cardesTaken() >= 1));
}


TEST_CASE("Play all turns")
{
    // init the game
    Player p1("Alice");
    Player p2("Bob");
    Game g(p1, p2);

    // done the game
    g.playAll();

    // check stacks of players are empty.
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);

    // check for can't play after the end.
    CHECK_THROWS(g.playTurn());
    CHECK_THROWS(g.playAll());
}


TEST_CASE("Play again")
{
    // init the first game
    Player p1("Alice");
    Player p2("Bob");
    Game g1(p1, p2);

    // try to create one more game
    // with these players
    CHECK_THROWS(Game(p1, p2));

    // done the first game
    g1.playAll();

    // play again :)
    CHECK_NOTHROW(Game(p1, p2));
}