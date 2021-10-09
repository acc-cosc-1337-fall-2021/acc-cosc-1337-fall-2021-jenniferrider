#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <func.h>

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Testing GET GC CONTENT")
{
	REQUIRE(get_gc_content("AGCTATAG")==.375);
	REQUIRE(get_gc_content("CGCTATAG") == .50);
	REQUIRE(get_reverse_string("AGCTATAG") == "GATATCGA");
	REQUIRE(get_reverse_string("CGCTATAG") == "GATATCGC");
	REQUIRE(get_dna_complement("AAAACCCGGT") == "ACCGGGTTTT");
	REQUIRE(get_dna_complement("CCCGGAAAAT") == "ATTTTCCGGG");
	
}

TEST_CASE("Testing custom uppercase function")
{
	REQUIRE(convert_to_uppercase("AgCtAtAg")=="AGCTATAG");
	REQUIRE(convert_to_uppercase("CgctAtAg")=="CGCTATAG");
	REQUIRE(convert_to_uppercase("AaaaCcCGgt")=="AAAACCCGGT");
	REQUIRE(convert_to_uppercase("cccggaaaat")=="CCCGGAAAAT");

}

TEST_CASE("Testing custom lowercase function")
{
	REQUIRE(convert_to_lowercase("AgCtAtAg")=="agctatag");
	REQUIRE(convert_to_lowercase("CgctAtAg")=="cgctatag");
	REQUIRE(convert_to_lowercase("AaaaCcCGgt")=="aaaacccggt");
	REQUIRE(convert_to_lowercase("CCCGGAAAAT")=="cccggaaaat");

}
