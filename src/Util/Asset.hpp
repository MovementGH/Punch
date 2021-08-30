#ifndef Asset_hpp
#define Asset_hpp
#include <string>

class AssetBase {
public:
    virtual void* getAsset() = 0;

    std::string m_Filename;
};

template <typename AssetType>
class Asset : public AssetBase {
public:

    Asset(std::string Filename) {
        m_Filename = Filename;
        m_Asset.loadFromFile(Filename);
    }

    virtual void* getAsset() {
        return &m_Asset;
    }

    AssetType m_Asset;
    
};

#endif