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

#ifndef _CAESARIA_FUNDISSUE_EVENT_H_INCLUDE_
#define _CAESARIA_FUNDISSUE_EVENT_H_INCLUDE_

#include "event.hpp"

namespace events
{

class FundIssueEvent : public GameEvent
{
public:
  static GameEventPtr create( int type, int value );
  static GameEventPtr import( Good::Type good, int qty );
  static GameEventPtr exportg( Good::Type good, int qty );

protected:
  virtual void _exec( Game& game, uint );
  virtual bool _mayExec(Game &game, uint time) const;

private:
  int _type;
  int _value;
  Good::Type _gtype;
  int _qty;
};

} //end namespace events
#endif //_CAESARIA_FUNDISSUE_EVENT_H_INCLUDE_