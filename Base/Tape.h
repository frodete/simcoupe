// Part of SimCoupe - A SAM Coupe emulator
//
// Tape.h: Tape handling
//
//  Copyright (c) 1999-2015 Simon Owen
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

#ifndef TAPE_H
#define TAPE_H

namespace Tape
{
    bool IsRecognised (const char *pcsz_);
    bool IsPlaying ();
    bool IsInserted ();

    const char* GetPath ();
    const char* GetFile ();
#ifdef USE_LIBSPECTRUM
    libspectrum_tape *GetTape ();
    const char *GetBlockDetails (libspectrum_tape_block *block);
#endif

    bool Insert (const char* pcsz_);
    void Eject ();
    void Play ();
    void Stop ();

    void NextEdge (DWORD dwTime_);
    bool LoadTrap ();

    bool EiHook ();
    bool RetZHook ();
    bool InFEHook ();
}

#endif
