#include "assetmanager.hpp"
#include <assert.h>

AssetManager* AssetManager::_instance = nullptr;

AssetManager::AssetManager()
{
    assert(_instance == nullptr);
    _instance = this;
}

sf::Texture &AssetManager::getTexture(const std::string &filename)
{
    auto& texMap = _instance->_textures;

    auto pairfound = texMap.find(filename);
    if(pairfound != texMap.end())
    {
        return pairfound->second;
    }
    else
    {
        sf::Texture& texture = texMap[filename];
        texture.loadFromFile(filename);
        return texture;
    }
}

