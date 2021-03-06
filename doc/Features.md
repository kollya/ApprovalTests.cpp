<!--
GENERATED FILE - DO NOT EDIT
This file was generated by [MarkdownSnippets](https://github.com/SimonCropp/MarkdownSnippets).
Source File: /doc/mdsource/Features.source.md
To change this file edit the source file and then execute ./run_markdown_templates.sh.
-->

<a id="top"></a>

# Features



<!-- toc -->
## Contents

  * [Using custom writers](#using-custom-writers)
  * [Using custom filename extensions](#using-custom-filename-extensions)
  * [Multiple output files per test](#multiple-output-files-per-test)
  * [SeparateApprovedAndReceivedDirectoriesNamer](#separateapprovedandreceiveddirectoriesnamer)
  * [Registering a Custom Namer](#registering-a-custom-namer)
  * [Customizing Google Tests Approval File Names](#customizing-google-tests-approval-file-names)
  * [Blocking Reporter](#blocking-reporter)
  * [Machine Blockers](#machine-blockers)
  * [Front Loaded Reporters](#front-loaded-reporters)
  * [Using sub-directories for approved files](#using-sub-directories-for-approved-files)
<!-- endtoc -->


## Using custom writers

See [Using custom writers](#using-custom-writers)

## Using custom filename extensions

See [Using custom filename extensions](#using-custom-filename-extensions)

## Multiple output files per test

See [Multiple output files per test](/doc/MultipleOutputFilesPerTest.md#top).

## SeparateApprovedAndReceivedDirectoriesNamer

See [SeparateApprovedAndReceivedDirectoriesNamer](/doc/Namers.md#separateapprovedandreceiveddirectoriesnamer)

## Registering a Custom Namer

See [Registering a Custom Namer](/doc/Namers.md#registering-a-custom-namer)

## Customizing Google Tests Approval File Names

See [Using Approval Tests With Google Tests](/doc/UsingGoogleTests.md#customizing-google-tests-approval-file-names)

## Blocking Reporter

See [Blocking Reporters](/doc/Reporters.md#blocking-reporters)

## Machine Blockers

Sometimes you will want tests to only run on certain machines. Machine blockers are a great way to do this.

<!-- snippet: machine_specific_test_runner -->
<a id='snippet-machine_specific_test_runner'/></a>
```cpp
TEST_CASE("Only run this test on John's machine")
{
    auto blocker = ApprovalTests::MachineBlocker::onMachinesNotNamed("JOHNS_MACHINE");
    if ( blocker.isBlockingOnThisMachine() )
    {
        return;
    }
    // Write tests here that depend on John's environment.
    REQUIRE(ApprovalTests::SystemUtils::getMachineName() == "JOHNS_MACHINE");
}
```
<sup>[snippet source](/tests/Catch2_Tests/utilities/MachineBlockerTests.cpp#L21-L32) / [anchor](#snippet-machine_specific_test_runner)</sup>
<!-- endsnippet -->

## Front Loaded Reporters

See [Front Loaded Reporters](/doc/Reporters.md#front-loaded-reporters)

## Using sub-directories for approved files

See [Using sub-directories for approved files](/doc/Configuration.md#using-sub-directories-for-approved-files)


---

[Back to User Guide](/doc/README.md#top)
