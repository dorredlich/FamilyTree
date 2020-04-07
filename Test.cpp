#include "doctest.h"
#include "FamilyTree.hpp"
#include <iostream>
using namespace std;
using namespace family;

// TEST_CASE("relation test case"){
//     family::Tree T("Dor");
//     T.addFather("Dor","Haim").addMother("Dor","Dana")
//     .addFather("Haim","Yossi").addMother("Dana","Yuval")
//     .addFather("Yossi", "Shaked").addMother("Yuval", "Shoval")
//     .addFather("Shaked", "Dan").addMother("Shoval", "Yafa")
//     .addFather("Dan","Gilad").addMother("Yafa","Daniel");
//     CHECK(T.relation("Dor") == "me");
//     CHECK(T.relation("Haim") == "father");
//     CHECK(T.relation("Dana") == "mother");
//     CHECK(T.relation("Yossi") == "grandfather");
//     CHECK(T.relation("Yuval") == "grandmother");
//     CHECK(T.relation("Shaked") == "great-great-grandfather");
//     CHECK(T.relation("Shoval") == "great-great-grandmother");
//     CHECK(T.relation("Dan") == "great-great-great-grandfather");
//     CHECK(T.relation("Yafa") == "great-great-great-grandmother");
//     CHECK(T.relation("Gilad") == "great-great-great-great-grandfather");
//     CHECK(T.relation("Daniel") == "great-great-great-great-grandmother");
//     CHECK(T.relation("Omri") == "unrelated");
//     CHECK(T.relation("Sheli") == "unrelated");
//     CHECK(T.relation("Michael") == "unrelated");
//     CHECK(T.relation("Omer") == "unrelated");
// }


// TEST_CASE("find test case"){
//     family::Tree T("Dor");
//      T.addFather("Dor","Haim").addMother("Dor","Dana")
//     .addFather("Haim","Yossi").addMother("Dana","Yuval")
//     .addFather("Yossi", "Shaked").addMother("Yuval", "Shoval")
//     .addFather("Shaked", "Dan").addMother("Shoval", "Yafa")
//     .addFather("Dan","Gilad").addMother("Yafa","Daniel");
//     CHECK(T.find("me") == "Dor");
//     CHECK(T.find("father") == "Haim");
//     CHECK(T.find("mother") == "Dana");
//     CHECK(T.find("grandfather") == "Yossi");
//     CHECK(T.find("grandmother") == "Yuval");
//     CHECK(T.find("great-great-grandfather") == "Shaked");
//     CHECK(T.find("great-great-grandfather") == "Shoval");
//     CHECK(T.find("great-great-great-grandfather") == "Dan");
//     CHECK(T.find("great-great-great-grandfather") == "Yafa");
//     CHECK(T.find("great-great-great-great-grandfather") == "Gilad");
//     CHECK(T.find("great-great-great-great-grandfather") == "Daniel");
//     CHECK(T.find("brother") == "Exption");
//     CHECK(T.find("sister") == "Exption");
//     CHECK(T.find("cousin") == "Exption");
//     CHECK(T.find("uncle") == "Exption");
//     CHECK(T.find("aunt") == "Exption");
// }

// TEST_CASE("find test case"){
//     family::Tree T("Dor");
//      T.addFather("Dor","Haim").addMother("Dor","Dana")
//     .addFather("Haim","Yossi").addMother("Dana","Yuval")
//     .addFather("Yossi", "Shaked").addMother("Yuval", "Shoval")
//     .addFather("Shaked", "Dan").addMother("Shoval", "Yafa")
//     .addFather("Dan","Gilad").addMother("Yafa","Daniel");
//     CHECK(T.find("me") == "Dor");
//     CHECK(T.find("father") == "Haim");
//     CHECK(T.find("mother") == "Dana");
//     CHECK(T.find("grandfather") == "Yossi");
//     CHECK(T.find("grandmother") == "Yuval");
//     CHECK(T.find("great-great-grandfather") == "Shaked");
//     CHECK(T.find("great-great-grandfather") == "Shoval");
//     CHECK(T.find("great-great-great-grandfather") == "Dan");
//     CHECK(T.find("great-great-great-grandfather") == "Yafa");
//     CHECK(T.find("great-great-great-great-grandfather") == "Gilad");
//     CHECK(T.find("great-great-great-great-grandfather") == "Daniel");
//     CHECK(T.find("brother") == "Exption");
//     CHECK(T.find("sister") == "Exption");
//     CHECK(T.find("cousin") == "Exption");
//     CHECK(T.find("uncle") == "Exption");
//     CHECK(T.find("aunt") == "Exption");
// }





TEST_CASE("find check"){
    Tree T("Haim");
    T.addFather("Haim","Yossi").addMother("Haim","Dana");
    for (int i = 0; i <100 ; ++i) {
        CHECK(T.find("find")=="Dana");
    }
}



