#ifndef BLACKFILEINTERFACE_H
#define BLACKFILEINTERFACE_H
#include <iostream>
#include <cstdio>
class BlackFileInterface {
private:
   FILE *file;
   BlackFileInterface() : file(nullptr) {}
public:
   static BlackFileInterface& Instance() {
       static BlackFileInterface instance;
       return instance;
   }
   bool openForRead(const char *filename) {
       file = fopen(filename, "rb");
       return (file != nullptr);
   }
   bool openForWrite(const char *filename) {
       file = fopen(filename, "wb");
       return (file != nullptr);
   }
   unsigned char getNextChar() {
       if (file == nullptr) return 0;
       return fgetc(file);
   }
   bool putNextChar(unsigned char c) {
       if (file == nullptr) return false;
       return (fputc(c, file) != EOF);
   }
   bool eof() {
       if (file == nullptr) return true;
       return feof(file);
   }
   bool close() {
       if (file == nullptr) return false;
       fclose(file);
       file = nullptr;
       return true;
   }
   ~BlackFileInterface() {
       if (file != nullptr) {
           fclose(file);
       }
   }
};
#endif // BLACKFILEINTERFACE_H
