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
	DLMARD001::PGMimageProcessor a(6,1000, 128, "outfile.PGM", "Ugly.pgm");
	SECTION("RETURN VALUE") {
		REQUIRE(a.getMinSize() == 6);
	}
}
TEST_CASE("Build Array", "[Build Array]"){
	DLMARD001::PGMimageProcessor a(20,1000, 128, "outfile.PGM", "Ugly.pgm");
	a.BuildArray();
	SECTION("RETURN VALUE") {
		REQUIRE(a.getImageHeight() == 600);
	}
}
