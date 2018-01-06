#pragma once

/*
  Big head class. It manages a lot, maybe a little too much. 
  Mostly internal stuff that requires global state for one reason or another.
  When you look into the singleton, it looks into you.
*/

#include <math.h>
#include <iostream>
#include <vector>
#include <stdlib.h>

#include <libconfig.h++>

#include <pandaFramework.h>
#include <pandaSystem.h>

#include <nodePathCollection.h>

#include <genericAsyncTask.h>
#include <asyncTaskManager.h>

#include <cIntervalManager.h>
#include <cLerpNodePathInterval.h>
#include <cMetaInterval.h>

#include <texturePool.h>

#include <load_prc_file.h>

#include <shader.h>
#include <ambientLight.h>
#include <directionalLight.h>
#include <pointLight.h>
#include <spotlight.h>
#include <lightRampAttrib.h>
#include <colorAttrib.h>

#include <geoMipTerrain.h>

#include <graphicsPipeSelection.h>

#include <mouseButton.h>
#include <keyboardButton.h>
#include <pgEntry.h>

#include <cardMaker.h>

#include <cullFaceAttrib.h>
#include <bitMask.h>
#include <collisionHandler.h>
#include <collisionHandlerQueue.h>

#include "AppStateManager.hpp"
//#include "AccumulationBuffer.hpp"
#include "GraphicalInterface.hpp"
#include "UtilFunctions.hpp"

class MainApp
{
public:
  ~MainApp();

  PandaFramework framework;
  WindowFramework *window;

  WindowProperties props;

  libconfig::Config cfg;

  static MainApp* get_instance();
  
  static void reset_instance();

  void start();

  float alpha = 0.0f, beta = 0.0f;
  int cursor_x_pos = 0, cursor_y_pos = 0;

  bool mouse_pressed[3] = {false, false, false};
  bool key_pressed[6] = {false, false, false, false, false, false};

  AppStateManager* m_pAppStateManager;

  //UI------------------------------------------
  PT(PGEntry) console_box;
  NodePath console_np;
  PT(TextNode) console_text;
  NodePath console_text_np;

  PT(PGButton) main_menu_button;
  NodePath mm_button_np;

  PT(PGButton) exit_menu_button;
  NodePath exit_menu_np;

  static libconfig::Config cfg_parser;

private:
  static MainApp* m_pInstance;

  void setup_console();

  MainApp();
  MainApp& operator=(MainApp const&) {};
};
