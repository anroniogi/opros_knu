#include "GridBasedGlobalMap.h"

GridBasedGlobalMap::GridBasedGlobalMap(double cellSize, unsigned int localMapSize) : cellSize(cellSize), localMapSize(localMapSize), globalMap(cellSize*localMapSize), useUpdateOncePerScan(true), logLikelihood_occupied(0.85), logLikelihood_free(-0.4), minLogLikelihood(-2), maxLogLikelihood(3.5)
{

}

GridBasedGlobalMap::GridBasedGlobalMap(const GridBasedGlobalMap &gridBasedGlobalMap) : cellSize(gridBasedGlobalMap.cellSize), localMapSize(gridBasedGlobalMap.localMapSize), globalMap(cellSize*localMapSize), useUpdateOncePerScan(gridBasedGlobalMap.useUpdateOncePerScan), logLikelihood_occupied(0.85), logLikelihood_free(-0.4), minLogLikelihood(-2),	maxLogLikelihood(3.5)
{
	if (this != &gridBasedGlobalMap) {
		globalMap.DeepCopy(gridBasedGlobalMap.globalMap);
	}
}

GridBasedGlobalMap::GridBasedGlobalMap(GridBasedGlobalMap &&gridBasedGlobalMap) : globalMap(cellSize*localMapSize)
{
	if (this != &gridBasedGlobalMap) {
		std::swap(cellSize, gridBasedGlobalMap.cellSize);
		std::swap(localMapSize, gridBasedGlobalMap.localMapSize);
		std::swap(globalMap, gridBasedGlobalMap.globalMap);
		std::swap(useUpdateOncePerScan, gridBasedGlobalMap.useUpdateOncePerScan);
		std::swap(logLikelihood_occupied, gridBasedGlobalMap.logLikelihood_occupied);
		std::swap(logLikelihood_free, gridBasedGlobalMap.logLikelihood_free);
		std::swap(minLogLikelihood, gridBasedGlobalMap.minLogLikelihood);
		std::swap(maxLogLikelihood, gridBasedGlobalMap.maxLogLikelihood);
	}
}

GridBasedGlobalMap::~GridBasedGlobalMap ()
{

}

GridBasedGlobalMap &GridBasedGlobalMap::operator =(const GridBasedGlobalMap &gridBasedGlobalMap)
{
	if (this != &gridBasedGlobalMap) {
		cellSize = gridBasedGlobalMap.cellSize;
		localMapSize = gridBasedGlobalMap.localMapSize;
		globalMap.DeepCopy(gridBasedGlobalMap.globalMap);
		useUpdateOncePerScan = gridBasedGlobalMap.useUpdateOncePerScan;
		logLikelihood_occupied = gridBasedGlobalMap.logLikelihood_occupied;
		logLikelihood_free = gridBasedGlobalMap.logLikelihood_free;
		minLogLikelihood = gridBasedGlobalMap.minLogLikelihood;
		maxLogLikelihood = gridBasedGlobalMap.maxLogLikelihood;
	}

	return *this;
}

GridBasedGlobalMap &GridBasedGlobalMap::operator =(GridBasedGlobalMap &&gridBasedGlobalMap)
{
	if (this != &gridBasedGlobalMap) {
		std::swap(cellSize, gridBasedGlobalMap.cellSize);
		std::swap(localMapSize, gridBasedGlobalMap.localMapSize);
		std::swap(globalMap, gridBasedGlobalMap.globalMap);
		std::swap(useUpdateOncePerScan, gridBasedGlobalMap.useUpdateOncePerScan);
		std::swap(logLikelihood_occupied, gridBasedGlobalMap.logLikelihood_occupied);
		std::swap(logLikelihood_free, gridBasedGlobalMap.logLikelihood_free);
		std::swap(minLogLikelihood, gridBasedGlobalMap.minLogLikelihood);
		std::swap(maxLogLikelihood, gridBasedGlobalMap.maxLogLikelihood);
	}

	return *this;
}

