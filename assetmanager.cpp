#include "assetmanager.hpp"

sf::Texture &AssetManager::getTexture(const std::string &filename)
{
    auto& texMap = getInstance()._textures;

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
