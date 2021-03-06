#include <stdio.h>
#include <stdlib.h>
#include <map>

#ifdef _WIN32
#include <windows.h>
#else
#include <stdint.h>
#include <unistd.h>
#include <cstdarg>
#include <cstddef>
#endif

#include "module.h"
#include "robot_module.h"
#include "db_module.h"

#include "test_db_module.h"

/* GLOBALS CONFIG */

#define IID "RCT.Test_db_module_v101"

TestDBModule::TestDBModule() {
  mi = new ModuleInfo;
  mi->uid = IID;
  mi->mode = ModuleInfo::Modes::PROD;
  mi->version = BUILD_NUMBER;
  mi->digest = NULL;
}

const struct ModuleInfo &TestDBModule::getModuleInfo() { return *mi; }

void TestDBModule::prepare(colorPrintfModule_t *colorPrintf_p,
                              colorPrintfModuleVA_t *colorPrintfVA_p) {
  this->colorPrintf_p = colorPrintfVA_p;
}

void *TestDBModule::writePC(unsigned int *buffer_length) {
  (*buffer_length) = 0;
  return NULL;
}

int TestDBModule::init() {
  //connect to data base here
  return 0;
}

void TestDBModule::final() {
  //disconnect from data base here
}

int TestDBModule::startProgram(int uniq_index) { return 0; }

RobotData **TestDBModule::makeChoise(RobotData** robots_data, unsigned int count_robots) {
  return robots_data;
}

int TestDBModule::endProgram(int uniq_index) { return 0; }

void TestDBModule::destroy() {
  delete mi;
  delete this;
}

void TestDBModule::colorPrintf(ConsoleColor colors, const char *mask, ...) {
  va_list args;
  va_start(args, mask);
  (*colorPrintf_p)(this, colors, mask, args);
  va_end(args);
}

PREFIX_FUNC_DLL unsigned short getDBModuleApiVersion() {
  return ROBOT_MODULE_API_VERSION;
};
PREFIX_FUNC_DLL DBModule *getDBModuleObject() {
  return new TestDBModule();
}