#include "resourceManager.hpp"
#include "error.hpp"

namespace Hearth
{

  std::map<std::string, HTexture*>   ResourceManager::m_textures;
  std::map<std::string, Font*>       ResourceManager::m_fonts;
  std::map<std::string, Music*>       ResourceManager::m_music;
  std::map<std::string, GameObject*> ResourceManager::m_prefabs;


  ResourceManager::ResourceManager()
  {

  }


  ResourceManager::~ResourceManager()
  {
    clear();
  }


  void ResourceManager::loadTexture(const std::string& texturePath, const std::string& name)
  {
    HTexture* tmp = new HTexture();
    tmp->loadFromFile(texturePath); 
    m_textures[name] = tmp;
  }


  HTexture* ResourceManager::getTexture(const std::string& name)
  {
    if(m_textures[name])
      return m_textures[name];

    Error::printMessage("Error: name <" + name + "> is not a texture name.");
    return nullptr;
  }


  void ResourceManager::loadFont(const std::string& fontPath, const std::string& name)
  {
    Font* tmp = new Font();
    tmp->loadText(fontPath); 
    m_fonts[name] = tmp;
  }


  Font* ResourceManager::getFont(const std::string& name)
  {
    if(m_fonts[name])
      return m_fonts[name];

    Error::printMessage("Error: name <" + name + "> is not a texture name.");
    return nullptr;
  } 


  void ResourceManager::loadMusic(const std::string& musicPath, const std::string& name)
  {
    Music* tmp = new Music();
    tmp->loadMusic(musicPath);
    m_music[name] = tmp;
  }


  Music* ResourceManager::getMusic(const std::string& name)
  {
    if(m_music[name])
      return m_music[name];

    Error::printMessage("Error: name <" + name + "> is not a music name.");
    return nullptr;
  }


  void ResourceManager::loadPrefab(GameObject* gameObject, const std::string& name)
  {
    m_prefabs[name] = gameObject;
  }


  GameObject* ResourceManager::getPrefab(const std::string& name)
  {
    if(m_prefabs[name])
      return m_prefabs[name];

    Error::printMessage("Error: name <" + name + "> is not a prefab name.");
    return nullptr;
  }

  void ResourceManager::clear()
  {
    //clear texture map
    auto txt_it = m_textures.begin();
    while(txt_it != m_textures.end())
    {
      delete txt_it->second;
      txt_it++;
    }
    //clear the texture map first elements 
    m_textures.clear();

    
    //clear font map
    auto font_it = m_fonts.begin();
    while(font_it != m_fonts.end())
    {
      delete font_it->second;
      font_it++;
    }
    //clear the font map first elements 
    m_fonts.clear();

    //clear music map
    auto music_it = m_music.begin();
    while(music_it != m_music.end())
    {
      delete music_it->second;
      music_it++;
    }
    //clear the music map first elements 
    m_music.clear();


    //clear prefab map
    auto obj_it = m_prefabs.begin();
    while(obj_it != m_prefabs.end())
    {
      delete obj_it->second;
      obj_it++;
    }
    //clear the texture map first elements 
    m_prefabs.clear();
  }

}//end Hearth
