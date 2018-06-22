#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP 

#include "hTexture.h"
#include "font.h"
#include "gameObject.hpp"

#include<map>
#include<string>
#include<vector>

namespace Hearth
{

  class ResourceManager
  {
    public:
      ResourceManager();
      ~ResourceManager();

      static void loadTexture(const std::string& texturePath, const std::string& name);
      static HTexture* getTexture(const std::string& name);

      static void loadFont(const std::string& fontPath, const std::string& name);
      static Font* getFont(const std::string& name);

      static void loadPrefab(GameObject* obj, const std::string& name);
      static GameObject* getPrefab(const std::string& name);

      static void clear();

    private:
      static std::map<std::string, HTexture*> m_textures;
      static std::map<std::string, Font*> m_fonts;
      static std::map<std::string, GameObject*> m_prefabs;
  };

}//end Hearth

#endif /* RESOURCEMANAGER_HPP */
