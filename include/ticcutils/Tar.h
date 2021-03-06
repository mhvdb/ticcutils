/*
  $Id$
  $URL$

  Copyright (c) 1998 - 2015
  ILK   - Tilburg University
  CLiPS - University of Antwerp

  This file is part of ticcutils

  timbl is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 3 of the License, or
  (at your option) any later version.

  timbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, see <http://www.gnu.org/licenses/>.

  For questions and suggestions, see:
      http://ilk.uvt.nl/software.html
  or send mail to:
      timbl@uvt.nl
*/

#ifndef TICC_TAR_TOOLS_H
#define TICC_TAR_TOOLS_H

#ifdef HAVE_LIBTAR_H
#include "libtar.h"
#else
#define TAR int
#endif
#include <fstream>
#include <vector>

namespace TiCC {

  class tar {
  public:
    tar();
    ~tar();
    bool open( const std::string& );
    bool extract_file_names( std::vector<std::string>&,
			     const std::string& = "" );
    bool extract_file_names_match( std::vector<std::string>&,
				   const std::string& );
    bool next_ifstream( std::ifstream&, std::string& );
    bool extract_ifstream( const std::string&, std::ifstream& );
    bool close();
  private:
    TAR *tar_file;
    std::string tarname;
  };

} // namespace TiCC

#endif
