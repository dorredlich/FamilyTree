/**
 * A demonstration test program for Gimatriya calculation.
 * 
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * Date: 2020-02
 */

#include "doctest.h"
#include <string>
#include "FamilyTree.hpp"
using namespace family;
using namespace std;

TEST_CASE("Test find")
{
  family::Tree T("Dor");
  T.addFather("Dor", "Moshe");
  T.addMother("Dor", "Dana");
  T.addFather("Moshe", "Yakov");
  T.addMother("Moshe", "Sara");
  T.addFather("Yakov", "Dan");
  T.addMother("Yakov", "Miriam");
  T.addFather("Dan", "David");
  T.addMother("Dan", "Keren");
  T.addFather("David", "Ran");
  T.addMother("David", "Rivka");
     CHECK_NOTHROW(T.find("father") );
   CHECK_NOTHROW(T.find("mother") );
   CHECK_NOTHROW(T.find("grandfather") );
   CHECK_NOTHROW(T.find("grandmother") );
   CHECK_NOTHROW(T.find("great-grandfather") );
   CHECK_NOTHROW(T.find("great-grandmother") );
   CHECK_NOTHROW(T.find("great-great-grandfather") );
   CHECK_NOTHROW(T.find("great-great-grandmother") );
   CHECK_NOTHROW(T.find("great-great-great-grandfather"));
   CHECK_NOTHROW(T.find("great-great-great-grandmother") );
  CHECK(T.find("father") == string("Moshe"));
  CHECK(T.find("mother") == string("Dana"));
  CHECK(T.find("grandfather") == string("Yakov"));
  CHECK(T.find("grandmother") == string("Sara"));
  CHECK(T.find("great-grandfather") == string("yaakov"));
  CHECK(T.find("great-grandmother") == string("Dan"));
  CHECK(T.find("great-great-grandfather") == string("David"));
  CHECK(T.find("great-great-grandmother") == string("Keren"));
  CHECK(T.find("great-great-great-grandfather") == string("Ran"));
  CHECK(T.find("great-great-great-grandmother") == string("Rivka"));
  CHECK_THROWS(T.find("uncle"));
  CHECK_THROWS(T.find("aunt"));
  CHECK_THROWS(T.find("son"));
  CHECK_THROWS(T.find("daughter"));
  CHECK_THROWS(T.find("brother"));
  CHECK_THROWS(T.find("sister"));
  CHECK_THROWS(T.find("nephew"));
  CHECK_THROWS(T.find("niece"));
    CHECK_THROWS(T.find("grandmother"));
  CHECK_THROWS(T.find("grand_mother"));
  CHECK_THROWS(T.find("dad"));
  CHECK_THROWS(T.find("mom"));
  CHECK_THROWS(T.find("grandpa"));
  CHECK_THROWS(T.find("grandad"));
  CHECK_THROWS(T.find("grandma"));
  CHECK_THROWS(T.find("Great grandmother"));
}
TEST_CASE("Test addFather")
{
  family::Tree T("Yoni");
  T.addFather("Yoni", "Eli");
  T.addFather("Eli", "Omri");
  T.addFather("Omri", "Gal");
  T.addFather("Gal", "david");
  T.addFather("david", "nisim");
  CHECK(T.find("father") == string("Eli"));
  CHECK(T.find("grandfather") == string("Omri"));
  CHECK(T.find("great-grandfather") == string("Gal"));
  CHECK(T.find("great-great-grandfather") == string("david"));
  CHECK(T.find("great-great-great-grandfather") == string("nisim"));
}

TEST_CASE("Test addMother")
{
  family::Tree T("Yoni");
  T.addMother("Yoni", "Dana");
  T.addMother("Dana", "Sara");
  T.addMother("Sara", "Miriam");
  T.addMother("Miriam", "Rivka");
  T.addMother("Rivka", "Gil");
  CHECK(T.find("mother") == string("Dana"));
  CHECK(T.find("grandmother") == string("Sara"));
  CHECK(T.find("great-grandmother") == string("Miriam"));
  CHECK(T.find("great-great-grandmother") == string("Rivka"));
  CHECK(T.find("great-great-great-grandmother") == string("Gil"));
}

