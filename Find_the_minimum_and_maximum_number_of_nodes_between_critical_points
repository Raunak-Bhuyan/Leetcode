class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        int prevVal =  head->val;
        int firstCriticalIndex = -1;
        int lastCriticalIndex = -1;
        int minDistance = INT_MAX;

        ListNode* currentNode = head->next;
        int currentIndex = 1;

        while(currentNode != nullptr && currentNode->next != nullptr){
            if((prevVal < currentNode->val && currentNode->val > currentNode->next->val) || (prevVal > currentNode->val && currentNode->val < currentNode->next->val)){
                if(firstCriticalIndex == -1){
                    firstCriticalIndex = currentIndex;
                }else{
                    minDistance = min(minDistance, currentIndex - lastCriticalIndex);
                }
                lastCriticalIndex = currentIndex;
            }
            prevVal = currentNode->val;
            currentNode = currentNode->next;
            currentIndex++;
        }
        if(firstCriticalIndex == -1 || lastCriticalIndex == firstCriticalIndex){
            return {-1,-1};
        }
        return {minDistance, lastCriticalIndex - firstCriticalIndex};
    }
};
