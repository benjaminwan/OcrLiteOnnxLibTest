#include "maintest.h"
#include <stdarg.h> //windows&linux for va_start
#include <OcrLiteCaller.h>
#include <stdexcept>
#include <cstdlib>

void Logger(const char *format, ...) {
    char *buffer = (char *) malloc(8192);
    va_list args;
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);
    printf("%s", buffer);
    free(buffer);
}

int main(int argc, char *argv[]) {
    OcrLiteCaller ocrLite;
    ocrLite.setNumThread(THREAD_NUM);
    ocrLite.initModels(DET_MODEL, CLS_MODEL, REC_MODEL, KEY_FILE);
    OcrResult result = ocrLite.detect(DEFAULT_IMG_PATH, DEFAULT_IMG_NAME, 50, 1024, 0.6, 0.3, 2.0, 1, 1);
    Logger("%s\n", result.strRes.c_str());
    return 0;
}
