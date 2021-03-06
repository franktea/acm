/*
 * bit_field_test.cpp
 *
 *  Created on: Aug 31, 2018
 *      Author: frank
 */
#include "bit_field.h"

// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "../../3rdparty/unit_test/catch2/catch.hpp"


TEST_CASE("test bit field")
{
	BoardStage bs;
	REQUIRE(sizeof(bs) == 4);
	bs.Set(vector<vector<int>> {{1, 2, 3}, {4, 0, 5}});
	cout<<bs.Value()<<"\n";
}

