/// Create luminance  source
Ref<LuminanceSource> source = MatSource::create(grayImage);

/// Set input image
Ref<Binarizer> binarizer(new GlobalHistogramBinarizer(source));
Ref<BinaryBitmap> bitmap(new BinaryBitmap(binarizer));

/// Set decode hint
DecodeHints hints;
if (is2D)
{
	hints.addFormat(BarcodeFormat::DATA_MATRIX);
	hints.addFormat(BarcodeFormat::QR_CODE);
	hints.addFormat(BarcodeFormat::AZTEC);
	hints.addFormat(BarcodeFormat::PDF_417);
}
else
{
	hints = DecodeHints(DecodeHints::ONED_HINT);
}
hints.setTryHarder(true);

/// Search for MultiBarcode
Ref<Reader> reader;
reader.reset(new MultiFormatReader);
Ref<Result> result(reader->decode(bitmap, hints));

/// Get result point count
int resultPointCount = result->getResultPoints()->size();





/// Extract detected line's start and end point
Point startPt = getResultPoint(result->getResultPoints()[0]);
Point endPt = getResultPoint(result->getResultPoints()[resultPointCount - 1]);

/// 1-D, Check recognization range
bool isRightRange = true;
if (!is2D)
{
	int recogDist = abs(startPt.x - endPt.x);

	vector<vector<Point>> barcodeContours;
	findContours(grayImage, barcodeContours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	int stdDist = 0;
	for (vector<Point> contour : barcodeContours)
	{
		for (int idx = 0; idx < contour.size(); idx++)
		{
			int dist = abs(contour[idx].x - contour[(idx + 1) % 4].x);
			if (stdDist < dist) stdDist = dist;
		}
	}

	float recogRatio = (float)recogDist / (float)stdDist;
	if (recogRatio < MIN_RECOG_RANGE_RATIO || recogRatio > MAX_RECOG_RANGE_RATIO) isRightRange = false;
}

/// 1-D, Check right degree
bool isRightDegree = true;
if (!is2D && isRightRange)
{
	float detectRadian = atan2(startPt.y - endPt.y, startPt.x - endPt.x);
	int detectDegree = detectRadian * 180 / CV_PI;
	if (!(detectDegree >= rotateDegree - ROTATE_ERROR && detectDegree <= rotateDegree + ROTATE_ERROR)
		&& !(detectDegree >= 180 - rotateDegree - ROTATE_ERROR && detectDegree <= 180 - rotateDegree + ROTATE_ERROR))
		isRightDegree = false;
}

// Extract line
Mat thsRotImg;
threshold(rotateImg, thsRotImg, 5, 255, THRESH_OTSU);

vector<int> restorePtX;
vector<int> startPtX;
vector<int> endPtX;
int blackX = 0;
for (int x = 0; x < thsRotImg.cols; x++)
{
	int beforeBlackX = blackX;
	int objHeight = 0;
	for (int y = 0; y < thsRotImg.rows; y++)
	{
		if (thsRotImg.at<uchar>(y, x) == 0)
		{
			objHeight++;
			if (objHeight > 20)
			{
				restorePtX.push_back(x);
				if (blackX == 0)startPtX.push_back(x);

				blackX++;
				break;
			}
		}
	}

	if (blackX != 0 && beforeBlackX == blackX)
	{
		endPtX.push_back(x - 1);
		blackX = 0;
	}
}

// Decrease too big black pixel group
int groupNum = startPtX.size();
for (int grpIdx = 0; grpIdx < groupNum; grpIdx++)
{
	int startPt = startPtX[grpIdx];
	int endPt = endPtX[grpIdx];
	int count = endPt - startPt + 1;
	int scaled = int(count * 9.0f / groupNum);

	if (scaled > 4)
	{
		//int startIdx = find(restorePtX.begin(), restorePtX.end(), startPt) - restorePtX.begin();
		int endIdx = find(restorePtX.begin(), restorePtX.end(), endPt) - restorePtX.begin();

		//restorePtX.erase(restorePtX.begin() + startIdx);
		restorePtX.erase(restorePtX.begin() + endIdx);

		//int dist1 = restorePtX[startIdx] - restorePtX[startIdx - 1];
		//int dist2 = restorePtX[endPt + 1] - restorePtX[endPt];

		//if (dist1 < dist2) restorePtX.erase(restorePtX.begin() + startIdx);
		//else restorePtX.erase(restorePtX.begin() + endIdx);
	}
}

// Create line
vector<vector<Point>> cons;
findContours(~thsRotImg, cons, RETR_LIST, CHAIN_APPROX_SIMPLE);

vector<Point> pts;
for (vector<Point> con : cons)
{
	for (Point pt : con) pts.push_back(pt);
}

Rect tmp = boundingRect(pts);
rectangle(thsRotImg, tmp, Scalar::all(255), -1);

for (int x = tmp.x; x < tmp.x + tmp.width; x++)
{
	if (find(restorePtX.begin(), restorePtX.end(), x) != restorePtX.end())
	{
		Point top(x, tmp.y);
		Point bot(x, tmp.y + tmp.height);
		line(thsRotImg, top, bot, Scalar::all(0), 1);
	}
}
rotateImg = thsRotImg;
decodeBarcode(rotateImg, decodedTexts, degree, is2D);