bool GridBasedGlobalMap::SetCellData(const double &x, const double &y, const double &data, const bool &createCell)
{
	Point point;
	point[0] = x;
	point[1] = y;

	LocalMapPtr localMap;
	if (globalMap.GetData(localMap, point, createCell)) {
		Point center = globalMap.GetCenter();

		if (localMap->GetWidth() == 0 || localMap->GetHeight() == 0) {
			localMap->Resize(localMapSize);
		}

		double i, j;
		if (globalMap.HasOneCell()) {
			i = floor((x - center[0]) / cellSize + localMapSize / 2.0);
			j = floor((y - center[1]) / cellSize + localMapSize / 2.0);
		} else {
			i = floor((x - center[0]) / cellSize);
			j = floor((y - center[1]) / cellSize);
		}
		i -= floor(i / localMapSize) * localMapSize;
		j -= floor(j / localMapSize) * localMapSize;

		return localMap->SetData((unsigned int)i, (unsigned int)j, data);
	} else {
		return false;
	}
}

bool GridBasedGlobalMap::GetCellData (const double &x, const double &y, double &data, const bool &createCell)
{
	Point point;
	point[0] = x;
	point[1] = y;

	LocalMapPtr localMap;
	if (globalMap.GetData(localMap, point, createCell)) {
		Point center = globalMap.GetCenter();

		if (localMap->GetWidth() == 0 || localMap->GetHeight() == 0) {
			localMap->Resize(localMapSize);
		}

		double i, j;
		if (globalMap.HasOneCell()) {
			i = floor((x - center[0]) / cellSize + localMapSize / 2.0);
			j = floor((y - center[1]) / cellSize + localMapSize / 2.0);
		} else {
			i = floor((x - center[0]) / cellSize);
			j = floor((y - center[1]) / cellSize);
		}
		i -= floor(i / localMapSize) * localMapSize;
		j -= floor(j / localMapSize) * localMapSize;

		return localMap->GetData((unsigned int)i, (unsigned int)j, data);
	} else {
		data = 0;
		return false;
	}
}

void GridBasedGlobalMap::GetMap(std::vector< std::vector<double> > &map, double &x, double &y)
{
	Point minCorner, maxCorner;
	globalMap.GetBoundingBox(minCorner, maxCorner);
	unsigned int width = round((maxCorner[0] - minCorner[0]) / cellSize);
	unsigned int height = round((maxCorner[1] - minCorner[1]) / cellSize);

	map = std::vector< std::vector<double> >(width, std::vector<double>(height, 0.5));

	x = minCorner[0];
	y = minCorner[1];

	double data;
	for (unsigned int i=0; i<width; ++i) {
		for (unsigned int j=0; j<height; ++j) {
			double px = x + (i+0.5) * cellSize;
			double py = y + (j+0.5) * cellSize;
			if (this->GetCellData(px,py,data)) {
				map[i][j] = 1 / (1 + exp(-data));
			}
		}
	}
}

void GridBasedGlobalMap::SetVisitedCellPtrs(const double &x, const double &y, const bool &isOccupied)
{
	Point point;
	point[0] = x;
	point[1] = y;

	LocalMapPtr localMap;
	double *data;
	if (globalMap.GetData(localMap, point, true)) {
		Point center = globalMap.GetCenter();

		if (localMap->GetWidth() == 0 || localMap->GetHeight() == 0) {
			localMap->Resize(localMapSize);
		}

		double i, j;
		if (globalMap.HasOneCell()) {
			i = floor((x - center[0]) / cellSize + localMapSize / 2.0);
			j = floor((y - center[1]) / cellSize + localMapSize / 2.0);
		} else {
			i = floor((x - center[0]) / cellSize);
			j = floor((y - center[1]) / cellSize);
		}
		i -= floor(i / localMapSize) * localMapSize;
		j -= floor(j / localMapSize) * localMapSize;

		if (localMap->GetDataPtr((unsigned int)i, (unsigned int)j, data) && visitedCellPtrs.count(data) != 0) {
			if (isOccupied) {
				++visitedCellPtrs[data].first;
			} else {
				++visitedCellPtrs[data].second;
			}
		} else {
			return;
		}
	} else {
		return;
	}
}

