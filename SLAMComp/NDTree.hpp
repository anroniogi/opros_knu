#ifndef _NDTREE_HPP_
#define _NDTREE_HPP_

#include <iostream>

template <typename DataT, const unsigned int Dimension>
NDTree<DataT,Dimension>::NDTree(double cellSize) : cellSize(cellSize), isInitialized(false)
{

}

template <typename DataT, const unsigned int Dimension>
NDTree<DataT,Dimension>::NDTree(const NDTree &ndTree)
{
	if (&ndTree != this) {
		cellSize = ndTree.cellSize;
		root = ndTree.root;
		isInitialized = ndTree.isInitialized;
		boundingBox[0] = ndTree.boundingBox[0];
		boundingBox[1] = ndTree.boundingBox[1];
	}
}

template <typename DataT, const unsigned int Dimension>
NDTree<DataT,Dimension>::NDTree(NDTree &&ndTree)
{
	if (&ndTree == this) {
		std::swap(cellSize, ndTree.cellSize);
		root.swap(ndTree.root);
		std::swap(isInitialized, ndTree.isInitialized);
		std::swap(boundingBox, ndTree.boundingBox);
	}
}

template <typename DataT, const unsigned int Dimension>
NDTree<DataT,Dimension>::~NDTree()
{

}

template <typename DataT, const unsigned int Dimension>
inline bool NDTree<DataT,Dimension>::IsIn (const Point &point) const
{
	return (isInitialized ? root->IsIn(point) : false);
}

template <typename DataT, const unsigned int Dimension>
DataT NDTree<DataT,Dimension>::GetData(const Point &point, const bool &createNode)
{
	if (createNode && !IsIn(point)) {
		if (!isInitialized) {
			root = std::make_shared<Node>(point, cellSize);

			isInitialized = true;
			boundingBox[0] = boundingBox[1] = point;
		} else {
			root = root->IncreaseDepth(point);
		}
	}

	NodePtr node;
	if (isInitialized && root->GetNode(node, point, boundingBox, createNode)) {
		return node->GetData();
	} else {
		return DataT();
	}
}

template <typename DataT, const unsigned int Dimension>
bool NDTree<DataT,Dimension>::GetData(DataPtr &pData, const Point &point, const bool &createNode)
{
	if (createNode && !IsIn(point)) {
		if (!isInitialized) {
			root = std::make_shared<Node>(point, cellSize);

			isInitialized = true;
			boundingBox[0] = boundingBox[1] = point;
		} else {
			root = root->IncreaseDepth(point);
		}
	}

	NodePtr node;
	if (isInitialized && root->GetNode(node, point, boundingBox, createNode)) {
		return node->GetData(pData);
	} else {
		return false;
	}
}

template <typename DataT, const unsigned int Dimension>
bool NDTree<DataT, Dimension>::SetData(const Point &point, const DataT &data, const bool &createNode)
{
	if (createNode && !IsIn(point)) {
		if (!isInitialized) {
			root = std::make_shared<Node>(point, cellSize);

			isInitialized = true;
			boundingBox[0] = boundingBox[1] = point;
		}
		else {
			root = root->IncreaseDepth(point);
		}
	}

	NodePtr node;
	if (isInitialized && root->GetNode(node, point, boundingBox, createNode)) {
		node->SetData(data);
		return true;
	} else {
		return false;
	}
}

template <typename DataT, const unsigned int Dimension>
void NDTree<DataT,Dimension>::DeepCopy(const NDTree &ndTree)
{
	if (this == &ndTree) {
		return;
	}
	cellSize = ndTree.cellSize;
	boundingBox[0] = ndTree.boundingBox[0];
	boundingBox[1] = ndTree.boundingBox[1];

	root = std::make_shared<Node>();
	if (ndTree.isInitialized) {
		root->DeepCopy(*ndTree.root);
		isInitialized = true;
	} else {
		isInitialized = false;
	}
}

template <typename DataT, const unsigned int Dimension>
NDTree<DataT,Dimension> &NDTree<DataT,Dimension>::operator=(const NDTree &ndTree)
{
	if (&ndTree == this) {
		return *this;
	}

	cellSize = ndTree.cellSize;
	root = ndTree.root;
	isInitialized = ndTree.isInitialized;
	boundingBox[0] = ndTree.boundingBox[0];
	boundingBox[1] = ndTree.boundingBox[1];
	
	return *this;
}

template <typename DataT, const unsigned int Dimension>
NDTree<DataT,Dimension> &NDTree<DataT,Dimension>::operator=(NDTree &&ndTree)
{
	if (&ndTree == this) {
		return *this;
	}

	std::swap(cellSize, ndTree.cellSize);
	root.swap(ndTree.root);
	std::swap(isInitialized, ndTree.isInitialized);
	std::swap(boundingBox, ndTree.boundingBox);

	return *this;
}

template <typename DataT, const unsigned int Dimension>
inline double NDTree<DataT,Dimension>::GetCellSize() const
{
	return cellSize;
}

