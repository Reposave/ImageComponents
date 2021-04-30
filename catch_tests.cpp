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
TEST_CASE("CC getNumOfPixels", "[CC getNumOFPixels]"){
	DLMARD001::ConnectedComponent c;
	c.push(1,1);
	DLMARD001::ConnectedComponent d;
	d.push(1,2);
	d.push(1,3);
	d.push(2,2);
	DLMARD001::ConnectedComponent e;
	SECTION("RETURN VALUE") {
		REQUIRE(c.getNumOfPixels() == 1);
		REQUIRE(d.getNumOfPixels() == 3);
		REQUIRE(e.getNumOfPixels() == 0);
	}
}
TEST_CASE("CCBasic Copy Constructor", "[CCBasic Copy Constructor]") {
	DLMARD001::ConnectedComponent c;
	c.push(1,34);
	DLMARD001::ConnectedComponent d(c);
	SECTION("RETURN VALUE a") {
		REQUIRE(c.getID() == 6); //6 because static int.
		REQUIRE(d.getID() == 7);
	}
	SECTION("RETURN VALUE b"){
		REQUIRE(c.getNumOfPixels() == 1);
		REQUIRE(d.getNumOfPixels() == 1);
	}
}


//Testing PGMimageProcessor.h.
TEST_CASE("Basic Constructor", "[Basic Constructor]") {
	DLMARD001::PGMimageProcessor a;
	SECTION("RETURN VALUE") {
		REQUIRE(a.getMinSize() == 3);
	}
}
TEST_CASE("Build Array", "[Build Array]"){
	DLMARD001::PGMimageProcessor a("outfile.pgm", "Ugly.pgm",20,1000, 128);
	a.BuildArray();
	SECTION("RETURN VALUE") {
		REQUIRE(a.getImageHeight() == 600);
	}
}
TEST_CASE("Extract Components", "[Extract Components]"){
	DLMARD001::PGMimageProcessor a("outfile.pgm", "Ugly.pgm",20,1000, 128);
	a.BuildArray();
	int b = a.extractComponents((unsigned char) 100, 3);
	SECTION("RETURN VALUE") {
		REQUIRE(a.getImageHeight() == 600);
		REQUIRE(b == 4);
	}
}
TEST_CASE("Build Component", "[BuildComponent]"){
	DLMARD001::PGMimageProcessor a("outfile.pgm", "Ugly.pgm",20,1000, 128);
	a.BuildArray();
	SECTION("RETURN VALUE") {
		REQUIRE(a.getComponentCount() > 1);
	}
}
TEST_CASE("writeComponents", "[WriteComponents]"){
	DLMARD001::PGMimageProcessor a("outfile.pgm", "Ugly.pgm",20,1000, 128);
	a.BuildArray();
	SECTION("RETURN VALUE") {
		REQUIRE(a.writeComponents("Output.pgm"));
	}
}

