#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "PGMimageProcessor.h"
#include "ConnectedComponent.h"

//Testing ConnectedComponent.h
TEST_CASE("CCBasic Constructor", "[CCBasic Constructor]") {
	DLMARD001::ConnectedComponent c;
	DLMARD001::ConnectedComponent d;
	DLMARD001::ConnectedComponent e;
	SECTION("RETURN VALUE") {
		REQUIRE(c.getID() == 0);
		REQUIRE(d.getID() == 1);
		REQUIRE(e.getID() == 2);
	}
}

//Testing PGMimageProcessor.h.
TEST_CASE("Basic Constructor", "[Basic Constructor]") {
	DLMARD001::PGMimageProcessor a;
	SECTION("RETURN VALUE") {
		REQUIRE(a.getMinSize() == 3);
	}
}
TEST_CASE("Custom Constructor", "[Custom Constructor]") {
	DLMARD001::PGMimageProcessor a("outfile.PGM", "Ugly.pgm",6,1000, 128);
	SECTION("RETURN VALUE") {
		REQUIRE(a.getMinSize() == 6);
	}
}
TEST_CASE("Build Array", "[Build Array]"){
	DLMARD001::PGMimageProcessor a("outfile.PGM", "Ugly.pgm",20,1000, 128);
	a.BuildArray();
	SECTION("RETURN VALUE") {
		REQUIRE(a.getImageHeight() == 600);
	}
}
TEST_CASE("Extract Components", "[Extract Components]"){
	DLMARD001::PGMimageProcessor a("outfile.PGM", "Ugly.pgm",20,1000, 128);
	a.BuildArray();
	//int b = a.extractComponents((unsigned char) 100, 3);
	SECTION("RETURN VALUE") {
		REQUIRE(a.getImageHeight() == 600);
		//REQUIRE(b == 0);
	}
}

