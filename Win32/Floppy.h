// Part of SimCoupe - A SAM Coupe emulator
//
// Floppy.h: Real floppy access (requires fdrawcmd.sys)
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

#ifndef FLOPPY_H
#define FLOPPY_H

#include <fdrawcmd.h>   // http://simonowen.com/fdrawcmd/fdrawcmd.h
#include "Stream.h"

typedef struct
{
    int sectors;
    BYTE cyl, head;     // physical track location
} TRACK, *PTRACK;

typedef struct
{
    BYTE cyl, head, sector, size;
    BYTE status;
    BYTE *pbData;
} SECTOR, *PSECTOR;


class CFloppyStream final : public CStream
{
    public:
        CFloppyStream (const char* pcszDevice_, bool fReadOnly_);
        CFloppyStream (const CFloppyStream &) = delete;
        void operator= (const CFloppyStream &) = delete;
        virtual ~CFloppyStream ();

    public:
        static bool IsSupported ();
        static bool IsAvailable ();
        static bool IsRecognised (const char* pcszStream_);

    public:
        void Close () override;
        unsigned long ThreadProc ();

    public:
        bool IsOpen () const override { return m_hDevice != INVALID_HANDLE_VALUE; }
        bool IsBusy (BYTE* pbStatus_, bool fWait_);

        // The normal stream functions are not used
        bool Rewind () override { return false; }
        size_t Read (void*, size_t) override { return 0; }
        size_t Write (void*, size_t) override { return 0; }

        BYTE StartCommand (BYTE bCommand_, PTRACK pTrack_=nullptr, UINT uSectorIndex_=0);

    protected:
        HANDLE m_hDevice = INVALID_HANDLE_VALUE; // Floppy device handle
        HANDLE m_hThread = nullptr; // Worker thread handles
        UINT m_uSectors = 0;        // Sector count, or zero for auto-detect (slower)

        BYTE m_bCommand = 0;        // Current command
        BYTE m_bStatus;             // Final status

        PTRACK m_pTrack = nullptr;  // Track for command
        UINT m_uSectorIndex = 0;    // Zero-based sector for write command
};

#endif  // FLOPPY_H
