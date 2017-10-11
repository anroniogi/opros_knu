#ifndef _GRIDMAP_H_
#define _GRIDMAP_H_

#include <vector>

//#define NDEBUG
//#include <assert.h>

template<typename DataT = double>
class GridMap
{
public:
	GridMap();
	GridMap(unsigned int size);
	GridMap(unsigned int w, unsigned int h);
	virtual ~GridMap();

	void Resize(unsigned int size);
	void Resize(unsigned int w, unsigned int h);
	inline unsigned int GetWidth() const;
	inline unsigned int GetHeight() const;

	inline bool IsIn(unsigned int x, unsigned int y) const;
	DataT GetData(unsigned int x, unsigned int y) const;
	bool GetData(unsigned int x, unsigned int y, DataT &data) const;
	bool SetData(unsigned int x, unsigned int y, const DataT &data);
	bool GetDataPtr(unsigned int x, unsigned int y, DataT *&dataPtr);

private:
	unsigned int width;
	unsigned int height;

	std::vector< std::vector<DataT> > grid;
};

template<typename DataT>
GridMap<DataT>::GridMap() : width(0), height(0)
{

}

template<typename DataT>
GridMap<DataT>::GridMap(unsigned int size) : width(size), height(size), grid (width, std::vector<DataT>(height, 0))
{

}

template<typename DataT>
GridMap<DataT>::GridMap(unsigned int w, unsigned int h) : width(w), height(h), grid (width, std::vector<DataT>(height, 0))
{

}

template<typename DataT>
GridMap<DataT>::~GridMap()
{

}

template<typename DataT>
void GridMap<DataT>::Resize(unsigned int size)
{
	width = height = size;
	grid = std::vector <std::vector <double> >(width, std::vector<DataT>(height, 0));
}

template<typename DataT>
void GridMap<DataT>::Resize(unsigned int w, unsigned int h)
{
	width = w;
	height = h;
	grid = std::vector <std::vector <double> >(width, std::vector<DataT>(height, 0));
}

template<typename DataT>
inline unsigned int GridMap<DataT>::GetWidth() const
{
	return width;
}

template<typename DataT>
inline unsigned int GridMap<DataT>::GetHeight() const
{
	return height;
}

template<typename DataT>
inline bool GridMap<DataT>::IsIn(unsigned int x, unsigned int y) const
{
	return (x <= width && y <= height);
}

template<typename DataT>
DataT GridMap<DataT>::GetData(unsigned int x, unsigned int y) const
{
	if (IsIn(x,y)){
		return grid[x][y];
	} else {
		std::cout << "ERROR : GridMap::GetData -> the (x,y) node is not allocated." << std::endl;
		return DataT();
	}
}

template<typename DataT>
bool GridMap<DataT>::GetData(unsigned int x, unsigned int y, DataT &data) const
{
	if (IsIn(x,y)){
		data = grid[x][y];
		return true;
	} else {
		std::cout << "ERROR : GridMap::GetData -> the (x,y) node is not allocated." << std::endl;
		data = DataT();
		return false;
	}
}

template<typename DataT>
bool GridMap<DataT>::SetData(unsigned int x, unsigned int y, const DataT &data)
{
	if (IsIn(x,y)){
		grid[x][y] = data;
		return true;
	} else {
		std::cout << "ERROR : GridMap::SetData -> the (x,y) node is not allocated." << std::endl;
		return false;
	}
}

template<typename DataT>
bool GridMap<DataT>::GetDataPtr(unsigned int x, unsigned int y, DataT *&dataPtr)
{
	if (IsIn(x,y)){
		dataPtr = &grid[x][y];
		return true;
	} else {
		std::cout << "ERROR : GridMap::SetData -> the (x,y) node is not allocated." << std::endl;
		return false;
	}
}
#endif
