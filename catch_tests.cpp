#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "PGMimageProcessor.h"
#include "ConnectedComponent.h"

TEST_CASE("Basic Constructor", "[Basic Constructor]") {
	DLMARD001::PGMimageProcessor a;
	SECTION("RETURN VALUE") {
		REQUIRE(a.getMinSize() == 3);
	}
}
