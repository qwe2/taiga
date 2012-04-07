/*
** Taiga, a lightweight client for MyAnimeList
** Copyright (C) 2010-2012, Eren Okka
** 
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
** 
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ANIMEDB_H
#define ANIMEDB_H

#include "std.h"
#include "win32/win_thread.h"

class Anime;

// =============================================================================

class AnimeDatabase {
public:
  AnimeDatabase();
  virtual ~AnimeDatabase() {}

  bool Load();
  bool Save();
  
  Anime* FindItem(int anime_id);
  void Update(Anime& anime);

public:
  vector<Anime> items;

private:
  win32::CriticalSection critical_section_;
  wstring file_, folder_;
};

class AnimeSeasonDatabase {
public:
  AnimeSeasonDatabase();
  virtual ~AnimeSeasonDatabase() {}

  bool Load(wstring file);
  bool Save(wstring file = L"");

public:
  vector<Anime> items;
  time_t last_modified;
  bool modified;
  wstring name;

private:
  wstring file_, folder_;
};

extern AnimeDatabase AnimeDatabase;
extern AnimeSeasonDatabase SeasonDatabase;

#endif // ANIMEDB_H