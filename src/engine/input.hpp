/**
 * @file inputManager.hpp
 * @brief input manager class header/declaration file
 * @author Colby Japp
 * @version 1.0.0
 * @date 2017-10-06
 * @edited 2017-10-06
 */
#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP 

#include<SDL.h>
namespace Hearth
{
  namespace INPUT
  {
    enum Button
    {
      ESC_KEY,
      A_KEY, 
      B_KEY, 
      C_KEY, 
      D_KEY, 
      E_KEY, 
      F_KEY, 
      G_KEY, 
      H_KEY, 
      I_KEY, 
      J_KEY, 
      K_KEY, 
      L_KEY, 
      M_KEY, 
      N_KEY, 
      O_KEY, 
      P_KEY, 
      Q_KEY, 
      R_KEY, 
      S_KEY, 
      T_KEY, 
      U_KEY, 
      V_KEY, 
      W_KEY, 
      X_KEY, 
      Y_KEY, 
      Z_KEY, 
      MAX_KEY
    };
  }

  /**
   * @brief button struct for input management
   *
   * @initial used for maintianing keypressed
   * @down   used for maintaing keydown and keyup
   */
  struct Button_Struct
  {
    bool pressed;
    bool down; 
  };

/**
* @brief Mouse position struct to keep track where mouse is on screen
*/
  struct Mouse
  {
    int x;
    int y;
    Button_Struct left;
    Button_Struct right;
  };

  class Input
  {

    public:
      Input();
      ~Input();

      void init();

      void handleInput(const SDL_Event& ev);

      static bool keyDown(INPUT::Button b){return (m_keyStates[b].down);}
      static bool keyUp(INPUT::Button b){return !(m_keyStates[b].down);}
      static bool keyPress(INPUT::Button b){return (m_keyStates[b].pressed);}

      static bool mouseLDown(){return m_mouse.left.down;}
      static bool mouseLUp(){return m_mouse.left.down;}
      static bool mouseLPress(){return m_mouse.left.pressed;}
      

      static bool mouseRDown(){return m_mouse.right.down;}
      static bool mouseRUp(){return m_mouse.right.down;}
      static bool mouseRPress(){return m_mouse.right.pressed;}

      static int mouseX(){return m_mouse.x;}
      static int mouseY(){return m_mouse.y;}

      void resetPress();
    private:
      void handleButton(const SDL_Event& ev, bool toggle);
      void toggleButton(INPUT::Button i, bool d, bool p);

      static Button_Struct m_keyStates[INPUT::Button::MAX_KEY]; 
      static Mouse m_mouse;
  };
}//end hearth

#endif /* INPUTMANAGER_HPP */
