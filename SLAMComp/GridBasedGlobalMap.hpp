/*
 * GridBasedGlobalMap.hpp
 *
 *  Created on: Jun 8, 2015
 *      Author: kjw
 */

#ifndef _GRIDBASEDGLOBALMAP_HPP_
#define _GRIDBASEDGLOBALMAP_HPP_

bool GridBasedGlobalMap::IsIn (double x, double y) const
{
	Point minCorner, maxCorner;
	globalMap.GetBoundingBox(minCorner, maxCorner);

	return (x >= minCorner[0] && x < maxCorner[0] && y >= minCorner[1] && y < maxCorner[1]);
}

double GridBasedGlobalMap::GetCellSize () const
{
	return cellSize;
}

double GridBasedGlobalMap::GetWidth() const
{
	Point minCorner, maxCorner;
	globalMap.GetBoundingBox(minCorner, maxCorner);
	return (maxCorner[0] - minCorner[0]);
}

double GridBasedGlobalMap::GetHeight() const
{
	Point minCorner, maxCorner;
	globalMap.GetBoundingBox(minCorner, maxCorner);
	return (maxCorner[1] - minCorner[1]);
}

GridBasedGlobalMap::Point GridBasedGlobalMap::GetMinCorner() const
{
	Point minCorner, maxCorner;
	globalMap.GetBoundingBox(minCorner, maxCorner);
	return minCorner;
}

GridBasedGlobalMap::Point GridBasedGlobalMap::GetMaxCorner() const
{
	Point minCorner, maxCorner;
	globalMap.GetBoundingBox(minCorner, maxCorner);
	return maxCorner;
}

void GridBasedGlobalMap::SetUseUpdateOncePerScan (bool useUpdateOncePerScan)
{
	this->useUpdateOncePerScan = useUpdateOncePerScan;
}

void GridBasedGlobalMap::SetUpdateParameters (const double &logLikelihood_occupied, const double &logLikelihood_free, const double &minLogLikelihood, const double &maxLogLikelihood)
{
	this->logLikelihood_occupied = logLikelihood_occupied;
	this->logLikelihood_free = logLikelihood_free;
	this->minLogLikelihood = minLogLikelihood;
	this->maxLogLikelihood = maxLogLikelihood;
}

void GridBasedGlobalMap::GetUpdateParameters (double &logLikelihood_occupied, double &logLikelihood_free, double &minLogLikelihood, double &maxLogLikelihood)
{
	logLikelihood_occupied = this->logLikelihood_occupied;
	logLikelihood_free = this->logLikelihood_free;
	minLogLikelihood = this->minLogLikelihood;
	maxLogLikelihood = this->maxLogLikelihood;
}

void GridBasedGlobalMap::ClearVisitedCellPtrs()
{
	visitedCellPtrs.clear();
}

#endif /* GRIDBASEDGLOBALMAP_HPP_ */
