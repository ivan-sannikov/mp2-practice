#pragma once
template <typename TKey, typename TData>
struct TabRecord {
	TKey key;
	TData pData;
	TabRecord(TKey key, TData data) : key(key), pData(data) {}
	TabRecord() {}
};