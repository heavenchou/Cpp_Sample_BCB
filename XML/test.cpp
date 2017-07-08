
#include <DUnitX.TestFramework.hpp>


#include <stdio.h>

#pragma option --xrtti

class __declspec(delphirtti) TMyXMlTest : public TObject
{
public:
  virtual void __fastcall SetUp();
  virtual void __fastcall TearDown();

__published:
  void __fastcall Test1();
  void __fastcall Test2();
};


void __fastcall TMyXMlTest::SetUp()
{

}

void __fastcall TMyXMlTest::TearDown()
{
}

void __fastcall TMyXMlTest::Test1()
{
  // TODO
  String s("Hello");
  Dunitx::Testframework::Assert::IsTrue(s == "Hello");
}

void __fastcall TMyXMlTest::Test2()
{
  // TODO
  String s("Hello");
  Dunitx::Testframework::Assert::IsTrue(s == "Hello2"); // This fails for illustrative purposes



}

static void registerTests()
{
  TDUnitX::RegisterTestFixture(__classid(TMyXMlTest));
}
#pragma startup registerTests 33