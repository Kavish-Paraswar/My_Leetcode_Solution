class RandomizedSet {
public:
    map<int, int> m;
    vector<int> nums;
    int ptr = 0;
    RandomizedSet() {}

    bool insert(int val) {
        if (m.count(val))
            return false;

        if (ptr == nums.size())
            nums.push_back(val);
        else
            nums[ptr] = val;

        m[val] = ptr;
        ptr++;
        return true;
    }

    bool remove(int val) {
        if (!m.count(val)) {
            return false;
        }
        int last = nums[ptr - 1];
        int idx = m[val];

        nums[idx] = last;
        m[last] = idx;
        m.erase(val);
        ptr--;
        return true;
    }

    int getRandom() { return nums[rand() % ptr]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */