#include"input.hpp"
#include<cstdio>

namespace Hearth
{

  using namespace INPUT;

  Button_Struct Input::m_keyStates[Button::MAX_KEY];
  Mouse Input::m_mouse;

  Input::Input()
  {
  }

  Input::~Input()
  {

  }

  /**
   * @brief Initialize the input manager states
   */
  void Input::init()
  {
    //Initialize key states to false
    for(int i = 0; i < Button::MAX_KEY; i++)
      toggleButton((Button)i,false,false);

    //init mouse struct
    m_mouse.x = 0;
    m_mouse.x = 1;
    m_mouse.left.pressed = false;
    m_mouse.left.down = false;
    m_mouse.right.pressed = false;
    m_mouse.right.down = false;
  }


  /**
   * @brief Handle input main function
   *
   * @param ev event to parsecaptured by SDL
   */
  void Input::handleInput(const SDL_Event& ev)
  {
    switch(ev.type)
    {
      case SDL_KEYDOWN:
        handleButton(ev, true); 
        break;
      case SDL_KEYUP:
        handleButton(ev, false); 
        break;
      case SDL_MOUSEBUTTONDOWN:
        handleButton(ev, true); 
        break;
      case SDL_MOUSEBUTTONUP:
        handleButton(ev, false); 
        break;
      case SDL_MOUSEMOTION:
        SDL_GetMouseState(&(m_mouse.x), &(m_mouse.y));
        break;
    };
  }


  /**
   * @brief When input is processed, need to reset pressed key state
   */
  void Input::resetPress()
  {
    for(int i = 0; i < Button::MAX_KEY; i++)
      m_keyStates[i].pressed = false;

    m_mouse.left.pressed = false;
    m_mouse.right.pressed = false;
  }


  /**
   * @brief function that changes the input state depending on event and toggle values passed
   *
   * @param ev      the sdl event witnessed, it is guaranteed to be that of KEYUP or KEYDOWN
   * @param toggle  the toggle value of key being passed in, could be up{FALSE} or down{TRUE}
   */
  void Input::handleButton(const SDL_Event& ev, bool toggle)
  {
    switch(ev.button.button)
    {
      case SDL_BUTTON_LEFT:
        {
          m_mouse.left.pressed = false;
          if(!m_mouse.left.down)
            m_mouse.left.pressed = toggle;
          m_mouse.left.down = toggle;
          return;
        }
      case SDL_BUTTON_RIGHT:
        {
          m_mouse.right.pressed = false;
          if(!m_mouse.right.down)
            m_mouse.right.pressed = toggle;
          m_mouse.right.down = toggle;
          return;
        }
    }

    switch(ev.key.keysym.sym)
    {
      case SDLK_ESCAPE:
        {
          toggleButton(Button::ESC_KEY,toggle,toggle);
          return;
        }
      case SDLK_a:
        {
          toggleButton(Button::A_KEY,toggle,toggle);
          return;
        }
      case SDLK_b:
        {
          toggleButton(Button::B_KEY,toggle,toggle);
          return;
        }
      case SDLK_c:
        {
          toggleButton(Button::C_KEY,toggle,toggle);
          return;
        }
      case SDLK_d:
        {
          toggleButton(Button::D_KEY,toggle,toggle);
          return;
        }
      case SDLK_e:
        {
          toggleButton(Button::E_KEY,toggle,toggle);
          return;
        }
      case SDLK_f:
        {
          toggleButton(Button::F_KEY,toggle,toggle);
          return;
        }
      case SDLK_g:
        {
          toggleButton(Button::G_KEY,toggle,toggle);
          return;
        }
      case SDLK_h:
        {
          toggleButton(Button::H_KEY,toggle,toggle);
          return;
        }
      case SDLK_i:
        {
          toggleButton(Button::I_KEY,toggle,toggle);
          return;
        }
      case SDLK_j:
        {
          toggleButton(Button::J_KEY,toggle,toggle);
          return;
        }
      case SDLK_k:
        {
          toggleButton(Button::K_KEY,toggle,toggle);
          return;
        }
      case SDLK_l:
        {
          toggleButton(Button::L_KEY,toggle,toggle);
          return;
        }
      case SDLK_m:
        {
          toggleButton(Button::M_KEY,toggle,toggle);
          return;
        }
      case SDLK_n:
        {
          toggleButton(Button::N_KEY,toggle,toggle);
          return;
        }
      case SDLK_o:
        {
          toggleButton(Button::O_KEY,toggle,toggle);
          return;
        }
      case SDLK_p:
        {
          toggleButton(Button::P_KEY,toggle,toggle);
          return;
        }
      case SDLK_q:
        {
          toggleButton(Button::Q_KEY,toggle,toggle);
          return;
        }
      case SDLK_r:
        {
          toggleButton(Button::R_KEY,toggle,toggle);
          return;
        }
      case SDLK_s:
        {
          toggleButton(Button::S_KEY,toggle,toggle);
          return;
        }
      case SDLK_t:
        {
          toggleButton(Button::T_KEY,toggle,toggle);
          return;
        }
      case SDLK_u:
        {
          toggleButton(Button::U_KEY,toggle,toggle);
          return;
        }
      case SDLK_v:
        {
          toggleButton(Button::V_KEY,toggle,toggle);
          return;
        }
      case SDLK_w:
        {
          toggleButton(Button::W_KEY,toggle,toggle);
          return;
        }
      case SDLK_x:
        {
          toggleButton(Button::X_KEY,toggle,toggle);
          return;
        }
      case SDLK_y:
        {
          toggleButton(Button::Y_KEY,toggle,toggle);
          return;
        }
      case SDLK_z:
        {
          toggleButton(Button::Z_KEY,toggle,toggle);
          return;
        }
    }
  }


  /**
   * @brief Helper function for toggling keystates
   *
   * @param b The index of key to change
   * @param pdown The toggle for whether the button is down or not
   * @param ppressed The toggle if button was just pressed
   */
  void Input::toggleButton(Button b, bool pdown, bool ppressed)
  {
    m_keyStates[b].pressed = false;

    //if key was up when toggle button was called, pressed needs to be set
    if(keyUp(b))
      m_keyStates[b].pressed = ppressed;

    m_keyStates[b].down = pdown;
  }


}//end Hearth
