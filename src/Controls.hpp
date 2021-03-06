#pragma once

/*
  This class is for setting up a keymap by manipulating the key_pressed and mouse_pressed arrays in MainApp.
*/

#include "MainApp.hpp"
#include "GraphicalInterface.hpp"

extern float beta;

enum CAMERA_KEY{C_MOUSE1 = 0,
				C_MOUSE2 = 1,
				C_MOUSE3 = 2};

enum KEY_MAP{
  ESC_KEY = 0,
  TILDE_KEY = 1,
  E_KEY = 2,
  D_KEY = 3,
  S_KEY = 4,
  F_KEY = 5,
};

class Controls {
public:

  static float alpha;
  
  static void mouse_event_handler(const Event* e, void* data) {
	if (e->get_name() == "mouse1")
	  M_A->mouse_pressed[C_MOUSE1] = true;
	else if (e->get_name() == "mouse1-up")
	  M_A->mouse_pressed[C_MOUSE1] = false;
  
	else if (e->get_name() == "mouse2")
	  M_A->mouse_pressed[C_MOUSE2] = true;
	else if (e->get_name() == "mouse2-up")
	  M_A->mouse_pressed[C_MOUSE2] = false;

	else if (e->get_name() == "mouse3")
	  M_A->mouse_pressed[C_MOUSE3] = true;
	else if (e->get_name() == "mouse3-up")
	  M_A->mouse_pressed[C_MOUSE3] = false;
  }

  static void key_event_handler(const Event* e, void* data) {
	std::cout << "event: " << e->get_name() << std::endl;
	if (e->get_name() == "escape")
	  M_A->key_pressed[ESC_KEY] = true;
	else if (e->get_name() == "escape-up")
	  M_A->key_pressed[ESC_KEY] = false;

	else if (e->get_name() == "`")
	  M_A->key_pressed[TILDE_KEY] = true;
	else if (e->get_name() == "`-up")
	  M_A->key_pressed[TILDE_KEY] = false;

	else if (e->get_name() == "e")
	  M_A->key_pressed[E_KEY] = true;
	else if (e->get_name() == "e-up")
	  M_A->key_pressed[E_KEY] = false;

	else if (e->get_name() == "d")
	  M_A->key_pressed[D_KEY] = true;
	else if (e->get_name() == "d-up")
	  M_A->key_pressed[D_KEY] = false;

	else if (e->get_name() == "s")
	  M_A->key_pressed[S_KEY] = true;
	else if (e->get_name() == "s-up")
	  M_A->key_pressed[S_KEY] = false;

	else if (e->get_name() == "f")
	  M_A->key_pressed[F_KEY] = true;
	else if (e->get_name() == "f-up")
	  M_A->key_pressed[F_KEY] = false;
  }
  
  static void define_keys();

  AsyncTask::DoneStatus move_player(GenericAsyncTask* task, void* data);
  
private:
  //bool mouse_pressed[3] = {false, false, false};
};
  
//extern CAMERA_KEY key;