TEST_CASE("Test relation")
{
  family::Tree T("Yoni");
  T.addFather("Yoni", "Eli");
  T.addMother("Yoni", "Dana");
  T.addFather("Eli", "Omri");
  T.addMother("Eli", "Sara");
  T.addFather("Omri", "Yaakov");
  T.addMother("Omri", "Miriam");
  T.addFather("Yaakov", "David");
  T.addMother("Yaakov", "Keren");
  T.addFather("David", "Nisim");
  T.addMother("David", "Rivka");
    CHECK_NOTHROW(T.relation("Yoni"));
  CHECK_NOTHROW(T.relation("Eli"));
  CHECK_NOTHROW(T.relation("Dana"));
  CHECK_NOTHROW(T.relation("Omri"));
  CHECK_NOTHROW(T.relation("Sara"));
  CHECK_NOTHROW(T.relation("Yaakov"));
  CHECK_NOTHROW(T.relation("Miriam"));
  CHECK_NOTHROW(T.relation("David"));
  CHECK_NOTHROW(T.relation("Keren"));
  CHECK_NOTHROW(T.relation("Nisim"));
  CHECK_NOTHROW(T.relation("Rivka"));
  CHECK(T.relation("Eli") == string("father"));
  CHECK(T.relation("Dana") == string("mother"));
  CHECK(T.relation("Omri") == string("grandfather"));
  CHECK(T.relation("Sara") == string("grandmother"));
  CHECK(T.relation("Yaakov") == string("great-grandfather"));
  CHECK(T.relation("Miriam") == string("great-grandmother"));
  CHECK(T.relation("David") == string("great-great-grandfather"));
  CHECK(T.relation("Keren") == string("great-great-grandmother"));
  CHECK(T.relation("Nisim") == string("great-great-great-grandfather"));
  CHECK(T.relation("Rivka") == string("great-great-great-grandmother"));
  CHECK(T.relation("Moshe") == string("unrelated"));
  CHECK(T.relation("Hadas") == string("unrelated"));
  CHECK(T.relation("Dolev") == string("unrelated"));
  CHECK(T.relation("Chen") == string("unrelated"));
  CHECK(T.relation("Yoni") == string("me"));
}
TEST_CASE("Test remove")
{
  family::Tree T("Dan");
  T.addFather("Dan", "Haim");
  T.addMother("Dan", "Dana");
  T.addFather("Haim", "Shaked");
  T.addMother("Haim", "Miri");
  T.addFather("Shaked", "Shone");
  T.addMother("Shaked", "Miriam");
  T.addFather("Shone", "Dor");
  T.addMother("Shone", "Gal");
  T.addFather("Dor", "Rea");
  T.addMother("Dor", "Chen");
  CHECK_NOTHROW(T.relation("Dan"));
  CHECK_NOTHROW(T.relation("Haim"));
  CHECK_NOTHROW(T.relation("Dana"));
  CHECK_NOTHROW(T.relation("Shaked"));
  CHECK_NOTHROW(T.relation("Miri"));
  CHECK_NOTHROW(T.relation("Shone"));
  CHECK_NOTHROW(T.relation("Miriam"));
  CHECK_NOTHROW(T.relation("Dor"));
  CHECK_NOTHROW(T.relation("Gal"));
  CHECK_NOTHROW(T.relation("Rea"));
  CHECK_NOTHROW(T.relation("Chen"));

  T.remove("Shone");
   CHECK_NOTHROW(T.relation("Gal"));
  CHECK(T.relation("Dor") == string("unrelated"));
  CHECK(T.relation("Rea") == string("unrelated"));
  CHECK(T.relation("Chen") == string("unrelated"));
  T.remove("Haim");
  CHECK(T.relation("Haim") == string("unrelated"));
  CHECK(T.relation("Shaked") == string("unrelated"));
  CHECK(T.relation("Miri") == string("unrelated"));
  CHECK(T.relation("Shone") == string("unrelated"));
  CHECK(T.relation("Miriam") == string("unrelated"));
}
TEST_CASE("Test remove 2")
{
  family::Tree t("ori");
   family::Tree T("Dan");
  T.addFather("Dan", "Haim");
  T.addMother("Dan", "Dana");
  T.addFather("Haim", "Shaked");
  T.addMother("Haim", "Miri");
  T.addFather("Shaked", "Shone");
  T.addMother("Shaked", "Miriam");
  T.addFather("Shone", "Dor");
  T.addMother("Shone", "Gal");
  T.addFather("Dor", "Rea");
  T.addMother("Dor", "Chen");
  t.remove("Dor");
  CHECK_THROWS(t.relation("Dor"));
  CHECK_THROWS(t.relation("Rea"));
  CHECK_THROWS(t.relation("Chen"));
  t.remove("Haim");
  CHECK_THROWS(t.relation("Haim"));
  CHECK_THROWS(t.relation("Shaked"));
  CHECK_THROWS(t.relation("Miri"));
  CHECK_THROWS(t.relation("Shone"));
  CHECK_THROWS(t.relation("Miriam"));
}

TEST_CASE("mother already exist- throw exeption"){
  family::Tree T("Yoni");
  T.addMother("Yoni", "Dana");
  CHECK_THROWS(T.addMother("ori", "Gal"));
}
