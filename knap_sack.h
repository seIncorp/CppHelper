
// TODO: create MACRO style

class KNAPSACK_ITEM
{
public:

    int value;
    int weight;
    int itemsInStock;
    int quantity;

    KNAPSACK_ITEM()
    {
        value = 0;
        weight = 0;
        itemsInStock = 1;
        quantity = 1;
    }

    KNAPSACK_ITEM(int v = 0, int w = 0, int iis = 1)
    {
        value = v;
        weight = w;
        itemsInStock = iis;
        quantity = 1;
    }

    int total_value()
    {
        return value * quantity;
    }

    int total_weight()
    {
        return weight * quantity;
    }

    int value_per_weight_ratio()
    {
        return value / weight;
    }

    string to_string()
    {
        return "V: " + std::to_string(value) + "\tW: " + std::to_string(weight) + "\tX:" + std::to_string(quantity) + "\tRatio: " + std::to_string(value_per_weight_ratio());
    }
};





class KNAPSACK
{
public:

    KNAPSACK_ITEM** possibleItems;
    std::vector<KNAPSACK_ITEM*> selectedItems;
    int leng;
    int weightLimit;

    KNAPSACK(KNAPSACK_ITEM* pItems[], int len, int wLimit)
    {
        weightLimit = wLimit;

        possibleItems = new KNAPSACK_ITEM * [len]();

        for (int aa = 0; aa < len; aa++)
            possibleItems[aa] = pItems[aa];

        leng = len;
    }

    bums(KNAPSACK_ITEM* a_arr[], KNAPSACK_ITEM* b_arr[], int len, int by)
    {

        for (int width = 1; width < len; width = 2 * width)
        {
            for (int ii = 0; ii < len; ii = ii + 2 * width)
                bum(a_arr, ii, fmin(ii + width, len), fmin(ii + 2 * width, len), b_arr, by);

            for (int ii = 0; ii < len; ii++)
                a_arr[ii] = b_arr[ii];
        }
    }

    bum(KNAPSACK_ITEM* a_arr[], int left, int right, int end, KNAPSACK_ITEM* b_arr[], int by)
    {
        int ii = left, jj = right;

        for (int k = left; k < end; k++)
        {
            switch (by)
            {
            case 0:     // BY Weight
                if ((ii < right) && (jj >= end || a_arr[ii]->weight <= a_arr[jj]->weight))
                {
                    b_arr[k] = a_arr[ii];
                    ii++;
                }
                else
                {
                    b_arr[k] = a_arr[jj];
                    jj++;
                }
                break;

            case 1:     // BY Value
                if ((ii < right) && (jj >= end || a_arr[ii]->value <= a_arr[jj]->value))
                {
                    b_arr[k] = a_arr[ii];
                    ii++;
                }
                else
                {
                    b_arr[k] = a_arr[jj];
                    jj++;
                }
                break;

            case 2:     // BY ValuePerWeightRatio
                if ((ii < right) && (jj >= end || a_arr[ii]->value_per_weight_ratio() <= a_arr[jj]->value_per_weight_ratio()))
                {
                    b_arr[k] = a_arr[ii];
                    ii++;
                }
                else
                {
                    b_arr[k] = a_arr[jj];
                    jj++;
                }
                break;
            }


        }
    }

    sortPossibleItemsByWeight()
    {
        KNAPSACK_ITEM* temp[leng];

        bums(possibleItems, temp, leng, 0);

        for (int width = 0; width < leng; width++)
            o << possibleItems[width]->to_string() << e;

    }

    sortPossibleItemsByValue()
    {
        KNAPSACK_ITEM* temp[leng];

        bums(possibleItems, temp, leng, 1);

        for (int width = 0; width < leng; width++)
            o << possibleItems[width]->to_string() << e;
    }

    sortPossibleItemsByValuePerWeightRatio()
    {
        KNAPSACK_ITEM* temp[leng];

        bums(possibleItems, temp, leng, 2);

        for (int width = 0; width < leng; width++)
            o << possibleItems[width]->to_string() << e;
    }

