// This file is part of CaesarIA.
//
// CaesarIA is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// CaesarIA is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with CaesarIA.  If not, see <http://www.gnu.org/licenses/>.
//
// Copyright 2012-2013 Gregoire Athanase, gathanase@gmail.com


#ifndef _CAESARIA_SCENE_LEVEL_H_INCLUDE_
#define _CAESARIA_SCENE_LEVEL_H_INCLUDE_

#include "base.hpp"
#include "core/predefinitions.hpp"
#include "core/scopedptr.hpp"
#include "game/game.hpp"

class Game;

namespace scene
{

class Level: public Base
{
public:
  typedef enum {mainMenu=0, loadGame, quitGame} ResultType;
  Level( Game& game, GfxEngine& engine );
  ~Level();

  void initialize();
  std::string getMapName() const;

  virtual void handleEvent( NEvent& event );
  virtual void draw();
  virtual void animate( unsigned int time );
  virtual void afterFrame();
  virtual int getResult() const;

  virtual bool installEventHandler(EventHandlerPtr);

  void setCameraPos( TilePos pos );

private:
  void _resolveEndGame();
  void _resolveExitGame();
  void _resolveSwitchMap();
  void _resolveFastLoad();

  class Impl;
  ScopedPtr< Impl > _d;
};

}//end namespace scene

#endif //_CAESARIA_SCENE_LEVEL_H_INCLUDE_