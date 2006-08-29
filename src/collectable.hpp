//  $Id: collectable.hpp,v 1.4 2005/08/19 20:51:56 joh Exp $
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

#ifndef HEADER_COLLECTABLE_H
#define HEADER_COLLECTABLE_H

#define MAX_COLLECTABLES 5

#include "collectable_manager.hpp"

class Kart;

class Collectable {
 protected:
  Kart*                      owner;
  collectableType            type;
  int                        number;

 public:
                  Collectable  (Kart* kart_);
  void            set          (collectableType _type, int n=1);
  void            clear        () {type=COLLECT_NOTHING; number=0;}
  int             getNum       () {return number;}
  collectableType getType      () {return type;}
  void            hitRedHerring(int n);
  Material*       getIcon      ();
  void            use          ();
};

#endif
