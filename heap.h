
class HEAP
{
public:

	Vi heapContainer;

	HEAP()
	{
		heapContainer.push_back(0);
	}

	int getLeftChildIndex(int parentIndex)
	{
		return (2 * parentIndex) + 1;
	}

	int getRightChildIndex(int parentIndex)
	{
		return (2 * parentIndex) + 2;
	}

	int getParentIndex(int childIndex)
	{
		return floor((childIndex - 1) / 2);
	}

	BOOL hasParent(int childIndex)
	{
		return getParentIndex(childIndex) >= 0;
	}

	BOOL hasLeftChild(int parentIndex)
	{
		return getLeftChildIndex(parentIndex) < heapContainer.size();
	}

	BOOL hasRightChild(int parentIndex)
	{
		return getRightChildIndex(parentIndex) < heapContainer.size();
	}

	int leftChild(int parentIndex)
	{
		return heapContainer[getLeftChildIndex(parentIndex)];
	}

	int rightChild(int parentIndex)
	{
		return heapContainer[getRightChildIndex(parentIndex)];
	}

	int parent(int childIndex)
	{
		return heapContainer[getParentIndex(childIndex)];
	}

	swap(int indexOne, int indexTwo)
	{
		int temp = heapContainer[indexTwo];
		heapContainer[indexTwo] = heapContainer[indexOne];
		heapContainer[indexOne] = temp;
	}

	int peek()
	{
		if (heapContainer.size() == 0)
			return NULL;

		return heapContainer[0];
	}

	int poll()
	{
		if (heapContainer.size() == 0)
			return NULL;

		if (heapContainer.size() == 1)
		{
			int temp1 = heapContainer.back();
			heapContainer.pop_back();
			return temp1;
		}

		int item = heapContainer[0];

		// Move the last element from the end to the head.
		heapContainer[0] = heapContainer.back();
		heapContainer.pop_back();
		heapifyDown();

		return item;
	}

	add(int item)
	{
		heapContainer.push_back(item);
		heapifyUp();
	}

	remove(int item)
	{
		// Find number of items to remove.
		int numberOfItemsToRemove = comparatorCount(item);

		for (int iteration = 0; iteration < numberOfItemsToRemove; iteration++)
		{
			int* arr;
			int indexToRemove = find(item, arr);




		}





	}

	find(int item, int arr[])
	{
		//		const foundItemIndices = [];
		//		
		//		for (let itemIndex = 0; itemIndex < this.heapContainer.length; itemIndex += 1) {
		//		  if (comparator.equal(item, this.heapContainer[itemIndex])) {
		//			foundItemIndices.push(itemIndex);
		//		  }
		//		}
		//
		//		return foundItemIndices;
		return 1;
	}

	isEmpty()
	{

	}

	toString()
	{

	}

	heapifyUp(int customStartIndex = 0)
	{

	}

	heapifyDown(int customStartIndex = 0)
	{

	}

	pairIsInCorrectOrder(int firstElement, int secondElement)
	{

	}

private:
	int comparatorCount(int item)
	{
		int temp = 0;
		for (int a = 0; a < heapContainer.size(); a++)
		{
			if (heapContainer[a] == item)
				temp++;
		}

		return temp;
	}
};