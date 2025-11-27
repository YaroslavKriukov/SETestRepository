#include "pch.h"
#include "CppUnitTest.h"
#include "C:\ProjectVisual\Lab 2 Basics\Lab2 Basics\Lab2 Basics\Lab2 Basics.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(checkValidN_Tests)
    {
    public:
        TEST_METHOD(checkValidN_get10_exceptionNotThrown)
        {
            int n = 10;
            try
            {
                checkValidN(n);
                Assert::IsTrue(true);
            }
            catch (...)
            {
                Assert::Fail(L"The exception should not have been thrown for n=10.");
            }
        }

        TEST_METHOD(checkValidN_get3_exceptionThrown)
        {
            int n = 3;
            try
            {
                checkValidN(n);
                Assert::Fail(L"An exception was expected for n=3, but it was not thrown.");
            }
            catch (...)
            {
                Assert::IsTrue(true);
            }
        }
    };

    TEST_CLASS(calculate_Tests)
    {
    public:
        TEST_METHOD(calculate_Sum_n6_xNeg6_executed)
        {
            calculate(6, -6.0, -6.0, 1.0);
            Assert::IsNotNull(this);
        }

        TEST_METHOD(calculate_Prod_n4_xNeg5_executed)
        {
            calculate(4, -5.0, -5.0, 1.0);
            Assert::IsNotNull(this);
        }

        TEST_METHOD(calculate_Range_n10_executed)
        {
            calculate(10, -7.0, -3.0, 1.0);
            Assert::IsNotNull(this);
        }
    };
}