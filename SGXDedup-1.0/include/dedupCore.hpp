#ifndef SGXDEDUP_DEDUPCORE_HPP
#define SGXDEDUP_DEDUPCORE_HPP

#include "configure.hpp"
#include "cryptoPrimitive.hpp"
#include "dataStructure.hpp"
#include "database.hpp"
#include "messageQueue.hpp"
#include "protocol.hpp"
#include <bits/stdc++.h>
#include <map>

using namespace std;

class DedupCore {
private:
    map<u_char*,pair<u_char*,u_char*>> cache;
public:
    DedupCore();
    ~DedupCore();
    bool dedupByHash(u_char* inputHashList, int chunkNumber, bool* out, int& requiredChunkNumber);
    bool dedupByCache(u_char* inputHashList, int chunkNumber, bool* requiredCalcList);
    bool updateCache(int chunkNumber, u_char* inputHashList, u_char* inputTagList, u_char* inputCkList);
};

#endif //SGXDEDUP_DEDUPCORE_HPP
