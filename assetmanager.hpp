#ifndef ASSETMANAGER_HPP
#define ASSETMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <singleton.hpp>

class AssetManager : public Singleton<AssetManager>
{
public:
    AssetManager() {}
    static sf::Texture& getTexture(std::string const& filename);

private:
    std::map<std::string, sf::Texture> _textures;
//    static AssetManager* _instance;
};

#endif // ASSETMANAGER_HPP