void GridBasedGlobalMap::UpdateVisitedCellData()
{
	for (auto &visitedCell : visitedCellPtrs) {
		std::cout << useUpdateOncePerScan << std::endl;
		if (useUpdateOncePerScan) {
			//(*visitedCell.first) += (visitedCell.second.first > visitedCell.second.second) ? logLikelihood_occupied : ((visitedCell.second.first < visitedCell.second.second) ? logLikelihood_free : logLikelihood_unknown);
			(*visitedCell.first) += (visitedCell.second.first > 0) ? logLikelihood_occupied : ((visitedCell.second.second > 0) ? logLikelihood_free : 0);
		} else {
			(*visitedCell.first) += logLikelihood_occupied*visitedCell.second.first + logLikelihood_free*visitedCell.second.second;
		}
		(*visitedCell.first) = ((*visitedCell.first) > maxLogLikelihood) ? maxLogLikelihood : (((*visitedCell.first) < minLogLikelihood) ? minLogLikelihood : (*visitedCell.first));
	}
	visitedCellPtrs.clear();
}

bool GridBasedGlobalMap::SaveMapToBMP(const std::string fileName, const double x, const double y, const double theta)
{
	Point minCorner, maxCorner;
	globalMap.GetBoundingBox(minCorner, maxCorner);
	unsigned int width = round((maxCorner[0] - minCorner[0]) / cellSize);
	unsigned int height = round((maxCorner[1] - minCorner[1]) / cellSize);

	unsigned char *data = new unsigned char[width * height];

	double d;
	for (unsigned int i=0; i<width; ++i) {
		for (unsigned int j=0; j<height; ++j) {
			double px = minCorner[0] + (i+0.5) * cellSize;
			double py = minCorner[1] + (j+0.5) * cellSize;
			if (this->GetCellData(px,py,d)) {
				data[(height - 1 - j) * width + i] = 255.0 / (1 + exp(-d));
			} else {
				data[(height - 1 - j) * width + i] = 127;
			}
		}
	}
	unsigned char palette[256][4];
	for (int i=0; i<256; ++i) {
		palette[i][0] = palette[i][1] = palette[i][2] = 255 - i;
		palette[i][3] = 0;
	}

	WriteBmp256 ((fileName+".bmp").c_str(), width, height, data, palette);

	delete[] data;

	std::ofstream ofs;
	ofs.open((fileName+".txt"));
	ofs<<x<<"\t"<<y<<"\t"<<theta<<std::endl<<minCorner[0]<<"\t"<<maxCorner[0]<<"\t"<<minCorner[1]<<"\t"<<maxCorner[1];
	ofs.close();

	return true;
}

bool GridBasedGlobalMap::LoadMapFromBMP(const std::string fileName, double &x, double &y, double &theta)
{
	Point minCorner, maxCorner;
	std::ifstream ifs;
	ifs.open((fileName+".txt"));
	ifs>>x>>y>>theta>>minCorner[0]>>maxCorner[0]>>minCorner[1]>>maxCorner[1];
	ifs.close();

	int width, height;
	unsigned char palette[256][4];
	unsigned char *data = ReadBmp256 ((fileName+".bmp").c_str(), width, height, palette);

	GlobalGridMap newGlobalMap(cellSize*localMapSize);
	std::swap(globalMap, newGlobalMap);
	for (int i=0; i<width; ++i) {
		for (int j=0; j<height; ++j) {
			double d = data[j*width+i];
			if (d != 127) {
				double px = minCorner[0] + (i + 0.5) * cellSize;
				double py = minCorner[1] + (j + 0.5) * cellSize;
				double logLikelihood = log(1.0 * d / (255.0 - d));
				logLikelihood = (logLikelihood < minLogLikelihood) ? minLogLikelihood : ((logLikelihood > maxLogLikelihood) ? maxLogLikelihood : logLikelihood);

				this->SetCellData(px, py, logLikelihood);
			}
		}
	}
	delete[] data;

	return true;
}
