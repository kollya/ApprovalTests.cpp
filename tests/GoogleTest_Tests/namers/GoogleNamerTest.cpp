#include "gtest/gtest.h"
#include "ApprovalTests/namers/ApprovalTestNamer.h"
#include "ApprovalTests/CombinationApprovals.h"
#include "ApprovalTests/integrations/google/GoogleConfiguration.h"

#include <ostream>
#include <string>

TEST(GoogleNamerTest, ItDropsFirstNameWhenItEqualsTheFilename)
{
    ApprovalTests::ApprovalTestNamer namer;
    EXPECT_EQ(namer.getTestName(), "ItDropsFirstNameWhenItEqualsTheFilename");
}

TEST(TestCaseNameDifferentNameThanFile, TestName)
{
    ApprovalTests::ApprovalTestNamer namer;
    EXPECT_EQ(namer.getTestName(), "TestCaseNameDifferentNameThanFile.TestName");
}

std::string createSuffix(const std::string& suffix, const std::string& fileName, const std::string& testCaseName)
{
    auto converter = ApprovalTests::GoogleConfiguration::createIgnorableTestCaseNameSuffixCheck(suffix);
    return converter(fileName, testCaseName) ? "redundant" : "";
}

TEST(GoogleNamerTest, TestSuffixMatcher)
{
    std::string suffix = "Test";
    std::string fileName = "/a/b/c/testGoogleNamer.cpp";
    std::vector<std::string> testCaseNames = {"GoogleNamerTest", "GoogleNamer", "GoogleTest", "NamerTest", "NamerTestTest", "NamerTestTests", "TestTest", "Test"};
    ApprovalTests::Approvals::verifyAll<std::vector<std::string>>(
        "suffix: " + suffix + 
        "\nfilename: " + fileName + 
        "\ntest case names:",
        testCaseNames,
        [&](const std::string& test, std::ostream& os){os << test << ": " << createSuffix(suffix, fileName, test);});
}

TEST(GoogleNamerTest, TestSuffixMatcherBug)
{
    std::string testCaseName = "ApprovalTestsTest";
    std::string suffix = "Test";
    std::string fileName = "/a/b/c/testApprovalTests.cpp";
    auto converter = ApprovalTests::GoogleConfiguration::createIgnorableTestCaseNameSuffixCheck(suffix);
    EXPECT_EQ(converter(fileName, testCaseName), true);
}

