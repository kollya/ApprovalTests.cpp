#include "Catch.hpp"
#include "ApprovalTests/StringWriter.h"
#include "ApprovalTests/Approvals.h"
#include "Approvals.h"

std::string readFileAndDelete(const char *fileName) {
    std::ifstream in(fileName, std::ios_base::in);
    std::stringstream written;
    written << in.rdbuf();
    in.close();
    remove(fileName);

    std::string text = written.str();
    return text;
}

TEST_CASE("ItWritesTheContentsToAFile") {
    StringWriter s("Hello");
    auto fileName = "out.txt";
    s.write(fileName);

    std::string text = readFileAndDelete(fileName);
    REQUIRE(text == "Hello\n");
}

TEST_CASE("ItWritesTheContentsToAStream") {
    std::stringstream out;
    StringWriter s("Hello");
    s.Write(out);
    REQUIRE(out.str() == "Hello\n");
}

TEST_CASE("TheDefaultExtensionIsText") {
    StringWriter s("Hello");
    REQUIRE(s.getFileExtensionWithDot() == ".txt");
}

TEST_CASE("TheExtensionIsConfigurable") {
    StringWriter s("Hello", ".html");
    REQUIRE(s.getFileExtensionWithDot() == ".html");
}

TEST_CASE("ItGivesMeaningfulErrorIfWritingFails") {
    StringWriter s("Hello");
    auto fileName = "I/do/not/exist/out.txt";
    ApprovalTests::Approvals::verifyExceptionMessage([&](){s.write(fileName);});
}