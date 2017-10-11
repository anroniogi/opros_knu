#ifndef _GRIDBASEDGLOBALMAP_H_
#define _GRIDBASEDGLOBALMAP_H_

#include "NDTree.h"
#include "GridMap.h"
#include <unordered_map>
#include "bmp256.h"
#include <fstream>

class GridBasedGlobalMap
{
public:
	typedef GridMap<double> LocalMap;
	typedef NDTree< LocalMap, 2 > GlobalGridMap;
	typedef GlobalGridMap::DataPtr LocalMapPtr;
	typedef GlobalGridMap::Point Point;
	typedef GlobalGridMap::PointSet PointSet;
	typedef std::shared_ptr< std::vector< std::vector<double> > > DoubleArray2DPtr;

	GridBasedGlobalMap(double cellSize, unsigned int localMapSize = 5);
	GridBasedGlobalMap(const GridBasedGlobalMap &gridBasedGlobalMap);
	GridBasedGlobalMap(GridBasedGlobalMap &&gridBasedGlobalMap);
	virtual ~GridBasedGlobalMap ();

	GridBasedGlobalMap &operator=(const GridBasedGlobalMap &gridBasedGlobalMap);
	GridBasedGlobalMap &operator=(GridBasedGlobalMap &&gridBasedGlobalMap);

	inline bool IsIn (double x, double y) const;
	bool SetCellData (const double &x, const double &y, const double &data, const bool &createCell = true);
	bool GetCellData (const double &x, const double &y, double &data, const bool &createCell = false);
	inline double GetCellSize() const;
	inline double GetWidth() const;
	inline double GetHeight() const;
	inline Point GetMinCorner() const;
	inline Point GetMaxCorner() const;
	void GetMap(std::vector< std::vector<double> > &map, double &x, double &y);
	inline void SetUseUpdateOncePerScan (bool useUpdateOncePerScan);
	inline void SetUpdateParameters (const double &logLikelihood_occupied, const double &logLikelihood_free, const double &minLogLikelihood, const double &maxLogLikelihood);
	inline void GetUpdateParameters (double &logLikelihood_occupied, double &logLikelihood_free, double &minLogLikelihood, double &maxLogLikelihood);
	inline void ClearVisitedCellPtrs();
	void SetVisitedCellPtrs(const double &x, const double &y, const bool &isOccupied);
	void UpdateVisitedCellData();
	bool SaveMapToBMP(const std::string fileName, const double x, const double y, const double theta);
	bool LoadMapFromBMP(const std::string fileName, double &x, double &y, double &theta);

private:
	double cellSize;
	unsigned int localMapSize;
	GlobalGridMap globalMap;

	bool useUpdateOncePerScan;
	double logLikelihood_occupied;
	double logLikelihood_free;
	double minLogLikelihood;
	double maxLogLikelihood;
	std::unordered_map<double *, std::pair<unsigned int, unsigned int> > visitedCellPtrs;
};

#include "GridBasedGlobalMap.hpp"

#endif
