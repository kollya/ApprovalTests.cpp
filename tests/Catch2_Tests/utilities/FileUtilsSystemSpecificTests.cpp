#include "Catch.hpp"
#include "ApprovalTests/utilities/FileUtilsSystemSpecific.h"
#include "ApprovalTests/namers/ApprovalTestNamer.h"
#include "ApprovalTests/Approvals.h"
#include "ApprovalTests/utilities/SystemUtils.h"
#include <stdio.h>

TEST_CASE("ItCanCopyAFile")
{
  ApprovalTests::ApprovalTestNamer namer;
  const auto& sep = ApprovalTests::SystemUtils::getDirectorySeparator();
  auto source = namer.getDirectory() + ".." + sep + ".." + sep + "sample.txt";
    auto destination = namer.getDirectory() + ".." + sep + "copy.temp.received.txt";

    if ( ApprovalTests::FileUtils::fileExists(destination))
    {
        ::remove(destination.c_str());
    }
    CHECK( ! ApprovalTests::FileUtils::fileExists(destination) );
    ApprovalTests::FileUtilsSystemSpecific::copyFile(source, destination);
    ApprovalTests::Approvals::verifyExistingFile(destination);
}
