// ZXing number of codes
std::cout << "========================================" << endl;
std::cout << "1 = AZTEC" << endl;
std::cout << "2 = CODABAR" << endl;
std::cout << "3 = CODE_39" << endl;
std::cout << "4 = CODE_93" << endl;
std::cout << "5 = CODE_128" << endl;
std::cout << "6 = DATA_MATRIX" << endl;
std::cout << "7 = EAN_8" << endl;
std::cout << "8 = EAN_13" << endl;
std::cout << "9 = ITF" << endl;
std::cout << "10 = MAXICODE" << endl;
std::cout << "11 = PDF_417" << endl;
std::cout << "12 = QR_CODE" << endl;
std::cout << "13 = RSS_14" << endl;
std::cout << "14 = RSS_EXPANDED" << endl;
std::cout << "15 = UPC_A" << endl;
std::cout << "16 = UPC_E" << endl;
std::cout << "17 = UPC_EAN_EXTENSION" << endl;
std::cout << "========================================" << endl << endl;





/// normalize image
Mat normImg;
double resizeRatio = img.cols / NORM_INPUT_SIZE;
resize(img, normImg, Size(img.cols / resizeRatio, img.rows / resizeRatio), INTER_CUBIC);

// Resize image to original size
Rect resRegion;
resRegion.x = (float)contourRegion.x * resizeRatio;
resRegion.y = (float)contourRegion.y * resizeRatio;
resRegion.width = (float)contourRegion.width * resizeRatio;
resRegion.height = (float)contourRegion.height * resizeRatio;





// Disconnect thin rows line
morphologyEx(binImg, morphBinImg, MORPH_OPEN, getStructuringElement(MORPH_RECT, Size(1, 5)));





// Connect 1-D barcode row
morphologyEx(morphBinImg, morphBinImg, MORPH_CLOSE, getStructuringElement(MORPH_RECT, Size(15, 1)));





/// Fill candidate rect in critca ratio
#define MIN_RECT_RATIO 0.95					// 2-D 바코드 사각형의 최소 가로 세로 비율
#define MAX_RECT_RATIO 1.1					// 2-D 바코드 사각형의 최대 가로 세로 비율
if (is2D)
{
	vector<vector<Point>> fillContours;
	findContours(morphBinImg, fillContours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	for (int i = 0; i < fillContours.size(); i++)
	{
		Rect fillRect = boundingRect(fillContours[i]);

		double rectRatio = 0.0;
		if (fillRect.width > fillRect.height) rectRatio = (double)fillRect.height / (double)fillRect.width;
		else rectRatio = (double)fillRect.width / (double)fillRect.height;

		if (rectRatio > MIN_RECT_RATIO && rectRatio < MAX_RECT_RATIO)
			rectangle(morphBinImg, fillRect, Scalar::all(255), -1);
	}
	// Disconnect thin cols line
	morphologyEx(morphBinImg, morphBinImg, MORPH_OPEN, getStructuringElement(MORPH_RECT, Size(21, 1)));

#ifdef DEBUG_EXTRACT_REGION_EXTRA
	showratioImage(morphBinImg, "morphBinImg", 0.4f);
#endif // DEBUG_EXTRACT_REGION_EXTRA
}





/// Delete (smallest and biggest area) or (high diff ratio about area between boundingRect and contour)
#define DEL_THS_TEXT_SIZE 20				// 임계치 미만의 사이즈를 가진 컨투어(텍스트) 제거
#define DEL_THS_DENSITY 0.9					// 임계치 미만의 밀도를 가진 후보군 제거
vector<vector<Point>> delContours;
findContours(morphBinImg, delContours, RETR_CCOMP, CHAIN_APPROX_SIMPLE);

for (int i = 0; i < delContours.size(); i++)
{
	// Delete assumed text area (first)
	Rect contourRect = boundingRect(delContours[i]);

	double densityRatio = contourArea(delContours[i]) / (contourRect.width * contourRect.height);
	if ((contourRect.width < DEL_THS_TEXT_SIZE && contourRect.height < DEL_THS_TEXT_SIZE)
		|| densityRatio < DEL_THS_DENSITY || (!is2D && (contourRect.height > contourRect.width)))
		drawContours(morphBinImg, delContours, i, Scalar::all(0), -1);
}






// Contour rect's row and column ratio
double rectRatio = 0.0;
if (is2D)
{
	if (contourRegion.width > normGrayImg.cols / 2 || contourRegion.height > normGrayImg.rows / 2) continue;

	if (contourRegion.width > contourRegion.height) rectRatio = (double)contourRegion.height / (double)contourRegion.width;
	else rectRatio = (double)contourRegion.width / (double)contourRegion.height;

	if (rectRatio < MIN_RECT_RATIO || rectRatio > MAX_RECT_RATIO) continue;
}
else
{
	if (contourRegion.height > contourRegion.width) continue;
}





// Get density region
Mat densityRegion = binImg(contourRegion);
resize(densityRegion, densityRegion, Size(densityRegion.cols * 2, densityRegion.rows * 2), INTER_CUBIC);

// Thresh density
double dRatio = countNonZero(densityRegion) / (double)(densityRegion.cols * densityRegion.rows);
if (dRatio > minRectDensity)





// Remove filled box about black color
Mat distribution(densityRegion.size(), densityRegion.type(), Scalar::all(255));
vector<int> blackPixels;
bool isBarcode = true;

int spaceCnt = 0;
if (!is2D) densityRegion = ~densityRegion;
for (int x = 1; x < densityRegion.cols - 1; x++)
{
	int blackNum = 0;
	for (int y = 0; y < densityRegion.rows; y++)
	{
		if (densityRegion.at<uchar>(y, x) == 0) distribution.at<uchar>(blackNum++, x) = 0;
	}

	if (blackNum > (densityRegion.rows / 20))
	{
		if (is2D) blackPixels.push_back(blackNum);
		else
		{
			if (blackNum >= densityRegion.rows - 30)
			{
				isBarcode = false;
				break;
			}
		}
	}
	else
	{
		if (is2D)
		{
			if (blackNum == 0) spaceCnt++;
			if (spaceCnt > 3)
			{
				spaceCnt = 0;
				isBarcode = false;
				break;
			}
		}
	}
}

if (is2D && isBarcode)
{
	// Calculate sum, mean, vrnc(분산), stdev(표준편차)
	double sum = std::accumulate(blackPixels.begin(), blackPixels.end(), 0.0);
	double mean = sum / blackPixels.size();

	// Prevent underflow or overflow
	vector<double> diff(blackPixels.size());
	std::transform(blackPixels.begin(), blackPixels.end(), diff.begin(), [mean](double x) { return x - mean; });

	double sq_sum = inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
	double vrnc = sq_sum / blackPixels.size();
	double stdev = sqrt(vrnc);

	if (mean < MIN_BLACK_PIXEL_MEAN_2D && stdev < MIN_BLACK_PIXEL_STDEV_2D)
		isBarcode = false;
}

if (!isBarcode) continue;