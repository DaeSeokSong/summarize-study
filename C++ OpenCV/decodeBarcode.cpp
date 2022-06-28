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