template <typename DataT, const unsigned int Dimension>
void NDTree<DataT,Dimension>::GetBoundingBox(Point &minCorner, Point &maxCorner) const
{
	minCorner = boundingBox[0];
	maxCorner = boundingBox[1];

	if (isInitialized) {
		minCorner = minCorner - cellSize/2;
		maxCorner = maxCorner + cellSize/2;
	}

}

template <typename DataT, const unsigned int Dimension>
inline typename NDTree<DataT,Dimension>::Point NDTree<DataT,Dimension>::GetCenter() const
{
	return (isInitialized ? root->GetCenter() : Point());
}

template <typename DataT, const unsigned int Dimension>
inline bool NDTree<DataT,Dimension>::IsInitialized() const
{
	return isInitialized;
}

template <typename DataT, const unsigned int Dimension>
inline bool NDTree<DataT,Dimension>::HasOneCell() const
{
	return (isInitialized ? root->IsLeaf() : false);
}

template <typename DataT, const unsigned int Dimension>
NDTree<DataT,Dimension>::Node::Node(Point point, double cellSize) : numberOfSons((unsigned int)pow(2,Dimension)), sons(std::vector<Ptr>(numberOfSons, nullptr)), center(point), cellSize(cellSize), level(0), pData(std::make_shared<DataT>())
{

}

template <typename DataT, const unsigned int Dimension>
NDTree<DataT, Dimension>::Node::Node(const Node &node) : numberOfSons((unsigned int)pow(2, Dimension))
{
	if (&node != this) {
		parent = node.parent;
		sons = node.sons;
		center = node.center;
		cellSize = node.cellSize;
		level = node.level;

		*pData = *node.pData;
	}
}

template <typename DataT, const unsigned int Dimension>
NDTree<DataT, Dimension>::Node::Node(Node &&node) : numberOfSons((unsigned int)pow(2, Dimension))
{
	if (&node != this) {		
		parent.swap(node.parent);
		sons.swap(node.sons);
		std::swap(center,node.center);
		std::swap(cellSize,node.cellSize);
		std::swap(level, node.level);

		pData.swap(node.pData);
	}
}

template <typename DataT, const unsigned int Dimension>
NDTree<DataT,Dimension>::Node::~Node()
{

}

template <typename DataT, const unsigned int Dimension>
inline void NDTree<DataT,Dimension>::Node::SetData(const DataT &data)
{
	*pData = data;
}

template <typename DataT, const unsigned int Dimension>
inline DataT NDTree<DataT,Dimension>::Node::GetData() const
{
	return *pData;
}

template <typename DataT, const unsigned int Dimension>
inline bool NDTree<DataT,Dimension>::Node::GetData(std::shared_ptr<DataT> &pData)
{
	pData = this->pData;
	return true;
}

template <typename DataT, const unsigned int Dimension>
inline typename NDTree<DataT,Dimension>::Point NDTree<DataT,Dimension>::Node::GetCenter() const
{
	return center;
}

template <typename DataT, const unsigned int Dimension>
inline double NDTree<DataT,Dimension>::Node::GetCellSize() const
{
	return cellSize;
}

template <typename DataT, const unsigned int Dimension>
bool NDTree<DataT,Dimension>::Node::IsIn (const Point &point) const
{
	bool isIn = true;
	for (std::size_t i = 0; i < Dimension; ++i) {
		isIn &= (center[i] - cellSize / 2 <= point[i]) && (center[i] + cellSize / 2 > point[i]);
	}
		
	return isIn;
}

template <typename DataT, const unsigned int Dimension>
inline void NDTree<DataT,Dimension>::Node::SetNode(unsigned int index, Point boundingBox[])
{
	Point c = center;
	for (std::size_t i = 0; i < Dimension; ++i) {
		c[i] += ((index >> (Dimension - i - 1)) & 1) * cellSize / 2 - cellSize / 4;
	}
	sons[index] = std::make_shared<Node>(c, cellSize / 2);
	sons[index]->level = level - 1;
	sons[index]->parent = this->shared_from_this();
	
	if (sons[index]->IsLeaf()) {
		for (std::size_t i = 0; i < Dimension; ++i) {
			if (boundingBox[0][i] > c[i]) {
				boundingBox[0][i] = c[i];
			}
			if (boundingBox[1][i] < c[i]) {
				boundingBox[1][i] = c[i];
			}
		}
	}
}

template <typename DataT, const unsigned int Dimension>
bool NDTree<DataT, Dimension>::Node::GetNode(Ptr &node, const Point &point, Point boudingBox[], const bool &createNode)
{
	if (IsIn(point)) {
		if (IsLeaf()) {
			node = this->shared_from_this();
			return true;
		} else {
			std::size_t selectedIndex = 0;
			for (std::size_t i = 0; i < Dimension; ++i) {
				selectedIndex |= (point[i] >= center[i]) << (Dimension - i - 1);
			}
			if (createNode) {
				if (sons[selectedIndex].get() == nullptr) {
					SetNode(selectedIndex, boudingBox);
				}
				return sons[selectedIndex]->GetNode(node, point, boudingBox, createNode);
			} else {
				if (sons[selectedIndex].get() == nullptr) {
					return false;
				} else {
					return sons[selectedIndex]->GetNode(node, point, boudingBox, createNode);
				}
			}
		}
	} else {
		return false;
	}
}

