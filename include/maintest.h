#ifndef __MAIN_TEST_H__
#define __MAIN_TEST_H__

#define DET_MODEL "models/dbnet.onnx"
#define CLS_MODEL "models/angle_net.onnx"
#define REC_MODEL "models/crnn_lite_lstm.onnx"
#define KEY_FILE  "models/keys.txt"

#define THREAD_NUM 3

#ifdef WIN32
const char* DEFAULT_IMG_PATH = "images\\";
#else
const char *DEFAULT_IMG_PATH = "images/";
#endif

const char *DEFAULT_IMG_NAME = "1.jpg";

#endif //__MAIN_TEST_H__
