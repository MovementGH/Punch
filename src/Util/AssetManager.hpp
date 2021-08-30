#ifndef AssetManager_hpp
#define AssetManager_hpp
#include <vector>
#include <string>
#include "Asset.hpp"

class AssetManager {
public:

    template<typename AssetType> AssetType& getAsset(std::string Filename) {
        for(auto & Asset : m_Assets)
            if(Asset->m_Filename == Filename)
                return *(AssetType*)Asset->getAsset();

        m_Assets.emplace_back(new Asset<AssetType>(Filename));
        return *(AssetType*)m_Assets[m_Assets.size()-1]->getAsset();
    }

protected:

    std::vector<AssetBase*> m_Assets;
};

#endif