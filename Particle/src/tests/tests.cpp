#include "tests.h"
#include "GSMTests.h"

void tests() {
    Serial.println("Hello Unit Tests");
    // Test that extern objects are available
    Serial.printlnf("%s", rtc.getTimeStamp().c_str());
#if EN_GSM
    testGsm();
#endif
    Serial.println("----- TESTING COMPLETE -----");
}

void printTestStart(String tag) {
    Serial.printlnf("----- START OF %s TEST -----", tag.c_str());
}

void printTestEnd(String tag) {
    Serial.printlnf("------ END OF %s TEST ------", tag.c_str());
}

void printTestFailed(String tag) {
    Serial.println("TEST FAILED");
    printTestEnd(tag);
}

void printTestPassed(String tag) {
    Serial.println("TEST PASSED");
    printTestEnd(tag);
}