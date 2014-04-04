// Part of SimCoupe - A SAM Coupe emulator
//
// Font.h: Font data used for on-screen text
//
//  Copyright (c) 1999-2014 Simon Owen
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#ifndef FONT_H
#define FONT_H

typedef struct
{
    WORD    wWidth, wHeight, wCharSize;
    BYTE    bFirst, bLast;
    bool    fFixedWidth;

    const BYTE* pcbData;
}
GUIFONT;

extern const GUIFONT sFixedFont, sPropFont, sGUIFont, sSpacedGUIFont;

#endif
