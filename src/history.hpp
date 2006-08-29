//  $Id: history.hpp,v 1.1 2005/09/28 17:00:42 joh Exp $
//
//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2006 Joerg Henrichs
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef HEADER_HISTORY_H
#define HEADER_HISTORY_H

#include <cstdio>
#include "constants.hpp"

class Kart;

class History {
 protected:
  // maximum number of history events to store
  int   nSize;
  int   current;
  bool  wrapped;
  FILE* fd;

  float *     allDeltas;
 public:
        History        ()             { SetSize(MAX_HISTORY);}
  int   GetCount       ()             { return wrapped ? nSize : current+1; }
  int   GetCurrentIndex()             { return current;}
  int   GetSize        ()             { return nSize;  }
  void  SetSize        (int n);
  void  StoreDelta     (float delta);
  void  Save           ();
  void  Load           ();
  void  LoadKartData   (Kart* k, int kartNumber);
  float GetNextDelta   ();
};

extern History* history;

#endif
