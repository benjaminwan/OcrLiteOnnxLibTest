chcp 65001
:: Set Param
@ECHO OFF
@SETLOCAL
echo "Setting the Number of Threads=%NUMBER_OF_PROCESSORS% Using an OpenMP Environment Variable"
set OMP_NUM_THREADS=%NUMBER_OF_PROCESSORS%

SET TARGET_IMG=images/1.jpg
if not exist %TARGET_IMG% (
echo "找不到待识别的目标图片：%TARGET_IMG%，请打开本文件并编辑TARGET_IMG"
PAUSE
exit
)

bin\OcrLibTest.exe

echo.
PAUSE

@ENDLOCAL
