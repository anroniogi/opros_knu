#ifndef _NDTREE_H_
#define _NDTREE_H_

#include <memory>
#include <vector>
#include <cmath>

template <typename DataT = double, const unsigned int Dimension = 2>
class NDTree
{
public:
	struct Point
	{
		Point(double d = 0)
		{
			for (unsigned int i=0; i<Dimension; i++) {
				data[i] = d;
			}
		}

		Point &operator+(const Point &point);
		Point &operator+(const double &a);
		Point &operator-(const Point &point);
		Point &operator-(const double &a);
		Point &operator*(const double &a);
		Point &operator/(const double &a);
		double &operator[](const unsigned int &i);
		const double &operator[](const unsigned int &i) const;

		double data[Dimension];
	};
	typedef typename std::vector<Point> PointSet;

private:
	class Node : public std::enable_shared_from_this< typename NDTree<DataT>::Node >
	{
	public:
		typedef std::shared_ptr<Node> Ptr;
		typedef std::shared_ptr<const Node> ConstPtr;

		Node(Point point = Point(), double cellSize = 1);
		Node(const Node &node);
		Node(Node &&node);
		virtual ~Node();
		Node &operator=(const Node &node);
		Node &operator=(Node &&node);
		void DeepCopy(const Node &node);

		inline void SetData(const DataT &data);
		inline DataT GetData() const;
		inline bool GetData(std::shared_ptr<DataT> &pData);
		inline Point GetCenter() const;
		inline double GetCellSize() const;
		bool IsIn (const Point &point) const;
		bool GetNode(Ptr &node, const Point &point, Point boudingBox[] = nullptr, const bool &createNode = false);
		inline bool IsLeaf() const;
		Ptr IncreaseDepth(const Point &point);

	private:
		const unsigned int numberOfSons;
		std::weak_ptr<Node> parent;
		std::vector<Ptr> sons;
		Point center;
		double cellSize;
		unsigned int level;
		
		std::shared_ptr<DataT> pData;

		inline void SetNode(unsigned int index, Point boundingBox[]);
	};

public:
	typedef std::shared_ptr<DataT> DataPtr;

	typedef typename Node::Ptr NodePtr;
	typedef typename Node::ConstPtr NodeConstPtr;

	typedef std::shared_ptr<NDTree> Ptr;
	typedef std::shared_ptr<const NDTree> ConstPtr;

	NDTree(double cellSize);
	NDTree(const NDTree &ndTree);
	NDTree(NDTree &&ndTree);
	virtual ~NDTree();
	NDTree &operator=(const NDTree &ndTree);
	NDTree &operator=(NDTree &&ndTree);
	void DeepCopy(const NDTree &ndTree);

	inline bool IsIn (const Point &point) const;
	bool SetData(const Point &point, const DataT &data, const bool &createNode = true);
	DataT GetData(const Point &point, const bool &createNode = false);
	bool GetData(DataPtr &pData, const Point &point, const bool &createNode = false);
	inline double GetCellSize() const;
	void GetBoundingBox(Point &minCorner, Point &maxCorner) const;
	inline Point GetCenter() const;
	inline bool IsInitialized() const;
	inline bool HasOneCell() const;

private:
	double cellSize;
	NodePtr root;
	bool isInitialized;
	Point boundingBox[2];

	//std::vector<NodePtr> leafNodeSet;
};

#include "NDTree.hpp"

#endif
