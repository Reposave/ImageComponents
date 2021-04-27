#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "PGMimageProcessor.h"
#include "ConnectedComponent.h"

//Testing ConnectedComponent.h
//Testing PGMimageProcessor.h.
TEST_CASE("Basic Constructor", "[Basic Constructor]") {
	DLMARD001::PGMimageProcessor a;
	SECTION("RETURN VALUE") {
		REQUIRE(a.getMinSize() == 3);
	}
}
TEST_CASE("Custom Constructor", "[Custom Constructor]") {
	DLMARD001::PGMimageProcessor a(6,1000, 128, "outfile", "infile");
	SECTION("RETURN VALUE") {
		REQUIRE(a.getMinSize() == 6);
	}
}
