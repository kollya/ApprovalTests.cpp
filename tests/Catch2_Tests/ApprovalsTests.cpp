#include <ostream>
#include <stdexcept>
#include "Catch.hpp"
#include "ApprovalTests/Approvals.h"

TEST_CASE("YouCanVerifyText") {
    ApprovalTests::Approvals::verify("My objects!");
}

TEST_CASE("TestStreamableObject") {
    ApprovalTests::Approvals::verify(42);
}

class NonCopyable
{
public:
    NonCopyable() = default;
    NonCopyable(const NonCopyable& x) = delete; // prevent copy construction

    friend std::ostream &operator<<(std::ostream &os, const NonCopyable &/*copyable*/) {
        return os << 999;
    }
};

TEST_CASE("TestNonCopyableStreamableObject") {
    NonCopyable object;
    ApprovalTests::Approvals::verify(object);
}

// ==============================================================

struct NonStreamablePoint
{
    int x = 0;
    int y = 0;
    // Note that NonStreamablePoint does not provide operator<<( ostream &os, const NonStreamablePoint& )
};

NonStreamablePoint getPoint()
{
    return NonStreamablePoint{4, 7};
}

TEST_CASE("YouCanVerifyWithConverterLambda")
{
    ApprovalTests::Approvals::verify(
        getPoint(),
        [](const auto& p, auto& os)
        {
            os << "[x: " << p.x << " y: " << p.y << "]";
        });
}

// ==============================================================

struct FormatNonStreamablePoint
{
    explicit FormatNonStreamablePoint(const NonStreamablePoint& point) : point(point)
    {
    }

    const NonStreamablePoint& point;

    friend std::ostream &operator<<(std::ostream &os, const FormatNonStreamablePoint &wrapper)
    {
        os << "(x,y) = (" <<
           wrapper.point.x << "," <<
           wrapper.point.y << ")";
        return os;
    }
};

TEST_CASE("YouCanVerifyWithConverterWrapperClass")
{
    ApprovalTests::Approvals::verify(
        getPoint(),
        [](auto r, auto& os){os << FormatNonStreamablePoint(r);}
    );
}

// ==============================================================

std::ostream& customToStreamFunction(std::ostream &os, const NonStreamablePoint& point)
{
    os << point.x << "," << point.y;
    return os;
}

TEST_CASE("YouCanVerifyWithConverterWrapperFunction")
{
    ApprovalTests::Approvals::verify(
        getPoint(),
        [](auto r, auto& os){ customToStreamFunction(os, r);}
    );
}

// ==============================================================

TEST_CASE("VerifyingException")
{
    ApprovalTests::Approvals::verifyExceptionMessage([](){throw std::runtime_error("Here is my exception message");});
}

TEST_CASE("VerifyingNoException")
{
    // begin-snippet: verify_exception_message_example
    ApprovalTests::Approvals::verifyExceptionMessage([](){/* your code goes here */});
    // end-snippet
}
