#ifndef TEST_DB_MODULE_H
#define TEST_DB_MODULE_H

class TestDBModule : public DBModule {
  colorPrintfModuleVA_t *colorPrintf_p;
  ModuleInfo *mi;
  
  public:
    TestDBModule();
    // init
    const struct ModuleInfo& getModuleInfo();
    void prepare(colorPrintfModule_t *colorPrintf_p, colorPrintfModuleVA_t *colorPrintfVA_p);

    // compiler only
    void *writePC(unsigned int *buffer_length);

    // intepreter - devices
    int init();
    void final();

    // intepreter - program & lib
    void readPC(void *buffer, unsigned int buffer_length);

    // intepreter - program
    int startProgram(int uniq_index);
    RobotData **makeChoise(RobotData** robots_data, unsigned int count_robots);
    int endProgram(int uniq_index);

    // destructor
    void destroy();
    ~TestDBModule() {}

  void colorPrintf(ConsoleColor colors, const char *mask, ...);
};

#endif /* TEST_DB_MODULE_H */