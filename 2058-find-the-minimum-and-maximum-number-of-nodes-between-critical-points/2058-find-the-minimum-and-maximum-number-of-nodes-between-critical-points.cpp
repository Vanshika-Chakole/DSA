class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> ans = {-1, -1};

        // Need at least 3 nodes for a critical point
        if (head == nullptr || head->next == nullptr ||
            head->next->next == nullptr) {
            return ans;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;

        int index = 1;

        int first = -1;
        int last = -1;

        int minDist = INT_MAX;

        while (curr->next != nullptr) {

            int nextVal = curr->next->val;

            // Check local maxima or local minima
            bool isCritical =
                (curr->val > prev->val && curr->val > nextVal) ||
                (curr->val < prev->val && curr->val < nextVal);

            if (isCritical) {

                // First critical point
                if (first == -1) {
                    first = index;
                }

                // If this is not the first critical point
                if (last != -1) {
                    minDist = min(minDist, index - last);
                }

                last = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        // Fewer than 2 critical points
        if (first == -1 || first == last) {
            return {-1, -1};
        }

        int maxDist = last - first;

        return {minDist, maxDist};
    }
};