template <typename DataT, const unsigned int Dimension>
inline bool NDTree<DataT,Dimension>::Node::IsLeaf() const
{
	return level == 0 ;
}

template <typename DataT, const unsigned int Dimension>
typename NDTree<DataT,Dimension>::Node::Ptr NDTree<DataT,Dimension>::Node::IncreaseDepth (const Point &point)
{
	if (IsIn(point)) {
		return this->shared_from_this();
	} else {
		unsigned int index = 0;
		Point c = center;
		for (std::size_t i = 0; i < Dimension; ++i) {
			c[i] += (point[i] >= center[i]) * cellSize - cellSize/2;
			index |= (center[i] >= c[i]) << (Dimension - i - 1);
		}
		Ptr root = std::make_shared<NDTree<DataT,Dimension>::Node>(c, cellSize * 2);
		parent = root;
		root->sons[index] = this->shared_from_this();
		root->level = level + 1;

		return root->IncreaseDepth (point);
	}
}

template <typename DataT, const unsigned int Dimension>
void NDTree<DataT,Dimension>::Node::DeepCopy(const Node &node)
{	
	center = node.center;
	cellSize = node.cellSize;
	level = node.level;
	*pData = *node.pData;

	for (std::size_t i = 0; i < numberOfSons; ++i) {
		if (node.sons[i].get() != nullptr) {
			sons[i] = std::make_shared<Node>();
			sons[i]->parent = this->shared_from_this();
			sons[i]->DeepCopy(*node.sons[i]);
		}
	}
}

template <typename DataT, const unsigned int Dimension>
typename NDTree<DataT,Dimension>::Node &NDTree<DataT,Dimension>::Node::operator=(const Node &node)
{
	if (&node == this) {
		return *this;
	}

	parent = node.parent;
	sons = node.sons;
	center = node.center;
	cellSize = node.cellSize;
	level = node.level;

	*pData = *node.pData;

	return *this;
}

template <typename DataT, const unsigned int Dimension>
typename NDTree<DataT,Dimension>::Node &NDTree<DataT,Dimension>::Node::operator=(Node &&node)
{
	if (&node == this) {
		return *this;
	}

	parent.swap(node.parent);
	sons.swap(node.sons);
	std::swap(center,node.center);
	std::swap(cellSize,node.cellSize);
	std::swap(level, node.level);

	pData.swap(node.pData);

	return *this;
}

template <typename DataT, const unsigned int Dimension>
typename NDTree<DataT,Dimension>::Point &NDTree<DataT,Dimension>::Point::operator+(const Point &point)
{
	for (unsigned int i=0; i<Dimension; ++i) {
		data[i] += point[i];
	}
	return *this;
}

template <typename DataT, const unsigned int Dimension>
typename NDTree<DataT,Dimension>::Point &NDTree<DataT,Dimension>::Point::operator+(const double &a)
{
	for (unsigned int i=0; i<Dimension; ++i) {
		data[i] += a;
	}
	return *this;
}

template <typename DataT, const unsigned int Dimension>
typename NDTree<DataT,Dimension>::Point &NDTree<DataT,Dimension>::Point::operator-(const Point &point)
{
	for (unsigned int i=0; i<Dimension; ++i) {
		data[i] -= point[i];
	}
	return *this;
}

template <typename DataT, const unsigned int Dimension>
typename NDTree<DataT,Dimension>::Point &NDTree<DataT,Dimension>::Point::operator-(const double &a)
{
	for (unsigned int i=0; i<Dimension; ++i) {
		data[i] -= a;
	}
	return *this;
}

template <typename DataT, const unsigned int Dimension>
typename NDTree<DataT,Dimension>::Point &NDTree<DataT,Dimension>::Point::operator*(const double &a)
{
	for (unsigned int i=0; i<Dimension; ++i) {
		data[i] *= a;
	}
	return *this;
}

template <typename DataT, const unsigned int Dimension>
typename NDTree<DataT,Dimension>::Point &NDTree<DataT,Dimension>::Point::operator/(const double &a)
{
	for (unsigned int i=0; i<Dimension; ++i) {
		data[i] /= a;
	}
	return *this;
}

template <typename DataT, const unsigned int Dimension>
double &NDTree<DataT, Dimension>::Point::operator[](const unsigned int &i)
{
	return data[i];
}

template <typename DataT, const unsigned int Dimension>
const double &NDTree<DataT, Dimension>::Point::operator[](const unsigned int &i) const
{
	return data[i];
}

#endif
