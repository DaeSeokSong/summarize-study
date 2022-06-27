// Extract line
Mat thsRotImg;
threshold(rotateImg, thsRotImg, 5, 255, THRESH_OTSU);

vector<int> restorePtX;
for (int x = 0; x < thsRotImg.cols; x++)
{
	int objHeight = 0;
	for (int y = 0; y < thsRotImg.rows; y++)
	{
		if (thsRotImg.at<uchar>(y, x) == 0)
		{
			objHeight++;
			if (objHeight > 20)
			{
				restorePtX.push_back(x);
				break;
			}
		}
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