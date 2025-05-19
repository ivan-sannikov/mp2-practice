#pragma once
template <typename TKey, typename TData>
struct TabRecord {
	TKey key;
	TData pData;
	TabRecord(TKey key, TData data) : key(key), pData(data) {}
	TabRecord() {}
    bool operator==(const TabRecord& other) const {
        return key == other.key && pData == other.pData;
    }

    bool operator!=(const TabRecord& other) const {
        return !(*this == other);
    }
};