    solveUnboundedKnapsackProblem()
    {
        sortPossibleItemsByValue();
        sortPossibleItemsByValuePerWeightRatio();

        for (int itemIndex = 0; itemIndex < leng; itemIndex += 1)
        {
            if (totalWeight() < weightLimit)
            {
                KNAPSACK_ITEM* currentItem = possibleItems[itemIndex];

                int availableWeight = weightLimit - totalWeight();
                int maxPossibleItemsCount = floor(availableWeight / currentItem->weight);

                if (maxPossibleItemsCount > currentItem->itemsInStock)
                {
                    currentItem->quantity = currentItem->itemsInStock;
                }
                else if (maxPossibleItemsCount)
                {
                    currentItem->quantity = maxPossibleItemsCount;
                }

                selectedItems.push_back(currentItem);
            }
        }
    }

    int totalValue()
    {
        int ttw = 0;
        for (int ii = 0; ii < selectedItems.size(); ii++)
        {
            ttw += selectedItems[ii]->total_value();
        }

        return ttw;
    }

    int totalWeight()
    {
        int ttw = 0;
        for (int ii = 0; ii < selectedItems.size(); ii++)
        {
            ttw += selectedItems[ii]->total_weight();
        }

        return ttw;
    }

    solveZeroOneKnapsackProblem()
    {
        sortPossibleItemsByValue();
        sortPossibleItemsByWeight();

        selectedItems.clear();

        int numberOfRows = leng;
        int numberOfColumns = weightLimit + 1;

        int knapsackMatrix[numberOfRows][numberOfColumns];

        for (int itemIndex = 0; itemIndex < leng; itemIndex += 1)
            knapsackMatrix[itemIndex][0] = 0;

        for (int weightIndex = 1; weightIndex <= weightLimit; weightIndex += 1)
        {
            int itemIndex = 0;
            int itemWeight = possibleItems[itemIndex]->weight;
            int itemValue = possibleItems[itemIndex]->value;

            knapsackMatrix[itemIndex][weightIndex] = (itemWeight <= weightIndex ? itemValue : 0);
        }

        for (int itemIndex = 1; itemIndex < leng; itemIndex += 1)
        {
            for (int weightIndex = 1; weightIndex <= weightLimit; weightIndex += 1)
            {
                int currentItemWeight = possibleItems[itemIndex]->weight;
                int currentItemValue = possibleItems[itemIndex]->value;

                if (currentItemWeight > weightIndex)
                {
                    knapsackMatrix[itemIndex][weightIndex] = knapsackMatrix[itemIndex - 1][weightIndex];
                }
                else
                {
                    knapsackMatrix[itemIndex][weightIndex] = fmax(
                        (currentItemValue + knapsackMatrix[itemIndex - 1][weightIndex - currentItemWeight]),
                        knapsackMatrix[itemIndex - 1][weightIndex]
                    );
                }
            }
        }

        int itemIndex = leng - 1;
        int weightIndex = weightLimit;

        while (itemIndex > 0)
        {
            KNAPSACK_ITEM* currentItem = possibleItems[itemIndex];
            KNAPSACK_ITEM* prevItem = possibleItems[itemIndex - 1];

            if (knapsackMatrix[itemIndex][weightIndex] && knapsackMatrix[itemIndex][weightIndex] == knapsackMatrix[itemIndex - 1][weightIndex])
            {
                int prevSumValue = knapsackMatrix[itemIndex - 1][weightIndex];
                int prevPrevSumValue = knapsackMatrix[itemIndex - 2][weightIndex];

                if (!prevSumValue || (prevSumValue && prevPrevSumValue != prevSumValue))
                {
                    selectedItems.push_back(prevItem);
                }
            }
            else if (knapsackMatrix[itemIndex - 1][weightIndex - currentItem->weight])
            {
                selectedItems.push_back(prevItem);
                weightIndex -= currentItem->weight;
            }

            itemIndex -= 1;
        }
    }










};