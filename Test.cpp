//
// Created by beni on 5/15/23.
//
#include "doctest.h"
#include "sources/Character.hpp"
#include "sources/Point.hpp"
#include "sources/Cowboy.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/OldNinja.hpp"
#include "sources/Team.hpp"
#include <iostream>

using namespace ariel;

TEST_CASE("Cowboy Class Initialization tests") {
// Create a new Cowboy
    Point luckyLukePos(10, 19);
    Cowboy luckyLuke("Lucky Luke", luckyLukePos);
// Check if 'Lucky Luke' was initialized correctly
    CHECK(luckyLuke.getName() == "Lucky Luke");
    CHECK_EQ(luckyLuke.getLife(), 110);
    CHECK(luckyLuke.isAlive());
    CHECK(luckyLuke.hasbullets());
}

TEST_CASE("Cowboy Class Shooting tests") {
    Point luckyLukePos(10, 19);
    Cowboy luckyLuke("Lucky Luke", luckyLukePos);
    Point yuvalPos(1, 1);
    Cowboy yuval("yuval tibi", yuvalPos);
// Lucky Luke shoots at yuval
    luckyLuke.shoot(&yuval);
// Check yuval's life after shooting
    CHECK_EQ(yuval.getLife(), 100);
// Lucky Luke shoots until he has no bullets left
    for (int i = 0; i < 5; i++) {
        luckyLuke.shoot(&yuval);
    }
// Check that Lucky Luke has no bullets left
    CHECK_FALSE(luckyLuke.hasbullets());
// Check yuval's life after being shot multiple times
    CHECK_EQ(yuval.getLife(), 50);
// Check if Lucky Luke have bullets after reloading
    luckyLuke.reload();
    CHECK(luckyLuke.hasbullets());
}

TEST_CASE("Ninja Class Initialization tests") {
//create new ninjas
    Point gotenPos(10, 19);
    Point kakarotoPos(10, 19);
    Point hattoriHanzoPos(40, 50);
    YoungNinja goten("Goten", gotenPos);
    TrainedNinja kakaroto("Kakaroto", kakarotoPos);
    OldNinja hattoriHanzo("Hattori Hanzo", hattoriHanzoPos);
// Check if the ninjas was initialized correctly
    CHECK(goten.getName() == "Goten");
    CHECK_EQ(goten.getLife(), 100);
    CHECK_EQ(goten.getSpeed(), 14);
    CHECK(kakaroto.getName() == "Kakaroto");
    CHECK_EQ(kakaroto.getLife(), 120);
    CHECK_EQ(kakaroto.getSpeed(), 12);
    CHECK(hattoriHanzo.getName() == "Hattori Hanzo");
    CHECK_EQ(hattoriHanzo.getLife(), 150);
    CHECK_EQ(hattoriHanzo.getSpeed(), 8);
}

TEST_CASE("Ninja Class Slashing tests") {
    Point gotenPos(10, 19);
    Point kakarotoPos(10, 19);
    Point hattoriHanzoPos(40, 50);
    YoungNinja goten("Goten", gotenPos);
    TrainedNinja kakaroto("Kakaroto", kakarotoPos);
    OldNinja hattoriHanzo("Hattori Hanzo", hattoriHanzoPos);
//Check Goten's life after being slashed
    kakaroto.slash(&goten);
    CHECK_EQ(goten.getLife(), 60);
//Check Kakaroto's life after being slashed
    hattoriHanzo.slash(&kakaroto);
    CHECK_EQ(kakaroto.getLife(), 120);
}

TEST_CASE("Test Team Class") {
    // Create some ninjas and cowboys
    Point beni_pos(10, 19);
    Point yuval_pos(1, 1);
    Point dani_pos(1, 1);
    Cowboy beni_tibi("beni tibi", beni_pos);
    YoungNinja yuval_tibi("yuval tibi", yuval_pos);
    Cowboy daniel_tibi("daniel tibi", dani_pos);
    // Create a team with "beni tibi" as the leader
    Team team(&beni_tibi);
    // Add members to the team
    team.add(&yuval_tibi);
    CHECK_EQ(team.stillAlive(), 2);
    for (int i = 0; i < 11; i++) {
        if (!daniel_tibi.hasbullets()) {
            daniel_tibi.reload();
        }
        daniel_tibi.shoot(&beni_tibi);
    }
    CHECK_EQ(team.stillAlive(), 1);
}

TEST_CASE("Test point Class: Distance method") {
//Create new points
    Point p1{3, 3};
    Point p2{5, 7};
    Point p3{-2, 2};
    Point p4{2, -8};
    Point p5{-2, -2};
// Check the distance from points with the same distance
    CHECK_EQ(p1.distance(p2), p2.distance(p1));
    CHECK_EQ(p3.distance(p4), p4.distance(p3));
    CHECK_EQ(p5.distance(p1), p1.distance(p5));
// Test the accuracy of the distance method
    CHECK_EQ(p4.distance(p1), 11);
    CHECK_EQ(p2.distance(p5), 7);
    CHECK_EQ(p1.distance(p1), 0);
}

TEST_CASE("Character actions with death") {
    Point gotenPos(2, 2);
    Point kakarotoPos(3, 3);
    Point hattoriHanzoPos(4, 4);
    Point luckyLukePos(5, 5);
    Cowboy luckyLuke("Lucky Luke", luckyLukePos);
    YoungNinja goten("Goten", gotenPos);
    TrainedNinja kakaroto("Kakaroto", kakarotoPos);
    OldNinja hattoriHanzo("Hattori Hanzo", hattoriHanzoPos);
    auto performAttack = [](auto &attacker, auto &victim) {
        while (victim.isAlive()) {
            attacker.slash(&victim);
        }
    };
// Perform attacks until death
    performAttack(goten, hattoriHanzo);
    performAttack(goten, kakaroto);
    performAttack(goten, luckyLuke);
    // Calling the attacking method of a dead character should throw an exception
    CHECK_THROWS_AS(hattoriHanzo.slash(&goten), std::runtime_error);
    CHECK_THROWS_AS(kakaroto.slash(&goten), std::runtime_error);
    CHECK_THROWS_AS(luckyLuke.shoot(&goten), std::runtime_error);
// Dead cowboy can't reload
    CHECK_THROWS_AS(luckyLuke.reload(), std::runtime_error);
}








